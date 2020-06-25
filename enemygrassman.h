#ifndef ENEMYGRASSMAN_H
#define ENEMYGRASSMAN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"
class EnemyGrassMan: public EnemyBase
{
public:
    EnemyGrassMan();
    EnemyGrassMan(QList<QPointF> path);
    int elementStrike(char attribute, int dmg) override;
};

#endif // ENEMYGRASSMAN_H
