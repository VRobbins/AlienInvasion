#ifndef BULLET_H
#define BULLET_H

#include "Game.h"
#include "Score.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>


class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
        constructs the air bullet and sets the first bullet
        and sets a timer for the amount of times the bullet
        can be used within a cetain amount of time
        @param whether the current bullet involved is for attacking the boss
    */
    Bullet(bool boss_bullet = false);

    /**
        sets a timer to be used for the bullet and connects
        it to the move function that sets the distance of the bullet
    */
    void connect_movement();

    /**
        destructs the bullet and timer
    */
    virtual ~Bullet();

public slots:
    /**
        moves the bullet to the right and checks if the bullet is out
        of bounds and destructs if so. It also checks if it has collided
        with the bossand if so decreases its health
    */
    void move();

protected:
    QPixmap* bullet_pixmap;
    QTimer* timer;
};


#endif // BULLET_H
