#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "Point.h"
#include "option.h"
#include "Liste.h"


using namespace std;

class terrain:public QGraphicsPixmapItem
{
private:

    char type;
    bool bloque;
    int resistance;
    bool bloqueobus;
public:
    terrain();
    terrain(char type,bool bloque,int resistance,bool boqueobus);//constructeurs

    char gettype() const;//retourne le type
    bool getbloque() const;//renvoi 1 si le terrain est bloquant
    int getresistance()const{return resistance;}
    bool getbloqueobus()const;
    void setterrain(const char t,const bool b,const int r,const char* image,const bool boqueobus);//setter
    void setimage();//pour le debug
    void setresistance(const int r){resistance=r;}
};

#endif // TERRAIN_H
