#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <QObject>
#include <QRect>

#include "Point.h"
#include "option.h"
#include "Liste.h"


using namespace std;

class terrain : public QObject
{
private:

    char type;
    bool bloque;
public:
    terrain(char type,bool bloque);//constructeurs
    terrain();

    char gettype() const;//retourne le type
    bool getbloque() const;//renvoi 1 si le terrain est bloquant

    void setterrain(char t,bool b);

};

#endif // TERRAIN_H
