#include <QTimer>
#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>
#include<qabstractbutton.h>
#include <QMessageBox>
#include "flyer.h"
#include "game.h"
#include "dragontower.h"
extern Game* game;
QGraphicsItem *p;
DragonTower::DragonTower(): Tower(p)
{
    //参考普通怪物基准血量100

    flyerSpeed = 18;
    power = 28;
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(getTarget()));
    timer->start(700);  //攻击频率-越小越快
}

void DragonTower::fire()
{
    // 发射子弹
    if (level==1){
        Flyer * fireball = new Flyer(power, 'f', flyerSpeed);
        fireball->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball->setPos(x()+18,y()+20);    //火球初始位置
        QLineF start_aim(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()+30, attackAim.y()+30));
        int angle = -1 * start_aim.angle();
        fireball->setRotation(angle);    //选择控制子弹方向
        game->scene->addItem(fireball);
    } else if (level==2) {
        Flyer * fireball1 = new Flyer(power, 'f', flyerSpeed);
        Flyer * fireball2 = new Flyer(power, 'f', flyerSpeed);
        fireball1->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball2->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball1->setPos(x()+18,y()+20);    //火球初始位置
        fireball2->setPos(x()+18,y()+20);
        QLineF line1(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()+50, attackAim.y()+50));
        QLineF line2(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()-50, attackAim.y()-50));
        int angle1 = -1 * line1.angle();
        int angle2 = -1 * line2.angle();
        fireball1->setRotation(angle1);    //选择控制子弹方向
        fireball2->setRotation(angle2);    //选择控制子弹方向
        game->scene->addItem(fireball1);
        game->scene->addItem(fireball2);
    } else {
        Flyer * fireball1 = new Flyer(power, 'f', flyerSpeed);
        Flyer * fireball2 = new Flyer(power, 'f', flyerSpeed);
        Flyer * fireball3 = new Flyer(power, 'f', flyerSpeed);
        fireball1->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball2->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball3->setPixmap(QPixmap(":/materials/fireball.png"));
        fireball1->setPos(x()+18,y()+20);    //火球初始位置
        fireball2->setPos(x()+18,y()+20);
        fireball3->setPos(x()+18,y()+20);
        QLineF line1(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()+80, attackAim.y()));
        QLineF line2(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()-80, attackAim.y()));
        QLineF line3(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x(), attackAim.y()));
        int angle1 = -1 * line1.angle();
        int angle2 = -1 * line2.angle();
        int angle3 = -1 * line3.angle();
        fireball1->setRotation(angle1);
        fireball2->setRotation(angle2);
        fireball3->setRotation(angle3);
        game->scene->addItem(fireball1);
        game->scene->addItem(fireball2);
        game->scene->addItem(fireball3);
    }
}


void DragonTower::getTarget(){
    Tower::getTarget();
}

void DragonTower::upgrade()
{
    level += 1;
    power += 6;
    flyerSpeed += 4;
    if (level==2){
        setPixmap(QPixmap(":/materials/mid_dragon.png"));
    } else if (level==3){
        setPixmap(QPixmap(":/materials/mega_dragon.png"));
    }
    update();
}

int DragonTower::getUpgradePrice(){
    int upgradePrice = level * 200;
    return upgradePrice;
}

void DragonTower::setImage()
{
    setPixmap(QPixmap(":/materials/little_dragon.png"));
}

void DragonTower::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    QString level_info;
    level_info = QString("Level %1").arg(level);
    Tower::paint(painter, option, widget);
    painter->setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setFont(QFont("Menlo",12, QFont::Bold));
    painter->drawText(boundingRect().center() + QPointF(55, 25), level_info);
}
