#ifndef ENEMYBAT_H
#define ENEMYBAT_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"

class EnemyBat: public EnemyBase
{
public:
    EnemyBat(QList<QPointF> path);
    int elementStrike(char attr, int dmg) override;
};

#endif // ENEMYBAT_H
