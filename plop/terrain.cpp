#include "terrain.h"

terrain::terrain()
{
    type='z';
    bloque=false;
}

 terrain::terrain(char t,bool b,int r)
 {
     type=t;
     bloque=b;
     resistance=r;
 }

char terrain::gettype()         const{return type;}
bool terrain::getbloque()       const{return bloque;}
void terrain::setterrain(const char t,const bool b,const int r,const char* image)
{
    type=t;
    bloque=b;
    resistance=r;
    setPixmap(QPixmap(image));

}
