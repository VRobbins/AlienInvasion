#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QMediaPlayer>

class Obstacle: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
    /**
        constructs an obstacle with no parameters
    */
    Obstacle();

    /**
        sets the sound effect and volume for the obstacle
        @param sound : pointer to a QMediaPlayer for the sound effect of obstacle collision
        @param volume: integer volume setting for sound effect
    */
    void set_sound_effect(QMediaPlayer* sound, int volume);

    /**
        plays the sound effect by setting the volume and when to be played
    */
    void play_sound_effect();

    /**
        connects the timer to the movement of the obstacle
        @param timer controls how often the obstacle moves
    */
    void set_move_timer(QTimer* timer);

    /**
        destructs the obstacle
    */
    virtual ~Obstacle(){};

public slots:
    /**
        pure vitural function that forces the the derived classes to contain this function
    */
    virtual void move() = 0;

private:
    QMediaPlayer* sound_effect;
    int music_volume;
};

#endif // OBSTACLE_H
