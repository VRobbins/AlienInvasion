#include "Health.h"
#include "WaterGame.h"
#include "BossLevel.h"
#include <QDebug>

extern WaterGame* water_game;
extern BossLevel* boss_game;

Health::Health(QGraphicsScene* input_scene) : scene(input_scene),//, heartWidget(new QWidget)
  spaceBetweenHearts(50),
  numberOfHearts(5),
  heart1(nullptr),
  heart2(nullptr),
  heart3(nullptr),
  heart4(nullptr),
  heart5(nullptr)
{
    //initialize pink heart
    QPixmap temp_pink(":/resources/img/heart.png");
    pinkHeart=temp_pink.scaled(40,40);
    //initialize grey heart
    QPixmap temp_grey(":/resources/img/greyHeart.png");
    greyHeart=temp_grey.scaled(40,40);
    //assign all hearts as pinkheart
    heart1 = new QGraphicsPixmapItem(pinkHeart);
    heart2 = new QGraphicsPixmapItem(pinkHeart);
    heart3 = new QGraphicsPixmapItem(pinkHeart);
    heart4 = new QGraphicsPixmapItem(pinkHeart);
    heart5 = new QGraphicsPixmapItem(pinkHeart);

    heart1->setPos(780,50);
    heart2->setPos(860,50);
    heart3->setPos(940,50);
    heart4->setPos(1020,50);
    heart5->setPos(1100,50);

    //add all hearts to scene
    scene->addItem(heart1);
    scene->addItem(heart2);
    scene->addItem(heart3);
    scene->addItem(heart4);
    scene->addItem(heart5);
    // Pushes back each heart into hearts_display vector with true (active) status
    for(int i=0; i<numberOfHearts; ++i){
        hearts_display.push_back(true);
    }

}

void Health::decrease()
{
       --numberOfHearts;
        if(hearts_display[4]==true)//if the fifth heart is red change to grey
        {
            heart5->setPixmap(greyHeart);
            hearts_display[4]=false;
        }
        else if(hearts_display[3]==true)//if the fourth heart is red change to grey
        {
            heart4->setPixmap(greyHeart);
            hearts_display[3]=false;
        }
        else if(hearts_display[2]==true)//if the third heart is red change to grey
        {
            heart3->setPixmap(greyHeart);
            hearts_display[2]=false;
        }
        else if(hearts_display[1]==true)//if the second heart is red change to grey
        {
            heart2->setPixmap(greyHeart);
            hearts_display[1]=false;
        }
        else if(hearts_display[0]==true)//if the first heart is red change to grey
        {
            heart1->setPixmap(greyHeart);
            hearts_display[0]=false;
        }
    if( getHealth()<=0 && boss_game!=nullptr ) //if the players life goes to zero the lose screen is created
    {
        boss_game->create_Losescreen();
    }
}


void Health::increase()
{
    // Number of hearts can only be increased if current number is less than the max, 5
    if(numberOfHearts<5){
      ++numberOfHearts;
           if(hearts_display[0]==false) //if the first heart is grey set the heart to pink
            {
                heart1->setPixmap(pinkHeart);
                hearts_display[0]=true;
            }
            else if(hearts_display[1]==false)//if the second heart is grey set the heart to pink
            {
                heart2->setPixmap(pinkHeart);
                 hearts_display[1]=true;
            }
            else if(hearts_display[2]==false)//if the third heart is grey set the heart to pink
            {
                heart3->setPixmap(pinkHeart);
                 hearts_display[2]=true;
            }
            else if(hearts_display[3]==false)//if the fourth heart is grey set the heart to pink
            {
                heart4->setPixmap(pinkHeart);
                 hearts_display[3]=true;
            }
            else if(hearts_display[4]==false)//if the fifth heart is grey set the heart to pink
            {
                heart5->setPixmap(pinkHeart);
                 hearts_display[4]=true;
            }
    }
}


int Health::getHealth() const
{
   // return health;
    return numberOfHearts;
}

// No destructor needed, since all hearts are QGraphicsPixmapItems part of scene. Will auto-delete when scene is deleted.
