#ifndef TANK_H
#define TANK_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>


#include <iostream>

#include "option.h"
#include "Point.h"
#include "caisse.h"
#include "tourelle.h"

class Tank
{
private:
    Caisse *caisse;
    Tourelle *tourelle;
    int obus2;
    int obus3;
    int pv;
    Point centre;
    //TODO marquer le centre

public:
    Tank();
    void afficheTank(QGraphicsScene *scene);
    void visee();
    void deplacement();
    int getobus2();
    int getobus3();
    bool hitbox(Point p);
};




#endif // TANK_H
