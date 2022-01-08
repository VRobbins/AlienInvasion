#include "Bomb.h"
#include "Game.h"
#include "BossSprayAttackSingle.h"
#include "Boss.h"
#include "BossLevel.h"
#include "Enemy.h"
#include <QDebug>
#include <vector>

extern Game* game;
extern BossLevel* boss_game;

Bomb::Bomb(int input_x_trajectory, int input_y_trajectory, bool input_explode ):
    timer(nullptr),
    explosion_timer(nullptr),
    x_trajectory(input_x_trajectory),
    y_trajectory(input_y_trajectory),
    explode_bool(input_explode),
    i(1),
    explode_time(0)
{

    if (explode_bool==true) //if it is exploded a new timer is created and is set to move
    {
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer -> start(15);
    }
}


void Bomb::move()
{
    setPos(x()+1.5*x_trajectory, y()-1.5*y_trajectory);
    y_trajectory = y_trajectory; // - 0.5 for acceleration
    explode_time++;
   if (x() >1200 || y() >800) //if the position on the screen is past these positions delete the bomb
    {
        delete this;
    }
    else if(explode_time>=15 && explode_bool==true) //if the position on the screen is past these positions delete the bomb an splatter
    {
        delete timer;
        timer=nullptr;
        explode();
    }
    else {
       QList<QGraphicsItem*> colliding_items = collidingItems();
       // Loops through the list of items with which bomb collides
       for (size_t i = 0; i < colliding_items.size(); ++i) {
           // if the obstacle collides with the player, remove obstacle from the scene
           // also play the ice shatter sound effect
           if (typeid(*(colliding_items[i])) == typeid(BossSprayAttackSingle)) {
               // decrease the health
               prepareGeometryChange();
               scene() -> removeItem(colliding_items[i]); //remove this obstacle from the scene
               delete colliding_items[i];
               colliding_items[i] = nullptr;
               return;
           }
               // if bullet collides with boss, destroy bullet and only destroy boss if health is 0
               if (typeid(*(colliding_items[i])) == typeid(Boss)&& explode_bool==0){
                   boss_game->boss->decrease_health(1);
                   prepareGeometryChange();
                   scene()->removeItem(this); //remove this bullet from the scene;
                   if (boss_game->boss->get_health() <= 0) {// If boss health is 0, destroy boss
                       boss_game->create_WinScreen();
                   }
                   delete this;
                   return;
                }
       }
   }
}


void Bomb::explode()
{
    //setPos(x() + 37, y()+37);
    int x1=x();
    int y1=y();
    ctr_x = x1+pixmap().width()/2;
    ctr_y = y1+pixmap().height()/2;
    explosion_timer = new QTimer;
    connect(explosion_timer, SIGNAL(timeout()) , this, SLOT(splat()));
    explosion_timer->start(10);
    //set pixmap of droplets
    QPixmap temp2(":/resources/img/Shell.png");
    QPixmap droplet =  QPixmap(temp2.scaled(25,25));
    QPixmap droplet_flipped =  QPixmap(droplet.transformed(QTransform().scale(-1,1)));
    std::vector<Bomb*> b;
    b.push_back( new Bomb(-5,5,false)); //no need to delete, spawn bombs with bomb attack
    b.push_back(new Bomb(0,5,false));
    b.push_back(new Bomb(5,5,false));
    b.push_back( new Bomb(5,-5,false));
    b.push_back(new Bomb(0,-5,false));
    b.push_back( new Bomb(-5,-5,false));
    b.push_back( new Bomb(5,0,false));
    b.push_back( new Bomb(-5,0,false));
    b.push_back( new Bomb(5,3,false));
    b.push_back( new Bomb(-5,3,false));
    b.push_back( new Bomb(5,3,false));
    b.push_back( new Bomb(-5,3,false));
    //qDebug()<<"size of vector is"<<b.size();
    for(size_t i=0; i<b.size();i++)//iterate through vector and flip pixmap based on position
    {
        b[i]->setPos(x1,y1);
        b[i]->setPixmap(droplet);
        scene() -> addItem(b[i]);
    }

    QTimer* testtimer = new QTimer();
    testtimer->start(15);
    //connect timers to move()
    for(size_t i=0; i<b.size();i++){
        connect(testtimer, SIGNAL(timeout()),b[i], SLOT(move()));
    }
    QTimer::singleShot(500, this, SLOT(destruct()));
}


void Bomb::destruct()
{
    delete this;
}


void Bomb::splat()
{
    if(i<220) //creates splat image when i is less than 220
    {
        QPixmap temp(":/resources/img/fireball.png");//MOVE AS PRIVATE FIELD
        QPixmap bomb_pixmap = QPixmap(temp.scaled(2*i ,2*i));
        setPixmap(bomb_pixmap);
        setPos(ctr_x - pixmap().width()/2 ,ctr_y -pixmap().height()/2 );
        ++i;
    }

}

Bomb::~Bomb()
{
    //qDebug()<<"Bomb Deleted";
    if(explode_bool==true){ //if the bomb exploded remove it from scene and delete timer
        scene() -> removeItem(this);
        delete timer;
        timer = nullptr;
        delete explosion_timer;
        explosion_timer = nullptr;
    }

}
