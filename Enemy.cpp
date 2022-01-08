#include "Enemy.h"
#include "Bullet.h"
#include "Bomb.h"
#include <QTimer>


Enemy::Enemy(QTimer* input_timer, Game* input_game) :
    graphics_timer(new QTimer),
    alive(true),
    game(input_game),
    already_dead(0)
{
    // Graphics timer
    QObject::connect(graphics_timer,SIGNAL(timeout()),this,SLOT(update_graphics()));
    graphics_timer->start(50);

    QPixmap temp(":/resources/img/eagle/1.png");
    enemy_pixmap = new QPixmap(temp.scaled(70,60));
    setPixmap(*enemy_pixmap);
    graphics_number = 1;

    int random_number = rand() % 300;
    if (random_number % 2 == 0) { //sets the position at random, add if random number is even
        setPos(1200, 400+random_number);
    } else { // //sets the position at random, subtract if modd
        setPos(1200, 350-random_number);
    }
    // Move timer
    connect(input_timer,SIGNAL(timeout()),this,SLOT(move()));
}


void Enemy::update_graphics()
{
    size_t to_image_number = graphics_number + 1;
    // If the graphics image number has reached the end, go back to the beginning
    if (to_image_number == 10) {
        to_image_number = 1;
    }
    std::string new_path(":/resources/img/eagle/" + std::to_string(to_image_number) + ".png");
    QPixmap temp(QString::fromUtf8(new_path.c_str()));
    delete enemy_pixmap;
    enemy_pixmap = nullptr;
    enemy_pixmap = new QPixmap(temp.scaled(70,60));
    setPixmap(*enemy_pixmap);
    graphics_number = to_image_number;
}


void Enemy::dead_graphics()
{
    graphics_timer->stop();
    size_t current_image_number = graphics_number;
    std::string new_path(":/resources/img/eagle/" + std::to_string(current_image_number) + ".png");
    QPixmap temp(QString::fromUtf8(new_path.c_str()));
    delete enemy_pixmap;
    enemy_pixmap = nullptr;
    enemy_pixmap = new QPixmap(temp.scaled(70,60).transformed(QTransform().rotate(270)));
    setPixmap(*enemy_pixmap);
    already_dead=1;
}


void Enemy::move()
{
    // collidingItems() returns a list of all items that collide with this item
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through the list of items with which Enemy collides
    for (size_t i = 0; i < colliding_items.size(); ++i) {
        // If collided with a bullet
        if (typeid(*(colliding_items[i])) == typeid(Bullet) || typeid(*(colliding_items[i])) == typeid(Bomb)) {
            dead_graphics();
            alive = false;
            delete colliding_items[i];
            colliding_items[i] = nullptr;
            return;
        // If collided with Player
        } else if (typeid(*(colliding_items[i])) == typeid(Player)&& already_dead==0) {
            // decrease the health
            game->health->decrease();
            dead_graphics();
            alive = false;

            if (game->health->getHealth()==0){//if health is 0 then the lose screen is created

                game->create_LoseScreen();
            }
            return;
        }
    }


    // If this enemy object is alive, then move it to the left
    if (alive) {
        int vertical = rand();
        // If random number is even, move enemy up
        if (vertical % 2 == 0) {
            setPos(x()-3,y()-1);
        } else { // If random number if odd, move enemy down
            setPos(x()-3,y()+1);
        }
    } else { // If enemy object is dead, send it downwards like a fall
        setPos(x(),y()+7);
    }

    // Only delete enemy if it has moved out of the screen either by dying or passing player
    if (x() < 0 || x() > 1200 || y() < 0 || y() > 800) {
        //qDebug() << "Deleted enemy";
        prepareGeometryChange();
        scene()->removeItem(this); //remove this obstacle from the scene
        delete this;
    }
}


Enemy::~Enemy()
{
    // If enemy_pixmap has not yet been deleted
    if (enemy_pixmap != nullptr) {
        delete enemy_pixmap;
        enemy_pixmap = nullptr;
    }
    delete graphics_timer;
    graphics_timer = nullptr;
}
