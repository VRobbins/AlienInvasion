#include "Boss.h"
#include <QDebug>

Boss::Boss(Player* player, BossHealth* boss_health) :
    health(100),
    health_bar(boss_health),
    sprayAttack_timer(new QTimer()), move_timer(new QTimer),
    opponent(player)
{
    // Setting boss image
    QPixmap temp(":/resources/img/fireboss.png");
    setPixmap(temp.scaled(650,800));
    // Setting periodic spray attacks from boss
    QObject::connect(sprayAttack_timer,SIGNAL(timeout()),this,SLOT(sprayAttack()));
    sprayAttack_timer -> start(1500);
    move_timer->start(12);
    QPixmap temp2(":/resources/img/fireball.png");
    weapon = new QPixmap(temp2.scaled(100,100));
}


short int Boss::get_health() const
{
    return health;
}

unsigned short int Boss::decrease_health(unsigned short int amount)
{
    health = health - amount;
    health_bar->update(health);
    //qDebug() << "Boss now has " << health << " health";
    return health;
}


void Boss::sprayAttack()
{
    sprayAttack_timer->stop();
    for (size_t i = 0; i < 50; i++) { // creates the 30 fireballs that release in a circle
        BossSprayAttackSingle* bullet = new BossSprayAttackSingle(x()+325,y()+400,opponent,move_timer);
        scene()->addItem(bullet);
        bullet->setPixmap(*weapon);
    }
    // Sets the timer to time out at somewhere between 500 and 1500 ms
    int random_number = (rand() % 1000) + 700;
    sprayAttack_timer->start(random_number);
}

Boss::~Boss()
{
    //qDebug()<<"BOSS DELETED";
    delete health_bar;
    delete sprayAttack_timer;
    delete move_timer;
    delete opponent;
    delete weapon;
}
