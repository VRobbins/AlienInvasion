#ifndef EARTHGAME_H
#define EARTHGAME_H

#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QMediaPlayer>

class EarthGame : public Game
{
    Q_OBJECT

public:
    /**
        constructs the earthgame and the scenery
        @param MainWindow* the mainwindow the scene will be placed on
        @param QString used to create a game object
    */
    EarthGame(MainWindow* mainwindow, const QString & bg_path);

    /**
        creates the avatar map when the game is over
        and deletes the current widget
    */
    void create_AvatarMap();

    /**
       creates the lose screen when the game is lost
    */
    void create_LoseScreen();

    /**
       destructs the earth gaem by deleting all private variables
    */
    ~EarthGame();

public slots:
    /**
        creates obstacles for the earthlevel
        based on a timer and move across the screen
    */
    void generate_EarthObstacles();

private:
    QMediaPlayer* ice_shatter_sound;
    QMediaPlayer* heart_sound;
    DistanceBar* distance_bar;
    int number_of_obstacles;
    QTimer* obstacle_spawn_timer; // spawn obstacles
    QTimer* transition_timer;

    friend class EarthObstacle;
    friend class Heart;
    friend class DistanceBar;

};

#endif // EARTHGAME_H
