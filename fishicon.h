#ifndef FISHICON_H
#define FISHICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class FishIcon: public QGraphicsPixmapItem
{
public:
    int PRICE;
    FishIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // FISHICON_H
