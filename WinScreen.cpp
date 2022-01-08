#include "WinScreen.h"
#include "EndCredits.h"


WinScreen::WinScreen(MainWindow *mw):w(mw),
    continue_button(new QPushButton("Continue"))
{
    w->stop_music();
    w->set_music(QUrl("qrc:/resources/sound/End.mp3"));
    w->start_music();
    w->set_background(":/resources/img/Win_Image.jpg");
    continue_button->setParent(this);
    continue_button->setGeometry(600,600,100,50);
    continue_button->setStyleSheet( "QPushButton{background-color: rgb(255,195,185); color: rgb(152,63,107); font:Courier 14px;}"
                                    "QPushButton:hover{background-color: rgba(255,195,185,150); color: rgb(152,63,107);}");
    QObject::connect(continue_button,SIGNAL(clicked()),this,SLOT(create_EndCredit()));
}

void WinScreen::create_EndCredit()
{
    EndCredits* credit_page = new EndCredits(w);
    w->setCentralWidget(credit_page);
    delete this;
}
