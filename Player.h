#ifndef PLAYER_H
#define PLAYER_H

#include "Health.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QMap>
#include <QTimer>
#include <QGraphicsScene>

class Player: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:
    /**
        constructs the player and initializes all member fields
        @param QGraphicsScene* the scene the player will be in
    */
    Player(QGraphicsScene* player_scene);

    /**
        allows the key B and Space to release a water bomb or bullet
        @param QKeyEvent* the key that was pressed
    */
    void keyPressEvent(QKeyEvent* event) override;

    /**
        when key is released it is set to false
        QKeyEvent* the key pressed
        @param QKeyEvent* the key that was released
    */
    void keyReleaseEvent(QKeyEvent *e) override;

    /**
        registers if the left, right, up, or down buttons have been clicked
        @param QTimerEvent* unused parameter
    */
    void timerEvent(QTimerEvent *) override;

    /**
        destructs the player
    */
    virtual ~Player();

    /**
        sets the health of the player
        @param Health* the health to be set
    */
    void set_health(Health* input_health);

    /**
        sets whether the bomb is active
        @param bool true if it is false if it isn't
    */
    void set_bomb_bool_active(bool);

    /**
        allows the player to become invincible
        @param bool true if can and false if cannot
    */
    void set_can_go_invincible(bool);

public slots:
    /**
        allows the bomb to be launched
    */
    void bomb_bool_set();

    /**
        allows the bullet to be used
    */
    void bullet_bool_set();

    /**
        sets the focus for the colliding items to check whether the player
        and an item have collided
    */
    void continuousFocus();

    /**
        ends the players invincibility and switches everythign back
    */
    void end_invincibility();

    /**
        allows the player to become invincible by changing the color
        of the pixmap and ability to be damaged
    */
    void activate_can_go_invincible();

private:
    QGraphicsScene* playerScene;
    QMap<int, bool> keys;
    bool can_bomb_be_launched;
    bool can_bullet_be_launched;
    QTimer* focus_timer;
    Health* my_health;
    bool bomb_bool_active;
    bool invincibility_bool;
    bool can_go_invincible;
    QGraphicsPixmapItem* bombicon;
    QGraphicsPixmapItem* invincibilityicon;
};


#endif // PLAYER_H
