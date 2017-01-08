#ifndef HUD_H
#define HUD_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include <QString>
#include "tank.h"

using namespace std;

class Hud
{
private:
    QGraphicsTextItem aff_pm;
    QGraphicsTextItem aff_obus2;
    QGraphicsTextItem aff_obus3;
    QGraphicsTextItem aff_angle_tourelle;
    QGraphicsTextItem aff_angle_canon;
    QString conversion;

public:
    Hud(Tank* t);
    void afficheHud(QGraphicsScene *scene);
};

#endif // HUD_H
