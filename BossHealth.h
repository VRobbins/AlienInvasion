#ifndef BOSSHEALTH_H
#define BOSSHEALTH_H

#include <QWidget>
#include <QGraphicsRectItem>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class BossHealth : public QWidget
{
    Q_OBJECT

public:
    /**
      BossHealth constructor that sets position of his health
      @param QGraphicsScene is the scene his health will be placed on
    */
    BossHealth(QGraphicsScene* scene);

    /**
        changes his health bar based on how many hits recieved
        @param int his current health
    */
    void update(int health);

    /**
       class destructor that deletes his health and frame
    */
    ~BossHealth();

private:
    QGraphicsRectItem* health_rect;
    QGraphicsPixmapItem* health_frame;
};

#endif // BOSSHEALTH_H
