#include <QTimer>
#include <qdebug.h>
#include <QGraphicsSceneMouseEvent>
#include <qabstractbutton.h>
#include <QMessageBox>

#include "flyer.h"
#include "game.h"
#include "fishtower.h"
extern Game* game;

FishTower::FishTower()
{
    flyerSpeed = 18;
    power = 25;
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(getTarget()));
    timer->start(600);  //fire rate
}


void FishTower::fire()
{
    if (level==1) {
        return;
    } else if (level==2) {
        return;
    } else {
        Flyer * fireball1 = new Flyer(power, 'w', flyerSpeed);
        Flyer * fireball3 = new Flyer(power, 'w', flyerSpeed);
        fireball1->setPixmap(QPixmap(":/materials/waterAttack.png"));
        fireball3->setPixmap(QPixmap(":/materials/waterAttack.png"));
        fireball1->setPos(x()+18,y()+20);    //火球初始位置
        fireball3->setPos(x()+18,y()+20);
        QLineF line1(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x()+50, attackAim.y()+50));
        QLineF line3(QPointF(x()+18,y()+20),
                         QPointF(attackAim.x(), attackAim.y()));
        int angle1 = -1 * line1.angle();
        int angle3 = -1 * line3.angle();
        fireball1->setRotation(angle1);
        fireball3->setRotation(angle3);
        game->scene->addItem(fireball1);
        game->scene->addItem(fireball3);
    }
}


void FishTower::upgrade(){
    level += 1;
    power += 7;
    flyerSpeed += 5;
    if (level==3) {
        setPixmap(QPixmap(":/materials/FishDragon.png"));
    }
    update();
}


int FishTower::getUpgradePrice(){
    int upgradePrice = level * 100;
    return upgradePrice;
}


void FishTower::setImage()
{
    setPixmap(QPixmap(":/materials/Fish.png"));
}
