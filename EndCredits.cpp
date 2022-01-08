#include "EndCredits.h"


EndCredits::EndCredits(MainWindow* w):
    mw(w),
    paragraph1(new QTextEdit()),
    paragraph2(new QTextEdit()),
    paragraph3(new QTextEdit()),

    p1_effect(nullptr),
    p1_animation(nullptr),

    p2_effect(nullptr),
    p2_animation(nullptr),

    p3_effect(nullptr),
    p3_animation(nullptr)
{

     //Set Background
     mw->set_background(":/resources/img/Background5.jpg");

     //Paragraph1
     paragraph1->setTextColor(QColor(255,247,232));
     //paragraph1->setFontFamily("Sans");
     QFont paragraph1_font("Courier",17,QFont::Bold);
     paragraph1->setFont(paragraph1_font);
     QString creators = "Alien Invasion\n\n\n"
                        "        CREATED BY  \n\n\n"
                        "      Dareen Atallah  \n\n"
                        "       Weiyu Huang   \n\n"
                        "        Peter Liu    \n\n"
                        "       Vince Robbins  \n\n";
     paragraph1->setText(creators);
     paragraph1->setParent(this);
     paragraph1->setReadOnly(true);
     paragraph1->setAlignment(Qt::AlignCenter);
     paragraph1->setFrameStyle(QFrame::NoFrame);
     paragraph1->setGeometry(200,200,400,500);
     paragraph1->viewport()->setAutoFillBackground(false);
     //Paragraph1 fade in
     p1_effect = new QGraphicsOpacityEffect(this);
     paragraph1->setGraphicsEffect(p1_effect);
     p1_animation = new QPropertyAnimation(p1_effect,"opacity");
     p1_animation->setDuration(4*1000);
     p1_animation->setStartValue(0);
     p1_animation->setEndValue(1);
     p1_animation->setEasingCurve(QEasingCurve::InBack);
     p1_animation->start(QPropertyAnimation::DeleteWhenStopped);

     //Paragraph2
     paragraph2->setTextColor(QColor(159,109,10));
     QFont paragraph2_font("Courier",18,QFont::Bold);
     paragraph2->setFont(paragraph2_font);
     QString creators2 = "Programming in Computing 10C\n\n"
                         "       ADVANCED PROGRAMMING\n\n"
                         "        Professor Falcon\n\n";
     paragraph2->setText(creators2);
     paragraph2->setParent(this);
     paragraph2->setReadOnly(true);
     paragraph2->setAlignment(Qt::AlignCenter);
     paragraph2->setFrameStyle(QFrame::NoFrame);
     paragraph2->setGeometry(600,150,500,500);
     paragraph2->viewport()->setAutoFillBackground(false);
     //Paragraph2 fade in
     p2_effect = new QGraphicsOpacityEffect(this);
     paragraph2->setGraphicsEffect(p2_effect);
     p2_animation = new QPropertyAnimation(p2_effect,"opacity");
     p2_animation->setDuration(15* 1000);
     p2_animation->setStartValue(0);
     p2_animation->setEndValue(1);
     p2_animation->setEasingCurve(QEasingCurve::InBack);
     p2_animation->start(QPropertyAnimation::DeleteWhenStopped);

     //Paragraph3
     paragraph3->setTextColor(QColor(138,199,246));
     QFont paragraph3_font("Courier",20,QFont::Bold);
     paragraph3->setFont(paragraph3_font);
     QString creators3 = "Thank you for Playing!";
     paragraph3->setText(creators3);
     paragraph3->setParent(this);
     paragraph3->setReadOnly(true);
     paragraph3->setAlignment(Qt::AlignCenter);
     paragraph3->setFrameStyle(QFrame::NoFrame);
     paragraph3->setGeometry(100,200,600,500);
     paragraph3->viewport()->setAutoFillBackground(false);
     //Paragraph3 fade in
     p3_effect = new QGraphicsOpacityEffect(this);
     paragraph3->setGraphicsEffect(p3_effect);
     p3_animation = new QPropertyAnimation(p3_effect,"opacity");
     p3_animation->setDuration(29*1000);
     p3_animation->setStartValue(0);
     p3_animation->setEndValue(1);
     p3_animation->setEasingCurve(QEasingCurve::InBack);
     p3_animation->start(QPropertyAnimation::DeleteWhenStopped);
     QTimer::singleShot(10*1000,this,SLOT(changeBackground()));
     QTimer::singleShot(20*1000,this,SLOT(changeBackground2()));
}

EndCredits::~EndCredits(){
   delete mw;
   mw=nullptr;

   delete p1_effect;
   p1_effect=nullptr;

   delete p1_animation;
   p1_animation=nullptr;

   delete p2_effect;
   p2_effect=nullptr;

   delete p2_animation;
   p2_animation=nullptr;

   delete paragraph3;
   paragraph3=nullptr;

   delete p3_effect;
   p3_effect=nullptr;

   delete p3_animation;
   p3_animation=nullptr;

}

void EndCredits::changeBackground(){
    delete paragraph1;
    paragraph1=nullptr;
    mw->set_background(":/resources/img/Background6.jpg");
}

void EndCredits::changeBackground2(){

    delete paragraph2;
    paragraph2=nullptr;
    mw->set_background(":/resources/img/Background7.jpg");
}
