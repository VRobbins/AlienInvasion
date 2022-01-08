#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "MainWindow.h"
#include "mywidget.h"
#include <QGraphicsEffect>
#include <QPropertyAnimation>

class Instructions : public MyWidget
{
    Q_OBJECT

private:
    MainWindow* mw;
    QPushButton* skipButton;
    QGraphicsOpacityEffect *eff;
    QPropertyAnimation *a;
    QTextEdit* paragraph;


public:
    /**
        constructs the instructions screen and initializes all
        private variables
    */
    Instructions();

    /**
        constructs the intrsuctions screen
        @param MainWindow* the window used to put the screen on
    */
    Instructions(MainWindow* w);

    /**
        destructs the instructions screen
    */
    ~Instructions();

public slots:
    /**
        creates the avatat map once the button has been clicked
    */
    void createMap();
};

#endif // INSTRUCTIONS_H
