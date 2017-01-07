#include "terrain.h"

terrain::terrain()
{
    type='z';
    bloque=false;
}

 terrain::terrain(char t,bool b,int r,bool bt)
 {
     type=t;
     bloque=b;
     resistance=r;
     bloqueobus=bt;
 }

 char terrain::gettype()         const{return type;}
 bool terrain::getbloque()       const{return bloque;}

 bool terrain::getbloqueobus()   const{return bloqueobus;}
 void terrain::setterrain(const char t,const bool b,const int r,const char* image,const bool bt)
{
    type=t;
    bloque=b;
    resistance=r;
    bloqueobus=bt;
    setPixmap(QPixmap(image));

}
