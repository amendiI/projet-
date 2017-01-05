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
using namespace std;

//hérite de Qwidget pour le focus
class Tank:public QGraphicsPixmapItem
{
private:
    QGraphicsPixmapItem  spriteCaisse;
    QGraphicsPixmapItem  spriteTourelle;
    int angle;
    int obus2;
    int obus3;
    int pv;

public:
    Tank();
    void keyPressEvent(QKeyEvent* event);
    void afficheTank(QGraphicsScene *scene);
    void deplacement(Point p);

    int getobus2();
    int getobus3();

    void setfocuscaisse();
    void setfocustourelle();

};




#endif // TANK_H
