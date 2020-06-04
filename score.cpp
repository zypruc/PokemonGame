#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 100;
    setPlainText(QString("Score:") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Menlo",22));
}
void Score::increase(int addScore){
    score += addScore;
    setPlainText(QString("Score:") + QString::number(score));
}

void Score::decrease(int minusScore)
{
    score -= minusScore;
    setPlainText(QString("Score:") + QString::number(score));
}

int Score::getScore(){
    return score;
}
