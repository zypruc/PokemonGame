#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsRectItem>
#include <typeinfo>
#include <QDebug>

#include "tower.h"
#include "game.h"
#include "enemybase.h"
#include "flyer.h"

extern Game* game;

Tower::Tower(QGraphicsItem * p)
    : QObject(), QGraphicsPixmapItem(p), power(1), level(1), flyerSpeed(0)
{
    QVector<QPointF> points;
    QVector<QPointF> attackBound;
    attackBound<< QPointF(0, 0) << QPointF(300, 0) << QPointF(300, 300) << QPointF(0, 300);
    attackArea = new QGraphicsPolygonItem(QPolygonF(attackBound), this);
    QPen penBoundary;
    QColor colBoundary(190, 230, 250);
    colBoundary.setAlphaF(0.05);
    penBoundary.setColor(colBoundary);
    attackArea->setPen(penBoundary);
    attackArea->setAcceptedMouseButtons(Qt::NoButton);
    QPointF centre(150,150);
    centre = mapToScene(centre);;
    QPointF towerCenter(x()+40,y()+50);
    QLineF ln(centre,towerCenter);
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());
    // 设置攻击目标
    attackAim = QPointF(0,0);
    targetExist = false;
}


double Tower::dBetween(QGraphicsItem *target)
{
    QLineF d(this->pos() + boundingRect().center(), target->pos() + target->boundingRect().center());
    return d.length();
}


void Tower::getTarget(){
    QList<QGraphicsItem *> colliding_items = attackArea->collidingItems();
    targetExist = false;
    double attackRange = 210;
    QPointF closeTarget(0, 0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        EnemyBase *enme = dynamic_cast<EnemyBase *>(colliding_items[i]);
        if (enme){
            double d1 = dBetween(colliding_items[i]);
            if (d1 < attackRange){
                attackRange = d1;
                closeTarget = enme->pos() + enme->boundingRect().center();
                targetExist = true;
            }
        }
    }
    if (targetExist){
        attackAim = closeTarget;
        this->fire();

        //目标检测调参
        //QGraphicsRectItem* pItem = new QGraphicsRectItem();
        //// 设置画笔、画刷
        //QPen pen = pItem->pen();
        //pen.setWidth(5);
        //pen.setColor(Qt::yellow);
        //pItem->setPen(pen);
        //pItem->setBrush(QBrush(QColor(0, 160, 230)));
        //// 矩形区域 起点：(50, 50) 宽：200 高：100
        //pItem->setRect(QRectF(closeTarget.x()-5, closeTarget.y()-5, 10, 10));
        //game->scene->addItem(pItem);
    }
}


void Tower::mousePressEvent(QGraphicsSceneMouseEvent* e)
{
    qDebug() << "Tower Press";
    QGraphicsPixmapItem::mousePressEvent(e);
}

