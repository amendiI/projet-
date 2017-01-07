#ifndef CAISSE_H
#define CAISSE_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "hitbox.h"
#include "option.h"
#include "Point.h"
#include "tourelle.h"
#include <iostream>

using namespace std;

class Caisse : public QGraphicsPixmapItem
{
private:
    Tourelle* tourelle;
    int angle;
    int pm;
    Point refHitbox;
public:
    Caisse();
    void deplacement();
    void keyPressEvent(QKeyEvent* event);
    void setAngle(int x){angle=x;}
    void setPm(int x){pm=x;}
    Tourelle* getTourelle(){return tourelle;}
    int getPm(){return pm;}
    int getAngle(){return angle;}
    bool peutBouger(int orientation);
    bool hitbox(Point impact);
};

#endif // CAISSE_H
