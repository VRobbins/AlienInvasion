#include "MainWindow.h"
#include "StartScreen.h"
#include "Game.h"
#include "WaterGame.h"
#include "EarthGame.h"
#include "BossLevel.h"
#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>

WaterGame* water_game;
EarthGame* earth_game;
BossLevel* boss_game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mainwindow = new MainWindow;
    mainwindow->setWindowTitle("Alien Invasion");
    StartScreen* welcome_page = new StartScreen(mainwindow);
    mainwindow->setCentralWidget(welcome_page);
    mainwindow->show();

    return a.exec();
}
