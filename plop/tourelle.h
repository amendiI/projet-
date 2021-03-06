#ifndef TOURELLE_H
#define TOURELLE_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <string.h>
#include <iostream>

#include "tir.h"
#include "option.h"
#include "Point.h"
#include "hud.h"

using namespace std;

class Tourelle : public QGraphicsPixmapItem
{
private:
    int angle_tourelle;
    int angle_canon;
    int obus2;
    int obus3;
    string type;
    QGraphicsScene* scene;
    Hud* hud;
    Grilleterrain* tab;
    Point centre;
public:
    Tourelle(string nomTank,QGraphicsScene* scene,Hud* mainhud,Grilleterrain* tab,Point centre);
    void keyPressEvent(QKeyEvent* event);
    void set_angle_tourelle(int x){angle_tourelle=x;}
    void set_angle_canon(int x){angle_canon=x;}
    void setcentre(Point p){centre=p;}
    string getType(){return type;}
    int get_angle_tourelle(){return angle_tourelle;}
    int get_angle_canon(){return angle_canon;}

    int getobus2();
    int getobus3();
};

#endif // TOURELLE_H
