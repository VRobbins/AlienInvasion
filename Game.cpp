#include "Game.h"
#include "Player.h"
#include "Heart.h"
#include "Enemy.h"

#include <QDebug>


Game::Game(MainWindow *mainwindow, const QString & bg_path) :
    mw(mainwindow),
    scene(new QGraphicsScene),
    view(new QGraphicsView(scene)),
    player(new Player(scene)),
    health(new Health(scene)),
    heart_spawn_timer(new QTimer),
    move_timer(new QTimer),
    enemy_spawn_timer(new QTimer),
    enemy_move_timer(new QTimer)
{
   //qDebug()<<"Game constructor begining";
    mw->set_background(bg_path);

    scene -> setSceneRect(0,0,1200,800);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setFixedSize(1200,800);
    view -> setStyleSheet("background-color: transparent"); //MAKES MAIN WINDOW BACKGROUND VISIBLE. DEFAULT BACKGROUND IS WHITE.

    //qDebug()<<"Game constructor before health";
    // add the health to the scene
   health -> setPos(100,25);
   scene -> addItem(health);

    // qDebug()<<"Game constructor before creating player";
    // add graphics to the player
    QPixmap temp(":/resources/img/Spaceship_new.png");
    player_pixmap = temp.scaled(80,80);
    player->setPixmap(player_pixmap);
    // set the position of the player
    // player -> setPos(view->width()/2, view->height() - player_pixmap.rect().height());
    player->setPos(100, view->height()/2 - player_pixmap.rect().height()/2);
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);


    heart_spawn_timer->start(10000);
    QObject::connect(heart_spawn_timer,SIGNAL(timeout()),this,SLOT(generate_heart()));

    enemy_spawn_timer->start(1000);
    QObject::connect(enemy_spawn_timer,SIGNAL(timeout()),this,SLOT(generate_enemy()));

    move_timer->start(8);
    enemy_move_timer->start(10);

}


QGraphicsScene* Game::get_scene() const
{
    return scene;
}


QGraphicsView* Game::get_view() const
{
    return view;
}


MainWindow* Game::get_mainwindow() const
{
    return mw;
}


void Game::generate_heart()
{
    // create a heart
    Heart* heart = new Heart(move_timer,this);
    scene->addItem(heart);
}


void Game::generate_enemy()
{
    Enemy* enemy = new Enemy(enemy_move_timer,this);
    scene->addItem(enemy);
}


Game::~Game()
{
    // Deleting things after deleting scene does not work because scene already takes care of all its contained items
    delete scene;
    scene = nullptr;
    delete view;
    view = nullptr;
    // Deleting scene takes care of all objects in scene, including player, score, health
}
