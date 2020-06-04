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
#include "enemy.h"
#include "flyer.h" //子弹

extern Game* game;

Tower::Tower(QGraphicsItem * p): QObject(), QGraphicsPixmapItem(p)
{
    QVector<QPointF> points;
    QVector<QPointF> attackBound;
    attackBound<< QPointF(0, 0) << QPointF(300, 0) << QPointF(300, 300) << QPointF(0, 300);
    attackArea = new QGraphicsPolygonItem(QPolygonF(attackBound), this);
    attackArea->setPen(QPen(Qt::DotLine));
    QPointF centre(150,150);
    centre = mapToScene(centre);;
    QPointF tower_center(x()+40,y()+50);
    QLineF ln(centre,tower_center);
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());

    // 设置攻击目标
    attackAim = QPointF(0,0);
    targetExist = false;
}

double Tower::dBetween(QGraphicsItem *target)
{
    QLineF d(this->pos(),target->pos());
    return d.length();
}

void Tower::fire(){
    //发射攻击子弹
    Flyer * flyer = new Flyer();
    flyer->setPos(x(),y());   //起始点
    QLineF start_end(QPointF(x(),y()), attackAim);
    //起始点-终点 连线
    int angle = -1 * start_end.angle();
    flyer->setRotation(angle);
    game->scene->addItem(flyer);
}


void Tower::get_target(){
    QList<QGraphicsItem *> colliding_items = attackArea->collidingItems();
    targetExist = false;
    double closest_dist = 200;
    QPointF closeTarget(0, 0);
    for (size_t i = 0, n = colliding_items.size(); i < n; ++i){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy){
            double d1 = dBetween(colliding_items[i]);
            if (d1 < closest_dist){
                closest_dist = d1;
                closeTarget = colliding_items[i]->pos();
                targetExist = true;
            }
        }
    }
    if (targetExist){
        attackAim = closeTarget;
        fire();
    }
}
