#include "BossSprayAttackSingle.h"

#include "math.h"
#include <QDebug>


BossSprayAttackSingle::BossSprayAttackSingle(int center_x, int center_y, Player* player, QTimer* input_move_timer) :
    target(player)
{
    setPos(center_x-25, center_y-25);
    x_change = rand() % 50+50;
    y_change = sqrt(9801 - x_change*x_change);

    if (rand() % 2 == 0) { //changes the x_change if it is even
        x_change = -1 * x_change;
    }
    if (rand() % 2 == 0) { //changes the y_change if even
        y_change = -1 * y_change;
    }
    x_change = x_change / 10;
    y_change = y_change / 10;
    connect(input_move_timer, SIGNAL(timeout()),this,SLOT(move()));
}


void BossSprayAttackSingle::move() {

    setPos(x()+x_change,y()-y_change);

    // If out of the screen, delete
    if (x() < 0 || x() > 1200 || y() < 0 || y() > 800) { //if the  fireballs are out of bounds they are deleted
        prepareGeometryChange();
        scene()->removeItem(this);
        delete this;
    }
}


BossSprayAttackSingle::~BossSprayAttackSingle()
{
    //qDebug()<<"fireball deleted";
}
