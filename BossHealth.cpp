#include "BossHealth.h"


BossHealth::BossHealth(QGraphicsScene* scene) :
    health_rect(new QGraphicsRectItem(555,700,320,55)),
    health_frame(new QGraphicsPixmapItem())
{
    // Health bar rectangle
    scene->addItem(health_rect);
    health_rect->setBrush(Qt::yellow);

    // Health bar frame used as image
    scene->addItem(health_frame);
    QPixmap temp(":/resources/img/boss_health_frame_edited.png");
    health_frame->setPixmap(temp.scaled(412,100));
    health_frame->setPos(465,680);
}


void BossHealth::update(int health)
{
    health_rect->setRect(555,700,320*health/100,55);
}

BossHealth::~BossHealth()
{
    delete health_rect;
    health_rect = nullptr;

    delete health_frame;
    health_frame = nullptr;
}
