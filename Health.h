#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QSlider>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <vector>
#include <QGraphicsScene>
#include <QDebug>

class Health : public QGraphicsTextItem
{

public:
    /**
        constructs the health used for the player
        @param QGraphicsScene the scene the hearts will be placed in
    */
    Health(QGraphicsScene* input_scene);

    /**
        decreases the health of the player
    */
    void decrease();

    /**
        increases the health of the player
    */
    void increase();

    /**
        gets the health of the player
        @return the health of the current player
    */
    int getHealth() const;

private:

    QGraphicsScene* scene;
    int spaceBetweenHearts;
    int numberOfHearts;

    QGraphicsPixmapItem* heart1;
    QGraphicsPixmapItem* heart2;
    QGraphicsPixmapItem* heart3;
    QGraphicsPixmapItem* heart4;
    QGraphicsPixmapItem* heart5;

    QPixmap pinkHeart;
    QPixmap greyHeart;

    std::vector<bool> hearts_display;



};

#endif // HEALTH_H
