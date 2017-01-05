#ifndef HUD_H
#define HUD_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include "tank.h"

class Hud
{
private:
    QGraphicsRectItem barre;
    QGraphicsTextItem aff_pv;
    QGraphicsTextItem aff_obus2;
    QGraphicsTextItem aff_obus3;

public:
    Hud();
};

#endif // HUD_H
