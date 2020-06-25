#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health:public QGraphicsTextItem
{
public:
    Health( int initHealth=10, QGraphicsItem * parent=0);
    void decrease();
    int getHealth();
    void setHealth(int initHealth){ health=initHealth; }
private:
    int health;
};

#endif // HEALTH_H
