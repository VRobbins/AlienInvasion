#ifndef WATEROBSTACLE_H
#define WATEROBSTACLE_H

#include "Obstacle.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QTimer>

class WaterObstacle : public Obstacle
{
    Q_OBJECT

public:
    /**
        constructs a water obstacle
        @param QTimer* the timer that will be used for the obstacles
    */
    WaterObstacle(QTimer* input_timer);

    /**
       destructs the water obstacle
    */
    ~WaterObstacle();

public slots:
    /**
        allows the water obstacle to move to the left
    */
    void move();

private:
    QPixmap* obstacle_pixmap;



};


#endif // WATEROBSTACLE_H
