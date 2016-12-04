#pragma once
class Point
{
private:
    int x;
    int y;

public:
	Point();
    Point(int xx, int yy);
	Point(const Point& p);
	~Point();
    int  getx() const ;
    int  gety() const ;
    void setx(int v);
    void sety(int v);
	virtual void afficher();
	virtual void cloner(const Point& p);



};
