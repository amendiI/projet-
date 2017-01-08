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
    this->obus.setPixmap(QPixmap(":/images/shell1.png"));

    distance= ((-abs(anglec-45)+45)/45)*W/3;

    posarrive.setx(posinit.getx()+((float)distance)*cos(angle));
    posarrive.sety(posinit.gety()+((float)distance)*sin(angle));

    coefdir=((float)(posinit.gety()-posarrive.gety()))/((float)(posinit.getx()- posarrive.getx()));
    ordori=-coefdir*posarrive.getx()+posarrive.gety();
}

Tir::~Tir()
{

}

int Tir::trajectoire(QGraphicsScene* scene)
{
    int x,y;
    x=posarrive.getx();
    y=posarrive.gety();

    bool en_cours=true;
    float compteur=0;
    scene->addItem(&obus);
    while(en_cours)
    {
        compteur+=coefdir;

        while(compteur>1)
        {
            compteur-=1;
            posobus.sety(posobus.gety()+1);
            obus.setPos(obus.x(),posobus.gety()*5);
            if(posobus.getx()==posarrive.getx()||posobus.gety()==posarrive.gety())
                impact();
            attendre(200);
        }
        posobus.setx(posobus.getx()+1);
        obus.setPos(posobus.getx()*5,obus.y());
        if(posobus.getx()==posarrive.getx()||posobus.gety()==posarrive.gety())
            impact();
        attendre(200);
    }
    return 0;
}

void Tir::impact()
{

}

