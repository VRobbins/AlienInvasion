#include "Player.h"
#include "Bullet.h"
#include "WaterObstacle.h"
#include "Bomb.h"
#include <QGraphicsScene>
#include "BossSprayAttackSingle.h"
#include "Enemy.h"


Player::Player(QGraphicsScene* player_scene) :
    playerScene(player_scene),
    can_bomb_be_launched(true),
    can_bullet_be_launched(true),
    focus_timer(new QTimer),
    my_health(new Health(playerScene)),
    bomb_bool_active(0),
    invincibility_bool(0),
    can_go_invincible(0),
    bombicon(nullptr),
    invincibilityicon(nullptr)
{
    startTimer(1000/60);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    QObject::connect(focus_timer, SIGNAL(timeout()), this, SLOT(continuousFocus()));
    focus_timer->start(25);
}


void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_B && can_bomb_be_launched && bomb_bool_active){ //creates a bomb if the key B has been pressed
                // create a bullet
                QPixmap temp(":/resources/img/bomb.png");
                QPixmap bomb_pixmap (temp.scaled(50,50));

                Bomb* bomb = new Bomb(10,0,true); // 2nd spot is y trajectory
                bomb->setPixmap(bomb_pixmap);
                bomb->setPos(x()+pixmap().width(),y()+pixmap().height()/2);
                scene()->addItem(bomb);
                prepareGeometryChange();
                scene()->removeItem(bombicon);
                can_bomb_be_launched = false;
                QTimer::singleShot(4000,this, SLOT(bomb_bool_set()));
    }
    if(event->key()==Qt::Key_Space && can_bullet_be_launched ){ //creates a bullet if the space bar has been pressed
                // create a bullet
                Bullet* bullet = new Bullet();
                bullet -> setPos(x()+pixmap().width(),y()+pixmap().height()/2);
                scene() -> addItem(bullet);

                can_bullet_be_launched = false;
                QTimer::singleShot(500,this, SLOT(bullet_bool_set()));
            }
    if (event->key()==Qt::Key_V && can_go_invincible)//if the key V has been pressed invincibility is created
    {
        QPixmap temp(":/resources/img/Spaceship_gold.png");
        QPixmap gold = temp.scaled(130,130);
        setPixmap(gold);
        invincibility_bool=1;
        QTimer::singleShot(5000,this,SLOT(end_invincibility()));
        prepareGeometryChange();
        scene()->removeItem(invincibilityicon);
        QTimer::singleShot(15000,this,SLOT(activate_can_go_invincible()));
    }
    else // for other keys simply set key having been pressed to true without functionality
    {
        keys[event->key()] = true;
    }

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    keys[event->key()] = false;

}

void Player::timerEvent(QTimerEvent *)
{
    if (keys[Qt::Key_Left]){ //checks if the left key has been clicked
        if (pos().x() > 0) { // only allows movement within screen boundary
            setPos(x()-10,y());
        }
    } if(keys[Qt::Key_Right]){ //checks if the right key has been clicked
        if (pos().x()  < 1200) { // only allows movement within screen boundary
            setPos(x()+10,y());
        }
    } if(keys[Qt::Key_Up]){ //checks if the up button has been clicked
        if (pos().y() > 0) { // only allows movement within screen boundary
            setPos(x(), y()-10);
        }
    }  if(keys[Qt::Key_Down]){ //checks if the down key has been clicked
        if (pos().y() + pixmap().height()+10< 800) { // only allows movement within screen boundary
            setPos(x(), y()+10);
        }
    }
}


void Player::bomb_bool_set()
{
    can_bomb_be_launched = true;
    playerScene->addItem(bombicon);
}


void Player::bullet_bool_set()
{
    can_bullet_be_launched = true;
}


void Player::continuousFocus()
{
    setFocus();
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through items with which Player collides and implements interaction
    for (size_t i = 0; i < colliding_items.size(); ++i) {
        // if the obstacle collides with the player, remove obstacle from the scene
        // also play the ice shatter sound effect
        if (typeid(*(colliding_items[i])) == typeid(BossSprayAttackSingle) && invincibility_bool==0) {
            // decrease the health
            prepareGeometryChange();
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            colliding_items[i] = nullptr;
            my_health->decrease();
            return;
        }
    }
}

void Player::set_bomb_bool_active(bool i)
{
    bomb_bool_active=i;
    if(i==1) // if setting active to true, set icon for indication of ready-to-use to user
    {
        QPixmap temp2(":/resources/img/fireball.png");
        bombicon = new QGraphicsPixmapItem(temp2.scaled(95,95));
        bombicon->setPos(105,800-95);
        playerScene->addItem(bombicon);
    }

}

void Player::end_invincibility()
{
    invincibility_bool=0;
    can_go_invincible=0;
    QPixmap temp(":/resources/img/Spaceship_new.png");
    QPixmap player_pixmap = temp.scaled(80,80);
    setPixmap(player_pixmap);
}

void Player::set_can_go_invincible(bool input)
{
    can_go_invincible=input;
    QPixmap temp(":/resources/img/ARM.png");
    invincibilityicon = new QGraphicsPixmapItem(temp.scaled(95,95));
    invincibilityicon->setPos(10,800-95);
    playerScene->addItem(invincibilityicon);
}

Player::~Player()
{
    delete focus_timer;
    focus_timer = nullptr;
    // If invincibility icon is on the screen, delete it
    if(invincibility_bool)
    {
        delete invincibilityicon;
        invincibilityicon = nullptr;
    }
    // If bomb icon is on the screen, delete it
    if(bomb_bool_active)
    {
        delete bombicon;
        bombicon = nullptr;
    }
}

void Player::set_health(Health *input_health)
{
    my_health = input_health;
}

void Player::activate_can_go_invincible()
{
    can_go_invincible=1;
    scene()->addItem(invincibilityicon);
}

