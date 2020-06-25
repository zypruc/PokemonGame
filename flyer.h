#ifndef FLYER_H
#define FLYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class Flyer
        : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Flyer();
    Flyer(int dmg, char Attr, int STEP);
    void setAttribute(char);
    void setSTEP(int);
    void setDMG(int);
    int getDMG() const{ return damage; }
public slots:
    void move();
protected:
    int damage;
    char attribute;
    int stepLen;

};

#endif // FLYER_H
