#include <QApplication>
#include <QTimer>
#include <QPen>
#include <QGraphicsLineItem>
#include <QtCore/QCoreApplication>
#include <QtMultimedia/QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QFont>
#include <QLabel>

#include "dragon_tower.h"
#include "game.h"
#include "enemy.h"
#include "flyer.h"
#include "dragonicon.h"
#include "tower.h"

Game::Game(): QGraphicsView()
{
    //初始化整个游戏界面
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/materials/map.jpg")));
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/materials/bgm.mp3"));
    bgm->play();

    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);
    //设置鼠标的图片
    setCursor(":/materials/cursor.png");
    setFixedSize(1024,770);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 窗口大小

    //摆放Score
    score = new Score();
    score->setPos(score->x()+48,score->y()+80);
    scene->addItem(score);

    //添加生命值要素
    health = new Health();
    health->setPos(health->x()+48,health->y()+40);
    scene->addItem(health);
    QGraphicsPixmapItem * heartPicture = new QGraphicsPixmapItem();
    heartPicture->setPixmap(QPixmap(":/materials/heart"));
    heartPicture->setPos(2, 40);
    scene->addItem(heartPicture);



    //炮塔价格放在右边
    QGraphicsTextItem* cost_tower = new QGraphicsTextItem(QString("$100 \n\n"));
    QFont costFont("Menlo", 34);
    cost_tower->setFont(costFont);
    int text_x = 645;
    int text_y = 30;
    cost_tower->setPos(text_x,text_y);
    cost_tower->setDefaultTextColor(Qt::red);
    scene->addItem(cost_tower);
    //添加可选炮塔
    createTimer = new QTimer(this);
//    waveTimer = new QTimer(this);
    enemyCreated = 0;
    maximumEnemies = 0;
    // 按照顺序从起点->终点
    pointsPath << QPointF(278, 5)
               << QPointF(278,350)
               << QPointF(870,350)
               << QPointF(870,570)
               << QPointF(540,570)
               << QPointF(540,750);
    //添加可以点击的炮塔
    dragonIcon *dragon = new dragonIcon();//指向小火龙图标
    dragon->setPos(732, 5);
    scene->addItem(dragon);
    //初始化整个游戏界面
    createEnemies(100);
}

void Game::setCursor(QString filename)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(QPixmap(filename)));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor)
        cursor->setPos(event->pos());
}

void Game::mousePressEvent(QMouseEvent *event)
{

    if (building){
        // 如果点击到了塔
        QList<QGraphicsItem*> items = cursor->collidingItems();
        for (size_t i=0, n=items.size(); i<n; ++i){
            if (dynamic_cast<Tower*>(items[i])){
                return;
            }
        }

        scene->addItem(building);
        building->setPos(event->pos());
        cursor = nullptr;
        building = nullptr;
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }
}

void Game::createEnemies(int number_Enemies)
{
    enemyCreated = 0;
    maximumEnemies = number_Enemies;

    connect(createTimer, SIGNAL(timeout()),this, SLOT(creat1Enemy()));
    createTimer->start(2000);  //spawn rate
}

void Game::creat1Enemy()
{
    //产生一个敌人
    Enemy* enemy = new Enemy(pointsPath);
    enemy->setPos(pointsPath[0]);   //起点
    scene->addItem(enemy);  //贴图
    enemyCreated++;
    if (enemyCreated >= maximumEnemies){
        createTimer->disconnect();
    }
}
