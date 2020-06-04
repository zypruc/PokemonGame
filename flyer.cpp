/**flyer.cpp
飞行物
**/

#include "flyer.h"
#include "game.h"
#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include <stdlib.h>

extern Game* game;

Flyer::Flyer()
{
    setPixmap(QPixmap(":/materials/fireball.png"));
    //设置飞行物贴图

    //记录飞行道具移动的timer
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(40);  //40-越小越快

}

void Flyer::move()
{

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*colliding_items[i]) == typeid(Enemy)){

            if(rand()%3 == 0){
                game->score->increase(50);   // 加分
                // 从场景中移除子弹、碰撞到的敌人
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }else{
                //没打死
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

    //当没有碰撞时继续移动，飞出地图时删除
    setPos(x(),y());
    if (pos().y()<0||pos().y()>746||pos().x()<2||pos().x()>950){
        scene()->removeItem(this);
        delete this;
        return;
    }

    //控制飞行道具继续移动
    int step_len = 6;
    //考虑后续设置为由炮塔类决定的参数

    double theta = rotation(); //degrees
    double y_step = step_len*qSin(qDegreesToRadians(theta));
    double x_step = step_len*qCos(qDegreesToRadians(theta));
    setPos(x()+x_step, y()+y_step);
}


