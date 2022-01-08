#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <QWidget>
#include "MainWindow.h"

class WinScreen : public QWidget
{
    Q_OBJECT

public:
    /**
        constructs the win screen that shows when the game has been defeated
        @param MainWindow the window the win screen will be displayed on
    */
    WinScreen(MainWindow* mw);

public slots:
    /**
        creates the EndCredits
    */
    void create_EndCredit();

private:
    MainWindow* w;
    QPushButton* continue_button;



};

#endif // WINSCREEN_H
