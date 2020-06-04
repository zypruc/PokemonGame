/**
    炮塔射出的飞行物
**/
#ifndef FLYER_H
#define FLYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Flyer: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Flyer();
public slots:
    void move();
private:
};

#endif // FLYER_H
