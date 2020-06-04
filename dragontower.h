
#ifndef DRAGONTOWER_H
#define DRAGONTOWER_H

#include "tower.h"
#include <QTimer>

class DragonTower: public Tower
{
    Q_OBJECT
public:
    DragonTower(QGraphicsItem* parent = 0);
    void fire();
public slots:
    void aquire_target();
};

#endif // DRAGONTOWER_H
