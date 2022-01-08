#ifndef MUSICTOGGLEBUTTON_H
#define MUSICTOGGLEBUTTON_H

#include <QPushButton>
#include <QMediaPlayer>


class MusicToggleButton : public QPushButton
{
    Q_OBJECT

public:

    /**
     * Constructs a MusicToggleButton linked to a media source
     * @param media: QMediaPlayer* to which this MusicToggleButton refers and upon which it acts
     */
    MusicToggleButton(QMediaPlayer* media);

private:
    QMediaPlayer* music;
    bool sound_on;

private slots:

    /**
     * Detects if current status has the sound on or off and appropriately changes the icon and music volume
     */
    void toggle();
};

#endif // MUSICTOGGLEBUTTON_H
