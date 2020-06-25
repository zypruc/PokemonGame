#include "kabiicon.h"
#include "game.h"
#include "kabitower.h"

extern Game * game;

KabiIcon::KabiIcon(QGraphicsItem *p): QGraphicsPixmapItem(p)
{
    PRICE = 100;
    setPixmap(QPixmap(":/materials/Kabi.png"));
}


void KabiIcon::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if (!game->building && game->score->getScore() >= PRICE){
        game->score->decrease(PRICE);
        game->building = new KabiTower();
        game->setCursor(QString(":/materials/Kabi.png"));
    }
}
