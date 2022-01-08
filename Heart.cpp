#include "Heart.h"
#include "Bullet.h"
#include "stdlib.h"


Heart::Heart(QTimer* input_move_timer, Game* input_game) : game(input_game), sound(new QMediaPlayer)
{
    // add graphics to the heart icon
    QPixmap temp(":/resources/img/heart.png");
    icon_pixmap = temp.scaled(20,20);
    setPixmap(icon_pixmap);

    // set random position on top of the screen
    int random_number = rand() % 800;
    setPos(400+random_number, -60);
    set_move_timer(input_move_timer);

    sound->setMedia(QUrl("qrc:/resources/sound/heart_sound.mp3"));

}


void Heart::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();
    // Loops through the list of items with which Heart collides
    for (int i = 0; i < colliding_items.size(); ++i){
        // if bullet collides with the heart icon
        // also play the heart sound effect
        if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            // decrease the health
            game->health->increase();
            // set the sound effect
            set_sound_effect(sound, 100);
            // play shattering sound
            play_sound_effect();
            prepareGeometryChange();
            scene()->removeItem(this); //remove this obstacle from the scene
            //qDebug() << "Heart deleted";
            delete this;
            return;
        }
    }

    setPos(x(), y()+2);
    // If heart moves out of screen, delete
    if (pos().y() > 800) {delete this;}
}
