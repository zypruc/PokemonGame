#ifndef PIKA_TOWER_H
#define PIKA_TOWER_H


#include "tower.h"
#include <QTimer>
class PikaTower: public Tower
{
    Q_OBJECT
public:
    PikaTower();
    void fire() override;
    void upgrade() override;
    void setImage()override;
    int getUpgradePrice() override;
};

#endif // PIKA_TOWER_H
