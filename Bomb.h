#ifndef BOMB_H
#define BOMB_H
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bomb : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

private:
    QTimer* timer;
    QTimer* explosion_timer;
    double x_trajectory;
    double y_trajectory;
    bool explode_bool;
    int i;
    int explode_time;
    int ctr_x;
    int ctr_y;

public:
    /**
        constructor for the bomb class
        @param int the x trajectory
        @param int the y trajectory
        @param bool if the item has exploded
    */
    Bomb(int, int, bool);

    /**
        destructor for the bomb class and deletes the timers
    */
    virtual ~Bomb();

public slots:
    /**
        allows the bomb to move as a projectile (upside down parabola)
    */
    void move();

    /**
        changes the pixmap of the bomb once it collides with another object
        releasing droplets that move down the screen
    */
    void explode();

    /**
        deletes the current widget
    */
    void destruct();

    /**
        creates the splatter image when the bomb explodes
    */
    void splat();
};

#endif // BOMB_H
