#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
#include "enemygrassman.h"

EnemyGrassMan::EnemyGrassMan(QList<QPointF> path) :EnemyBase(path)
{
    bonus = 50;
    hp = 120;
    speed = 18;
    setPixmap(QPixmap(":/materials/GrassMan.png"));
}

int EnemyGrassMan::elementStrike(char attribute, int damage){
    if (attribute == 'f'){
        this->setPixmap(QPixmap(":/materials/GrassManBurn.png"));
        return 2 * damage;
    }
    else if(attribute == 'n'){
        return damage;
    }
    else if(attribute == 'w'){
        return 0.5 * damage;
    }
    else{
        return damage;
    }
}
