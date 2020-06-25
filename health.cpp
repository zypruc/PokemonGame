#include "health.h"
#include <QPixmap>
#include <QFont>
Health::Health(int initHealth, QGraphicsItem *parent)
    : QGraphicsTextItem(parent), health(initHealth)
{
    setPlainText(QString(":") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Menlo",22));
}

void Health::decrease(){
    health -= 1;
    setPlainText(QString(":") + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
