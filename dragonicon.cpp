/* dragonicon.cpp
 * 小火龙，仅仅用于建造
 */
#include "game.h"
#include "dragonicon.h"
#include "dragon_tower.h"

extern Game * game;
dragonIcon::dragonIcon(QGraphicsItem *p):QGraphicsPixmapItem(p)
{
    setPixmap(QPixmap(":/materials/little_dragon.png"));
}

void dragonIcon::mousePressEvent(QGraphicsSceneMouseEvent *e){
    if (!game->building && game->score->score >=100){
        game->score->decrease(100);
        game->building = new Dragon_Tower();
        game->setCursor(QString(":/materials/little_dragon.png"));
    }
}
