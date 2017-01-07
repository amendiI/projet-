#include "tir.h"

#include <iostream>
using namespace std ;

Tir::Tir(Point posinit, Point posarrive ,int angle, int anglec, int typeobus)
{
    this->angle=angle;
    this->anglec=anglec;
    this->typeobus=typeobus;
    this->posinit=posinit;
    this->posarrive=posarrive;

    distance= ((-abs(anglec-45)+45)/45)*W/3;

    posarrive.setx(posinit.getx()+((float)distance)*cos(angle));
    posarrive.sety(posinit.gety()+((float)distance)*sin(angle));

    coefdir=((float)(posinit.gety()-posarrive.gety()))/((float)(posinit.getx()- posarrive.getx()));
    ordori=-coefdir*posarrive.getx()+posarrive.gety();
}

int Tir::trajectoire()
{
    int x,y;
    x=posinit.getx();
    y=posinit.gety();

    bool en_cours=true;
    float compteur;


    //while(en_cours)
    {
        compteur+=coefdir;
        int i=0;
        time_t t=time(NULL);
        while(t)
        {
             cout<<("pwet")<<endl;
             i++;
        }
    }
    return 0;
}

