#ifndef DRAGONTOWER_H
#define DRAGONTOWER_H

#include "tower.h"
#include <QTimer>

class DragonTower:public Tower
{
    Q_OBJECT
public slots:
    void getTarget();
public:
    DragonTower();
    int getUpgradePrice() override;
    void fire() override;
    void upgrade() override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setImage() override;
};
#endif // DRAGONTOWER_H
