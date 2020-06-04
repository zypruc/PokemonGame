#include "health.h"
#include <QPixmap>
#include <QFont>
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // 初始生命值
    health = 50;
    // 描述生命
    setPlainText(QString(":") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("Menlo",22));
}

void Health::decrease(){
    health -= 1;
    setPlainText(QString(":") + QString::number(health)); // Health: 2
}

int Health::get_health(){
    return health;
}
