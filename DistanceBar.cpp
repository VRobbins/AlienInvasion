#include "DistanceBar.h"
#include "WaterGame.h"
#include "EarthGame.h"
#include <QPainter>

extern WaterGame* water_game;
extern EarthGame* earth_game;

DistanceBar::DistanceBar(QGraphicsScene* scene, int input_level):
    bg_rect(new QGraphicsRectItem(5,55,525,30)),
    distance_frame(new QGraphicsPixmapItem),
    moving_icon(new QGraphicsPixmapItem),
    level(input_level)
{
    bg_rect->setBrush(QColor(247,219,219));
    scene->addItem(bg_rect);

    if (level==1) {current_x = 0;} //sets the position of the bar based on the level it is on
    else if (level==2) {current_x = 264;} //setas the width of the bar if it is on the earth game

    distance_rect = new QGraphicsRectItem(5,55,current_x,30);
    distance_rect->setBrush(QColor(255,192,81));
    scene->addItem(distance_rect);

    //sets the pix maps for the distance bar
    scene->addItem(distance_frame);
    distance_frame->setPos(0,0);

    QPixmap icon_temp(":/resources/img/Alien_figure.png");
    moving_icon->setPixmap(icon_temp.scaled(100,100));
    scene->addItem(moving_icon);
    moving_icon->setPos(0,0);

    //updates the timer that times out of the levels
    QTimer* update_timer = new QTimer;
    QObject::connect(update_timer,SIGNAL(timeout()),this,SLOT(update_bar()));
    update_timer->start(400);
}


void DistanceBar::update_bar()
{
    current_x = current_x + 2;
    if (level == 1) { //sets the width before the water level

        if (current_x<264){ //sets the width to begin at 5
            distance_rect->setRect(5,55,current_x,30);
        }

        else if (current_x==264){ //ends the game when the width is equal to 255
            water_game->create_AvatarMap();
        }
    }

    if (level == 2){ //if the bar is in the earth level the width is set past the earth nation icon
        // If progress of the bar is still within 524, update rect accordingly
        if (current_x<524){
            distance_rect->setRect(5,55,current_x,30);
        }
        else if (current_x==524){ //once the width reaches 525 the avatar map is created
            earth_game->create_AvatarMap();
        }
    }
}


DistanceBar::~DistanceBar()
{
    delete bg_rect;
    bg_rect = nullptr;

    delete distance_rect;
    distance_rect = nullptr;

    delete distance_frame;
    distance_frame = nullptr;
}



