/**flyer.cpp
飞行物
**/
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include <stdlib.h>


#include "flyer.h"
#include "game.h"
#include "enemybase.h"
#include "enemymonkey.h"
#include "enemygengar.h"
#include "enemybat.h"
#include "enemykyogre.h"
#include "enemyrocksnake.h"
#include "enemyrockgod.h"
#include "enemygrassman.h"

extern Game* game;

Flyer::Flyer():damage(1),attribute('n'),stepLen(5)
{
    setPixmap(QPixmap(":/materials/fireball.png"));
    //设置飞行物贴图
    //记录飞行道具移动的timer
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(40);  //40-越小越快

}

Flyer::Flyer(int Dmg, char Attr, int Step)
    :damage(Dmg), attribute(Attr), stepLen(Step){
    setPixmap(QPixmap(":/materials/fireball.png"));
    //设置飞行物贴图
    //记录飞行道具移动的timer
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(40);  //40-越小越快
}

void Flyer::setAttribute(char c){
    attribute = c;
}

void Flyer::setSTEP(int x){
    stepLen = x;
}


void Flyer::setDMG(int d){
    damage = d;
}

void Flyer::move(){
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        // 遇到火爆猴时
        if (typeid(*colliding_items[i]) == typeid(EnemyMonkey))
        {
            EnemyMonkey *monkey = dynamic_cast<EnemyMonkey *>(colliding_items[i]);
            //累计2次攻击后，愤怒状态
            monkey->increaseHit();
            if(monkey->getHit()>=2)
                monkey->getAngry();
            monkey->deductHP(getDMG());
            //如果打死
            if(monkey->getHP()<=0){
                game->score->increase(monkey->getBonus());
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }else{
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        //遇到耿鬼时
        else if (typeid(*colliding_items[i]) == typeid(EnemyGengar))
        {
            EnemyGengar *gengar = dynamic_cast<EnemyGengar *>(colliding_items[i]);
            gengar->deductHP(gengar->elementStrike(attribute, getDMG()));
            int chanceJump = rand()%10;
            if (chanceJump <= 1){
                gengar->indexJump();
                scene()->removeItem(this);  //移除子弹图片
                delete this;                //删除子弹
                return;
            }
            gengar->getParalyzed(attribute);
            if(gengar->getHP()<=0){
                game->score->increase(gengar->getBonus());
                scene()->removeItem(colliding_items[i]);    //删除被打死
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
        else if (typeid(*colliding_items[i]) == typeid(EnemyBat))
        {
            EnemyBat *bat = dynamic_cast<EnemyBat *>(colliding_items[i]);
            bat->deductHP(bat->elementStrike(attribute, getDMG()));
            if (bat->getHP()<=0) {
                game->score->increase(bat->getBonus());
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            } else {
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        else if (typeid(*colliding_items[i]) == typeid(EnemyKyogre))
        {
             EnemyKyogre *kyogre = dynamic_cast<EnemyKyogre *>(colliding_items[i]);
             kyogre->deductHP(kyogre->elementStrike(attribute, getDMG()));
             if (kyogre->getHP()<=0) {
                 game->score->increase(kyogre->getBonus());
                 scene()->removeItem(colliding_items[i]);
                 scene()->removeItem(this);
                 delete colliding_items[i];
                 delete this;
                 return;
             } else {
                 scene()->removeItem(this);
                 delete this;
                 return;
             }
        }
        else if (typeid(*colliding_items[i]) == typeid(EnemyRockSnake)
                   ||typeid(*colliding_items[i]) == typeid(EnemyRockGod))
        {
            EnemyRockSnake *snake = dynamic_cast<EnemyRockSnake *>(colliding_items[i]);
            snake->deductHP(snake->elementStrike(attribute, getDMG()));
            if(snake->getHP()<=0){
                game->score->increase(snake->getBonus());
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }else{
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        else if (typeid(*colliding_items[i]) == typeid(EnemyGrassMan)) {
            EnemyGrassMan *grass = dynamic_cast<EnemyGrassMan *>(colliding_items[i]);
            grass->deductHP(grass->elementStrike(attribute, getDMG()));
            if(grass->getHP()<=0){
                game->score->increase(grass->getBonus());
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                delete colliding_items[i];
                delete this;
                return;
            }else{
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }
    //当没有碰撞时继续移动，飞出地图时删除
    setPos(x(),y());
    if (pos().y()<10||pos().y()>746||pos().x()<10||pos().x()>940) {
        scene()->removeItem(this);
        delete this;
        return;
    }
    //控制飞行道具继续移动
    double theta = rotation(); //degrees
    double y_step = stepLen*qSin(qDegreesToRadians(theta));
    double x_step = stepLen*qCos(qDegreesToRadians(theta));
    setPos(x()+x_step, y()+y_step);
}


