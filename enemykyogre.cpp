#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include "enemykyogre.h"

EnemyKyogre::EnemyKyogre(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 100;
    hp = 800;
    speed = 17;
    setPixmap(QPixmap(":/materials/Kyogre.png"));
}

int EnemyKyogre::elementStrike(char attribute, int damage){
    if (attribute == 't')
        return 2 * damage;
    else if(attribute == 'n')
        return damage;
    else if(attribute == 'f')
        return 0;
    else if(attribute == 'g')
        return 2 * damage;
    else
        return damage;
}
