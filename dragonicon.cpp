#include "dragonicon.h"
#include "game.h"
#include "dragontower.h"
#include <qdebug.h>

extern Game * game;
DragonIcon::DragonIcon(QGraphicsItem *p):QGraphicsPixmapItem(p)
{
    PRICE = 100;
    setPixmap(QPixmap(":/materials/little_dragon.png"));
}

void DragonIcon::mousePressEvent(QGraphicsSceneMouseEvent *e){
    qDebug() << "DragonIcon MousePressEvent";
    if (e->button() == Qt::LeftButton){
        if (!game->building && game->score->getScore() >= PRICE) {
            game->score->decrease(PRICE);
            game->building = new DragonTower();
            game->setCursor(QString(":/materials/little_dragon.png"));
        }
    }else{
        QGraphicsPixmapItem::mousePressEvent(e);
    }
}
