#ifndef TIR_H
#define TIR_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "math.h"
#include "point.h"
#include "option.h"

class Tir
{
private:
    QGraphicsPixmapItem obus;
    Point posobus;
    Point posinit;
    Point posarrive;
    int angle;
    int anglec;
    int typeobus;
    int ordori;
    float coefdir;
    int distance;


public:
    Tir(Point posinit, Point posarrive,int angle,int anglec,int typeobus);
    ~Tir();
    int trajectoire(QGraphicsScene *scene);
    void impact();

};

#endif // TIR_H
