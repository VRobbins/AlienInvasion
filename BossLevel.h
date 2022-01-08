#ifndef BOSSLEVEL_H
#define BOSSLEVEL_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "MainWindow.h"
#include "Boss.h"
#include "BossHealth.h"
#include "WinScreen.h"
#include <QTimer>


class BossLevel: public QGraphicsScene, public QWidget
{
public:
    /**
        constructor for class
        @param MainWindow the window the level will be displayed on
    */
    BossLevel(MainWindow* w);

    /**
        creates the player for the level and sets its position and
        size then adds it to the scene
    */
    void create_player();

    /**
        creates the boss and its characteristics
    */
    void create_boss();

    /**
        creates the bosses health
    */
    void create_boss_health();

    /**
        returns the view of the game
        @return QGraphicsView*, pointer to the view of the game
    */
    QGraphicsView* get_view() const;

    /**
        creates the avatar map
    */
    void create_AvatarMap();

    /**
        creates the win screen
    */
    void create_WinScreen();

    /**
        creates the lose screen
    */
    void create_Losescreen();

    /**
        returns the current player
        @return Player*, pointer to the player object
    */
    Player* get_player() const;

    /**
        destructs the boss level
    */
    ~BossLevel();

private:
    MainWindow* mw;
    QGraphicsScene* scene;
    QGraphicsView* view;
    Player* player;
    QPixmap player_pixmap;
    Boss* boss;
    BossHealth* boss_health;
    QPixmap boss_pixmap;
    friend class BossLevelBullet;
    friend class Bullet;
    friend class Bomb;

};


#endif // BOSSLEVEL_H
