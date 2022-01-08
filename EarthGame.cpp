#include "EarthGame.h"
#include "AvatarMap.h"
#include "EarthObstacle.h"
#include "Heart.h"
#include "Enemy.h"


extern EarthGame* earth_game;

EarthGame::EarthGame(MainWindow* mainwindow, const QString & bg_path) :
    Game(mainwindow,bg_path),
    ice_shatter_sound(new QMediaPlayer),
    heart_sound(new QMediaPlayer),
    obstacle_spawn_timer(new QTimer),
    transition_timer(new QTimer)
{
    mw->stop_music();
    mw->set_music(QUrl("qrc:/resources/sound/Earth.mp3"));
    mw->start_music();
    QObject::connect(obstacle_spawn_timer,SIGNAL(timeout()),this,SLOT(generate_EarthObstacles()));
    obstacle_spawn_timer->start(800);
    player->set_bomb_bool_active(1);
    // Add sound effects
    ice_shatter_sound->setMedia(QUrl("qrc:/resources/sound/ice_shatter_sound_effect.mp3"));
    heart_sound->setMedia(QUrl("qrc:/resources/sound/heart_sound.mp3"));
    distance_bar = new DistanceBar(scene,2);

}


void EarthGame::generate_EarthObstacles()
{
    // create an obstacle
    ++number_of_obstacles;
    if(number_of_obstacles==100) //after 100 obstacles have been created the avatar map is created
    {
        create_AvatarMap();
        return;
    }
    EarthObstacle* earth_obstacle = new EarthObstacle(move_timer);
    scene->addItem(earth_obstacle);
}


void EarthGame::create_AvatarMap()
{
    AvatarMap* avatar_map = new AvatarMap(mw,2);
    mw->setCentralWidget(avatar_map);
    delete this;
    earth_game = nullptr;
}

void EarthGame::create_LoseScreen()
{
    LoseScreen* lose_page = new LoseScreen(mw);
    mw->setCentralWidget(lose_page);
    delete this;
    earth_game = nullptr;

}

EarthGame::~EarthGame()
{
    delete heart_sound;
    heart_sound = nullptr;
    delete distance_bar;
    distance_bar = nullptr;
    delete obstacle_spawn_timer;
    obstacle_spawn_timer = nullptr;
    delete heart_spawn_timer;
    heart_spawn_timer = nullptr;
    delete move_timer;
    move_timer = nullptr;
    delete enemy_move_timer;
    enemy_move_timer = nullptr;
    delete transition_timer;
    transition_timer = nullptr;
}
