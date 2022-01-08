#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem{

public:
    /**
        constructs the score of the player
        @param QGraphicsItem* the item to display the score
    */
    Score(QGraphicsItem* parent = nullptr);

    /**
        increases the score once hit
    */
    void increase();

    /**
        retruns the score
        @return int the current score
    */
    int getScore() const;

private:
    int score;

};



#endif // SCORE_H


