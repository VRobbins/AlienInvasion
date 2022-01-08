#ifndef GAME_H
#define GAME_H

#include "MainWindow.h"
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Obstacle.h"
#include "DistanceBar.h"
#include "LoseScreen.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>

class Game : public QObject
{
    Q_OBJECT

public:
    /**
        constructs the game and the way the game will be played
        @param MainWindow* the window the game will be displayed on
        @param QString& the background for the game
    */
    Game(MainWindow* mainwindow, const QString & bg_path);
    /**
        pure virtual function meant for every game to contain an create_AvatarMap()
    */
    virtual void create_AvatarMap() = 0;
    /**
        gets the gurrent scene
        @return the current scene
    */
    QGraphicsScene* get_scene() const;
    /**
        gets the games view
        @return the games view
    */
    QGraphicsView* get_view() const;
    /**
        gets the mainwindow
        @returns the main window of the game
    */
    MainWindow* get_mainwindow() const;
    /**
        pure virtual function to make sure all deruved classes contain this function
    */
    virtual void create_LoseScreen() = 0;
    /**
        destructs the game
    */
    virtual ~Game();

public slots:
    /**
        creates a heart when a given time goes off used to regain health
    */
    void generate_heart();
    /**
        generates an enemy based on a timer and can damage the player
    */
    void generate_enemy();

private:
    QPixmap player_pixmap;
    MainWindow* mw;
    QGraphicsScene* scene;
    QGraphicsView* view;

    Player* player;
    Health* health;

    QTimer* heart_spawn_timer;
    QTimer* move_timer; // controls the amount of time between each object's movement
    QTimer* enemy_spawn_timer;
    QTimer* enemy_move_timer; // different from move_timer since enemy moves at different speed

    friend class Bullet;
    friend class Health;
    friend class Heart;
    friend class WaterGame;
    friend class WaterObstacle;
    friend class WaterEnemy;
    friend class EarthGame;
    friend class EarthObstacle;
    friend class Enemy;

};


#endif // GAME_H
