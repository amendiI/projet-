#include "tir.h"

#include <iostream>
using namespace std ;

Tir::Tir(Point posinit,int angle, int anglec, int typeobus,Grilleterrain* tab)
{
    this->angle=angle;
    this->anglec=anglec;
    this->typeobus=typeobus;
    this->posinit=posinit;
    this->posarrive=posarrive;
    this->posobus=posinit;
    this->tab=tab;

    distance= (-abs(anglec-25)+45);

    posarrive.setx(posinit.getx()+((float)distance)*cos(angle*PI/180));
    posarrive.sety(posinit.gety()+((float)distance)*sin(angle*PI/180));



    coefdir=((float)(posinit.gety()-posarrive.gety()))/((float)(posinit.getx()- posarrive.getx()));

    ordori=-coefdir*posarrive.getx()+posarrive.gety();

    cout<<posarrive.getx()<<";"<<posarrive.gety()<<endl;
}

Tir::~Tir()
{

}

int Tir::trajectoire(QGraphicsScene* scene)
{

    compteur=0;
    bool en_cours=true;
    cout<<"depart"<<endl;
    while(en_cours)
    {
        compteur+=coefdir;

        while(abs(compteur)>1)
        {
            if(compteur>0)
                compteur-=1;
            else
                compteur+=1;
            cout<<"changey"<<endl;
            posobus.sety(posobus.gety()+1);
            if(posobus.getx()== posarrive.getx()&& posobus.gety()== posarrive.gety())//si l'obus arrive a la fin de son voyage
                en_cours= false;
            cout<<"opo"<<endl;

        }

        posobus.setx(posobus.getx()+1);
        //en_cours=testfin();
        if(posobus.getx()== posarrive.getx()&& posobus.gety()== posarrive.gety())//si l'obus arrive a la fin de son voyage
            en_cours= false;
    }


    cout<<"fin en "<<posobus.getx()<<";"<<posobus.gety()<<endl;
    impact(posobus);

return 0;
}

void Tir::impact(Point p)
{
    tab->changeterrain(p.getx(),p.gety());
}

bool Tir::testfin()
{
    if(posobus.getx()== posarrive.getx()&& posobus.gety()== posarrive.gety())//si l'obus arrive a la fin de son voyage
        return false;
    //if(tab->nontraversableobus(posobus))//si l'obus n'es pas bloqué par le terrain
    //    return false;
    return true;

}

