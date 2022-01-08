#ifndef BOSSSPRAYATTACKSINGLE_H
#define BOSSSPRAYATTACKSINGLE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "stdlib.h"
#include "Player.h"


class BossSprayAttackSingle : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
     * Constructs a single fireball originating from the position given by the parameters
     * @param center_x: the center of the fireball's intended x-coordinates
     * @param center_y: the center of the fireball's intended y-coordinates
     * @param type: indicates direction of single attack, with 8 options, the number 1 representing up and incrementing going clockwise by 45 degrees
     */
    BossSprayAttackSingle(int center_x, int center_y, Player* target, QTimer* input_move_timer);
    /**
        destructs the fireballs
    */
    ~BossSprayAttackSingle();

public slots:
    /**
        sets the new position of the newly created fireballs
        and deletes them if they are out of the screen
    */
    void move();

private:
    Player* target;
    int x_change;
    double y_change;
};

#endif // BOSSSPRAYATTACKSINGLE_H
