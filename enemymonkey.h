#ifndef ENEMY_MONKEY_H
#define ENEMY_MONKEY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>

#include "enemybase.h"
class EnemyMonkey: public EnemyBase
{
protected:
    int hit;
public:
    EnemyMonkey(QList<QPointF> path);
    int getHit();
    void getAngry();
    void increaseHit();
    int elementStrike(char attribute, int dmg) override;
};

#endif // ENEMY_MONKEY_H
