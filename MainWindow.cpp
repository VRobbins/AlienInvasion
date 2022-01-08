#include "MainWindow.h"
#include "Storyline.h"
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), musicplayer(new QMediaPlayer(this))
{
    this->setFixedSize(1200,800);

}


void MainWindow::set_background(const QString & filename) {
    QPixmap bg(filename);
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette bg_palette;
    bg_palette.setBrush(QPalette::Background, bg);
    this->setPalette(bg_palette);
}

void MainWindow::set_music(const QMediaContent input)
{
    musicplayer->setMedia(input);
}

void MainWindow::start_music()
{
    musicplayer->play();
}

void MainWindow::stop_music()
{
    musicplayer->stop();
}
