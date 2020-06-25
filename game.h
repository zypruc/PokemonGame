#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <qvector.h>

#include "tower.h"
#include "health.h"
#include "score.h"

class Game: public QGraphicsView{
    Q_OBJECT
protected:
    int enemyCreated;   //记录已经产生的敌人
    int maximumEnemies; //敌人数量限制
public:
    Game();
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void setCursor(QString fileAddress);
    void addBGM();
    void addHealth();
    void addScore();
    void addCost();
    void addIcon();

    QGraphicsScene* scene;
    QGraphicsPixmapItem* cursor;
    Tower* building;
    QList<QPointF> pointsPath;
    QVector<Tower*> towers;
    QTimer* createTimer;
    Score* score;
    Health* health;



public slots:
    void creat1Enemy();
    void createEnemies(int);
    void ifEnd();
};

#endif // GAME_H
