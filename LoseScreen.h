#ifndef LOSESCREEN_H
#define LOSESCREEN_H

#include <QWidget>
#include <QPixmap>
#include <QIcon>

#include "AvatarMap.h"
#include "MainWindow.h"

class LoseScreen : public QWidget
{
    Q_OBJECT

public:
    /**
        constructs the lose screen
        @param MainWindow* the window the lose screen will be displayed on
    */
    LoseScreen(MainWindow* mw);

public slots:
    /**
        creates the avatar map when the restart button is clicked
    */
    void create_AvatarMap();

private:
    MainWindow* w;
    QPushButton* restart_button;


};

#endif // LOSESCREEN_H
