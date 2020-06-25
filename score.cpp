#include "score.h"
#include <QFont>
Score::Score(int initScore, QGraphicsItem *parent)
    :QGraphicsTextItem(parent),score(initScore)
{
    setPlainText(QString(":") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Menlo",22));
}
void Score::increase(int addScore){
    score += addScore;
    setPlainText(QString(":") + QString::number(score));
}

void Score::decrease(int minusScore)
{
    score -= minusScore;
    setPlainText(QString(":") + QString::number(score));
}

int Score::getScore(){
    return score;
}
