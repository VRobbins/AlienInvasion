#include "LoseScreen.h"

LoseScreen::LoseScreen(MainWindow *mw):w(mw),
  restart_button(new QPushButton)
{
    restart_button->setParent(this);

    restart_button->setGeometry(550,570,100,100);
    restart_button -> setStyleSheet("QPushButton{background-color: transparent}");

    QPixmap restart_temp(":/resources/img/restartButton.png");
    QPixmap restart_pixmap = restart_temp.scaled(100,100);
    QIcon restart_icon(restart_pixmap);

    restart_button->setIcon(restart_pixmap);
    restart_button->setIconSize(restart_button->size());

    mw->set_background(":/resources/img/game_over.jpg");

    QObject::connect(restart_button,SIGNAL(clicked()),this,SLOT(create_AvatarMap()));


}

void LoseScreen::create_AvatarMap()
{
    AvatarMap* avatar_map = new AvatarMap(w,0);
    w->setCentralWidget(avatar_map);
    delete this;

}
