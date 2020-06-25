#ifndef ENEMYROCKGOD_H
#define ENEMYROCKGOD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemyrocksnake.h"
class EnemyRockGod: public EnemyRockSnake
{
public:
    EnemyRockGod(QList<QPointF> path);
};

#endif // ENEMYROCKGOD_H
