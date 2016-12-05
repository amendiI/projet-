#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "Point.h"
#include "option.h"
#include "Liste.h"


using namespace std;

class terrain
{
private:

    char type;
    bool bloque;
public:
    terrain();
    terrain(char type,bool bloque);//constructeurs

    char gettype() const;//retourne le type
    bool getbloque() const;//renvoi 1 si le terrain est bloquant

    void setterrain(const char t,const bool b);//setter
};

#endif // TERRAIN_H
