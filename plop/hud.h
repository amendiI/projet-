#ifndef HUD_H
#define HUD_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include <QString>
#include "tank.h"

class Hud
{
private:
    QGraphicsTextItem aff_pv;
    QGraphicsTextItem aff_pm;
    QGraphicsTextItem aff_obus2;
    QGraphicsTextItem aff_obus3;
    QGraphicsTextItem aff_angle_tourelle;
    QGraphicsTextItem aff_angle_canon;

public:
    Hud(Tank t);
};

#endif // HUD_H
