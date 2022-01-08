#include "StartScreen.h"
#include "Storyline.h"
#include "MusicToggleButton.h"


StartScreen::StartScreen():
    mw(nullptr),
    start_button(nullptr),
    title(nullptr),
    startscreen_layout(nullptr)//,
    //intro_music(nullptr)
{}


StartScreen::StartScreen(MainWindow* w):
    MyWidget(w),
    mw(w),
    start_button(new QPushButton("Play")),
    title(new QLabel(" Alien Invasion ")),
    startscreen_layout(new QGridLayout)//,
    //intro_music(new QMediaPlayer(this)),
    //music_button(new MusicToggleButton(intro_music))

{


    // Title label related graphics
    QFont title_font("title_font", 60, QFont::ExtraBold);
    title->setStyleSheet("QLabel {color: white; }");
    title->setFont(title_font);
    startscreen_layout -> addWidget(title, 1, 1, Qt::AlignCenter);

    // Start button related
    start_button -> setParent(this);
    start_button -> setStyleSheet( "QPushButton{background-color: rgb(255,195,185); color: rgb(152,63,107); font:Courier 14px;}"
                                   "QPushButton:hover{background-color: rgba(255,195,185,150); color: rgb(152,63,107);}");
    mw -> set_background(":/resources/img/Background1.jpg");
    startscreen_layout -> addWidget(start_button, 2, 1, Qt::AlignCenter);
    QObject::connect(start_button,SIGNAL(clicked()),this,SLOT(create_storyline()));


    mw->set_music(QUrl("qrc:resources/sound/intro.mp3"));
    mw->start_music();

    setLayout(startscreen_layout);
}


void StartScreen::create_storyline() const {
    Storyline* s = new Storyline(mw);
    mw->setCentralWidget(s);
    delete this;
}



