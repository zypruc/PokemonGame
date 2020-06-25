#ifndef KABIICON_H
#define KABIICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class KabiIcon: public QGraphicsPixmapItem
{
public:
    int PRICE;
    KabiIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // KABIICON_H
