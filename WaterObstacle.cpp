#include "WaterObstacle.h"
#include "WaterGame.h"
#include "stdlib.h"


extern WaterGame* water_game;

WaterObstacle::WaterObstacle(QTimer* input_timer) : obstacle_pixmap(nullptr)
{
    // set random position
    int random_number = rand() %500;
    // drew the enemy
    QPixmap temp(":/resources/img/icicle.png");
    if(random_number%2==0) { //if an even number
        setPos(1200, -60);
        obstacle_pixmap = new QPixmap(temp.scaled(70,random_number));
        setPixmap(*obstacle_pixmap);
    } else { //if not even
        setPos(1200, 800-random_number+50);
        obstacle_pixmap = new QPixmap(temp.scaled(70,random_number).transformed(QTransform().rotate(180)));
        setPixmap(*obstacle_pixmap);
    }
    set_move_timer(input_timer);
}


void WaterObstacle::move()
{
    // collidingItems() returns a list of all items that collide with this item
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through the items with which WaterObstacle has collided
    for (size_t i = 0; i < colliding_items.size(); ++i) {
        // if the obstacle collides with the player, remove obstacle from the scene
        // also play the ice shatter sound effect
        if (typeid(*(colliding_items[i])) == typeid(Player)) {
            // decrease the health
            water_game->health->decrease();
            // set the sound effect
            set_sound_effect(water_game->ice_shatter_sound, 50);
            // play shattering sound
            play_sound_effect();
            prepareGeometryChange();
            scene() -> removeItem(this); //remove this obstacle from the scene
            // If we detect that the water_game's player's health is 0, lose the game
            if (water_game->health->getHealth()==0){
                water_game->create_LoseScreen();
            }
            delete this;
            return;
        }
    }
    setPos(x()-5,y());
    // If obstacle has moved off the screen, delete it
    if (pos().x() < -100){
        prepareGeometryChange();
        scene()->removeItem(this);
        delete this;
    }
}


WaterObstacle::~WaterObstacle()
{
    delete obstacle_pixmap;
    obstacle_pixmap = nullptr;
}

