/*
Tower.h:
    1.炮塔，能够对敌人攻击
    2.存在一定范围
 */
#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent=0);
    double dBetween(QGraphicsItem* item);
    virtual void fire();
public slots:
    void get_target();
protected:
    QGraphicsPolygonItem * attackArea;
    QPointF attackAim;  //要攻击的目标
    bool targetExist;

};

#endif // TOWER_H
