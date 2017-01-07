#include "tir.h"

Tir::Tir(Point posinit, Point posarrive ,int angle, int anglec, int typeobus)
{
    this->angle=angle;
    this->anglec=anglec;
    this->typeobus=typeobus;
    this->posinit=posinit;
    this->posarrive=posarrive;

    distance= ((-abs(anglec-45)+45)/45)*W/3;

    posarrive.setx(posinit.getx()+distance*cos(angle));
    posarrive.sety(posinit.gety()+distance*sin(angle));

    d_a=(posinit.gety()- posarrive.gety())/(posinit.getx()- posarrive.getx());
    d_b=-d_a*posarrive.getx()+posarrive.gety();
}

int Tir::trajectoire()
{
    int x,y;
    x=posinit.getx();
    y=posinit.gety();

    while(posobus!=posarrive)
    {

    }
}

