#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemymonkey.h"
EnemyMonkey::EnemyMonkey(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 50;
    hit = 0;
    hp = 100;
    speed = 24;
    setPixmap(QPixmap(":/materials/monkey.png"));
};

int EnemyMonkey::getHit(){
    return hit;
}

void EnemyMonkey::increaseHit(){
    hit++;
}

void EnemyMonkey::getAngry(){
    this->setSpeed(40);
    this->setPixmap(QPixmap(":/materials/monkeyAngry.png"));
}


int EnemyMonkey::elementStrike(char attribute, int damage){
    if (attribute == 'n')
        return  damage;
    else
        return damage;
}
