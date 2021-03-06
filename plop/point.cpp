#include "Point.h"
#include <iostream>

using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(int xx, int yy )
{
	x = xx;
	y = yy;
}

Point::Point(const Point& p)
{
	x = p.getx();
	y = p.gety();
}

int Point::getx() const
{
	return x;
}

int Point::gety() const
{
	return y;
}

void Point::afficher()
{
	cout << "x="<<x << endl;
	cout << "y="<<y << endl;
}

void Point::cloner(const Point& p)
{
	x = p.getx();
	y = p.gety();
}

Point::~Point()
{
}
void Point::setx(int v)
{
	x=v;
}
void Point::sety(int v)
{
        y=v;
}
