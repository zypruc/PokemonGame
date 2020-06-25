#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
class Score:public QGraphicsTextItem
{
public:
    Score(int initScore=200, QGraphicsItem* parent=0);
    void increase(int);
    void decrease(int);
    void setScore(int initScore){ score=initScore; }
    int getScore();
private:
    int score;
};

#endif // SCORE_H
