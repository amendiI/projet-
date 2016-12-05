#include "terrain.h"

terrain::terrain()
{
    type='z';
    bloque=false;
}

 terrain::terrain(char t,bool b)
 {
     type=t;
     bloque=b;
 }

char terrain::gettype()         const{return type;}
bool terrain::getbloque()       const{return bloque;}
void terrain::setterrain(const char t,const bool b)
{
    type=t;
    bloque=b;

}
