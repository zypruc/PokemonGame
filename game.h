/*
Game.h:
    产生界面：音乐、背景
    控制生命、分数元素的位置
    协调买卖“炮塔”
待补充：
    升级
    怪物血量
    暂停
*/

#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QMouseEvent>

#include "tower.h"
#include "health.h"
#include "enemy.h"
#include "score.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    Tower* building;
    QList<QPointF> pointsPath;
    QTimer* createTimer;
//    QTimer* waveTimer;
    int enemyCreated;   //记录已经产生的敌人
    int maximumEnemies; //敌人数量限制
    Score* score;
    Health* health;

public slots:
    void creat1Enemy();
    void createEnemies(int);
};

#endif // GAME_H
