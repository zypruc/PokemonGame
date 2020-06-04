#ifndef DRAGON_TOWER_H
#define DRAGON_TOWER_H

#include "tower.h"
#include <QTimer>
class Dragon_Tower: public Tower
{
    Q_OBJECT
public:
    Dragon_Tower();
    void fire();
public slots:
    void get_target();
};

#endif // DRAGON_TOWER_H
