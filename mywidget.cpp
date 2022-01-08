#include "mywidget.h"

MyWidget::MyWidget(MainWindow *parent) : QWidget(parent), music_button(new MusicToggleButton(parent->musicplayer))
{
music_button->setParent(this);
}
