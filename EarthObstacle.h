#ifndef EARTHOBSTACLE_H
#define EARTHOBSTACLE_H


#include "Obstacle.h"

class EarthObstacle : public Obstacle
{
    Q_OBJECT

public:
    /**
        contructs the earth obstacles
        @param QTimer* takes in the timer used to time the obstacles
    */
    EarthObstacle(QTimer* input_timer);

    /**
        destructs the obstacles
    */
    ~EarthObstacle();

public slots:
    /**
        moves the obstacles to the left and checks collision
        and destructs accordingly
    */
    void move();

private:
    QPixmap* obstacle_pixmap;
};

#endif // EARTHOBSTACLE_H
