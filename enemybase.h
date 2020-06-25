#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
class EnemyBase: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    EnemyBase(QList<QPointF> path);
    EnemyBase(QList<QPointF> path, int s, int h);
    int getHP() const{ return hp; }
    int getBonus () const{ return bonus; };
    void deductHP(int deduct = 1);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setSpeed(int s=20);
    void setHP(int hpNew);
    virtual int elementStrike(char, int) {};

public slots:
    void moveToPoint();

protected:
    int setDirection(const float &);
    QList<QPointF> points;
    QPointF nextPosition;
    bool ifDead;
    int indexPath;
    int hp;
    int speed;
    int bonus;
    //    int hpMax;
};

#endif
