#include "Storyline.h"
#include "Instructions.h"
#include <QTimer>


Storyline::Storyline():
    mw(nullptr),
    instructions_button(nullptr),
    storyline_layout(nullptr),
    line1(nullptr),
    line2(nullptr),
    line3(nullptr),
    line4(nullptr),
    story_music(nullptr),
    music_button(nullptr)
{}


Storyline::Storyline(MainWindow* w) :
    MyWidget(w),
    mw(w),
    instructions_button(new QPushButton("Go to Instructions")),
    storyline_layout(new QGridLayout),
    line1( new QLabel("Alien Invasion is set in a world invaded by Aliens, ")),
    line2(new QLabel("from the planet Agnuli: ")),
    line3(new QLabel("As an Invader, you must attack the system")),
    line4(new QLabel("and defeat it's Lord of Fire"))
    //story_music(new QMediaPlayer(this)),
    //music_button(new MusicToggleButton(mw->musicplayer))
{
    // Creation of line labels
    mw->set_background(":/resources/img/Background2.jpg");

    // Setting font of line labels
    QFont myfont("myfont", 12, QFont::Bold);
    line1->setFont(myfont);
    line2->setFont(myfont);
    line3->setFont(myfont);
    line4->setFont(myfont);

    // Music button related
    //music_button->setParent(this);

    // Intro music
    //story_music->setMedia(QUrl("qrc:resources/sound/intro.mp3"));
    //story_music->play();

    //mw->musicplayer->setMedia(QUrl("qrc:resources/sound/intro.mp3")); //DELETE
    //mw->musicplayer->play(); //DELETE

    // Starting sequence of line labels by first displaying line1
    storyline_layout -> addWidget(line1, 1, 1, Qt::AlignCenter);
    setLayout(storyline_layout);
    QTimer::singleShot(2000, this, SLOT(updatecaption1()));
}

Storyline::~Storyline()
{
    // instructions_button handled via parent
    delete storyline_layout;
    storyline_layout = nullptr;
    //Lines deleted in updating of captions
    //delete story_music;
    //story_music = nullptr;
    // music_button handled by parent
}


void Storyline::updatecaption1() {
    delete line1;
    line1=nullptr;
    storyline_layout->addWidget(line2, 1, 1,Qt::AlignCenter);
    QTimer::singleShot(2000, this, SLOT(updatecaption2()));
}


void Storyline::updatecaption2() {
    delete line2;
    line2=nullptr;
    storyline_layout->addWidget(line3, 1, 1, Qt::AlignCenter);
    QTimer::singleShot(2000, this, SLOT(updatecaption3()));
}


void Storyline::updatecaption3() {
    delete line3;
    line3=nullptr;
    storyline_layout->addWidget(line4, 1, 1, Qt::AlignCenter);
    QTimer::singleShot(2000, this, SLOT(show_begin_button()));
}

void Storyline::show_begin_button() {
    delete line4;
    line4 = nullptr;
    instructions_button->setParent(this);
    instructions_button->setStyleSheet( "QPushButton{background-color: rgb(255,195,185); color: rgb(152,63,107); font:Courier 14px;}"
                                        "QPushButton:hover{background-color: rgba(255,195,185,150); color: rgb(152,63,107);}");
    storyline_layout->addWidget(instructions_button, 1, 1, Qt::AlignCenter);
    QObject::connect(instructions_button,SIGNAL(clicked()),this,SLOT(create_instructions()));
}


void Storyline::create_instructions() {
    Instructions* ins = new Instructions(mw);
    mw->setCentralWidget(ins);
    delete this;
}
