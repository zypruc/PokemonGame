#include <QTimer>

#include "flyer.h"
#include "game.h"
#include "kabitower.h"

extern Game* game;
KabiTower::KabiTower()
{
    flyerSpeed = 25;
    power = 35;
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(getTarget()));
    timer->start(900);  //fire rate
}


void KabiTower::fire()
{
    //怪物血量100
    Flyer * attack = new Flyer(power, 'n', 25);
    attack->setPixmap(QPixmap(":/materials/energyball.png"));
    attack->setPos(x()+20,y()+20);
    QLineF startToAim(QPointF(x()+20,y()+20),
                     QPointF(attackAim.x()+20,attackAim.y()+20));
    int angle = -1 * startToAim.angle();
    attack->setRotation(angle);
    game->scene->addItem(attack);
}


void KabiTower::upgrade(){
    level += 1;
    power += 6;
    flyerSpeed += 4;
    update();
}


int KabiTower::getUpgradePrice(){
    int upgradePrice = level * 100;
    return upgradePrice;
}

void KabiTower::setImage()
{
    setPixmap(QPixmap(":/materials/Kabi.png"));
}
