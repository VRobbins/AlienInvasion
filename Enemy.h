#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Game.h"


class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
        constructs the enemy
        @param Qtimer* the timer used for the grphics
        @param Game* the game the enemy will be placed in
    */
    Enemy(QTimer* input_timer, Game* input_game);

    /**
        destructs the enemy
    */
    ~Enemy();

public slots:
    /**
        updates the graphics of the enemy
    */
    void update_graphics();

    /**
        updates the image of the enemy once it has been killed
    */
    void dead_graphics();

    /**
        moves the enemy to the left and check for collision of the other
        objects or bullets
    */
    void move();

private:
    QTimer* graphics_timer;
    size_t graphics_number;
    QPixmap* enemy_pixmap;
    bool alive;
    Game* game;
    bool already_dead;
};

#endif // ENEMY_H
