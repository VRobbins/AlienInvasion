#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "MainWindow.h"
#include <QMediaPlayer>
#include "MusicToggleButton.h"
#include "mywidget.h"


class StartScreen : public MyWidget
{
    Q_OBJECT

public:

    /**
     * Default constructor for starting screen with title and play button, initializes all member fields to nullptr
     */
    StartScreen();

    /**
     * Constructor with parameters, initializing mw to the parameter input, start_button with "Play", title with game name,
     * and startscreen_layout with new layout
     * @param w: MainWindow for which StartScreen is set
     */
    StartScreen(MainWindow* w);

private:
    MainWindow* mw;
    QPushButton* start_button;
    //QPushButton* sound_button;
    QLabel* title;
    QGridLayout* startscreen_layout;
    //QMediaPlayer* intro_music;
    //MusicToggleButton* music_button;
    //bool sound_on;

public slots:

    /**
     * Slot which is called when the "Play" button is pressed to create and move on to the Storyline screen; this widget is deleted
     * @return void
     */
    void create_storyline() const;

};


#endif // STARTSCREEN_H
