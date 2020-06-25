#ifndef PIKA_ICON_H
#define PIKA_ICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class PikaIcon: public QGraphicsPixmapItem
{
public:
    int PRICE;
    PikaIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // PIKA_ICON_H
