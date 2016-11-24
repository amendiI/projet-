#include "terrain.h"

 //terrain::terrain(QObject *parent) : QObject(parent){}

 terrain::terrain(char t,bool b,int r)
 {
     type=t;
     bloque=b;
     resistance=r;
 }

 void terrain::impact()
 {

 }

char terrain::gettype()         const{return type;}
bool terrain::getbloque()       const{return bloque;}
int  terrain::getresistance()   const{return resistance;}

void terrain::setall(char type,bool bloque,int resistance)
{
    this->type=type;
    this->bloque=bloque;
    this->resistance=resistance;
}

void terrain::settype(char type)            {this->type=type;}
void terrain::setbloque(bool bloque)        {this->bloque=bloque;}
void terrain::setresistance(int resistance) {this->resistance=resistance;}
void terrain::setaff(int x,int y)           {this->aff=new QRect(x,y,5,5);}

