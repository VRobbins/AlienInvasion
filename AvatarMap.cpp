#include "AvatarMap.h"
#include "MainWindow.h"
#include "Game.h"
#include "WaterGame.h"
#include "EarthGame.h"
#include "BossLevel.h"

#include <QPixmap>
#include <QIcon>
#include <QStyleOption>
#include <QPainter>

extern WaterGame* water_game;
extern EarthGame* earth_game;
extern BossLevel* boss_game;

AvatarMap::AvatarMap(MainWindow* mainwindow, int i):
    MyWidget(mainwindow),
    mw(mainwindow),
    water_button_north(new QPushButton),
    water_button_south(new QPushButton),
    earth_button(new QPushButton),
    fire_button(new QPushButton),
    end_button(nullptr)

{
    connect(fire_button,SIGNAL(clicked()),this,SLOT(create_BossGame()));
    mw->stop_music();
    complete_level = i;
    earth_button->setParent(this);
    fire_button->setParent(this);
    water_button_north->setParent(this);
    water_button_south->setParent(this);

    //sets position of the button on the screen
    water_button_north->setGeometry(483,48,250,110);
    water_button_south->setGeometry(437,612,300,170);
    fire_button->setGeometry(100,275,405,200);
    earth_button->setGeometry(380,100,720,550);

    //sets nackground color and hover effect to buttons
    water_button_north->setStyleSheet( "QPushButton{background-color: transparent}"
                                       "QPushButton:hover{background-color: rgba(100, 100, 255, 30)}");
    water_button_south->setStyleSheet( "QPushButton{background-color: transparent}"
                                       "QPushButton:hover{background-color: rgba(100, 100, 255, 30)}");
    fire_button->setStyleSheet( "QPushButton{background-color: transparent}"
                                "QPushButton:hover{background-color: rgba(255, 0, 0, 20)}");
    earth_button->setStyleSheet( "QPushButton{background-color: transparent}"
                                 "QPushButton:hover{background-color: rgba(0, 255, 0, 20)}");

    //sets buttons for each nation

    QPixmap water_north_temp(":/resources/img/bluePlanet.png");
    QPixmap water_north_pixmap = water_north_temp.scaled(380,300);
    QIcon eater_north_icon(water_north_pixmap);

    QPixmap water_south_temp(":/resources/img/bluePlanet.png");
    QPixmap water_south_pixmap = water_south_temp.scaled(380,300);
    QIcon eater_south_icon(water_south_pixmap);

    QPixmap earth_temp(":/resources/img/greenPlanet.png");
    QPixmap earth_pixmap = earth_temp.scaled(400,260);
    QIcon earth_icon(earth_pixmap);

    QPixmap fire_temp(":/resources/img/redPlanet.png");
    QPixmap fire_pixmap = fire_temp.scaled(230,230);
    QIcon fire_icon(fire_pixmap);
    earth_button->setIcon(earth_pixmap);
    earth_button->setIconSize(earth_button->size());
    fire_button->setIcon(fire_pixmap);
    fire_button->setIconSize(earth_button->size());
    water_complete = new QPushButton;
    if (complete_level>=1){//if the water level is complete set the water level beaten badge
        connect(earth_button,SIGNAL(clicked()),this,SLOT(create_EarthGame()));
    }
    earth_complete = new QPushButton;
    if (complete_level>=2){ //if more than two levels are complete set earth game complete badge
        connect(fire_button,SIGNAL(clicked()),this,SLOT(create_BossGame()));
    }
    //set pixmaps for each nation
    water_button_north->setIcon(water_north_pixmap);
    water_button_north->setIconSize(water_button_north->size());

    water_button_south->setIcon(water_south_pixmap);
    water_button_south->setIconSize(water_button_south->size());
    //connect button clicked() to the correct slot for each nation
    connect(water_button_north,SIGNAL(clicked()),this,SLOT(create_WaterGame()));
    connect(water_button_south,SIGNAL(clicked()),this,SLOT(create_WaterGame()));
}


void AvatarMap::paintEvent(QPaintEvent *event)
{
    QPixmap bg(":/resources/img/Background3.jpg"); // set background (fit for resizing)
    bg = bg.scaled(mw->size(), Qt::IgnoreAspectRatio);
    QPalette bg_palette;
    bg_palette.setBrush(QPalette::Background, bg);
    mw->setPalette(bg_palette);
}

void AvatarMap::create_WaterGame()
{
    mw->hide(); // hide then show fixes problem of focus
    water_game = new WaterGame(mw,":/resources/img/bluecave.jpg"); // create water game
    QGraphicsView* view = water_game->get_view(); // get view from game
    mw->setCentralWidget(view); // give view to main window
    mw->show();
    delete this;
}

void AvatarMap::create_EarthGame()
{
    mw->hide(); // hide then show fixes problem of focus
    earth_game = new EarthGame(mw,":/resources/img/ForestNew.jpg"); // create water game
    QGraphicsView* view = earth_game->get_view(); // get view from game
    mw->setCentralWidget(view); // give view to main window
    mw->show();
    delete this;
}


void AvatarMap::create_BossGame()
{
    mw->hide();
    boss_game = new BossLevel(mw);//create boss level
    QGraphicsView* view = boss_game->get_view();
    mw->setCentralWidget(view);
    mw->show();
    delete this;//delete avatar map after the boss level has been created
}
// No destructor needed here. No memory leaks
