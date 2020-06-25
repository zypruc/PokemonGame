#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <stdlib.h>
#include "enemybat.h"

EnemyBat::EnemyBat(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 40;
    hp = 100;
    speed = 32;
    setPixmap(QPixmap(":/materials/bat.png"));
}

int EnemyBat::elementStrike(char attr, int damage){
    if (attr == 't')
        return 2 * damage;
    else
        return damage;
}
