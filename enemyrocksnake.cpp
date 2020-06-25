#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <stdlib.h>
#include "enemyrocksnake.h"

EnemyRockSnake::EnemyRockSnake(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 50;
    hp = 100;
    speed = 18;
    setPixmap(QPixmap(":/materials/RockSnake.png"));
}

int EnemyRockSnake::elementStrike(char attribute, int damage){
    if (attribute == 't')
        return 0.5 * damage;
    else if (attribute == 'f')
        return 0.5 * damage;
    else if (attribute == 'n')
        return 0.5 * damage;
    else if (attribute == 'w')
        return 2 * damage;
    else
        return damage;
}
