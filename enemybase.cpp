#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>
#include "game.h"
#include <stdlib.h>
#include "enemybase.h"

extern Game* game;

EnemyBase::EnemyBase(QList<QPointF> path):ifDead(false), speed(0)
{
    points = path;  //保存要走的路径
    indexPath = 0;
    bonus = 0;
    hp = 0;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveToPoint()));
    timer->start(6);
}


EnemyBase::EnemyBase(QList<QPointF> path, int s, int h)
    :ifDead(false), hp(h), points(path), speed(s)
{

    indexPath = 0;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveToPoint()));
    timer->start(6);
}

int EnemyBase::setDirection(const float &x){
    // 大于0则返回1；否则0；用于按照坐标移动
    if(x>1e-6){
        return 1;
    }else if (x<-1e-6) {
        return -1;
    }
    else{
        return 0;
    }
}

void EnemyBase::deductHP(int x){
    hp -= x;
}


void EnemyBase::setSpeed(int s){
    speed = s;
}


void EnemyBase::setHP(int hpNew){
    hp = hpNew;
}

void EnemyBase::moveToPoint(){
    /*
    points     << QPointF(330, 5) -0
               << QPointF(330,380)-1
               << QPointF(900,380)-2
               << QPointF(900,630)-3
               << QPointF(560,630)-4
               << QPointF(560,750)-5
    */
    double dx, dy;
    switch (indexPath) {
    case 0:
        dx = setDirection(points[indexPath+1].x()-points[indexPath].x());
        dy = setDirection(points[indexPath+1].y()-points[indexPath].y());
        if(pos().y()>points[1].y())
            indexPath++;
        break;
    case 1:
        dx = setDirection(points[indexPath+1].x()-points[indexPath].x());
        dy = setDirection(points[indexPath+1].y()-points[indexPath].y());
        if(pos().x()>points[2].x())
            indexPath++;
        break;
    case 2:
        dx = setDirection(points[indexPath+1].x()-points[indexPath].x());
        dy = setDirection(points[indexPath+1].y()-points[indexPath].y());
        if(pos().y()>points[3].y())
            indexPath++;
        break;
    case 3:
        dx = setDirection(points[indexPath+1].x()-points[indexPath].x());
        dy = setDirection(points[indexPath+1].y()-points[indexPath].y());
        if(pos().x()<points[4].x())
            indexPath++;
        break;
    case 4:
        dx = setDirection(points[indexPath+1].x()-points[indexPath].x());
        dy = setDirection(points[indexPath+1].y()-points[indexPath].y());
        if (pos().y() > 740){
            //decrease the health
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
        }
        break;
    }
    dx *= speed;    //缩放速度
    dy *= speed;
    dx *= 0.1;
    dy *= 0.1;
    setPos(x()+dx, y()+dy);
}


void EnemyBase::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QGraphicsPixmapItem::paint(painter, option, widget);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    QRectF rect = boundingRect();
    QColor col(190, 230, 250);
    col.setAlphaF(0.1);
    painter->setPen(col);
    painter->drawRect(QRectF(rect.center() - QPointF(10, 10), rect.center() + QPointF(10, 10)));
}
