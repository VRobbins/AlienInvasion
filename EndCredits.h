#ifndef ENDCREDITS_H
#define ENDCREDITS_H

#include "MainWindow.h"
#include "MusicToggleButton.h"
#include <QFont>
#include <QTimer>
#include <QTextEdit>
#include <QGraphicsEffect>
#include <QPropertyAnimation>

class EndCredits : public QWidget
{

    Q_OBJECT

private:
    MainWindow* mw;
    QTextEdit* paragraph1;
    QTextEdit* paragraph2;
    QTextEdit* paragraph3;

    QGraphicsOpacityEffect* p1_effect;
    QPropertyAnimation* p1_animation;

    QGraphicsOpacityEffect* p2_effect;
    QPropertyAnimation* p2_animation;

    QGraphicsOpacityEffect* p3_effect;
    QPropertyAnimation* p3_animation;


public:
    /**
        constructs the endcredits
    */
    EndCredits():
        mw(nullptr),
        paragraph1(nullptr),
        paragraph2(nullptr),
        paragraph3(nullptr),

        p1_effect(nullptr),
        p1_animation(nullptr),

        p2_effect(nullptr),
        p2_animation(nullptr),

        p3_effect(nullptr),
        p3_animation(nullptr)

    {}

    /**
        constructs the endcredits
        @param MainWindow the window the endcredits will be displayed on
    */
    EndCredits(MainWindow* w);

    //Destructor
    virtual ~EndCredits();




public slots:
    /**
        changes the background of the window
    */
    void changeBackground();

    /**
        changes the background of the endcredits
    */
    void changeBackground2();

};

#endif // ENDCREDITS_H
