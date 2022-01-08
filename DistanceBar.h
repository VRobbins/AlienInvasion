#ifndef DISTANCEBAR_H
#define DISTANCEBAR_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>


class DistanceBar : public QWidget
{
    Q_OBJECT

public:
    /**
        constucts the distance bar and sets its position,
        color, and pixmaps
        @param QGraphicsScene is the scene being used for the distance bar
        @param int is the level the distance bar is being used for
    */
    DistanceBar(QGraphicsScene* scene, int input_level);

    /**
        destructs the distance bar
    */
    ~DistanceBar();

public slots:
    /**
        updates the bar based on a timer and sets its current
        position based on which level it is being used for
    */
    void update_bar();

private:
    QGraphicsRectItem* bg_rect;
    QGraphicsRectItem* distance_rect;
    QGraphicsPixmapItem* distance_frame;
    QGraphicsPixmapItem* moving_icon;

    int level;
    int current_x;

};






#endif // DISTANCEBAR_H
