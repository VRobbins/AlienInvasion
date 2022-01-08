#ifndef STORYLINE_H
#define STORYLINE_H

#include "MainWindow.h"
#include "MusicToggleButton.h"
#include "mywidget.h"


class Storyline : public MyWidget
{
    Q_OBJECT

public:

    /**
     * Default constructor for Storyline, initializes all data fields to be nullptr
     */
    Storyline();

    /**
     * Constructor with parameters, initializing mw to the parameter input, skip_button with "Skip", title with game name,
     * and storyline_layout with new layout; also initializes QLabel objects and sets addresses to line1-line4
     * @param w: MainWindow for which Storyline screen is set
     */
    Storyline(MainWindow* w);
    ~Storyline();

private:
    MainWindow* mw;
    QPushButton* instructions_button;
    QGridLayout* storyline_layout;
    QLabel* line1;
    QLabel* line2;
    QLabel* line3;
    QLabel* line4;
    QMediaPlayer* story_music;
    MusicToggleButton* music_button;

public slots:

    /**
     * Deletes line1 and adds line2 as the next widget to be displayed
     */
    void updatecaption1();

    /**
     * Deletes line2 and adds line3 as the next widget to be displayed
     */
    void updatecaption2();

    /**
     * Deletes line3 and adds line4 as the next widget to be displayed
     */
    void updatecaption3();

    /**
     * Displays button for transition to Instructinos
     */
    void show_begin_button();

    /**
     * Actually creates the instructions screen
     */
    void create_instructions();

};


#endif // STORYLINE_H
