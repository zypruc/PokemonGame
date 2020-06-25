#include <QApplication>
#include <QTimer>
#include <QPen>
#include <QGraphicsLineItem>
#include <QtCore/QCoreApplication>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <qmessagebox.h>
#include <qabstractbutton.h>
#include <QFont>
#include <QLabel>
#include <stdlib.h>

#include "game.h"
#include "flyer.h"
#include "tower.h"

#include "dragonicon.h"
#include "dragontower.h"
#include "pikaicon.h"
#include "pikatower.h"
#include "kabiicon.h"
#include "kabitower.h"
#include "fishicon.h"
#include "fishtower.h"

#include "enemymonkey.h"
#include "enemygengar.h"
#include "enemybat.h"
#include "enemykyogre.h"
#include "enemyrocksnake.h"
#include "enemyrockgod.h"
#include "enemygrassman.h"

Game::Game(): QGraphicsView()
{
    //初始化整个游戏界面
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/materials/map.jpg")));
    //BGM
    addBGM();
    cursor = nullptr;
    building = nullptr;
    setMouseTracking(true);

    // 窗口大小
    setFixedSize(1024,770);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //添加分数要素
    addScore();

    //添加生命值要素
    addHealth();

    //添加花费要素
    addCost();

    //添加可选炮塔
    createTimer = new QTimer(this);

    enemyCreated = 0;
    maximumEnemies = 0;

    // 按照顺序从起点->终点
    pointsPath << QPointF(270, 5) << QPointF(270,350)
               << QPointF(870,350) << QPointF(870,570)
               << QPointF(540,570) << QPointF(540,750);
    addIcon();

    //初始化整个游戏界面
    createEnemies(1000);
    ifEnd();
}


void Game::addBGM(){
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/materials/bgmRelax.mp3"));
    playlist->addMedia(QUrl("qrc:/materials/bgmRelax.mp3"));
    playlist->addMedia(QUrl("qrc:/materials/bgmGod.mp3"));
    playlist->addMedia(QUrl("qrc:/materials/bgmFight.mp3"));
    playlist->addMedia(QUrl("qrc:/materials/bgmFight2.mp3"));
    playlist->addMedia(QUrl("qrc:/materials/bgmFight.mp3"));
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setPlaylist(playlist);
    bgm->play();
}


void Game::addHealth(){
    health = new Health(10);
    health->setPos(health->x()+48,health->y()+40);
    health->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(health);
    QGraphicsPixmapItem * heartPicture = new QGraphicsPixmapItem();
    heartPicture->setPixmap(QPixmap(":/materials/heart"));
    heartPicture->setPos(2, 40);
    heartPicture->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(heartPicture);
}


void Game::addScore(){
    score = new Score(400);
    score->setPos(score->x()+48,score->y()+84);
    score->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(score);
    QGraphicsPixmapItem * starPicture = new QGraphicsPixmapItem();
    starPicture->setPixmap(QPixmap(":/materials/star"));
    starPicture->setPos(2, 80);
    score->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(starPicture);
}


void Game::addIcon(){
    DragonIcon * dragon = new DragonIcon();
    PikaIcon * pika = new PikaIcon();
    KabiIcon * kabi = new KabiIcon();
    FishIcon *fish = new FishIcon();

    dragon->setPos(662, 5);
    pika->setPos(672, 80);
    kabi->setPos(645, 160);
    fish->setPos(812, 5);

    scene->addItem(dragon);
    scene->addItem(pika);
    scene->addItem(kabi);
    scene->addItem(fish);
}


void Game::addCost(){
    QGraphicsTextItem* costTower = new QGraphicsTextItem(QString("$100 \t $100\n\n"
                                                                 "$150 \n\n"
                                                                 "$100 \n\n"));
    QFont costFont("Menlo", 34);
    costTower->setFont(costFont);
    int text_x = 565;
    int text_y = 30;
    costTower->setPos(text_x,text_y);
    costTower->setDefaultTextColor(Qt::red);
    costTower->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(costTower);
}


void Game::setCursor(QString fileAddress)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(QPixmap(fileAddress)));
    cursor->setAcceptedMouseButtons(Qt::NoButton);
    scene->addItem(cursor);
}


void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor)
        cursor->setPos(event->pos().x()-10, event->pos().y()-10);
    QGraphicsView::mouseMoveEvent(event);
}


void Game::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        if (building){
            qDebug() << "鼠标当前位置" << event->x() << ' ' << event->y();
            QList<QGraphicsItem*> items = cursor->collidingItems();
            for (size_t i=0, n=items.size(); i<n; ++i){
                if (dynamic_cast<Tower*>(items[i])){
                    return;
                }
            }
            building->setPos(event->pos());
            building->setImage();
            scene->addItem(building);
            scene->addItem(building);
            towers.push_back(building);
            scene->removeItem(cursor);
            cursor = nullptr;
            building = nullptr;
        }
    }else if (event->button()==Qt::RightButton){
        qDebug() << "Right Button";
        for (const auto& tower : towers)
        {

            QPointF temp = tower->pos() - event->pos();
            qDebug() << "Tower pos = " << tower->pos() << ", event pos = " << event->pos();
            if (temp.x() * temp.x() + temp.y() * temp.y() < 3600)
            {
                QMessageBox info(QMessageBox::Information, "Modify", "Upgrade or Remove(50score)");
                //// 插入价格
                info.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                info.button(QMessageBox::Yes)->setText("Upgrade");
                info.button(QMessageBox::No)->setText("Remove");
                int res = info.exec();
                if (res == QMessageBox::Yes){
                    if (score->getScore() >= tower->getUpgradePrice()) {
                        score->decrease(tower->getUpgradePrice());
                        tower->upgrade();
                    } else {
                        QMessageBox::information(nullptr, "MoneyNotEnough", "Your Score Not Enough");
                    }
                }
                else
                {
                    score->increase(50);
                    scene->removeItem(tower);
                }
            }
        }

    }
    QGraphicsView::mousePressEvent(event);
}


void Game::createEnemies(int numberEnemies)
{
    enemyCreated = 0;
    maximumEnemies = numberEnemies;
    connect(createTimer, SIGNAL(timeout()),this, SLOT(creat1Enemy()));
    createTimer->start(1500);  //spawn rate
}


void Game::creat1Enemy()
{
    int hpPlus = enemyCreated / 2;
    // 随着产生怪物数量增加血量

    int randomEnemyType = rand()%100;
    // 使用随机数字控制产生比例

    if (randomEnemyType<=20) {
        EnemyMonkey * monkey = new EnemyMonkey(pointsPath);
        monkey->setPos(pointsPath[0]);
        monkey->setHP(monkey->getHP()+hpPlus);
        scene->addItem(monkey);
    }
    else if (randomEnemyType<=40)
    {
        EnemyGrassMan * grass = new EnemyGrassMan(pointsPath);
        grass->setPos(pointsPath[0]);
        grass->setHP(grass->getHP()+hpPlus);
        scene->addItem(grass);
    }
    else if(randomEnemyType<=60)
    {
        EnemyGengar *gengar = new EnemyGengar(pointsPath);
        gengar->setPos(pointsPath[0]);
        gengar->setHP(gengar->getHP()+hpPlus);
        scene->addItem(gengar);
    }
    else if (randomEnemyType<=80)
    {
        int strongEnemyChance = rand()%100;
        if (strongEnemyChance == 1) {
            EnemyRockGod *rock = new EnemyRockGod(pointsPath);
            rock->setPos(pointsPath[0]);
            rock->setHP(rock->getHP()+hpPlus);
            scene->addItem(rock);
        }
        else{
            EnemyRockSnake *rock = new EnemyRockSnake(pointsPath);
            rock->setPos(pointsPath[0]);
            rock->setHP(rock->getHP()+hpPlus);
            scene->addItem(rock);
        }

    }
    else if(randomEnemyType<=100)
    {
        EnemyBat *bat =  new EnemyBat(pointsPath);
        bat->setPos(pointsPath[0]);
        bat->setHP(bat->getHP()+hpPlus);
        scene->addItem(bat);
    }
    if (randomEnemyType==99||randomEnemyType==98)
    {
        EnemyKyogre *kyogre = new EnemyKyogre(pointsPath);
        kyogre->setPos(pointsPath[0]);
        kyogre->setHP(kyogre->getHP()+hpPlus);
        scene->addItem(kyogre);
    }
    if (enemyCreated >= maximumEnemies){
        createTimer->disconnect();
    }
    enemyCreated++;
    return;
}


void Game::ifEnd()
{
    //// 待修改timer
//    QTimer * timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()),this, SLOT(creat1Enemy));
//    timer->start(1000);
    if (health->getHealth() > 0) {
        return;
    } else if (health->getHealth() <= 0) {
        QGraphicsTextItem* gameOver = new QGraphicsTextItem(QString("Game Over"));
        QGraphicsPixmapItem * loseFlag = new QGraphicsPixmapItem();
        QFont gameOverFont("Menlo", 64);
        gameOver->setFont(gameOverFont);
        int text_x = 360;
        int text_y = 500;
        gameOver->setPos(text_x,text_y);
        gameOver->setDefaultTextColor(Qt::red);
        gameOver->setAcceptedMouseButtons(Qt::NoButton);
        loseFlag->setPixmap(QPixmap(":/materials/loseFlag"));
        loseFlag->setPos(350, 140);
        loseFlag->setAcceptedMouseButtons(Qt::NoButton);
        scene->addItem(loseFlag);
        scene->addItem(gameOver);
        createTimer->disconnect();
        return;
    }
}
