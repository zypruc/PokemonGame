#ifndef ENEMY_GANGAR_H
#define ENEMY_GANGAR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"
class EnemyGengar: public EnemyBase
{
public:
    EnemyGengar(QList<QPointF> path);
    int elementStrike(char attribute, int damage) override;
    void indexJump();
    void getParalyzed(char);
};

#endif // ENEMY_GANGAR_H
