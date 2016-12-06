#pragma once
#include "Point.h"
class segment
{
private:
    Point p1;
    Point p2;

public:
    Point getp1()const;
    Point getp2()const;
    segment();
    segment(Point p1, Point p2);
    segment(const segment &s);
    ~segment();

    double longueur();
    bool estvertical();
    bool esthorizontal();
    bool estsurdiagonale();




};
