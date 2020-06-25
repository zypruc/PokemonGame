#ifndef ENEMYKYOGRE_H
#define ENEMYKYOGRE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"

class EnemyKyogre: public EnemyBase
{
public:
    EnemyKyogre(QList<QPointF> path);
    int elementStrike(char attribute, int dmg) override;
};

#endif // ENEMYKYOGRE_H
