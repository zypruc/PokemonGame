#include "dragontower.h"
#include <QTimer>
#include "flyer.h"
#include "game.h"
extern Game *game;
DragonTower::DragonTower(QGraphicsItem* parent)
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(2000);  //fire rate
}
void DragonTower::fire()
{

    Flyer * flyer = new Flyer();
    flyer->setPixmap(QPixmap(":/materials/fireball.png"));
    flyer->setPos(x()+40,y()+50);



    QLineF ln(QPointF(x()+40,y()+50), attack_dest);
    int angle = -1 * ln.angle();
    flyer->setRotation(angle);
    game->scene->addItem(flyer);
}

void DragonTower::aquire_target()
{
    Tower::aquire_target();
}
