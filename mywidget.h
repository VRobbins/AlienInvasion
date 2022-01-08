#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "MusicToggleButton.h"
#include "MainWindow.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(MainWindow* parent = nullptr);
private:
     MusicToggleButton* music_button;

signals:

};

#endif // MYWIDGET_H
