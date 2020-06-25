#include <QTimer>
#include "pikatower.h"
#include "flyer.h"
#include "game.h"

extern Game* game;

PikaTower::PikaTower()
{
    flyerSpeed = 23;
    power = 20;
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(getTarget()));
    timer->start(420);  //fire rate
}


void PikaTower::fire()
{
    //怪物血量100
    Flyer * thund = new Flyer(power, 't', flyerSpeed);
    thund->setPixmap(QPixmap(":/materials/thunder.png"));
    thund->setPos(x()+18,y()+20);
    QLineF startToAim(QPointF(x()+18,y()+20),
                     QPointF(attackAim.x()+20,attackAim.y()+20));
    int angle = -1 * startToAim.angle();
    thund->setRotation(angle);
    game->scene->addItem(thund);
}


void PikaTower::upgrade(){
    level += 1;
    power += 6;
    flyerSpeed += 5;
    update();
}


int PikaTower::getUpgradePrice(){
    int upgradePrice = level * 100;
    return upgradePrice;
}


void PikaTower::setImage()
{
    setPixmap(QPixmap(":/materials/pikachu.png"));
}
