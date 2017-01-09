#ifndef TANK_H
#define TANK_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>

#include "option.h"
#include "Point.h"
#include "tourelle.h"
#include "grilleterrain.h"
#include "hitbox.h"

using namespace std;

#include <iostream>

class Tank: public QGraphicsPixmapItem
{
private:
    Tourelle *tourelle;
    int angle;
    int pm;
    Point centre;
    Grilleterrain* tab;
    Hud* hud;
    QGraphicsScene *scene;
    string nomTank;

public:
    Tank(Grilleterrain* grille, string nomTank, Point pos, QGraphicsScene *scene, Hud *mainhud);
    ~Tank();
    void afficheTank(QGraphicsScene *scene);
    void visee();
    void deplacement();
    bool hitbox(Point p);
    bool estVivant();
    void keyPressEvent(QKeyEvent* event);
    void setAngle(int x){angle=x;}
    void setPm(int x){pm=x;}
    Tourelle* getTourelle(){return tourelle;}
    int getPm(){return pm;}
    int getAngle(){return angle;}
    Point getcentre(){return centre;}
    bool peutBouger(Grilleterrain *tab);
    bool hitbox(int x,int y);

};




#endif // TANK_H
