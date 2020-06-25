#include "fishicon.h"
#include "game.h"
#include "fishtower.h"

extern Game * game;

FishIcon::FishIcon(QGraphicsItem *p): QGraphicsPixmapItem(p)
{
    PRICE = 100;
    setPixmap(QPixmap(":/materials/Fish.png"));
}


void FishIcon::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if (!game->building && game->score->getScore() >= PRICE){
        game->score->decrease(PRICE);
        game->building = new FishTower();
        game->setCursor(QString(":/materials/Fish.png"));
    }
}
