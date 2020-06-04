/* Enemy.cpp
 * 随机出现敌人
 * 沿既定路程
 */
#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>
#include "game.h"
#include <stdlib.h>
extern Game* game;
Enemy::Enemy(QList<QPointF> path, QGraphicsItem *parent):ifDead(false)
{
    //int enemyType = rand() % 2; // 2种怪物-待后续补充
    int enemyType=0;
    if(enemyType==0){
        setPixmap(QPixmap(":/materials/gengar.png"));
    }else if(enemyType==1){
        // 待补充更多怪兽素材
    };
    points = path;  //保存要走的路径
    indexPath = 0;

    //连接时间
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveToPoint()));
    if(enemyType==0)
        timer->start(10);
}

int set_direction(const float &x){
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
void Enemy::moveToPoint(){
    /*
    points     << QPointF(330, 5) -0
               << QPointF(330,380)-1
               << QPointF(900,380)-2
               << QPointF(900,630)-3
               << QPointF(560,630)-4
               << QPointF(560,750)-5
    */
    double dx, dy;
    //依据当前所处节点不同，选择前进方向，当位置大于某一值时转变方向
    switch (indexPath) {
    case 0:
        dx = set_direction(points[indexPath+1].x()-points[indexPath].x());
        dy = set_direction(points[indexPath+1].y()-points[indexPath].y());
        if(pos().y()>points[1].y())
            indexPath++;
        break;
    case 1:
        dx = set_direction(points[indexPath+1].x()-points[indexPath].x());
        dy = set_direction(points[indexPath+1].y()-points[indexPath].y());
        if(pos().x()>points[2].x())
            indexPath++;
        break;
    case 2:
        dx = set_direction(points[indexPath+1].x()-points[indexPath].x());
        dy = set_direction(points[indexPath+1].y()-points[indexPath].y());
        if(pos().y()>points[3].y())
            indexPath++;
        break;
    case 3:
        dx = set_direction(points[indexPath+1].x()-points[indexPath].x());
        dy = set_direction(points[indexPath+1].y()-points[indexPath].y());
        if(pos().x()<points[4].x())
            indexPath++;
        break;
    case 4:
        dx = set_direction(points[indexPath+1].x()-points[indexPath].x());
        dy = set_direction(points[indexPath+1].y()-points[indexPath].y());
        if (pos().y() > 740){
            //decrease the health
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
        }
        break;
    }
    dx *= 2;    //缩放速度
    dy *= 2;
    setPos(x()+dx, y()+dy);
}
