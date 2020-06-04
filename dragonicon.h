#ifndef DRAGONTOWER_H
#define DRAGONTOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class dragonIcon:public QGraphicsPixmapItem
{
public:
    dragonIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DRAGONTOWER_H
