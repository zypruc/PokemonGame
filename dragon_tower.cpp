#include <QTimer>
#include "flyer.h"
#include "game.h"
#include "dragon_tower.h"

extern Game* game;
QGraphicsItem *p;
Dragon_Tower::Dragon_Tower()
{
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(get_target()));
    timer->start(200);
    //攻击速度！越小越快
}
void Dragon_Tower::fire()
{
    // 发射子弹
    Flyer * fireball = new Flyer();
    fireball->setPixmap(QPixmap(":/materials/fireball.png"));
    fireball->setPos(x()+30,y()+30);    //火球产生位置
    QLineF start_aim(QPointF(x()+30,y()+30), attackAim);
    int angle = -1 * start_aim.angle();
    fireball->setRotation(angle);    //选择控制子弹方向
    game->scene->addItem(fireball);
}

void Dragon_Tower::get_target()
{
    Tower::get_target();
}
