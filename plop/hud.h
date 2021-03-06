#ifndef HUD_H
#define HUD_H
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include <QString>

using namespace std;

class Hud
{
private:
    int pm;
    int obus2;
    int obus3;
    int angle_tourelle;
    int angle_canon;
    QGraphicsTextItem aff_pm;
    QGraphicsTextItem aff_obus2;
    QGraphicsTextItem aff_obus3;
    QGraphicsTextItem aff_angle_tourelle;
    QGraphicsTextItem aff_angle_canon;
    QString conversion;

public:
    Hud(int joueur);
    void afficheHud(QGraphicsScene *scene);
    void setHudPm(int newpm);
    void setHudObus2(int newobus2);
    void setHudObus3(int newobus3);
    void setHudAngleTourelle(int newangletourelle);
    void setHudAngleCanon(int newanglecanon);
};

#endif // HUD_H
