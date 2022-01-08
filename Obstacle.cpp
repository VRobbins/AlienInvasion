#include "Obstacle.h"
#include "Game.h"
#include "WaterGame.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Obstacle::Obstacle()
{}

void Obstacle::set_sound_effect(QMediaPlayer* sound, int volume)
{
    sound_effect = sound;
    music_volume = volume;
}

/*
 connect the timer to a move slot defined for each class inherited from Obstacle
 how much time a timer times out is controlled by input parameter: int duration
 */

void Obstacle::set_move_timer(QTimer* timer)
{
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
}


void Obstacle::play_sound_effect()
{
    sound_effect -> setVolume(music_volume);
    // If sound effect is currently playing, set its position to beginning
    if (sound_effect -> state() == QMediaPlayer::PlayingState) {
        sound_effect -> setPosition(0);
    // If sound effect is currently stopped, play it
    } else if (sound_effect -> state() == QMediaPlayer::StoppedState){
        sound_effect -> play();
    }
}




