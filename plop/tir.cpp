#include "tir.h"

#include <iostream>
using namespace std ;

Tir::Tir(Point posinit,int angle, int anglec, int typeobus)
{
    this->angle=angle;
    this->anglec=anglec;
    this->typeobus=typeobus;
    this->posinit=posinit;
    this->posarrive=posarrive;
    this->posobus=posinit;
    this->obus.setPixmap(QPixmap(":/images/shell1.png"));

    distance= ((-abs(anglec-45)+45)/45)*W/3;

    posarrive.setx(posinit.getx()+((float)distance)*cos(angle));
    posarrive.sety(posinit.gety()+((float)distance)*sin(angle));

    coefdir=((float)(posinit.gety()-posarrive.gety()))/((float)(posinit.getx()- posarrive.getx()));
    cout<<coefdir<<endl;
    ordori=-coefdir*posarrive.getx()+posarrive.gety();
}

Tir::~Tir()
{

}

int Tir::trajectoire(QGraphicsScene* scene)
{
    cout<<posinit.getx()<<";"<<posinit.gety()<<endl;
    cout<<posarrive.getx()<<";"<<posarrive.gety()<<endl;
    cout<<coefdir<<endl;

    int x,y;
    x=posarrive.getx();
    y=posarrive.gety();

    bool en_cours=true;
    float compteur=0;
    scene->addItem(&obus);
    while(en_cours)
    {
        compteur+=coefdir;

        while(abs(compteur)>1)
        {
            if(compteur>0)
                compteur-=1;
            else
                compteur+=1;
            posobus.sety(posobus.gety()+1);
            obus.setPos(obus.x(),posobus.gety()*5);
            if(posobus.getx()==posarrive.getx()&&posobus.gety()==posarrive.gety())
                impact();
            attendre(200);
        }
        posobus.setx(posobus.getx()+1);
        obus.setPos(posobus.getx()*5,obus.y());
        if(posobus.getx()==posarrive.getx()&&posobus.gety()==posarrive.gety())
            impact();
        attendre(200);
    }
    return 0;
}

void Tir::impact()
{

}

