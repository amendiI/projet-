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

    distance= (-abs(anglec-25)+45);

    posarrive.setx(posinit.getx()+((float)distance)*cos(angle*PI/180));
    posarrive.sety(posinit.gety()+((float)distance)*sin(angle*PI/180));



    coefdir=((float)(posinit.gety()-posarrive.gety()))/((float)(posinit.getx()- posarrive.getx()));

    ordori=-coefdir*posarrive.getx()+posarrive.gety();

    cout<<distance<<endl;
    cout<<posarrive.getx()<<";"<<posarrive.gety()<<endl;
    cout<<coefdir<<endl;
}

Tir::~Tir()
{

}
/*
int Tir::trajectoire(QGraphicsScene* scene)
{

    QTimer* timer=new QTimer();
    connect(timer,Signal(timeout()),this,SLOT(mouvement_obus()));
    timer->start;

    float compteur=0;
    scene->addItem(&obus);
    timer->start(200);

    while(timer->isActive())
    {
        cout<<"do nothing"<<endl;
    }
    impact(posobus);
}

void Tir::impact(Point p)
{

}

void Tir::mouvement_obus(float compteur,)
{
        compteur+=coefdir;

        while(abs(compteur)>1)
        {
            if(compteur>0)
                compteur-=1;
            else
                compteur+=1;

            posobus.sety(posobus.gety()+1);
            obus.setPos(posobus.getx()*5,posobus.gety()*5);
            cout<<obus.x()<<";"<<obus.y()<<endl;
            if(posobus.getx()==posarrive.getx()&&posobus.gety()==posarrive.gety())
            {
                en_cours=false;
            }
        }
        posobus.setx(posobus.getx()+1);
        obus.setPos(posobus.getx()*5,posobus.gety()*5);
        if(posobus.getx()==posarrive.getx()&&posobus.gety()==posarrive.gety())
        {
            en_cours=false;
        }

}
*/

