#include "Instructions.h"
#include "AvatarMap.h"


Instructions::Instructions(): mw(nullptr), skipButton(nullptr), paragraph(nullptr) {}


Instructions::Instructions(MainWindow* w) : MyWidget(w), mw(w), skipButton(new QPushButton("Skip")), eff(nullptr), a(nullptr),
    paragraph(new QTextEdit()) {

    //set background
    mw->set_background(":/resources/img/Background4.jpg");

    //skip button implementation

    skipButton->setParent(this);
    skipButton->setGeometry(550, 720,100,50);
    skipButton->setStyleSheet("background-color: rgb(255,195,185); color: rgb(152,63,107); font:Courier 14px;");
    QObject::connect(skipButton,SIGNAL(clicked()),this,SLOT(createMap()));
    skipButton->setStyleSheet( "QPushButton{background-color: rgb(255,195,185); color: rgb(152,63,107); font:Courier 14px;}"
                               "QPushButton:hover{background-color: rgba(255,195,185,150); color: rgb(152,63,107);}");

    //pargraph (instructions) implementation
    //make sure anything that changes text is set before text is set
    paragraph->setTextColor(QColor(255,255,255));
    paragraph->setFontPointSize(25);
    paragraph->setFontFamily("Courier");
    QString instructions = "Instructions\n\n"
                           "1. Begin the game by clicking on the Blue Planet \n"
                           "2. Use the up ^, down v, left <, and right >,\n"
                           "   keys to dodge all objects \n"
                           "3. Upon running into an object you will lose\n"
                           "   a life\n"
                           "4. Press the B key to release your water element\n   once it is active\n"
                           "5. Press the V key to go invincible \n"
                           "6. Press the space key to use your air element\n   once it is active\n"
                           "7. At the end of each level you will gain an\n"
                           "   element\n"
                           "                  GOOD LUCK!";


    paragraph->setText(instructions);
    paragraph->setParent(this);
    paragraph->setReadOnly(true);
    paragraph->setAlignment(Qt::AlignCenter);
    paragraph->setFrameStyle(QFrame::NoFrame);
    paragraph->setGeometry(250,70,800,500);
    paragraph->viewport()->setAutoFillBackground(false);

    //fades in the paragraph (instructions)
    eff = new QGraphicsOpacityEffect(this);
    paragraph->setGraphicsEffect(eff);
    a = new QPropertyAnimation(eff,"opacity");
    a->setDuration(3000);
    a->setStartValue(0);
    a->setEndValue(1);
    a->setEasingCurve(QEasingCurve::InBack);
    a->start(QPropertyAnimation::DeleteWhenStopped);

}


void Instructions::createMap(){
    AvatarMap* am = new AvatarMap(mw,0);
    mw->setCentralWidget(am);
    delete this;
}

Instructions::~Instructions()
{
    // paragraph handled by parent
    delete eff;
    eff = nullptr;
    // skipButton handled by parent
}




