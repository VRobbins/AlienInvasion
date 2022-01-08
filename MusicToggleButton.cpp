#include "MusicToggleButton.h"


MusicToggleButton::MusicToggleButton(QMediaPlayer* media) : music(media), sound_on(true) {
    QPixmap sound_on_pixmap(":/resources/img/sound_on.png");
    QIcon sound_on_icon(sound_on_pixmap);
    setIcon(sound_on_icon);
    setIconSize(sound_on_pixmap.rect().size());
    setStyleSheet("background-color: transparent;");
    setGeometry(1130,20,50,50);
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(toggle()));
}


void MusicToggleButton::toggle() {
    // If sound was on, this slot will change button to muted icon and set volume 0
    if (sound_on) {
        QPixmap sound_off_pixmap(":/resources/img/sound_off.png");
        QIcon sound_off_icon(sound_off_pixmap);
        this->setIcon(sound_off_icon);
        this->setIconSize(sound_off_pixmap.rect().size());
        music->setVolume(0);
        sound_on = false;
    } else { // If sound was off, this slot will change button to speaker icon and set volume 100
        QPixmap sound_on_pixmap(":/resources/img/sound_on.png");
        QIcon sound_on_icon(sound_on_pixmap);
        this->setIcon(sound_on_icon);
        this->setIconSize(sound_on_pixmap.rect().size());
        music->setVolume(100);
        sound_on = true;
    }
}
