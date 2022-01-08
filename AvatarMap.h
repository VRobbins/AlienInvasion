#ifndef AVATAR_MAP_H
#define AVATAR_MAP_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include "MainWindow.h"
#include <QDebug>
#include "mywidget.h"

class AvatarMap : public MyWidget
{
    Q_OBJECT

public:
    /**
        constructor for the avatar map
        @param MainWindow* that takes a pointer of the current window
        @param int the integer of how many levels have been completed
    */
    AvatarMap(MainWindow*, int);

    /**
       sets the background for the avatar map
       @param event parameter but is unused in this function
    */
    void paintEvent(QPaintEvent *event);

public slots:
    /**
        creates the Water Game
    */
    void create_WaterGame();

    /**
        creates the Earth Game
    */
    void create_EarthGame();

    /**
        creates the Boss Game
    */
    void create_BossGame();


private:
    MainWindow* mw;
    int complete_level;
    QPushButton* water_button_north;
    QPushButton* water_button_south;
    QPushButton* earth_button;
    QPushButton* fire_button;
    QPushButton* end_button;
    QPushButton* water_complete;
    QPushButton* earth_complete;
    QPushButton* fire_complete;

};


#endif // AVATAR_MAP_H
