#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include "QMediaPlayer"
#include "MusicToggleButton.h"
#include <QMediaContent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * Constructor with parameters for MainWindow, sets size to disallow resizing
     * @param parent: a QWidget pointer set to be the parent of MainwWindow, null by default
     */
    MainWindow(QWidget *parent = nullptr);

    /**
       Sets background image for main window
       @param filename: file or path to be used as background image
     */
    void set_background(const QString & filename);
    QMediaPlayer* musicplayer; //DELETE
    void set_music(const QMediaContent);
    void stop_music();
    void start_music();


private:
    Ui::MainWindow *ui;




};


#endif // MAINWINDOW_H
