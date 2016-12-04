#include "terrain.h"

terrain::terrain()
{
    type='z';
    bloque=false;
}

 terrain::terrain(char t,bool b,char* image)
 {
     type=t;
     bloque=b;
     setPixmap(QPixmap(image));
 }

char terrain::gettype()         const{return type;}
bool terrain::getbloque()       const{return bloque;}
void terrain::setterrain(const char t,const bool b,const char* image)
{
    type=t;
    bloque=b;
    setPixmap(QPixmap(image));
}

void terrain::affichage(QGraphicsScene* scene)
{
    scene->addItem(this);
}
