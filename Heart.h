#ifndef HEART_H
#define HEART_H

#include "MainWindow.h"
#include "Obstacle.h"
#include "Game.h"

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>


class Heart : public Obstacle
{

public:
    /**
        constructs hearts that fall from the sky that can improve health
        @param QTimer* the timer used to move the hearts
        @param Game* the game the hearts will be placed in
    */
    Heart(QTimer* input_move_timer, Game* input_game);

public slots:
    /**
        checks if the bullet has collided with a heart and
        if so increases the players health
    */
    void move();

private:
    QPixmap icon_pixmap;
    Game* game;
    QMediaPlayer* sound;



};

#endif // HEART_H
