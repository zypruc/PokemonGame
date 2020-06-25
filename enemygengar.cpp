#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <stdlib.h>

#include "enemygengar.h"

EnemyGengar::EnemyGengar(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 50;
    hp = 120;
    speed = 20;
    setPixmap(QPixmap(":/materials/gengar.png"));
}


void EnemyGengar::indexJump(){
    setPos(points[indexPath+1].x(), points[indexPath+1].y());
}


int EnemyGengar::elementStrike(char attribute, int damage){
    if (attribute=='n') {
        return 0;
    } else {
        return damage;
    }
}

void EnemyGengar::getParalyzed(char FlyerAttribute){
    int chanceParalyzed = rand()%5; //麻痹的概率
    if (FlyerAttribute=='t' && chanceParalyzed==1){
        this->setPixmap(QPixmap(":/materials/gengarParalyzed.png"));
        this->setSpeed(13);
    }else{
        this->setSpeed(20);
        return;
    }
}
