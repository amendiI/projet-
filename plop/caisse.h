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
#include "grilleterrain.h"
#include <iostream>

using namespace std;

class Caisse : public QGraphicsPixmapItem
{
private:
    Tourelle* tourelle;
    int angle;
    int pm;
    Point centre;
public:
    Caisse();
    void deplacement();
    void keyPressEvent(QKeyEvent* event, Grilleterrain tab);
    void setAngle(int x){angle=x;}
    void setPm(int x){pm=x;}
    Tourelle* getTourelle(){return tourelle;}
    int getPm(){return pm;}
    int getAngle(){return angle;}
    Point getcentre(){return centre;}
    bool peutBouger(Grilleterrain tab);
    bool hitbox(int x,int y);
    void prendpos(Caisse *c);
};

#endif // CAISSE_H
