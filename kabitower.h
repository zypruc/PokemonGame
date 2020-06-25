#ifndef KABITOWER_H
#define KABITOWER_H
#include "tower.h"
#include <QTimer>

class KabiTower: public Tower
{
    Q_OBJECT
public:
    KabiTower();
    void fire() override;
    void upgrade() override;
    void setImage()override;
    int getUpgradePrice() override;
};

#endif // KABITOWER_H
