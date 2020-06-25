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
    virtual void fire(){};
    virtual void upgrade() {};
    virtual void setImage() {};
    virtual int getUpgradePrice() {};
public slots:
    void getTarget();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*e)override;
    QGraphicsPolygonItem * attackArea;
    QPointF attackAim;  //要攻击的目标
    bool targetExist;
    int power;  //伤害
    int level;  //等级
    int flyerSpeed;
};

#endif // TOWER_H
