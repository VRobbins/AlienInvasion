#include "Bullet.h"
#include "Obstacle.h"
#include "WaterObstacle.h"
#include "Game.h"
#include "WaterGame.h"
#include "BossLevel.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

extern WaterGame* water_game;
extern BossLevel* boss_game;

Bullet::Bullet(bool boss_bullet):
    bullet_pixmap(nullptr),
    timer(nullptr)
{
    //drew the rect
    QPixmap temp(":/resources/img/missile.png");
    bullet_pixmap = new QPixmap(temp.scaled(80,30));
    setPixmap(*bullet_pixmap);
    if (!boss_bullet) connect_movement(); //if this is not a boss bullet connect a movement
}


void Bullet::connect_movement()
{
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer -> start(15);
}


void Bullet::move()
{
    setPos(x()+10, y()); // move bullet to right
    if (pos().x() >1200) { //if the bullet goes out of bounds the bullet is removed
        scene() -> removeItem(this);
        delete this;
    }
    else
    {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through the list of items with which this bullet object collides
    for (int i = 0; i < colliding_items.size(); ++i){
        // if bullet collides with boss, destroy bullet and only destroy boss if health is 0
        if (typeid(*(colliding_items[i])) == typeid(Boss)){
            boss_game->boss->decrease_health(5);
            prepareGeometryChange();
            scene()->removeItem(this); //remove this bullet from the scene;

            if (boss_game->boss->get_health() <= 0) { // If boss health is 0, destroy boss
                boss_game->create_WinScreen();
            }
            delete this;
            return;
        }
    }
    }
}

Bullet::~Bullet()
{
    //qDebug() << "Bullet deleted";
    delete timer;
    timer = nullptr;

    delete bullet_pixmap;
    bullet_pixmap = nullptr;
}
