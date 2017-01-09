#ifndef TIR_H
#define TIR_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

#include "grilleterrain.h"
#include "math.h"
#include "point.h"
#include "option.h"

class Tir:QObject
{
private:
    Grilleterrain* tab;
    Point posobus;
    Point posinit;
    Point posarrive;
    int angle;
    int anglec;
    int typeobus;
    int ordori;
    float coefdir;
    int distance;

    //pour le chrono
    float compteur;
    QTimer* timer;


public:
    Tir(Point posinit, int angle, int anglec, int typeobus, Grilleterrain* tab);
    ~Tir();
    int trajectoire(QGraphicsScene *scene);
    void impact(Point p);
    bool testfin();
};

#endif // TIR_H
