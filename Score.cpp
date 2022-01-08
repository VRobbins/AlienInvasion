#include "Score.h"


Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    ++score;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() const
{
    return score;
}
