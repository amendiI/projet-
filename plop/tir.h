#ifndef TIR_H
#define TIR_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>

#include "grilleterrain.h"
#include "math.h"
#include "point.h"
#include "option.h"

class Tir
{
private:
    Grilleterrain* tab;
    Point posobus;
    Point posinit;
    Point posarrive;
    int angle;
    int anglec;
    int typeobus;
    float coefdir;
    int distance;

    float compteur;


public:
    Tir(Point posinit, int angle, int anglec, int typeobus, Grilleterrain* tab);
    ~Tir();
    int trajectoire(QGraphicsScene *scene);
    void impact(Point p, tank t);
    bool testfin();
};

#endif // TIR_H
