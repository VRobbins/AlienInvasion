#include "EarthObstacle.h"
#include "EarthGame.h"
#include "stdlib.h"


extern EarthGame* earth_game;

EarthObstacle::EarthObstacle(QTimer* input_timer) :
    obstacle_pixmap(nullptr)
{
    // set random position
    int random_number = rand() %470;
    // drew the enemy
    QPixmap temp(":/resources/img/vine.png");
    if(random_number%2==0) { //if even set the position accordingly
        setPos(1200, -60);
        obstacle_pixmap = new QPixmap(temp.scaled(70,random_number));
        setPixmap(*obstacle_pixmap);
    } else { //otherwise transform
        setPos(1200, 800-random_number+50);
        obstacle_pixmap = new QPixmap(temp.scaled(70,random_number).transformed(QTransform().rotate(180)));
        setPixmap(*obstacle_pixmap);
    }

    set_move_timer(input_timer);
}


void EarthObstacle::move()
{
    // collidingItems() returns a list of all items that collide with this item
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through the list of items with which EarthObstacle collides
    for (size_t i = 0; i < colliding_items.size(); ++i){
        // if the obstacle collides with the player, remove obstacle from the scene
        // also play the ice shatter sound effect
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            // decrease the health
            earth_game->health->decrease();
            // set the sound effect
            set_sound_effect(earth_game->ice_shatter_sound, 50);
            // play shattering sound
            play_sound_effect();
            prepareGeometryChange();
            scene()->removeItem(this); //remove this obstacle from the scene
            if (earth_game->health->getHealth()==0){ //if health goes down to zero the lose screan is created
                earth_game->create_LoseScreen();
            }
            delete this;
            return;
        }
    }

    setPos(x()-5,y());
    if (pos().x() < -100){//if obstacle goes out of scene remove it
        scene()->removeItem(this);
        delete this;
    }
}


EarthObstacle::~EarthObstacle()
{
    delete obstacle_pixmap;
    obstacle_pixmap = nullptr;
}

