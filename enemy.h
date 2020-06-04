#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QGraphicsItem>
class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(QList<QPointF> path, QGraphicsItem * parent=0);
    int hp; //生命值
public slots:

    void moveToPoint();
private:
    QList<QPointF> points;
    QPointF nextPosition;

    int indexPath;
    //在路线上第几个点
    bool ifDead;
    //判断是否被打死
    int score;
    int speed;  //移动速度
};

#endif // ENEMY_H
