#ifndef FISHTOWER_H
#define FISHTOWER_H
#include "tower.h"
#include <QTimer>


class FishTower: public Tower
{
    Q_OBJECT
public:
    FishTower();
    void fire() override;
    void upgrade() override;
    void setImage()override;
    int getUpgradePrice() override;
};

#endif // FISHTOWER_H
