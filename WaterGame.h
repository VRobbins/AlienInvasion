#ifndef WATERGAME_H
#define WATERGAME_H

#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QDebug>

class WaterGame : public Game
{
    Q_OBJECT

public:
    /**
        constructs the water game
        @param MainWindow* the main window the game will be displayed on
        @param QString the background of the water game
    */
    WaterGame(MainWindow* mainwindow, const QString & bg_path);

    /**
        creates the avatar map at the end of the game
    */
    void create_AvatarMap();

    /**
        creates the lose screen when the game has been lost
    */
    void create_LoseScreen();

    /**
        destructs the water game
    */
    ~WaterGame();

public slots:
    /**
        generates the water obstacles
    */
    void generate_WaterObstacles();

private:
    QMediaPlayer* ice_shatter_sound;
    DistanceBar* distance_bar;
    int number_of_obstacles;
    QTimer* obstacle_spawn_timer; // spawn obstacles
    QTimer* transition_timer;
    friend class WaterObstacle;
    friend class DistanceBar;
};

#endif // WATERGAME_H
