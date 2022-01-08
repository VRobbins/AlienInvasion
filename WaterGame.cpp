#include "WaterGame.h"
#include "AvatarMap.h"
#include "WaterObstacle.h"
#include "Enemy.h"


extern WaterGame* water_game;

WaterGame::WaterGame(MainWindow* mainwindow, const QString & bg_path) :
    Game(mainwindow,bg_path),
    ice_shatter_sound(new QMediaPlayer),
    distance_bar(new DistanceBar(scene,1)),
    obstacle_spawn_timer(new QTimer),
    transition_timer(new QTimer)
{
    mw->stop_music();
    mw->set_music(QUrl("qrc:/resources/sound/Water.mp3"));
    mw->start_music();
    QObject::connect(obstacle_spawn_timer,SIGNAL(timeout()),this,SLOT(generate_WaterObstacles()));
    obstacle_spawn_timer->start(800);

    // Add sound effects
    ice_shatter_sound->setMedia(QUrl("qrc:/resources/sound/iceshatter.mp3"));
}


void WaterGame::generate_WaterObstacles()
{
    // create an obstacle
    ++number_of_obstacles;
    if(number_of_obstacles==500) //after 100 obstacles have been created the game exits
    {
        create_AvatarMap();
        return;
    }
    WaterObstacle* water_obstacle = new WaterObstacle(move_timer);
    scene->addItem(water_obstacle);
}


void WaterGame::create_AvatarMap()
{
    AvatarMap* avatar_map = new AvatarMap(mw,1);
    mw->setCentralWidget(avatar_map);
    delete this;
    water_game = nullptr;
}

void WaterGame::create_LoseScreen()
{
    LoseScreen* lose_page = new LoseScreen(mw);
    mw->setCentralWidget(lose_page);
    delete this;
    water_game = nullptr;

}

WaterGame::~WaterGame()
{
    delete ice_shatter_sound;
    ice_shatter_sound = nullptr;
    delete distance_bar;
    distance_bar = nullptr;
    delete obstacle_spawn_timer;
    obstacle_spawn_timer = nullptr;
    delete move_timer;
    move_timer = nullptr;
    delete enemy_move_timer;
    enemy_move_timer = nullptr;
    delete transition_timer;
    transition_timer = nullptr;
}
