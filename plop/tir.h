#ifndef TIR_H
#define TIR_H

#include "math.h"
#include "point.h"
#include "option.h"
#include "time.h"

class Tir
{
private:
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
    int trajectoire();
    void impact();

};

#endif // TIR_H
