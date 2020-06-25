#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include <stdlib.h>
#include "enemyrockgod.h"

EnemyRockGod::EnemyRockGod(QList<QPointF> path):EnemyRockSnake(path)
{
    bonus = 100;
    hp = 400;
    speed = 15;
    setPixmap(QPixmap(":/materials/RockGod.png"));
}
