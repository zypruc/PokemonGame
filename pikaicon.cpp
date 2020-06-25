#include "pikaicon.h"
#include "game.h"
#include "pikatower.h"

extern Game * game;

PikaIcon::PikaIcon(QGraphicsItem *p):QGraphicsPixmapItem(p)
{
    PRICE = 200;
    setPixmap(QPixmap(":/materials/pikachu.png"));
}

void PikaIcon::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if (!game->building && game->score->getScore() >= PRICE){
        game->score->decrease(PRICE);
        game->building = new PikaTower();
        game->setCursor(QString(":/materials/pikachu.png"));
    }
}
