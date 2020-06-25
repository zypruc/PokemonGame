#ifndef DRAGONICON_H
#define DRAGONICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
class DragonIcon:public QGraphicsPixmapItem
{
public:
    int PRICE;
    DragonIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DRAGONICON_H
