#ifndef ENEMYROCKSNAKE_H
#define ENEMYROCKSNAKE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"
class EnemyRockSnake: public EnemyBase
{
public:
    EnemyRockSnake(QList<QPointF> path);
    int elementStrike(char attr, int dmg);
};

#endif // ENEMYROCKSNAKE_H
