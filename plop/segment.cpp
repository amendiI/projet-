#include "segment.h"
#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point segment::getp1() const { return p1; }
Point segment::getp2() const { return p2; }

segment::segment()
{
    p1 = Point();
    p2 = Point();
}

segment::segment(Point p1, Point p2)
{
    this->p1 = Point(p1);
    this->p2 = Point(p2);
}
segment::segment(const segment &s)
{
    this->p1 = s.getp1();
    p2 = s.getp2();
}

segment::~segment()
{
    cout << "segment d�truit" << endl;
}

double segment::longueur() { return p1.getx(); }

bool segment::estvertical()
{
    if (p1.getx() == p2.getx()) { return true; }
    return false;
}
bool segment::esthorizontal()
{
    if (this->p1.gety() == this->p2.gety()) { return true; }
    return false;
}
bool segment::estsurdiagonale()
{
    if (esthorizontal() && estvertical()){return false;}
    return true;
}
