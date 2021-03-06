#include "hud.h"

Hud::Hud(int joueur)
{

    aff_pm.setPlainText(QString("pm :"+conversion.number(pm)));
    aff_obus2.setPlainText(QString("obus 2 :"+conversion.number(obus2)));
    aff_obus3.setPlainText(QString("obus 3 :"+conversion.number(obus3)));
    aff_angle_tourelle.setPlainText(QString("tourelle :"+conversion.number(angle_tourelle)));
    aff_angle_canon.setPlainText(QString("canon :"+conversion.number(angle_canon)));


    aff_pm.setDefaultTextColor(QColor(255,255,255,255));
    aff_obus2.setDefaultTextColor(QColor(255,255,255,255));
    aff_obus3.setDefaultTextColor(QColor(255,255,255,255));
    aff_angle_tourelle.setDefaultTextColor(QColor(255,255,255,255));
    aff_angle_canon.setDefaultTextColor(QColor(255,255,255,255));

    aff_pm.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_obus2.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_obus3.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_angle_tourelle.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_angle_canon.setTextInteractionFlags(Qt::NoTextInteraction);

    aff_pm.setTextWidth(200);
    aff_obus2.setTextWidth(200);
    aff_obus3.setTextWidth(200);
    aff_angle_tourelle.setTextWidth(200);
    aff_angle_canon.setTextWidth(200);

    aff_pm.setPos(700*(joueur-1)+25,25);
    aff_obus2.setPos(aff_pm.x(),aff_pm.y()+25);
    aff_obus3.setPos(aff_pm.x(),aff_obus2.y()+25);
    aff_angle_tourelle.setPos(aff_pm.x(),aff_obus3.y()+25);
    aff_angle_canon.setPos(aff_pm.x(),aff_angle_tourelle.y()+25);
}

void Hud::afficheHud(QGraphicsScene* scene)
{
    scene->addItem(&aff_pm);
    scene->addItem(&aff_obus2);
    scene->addItem(&aff_obus3);
    scene->addItem(&aff_angle_tourelle);
    scene->addItem(&aff_angle_canon);
}

void Hud::setHudPm(int newpm)
{
    pm=newpm;
    aff_pm.setPlainText(QString("pm :"+conversion.number(pm)));
}

void Hud::setHudObus2(int newobus2)
{
    obus2=newobus2;
    aff_obus2.setPlainText(QString("obus 2 :"+conversion.number(obus2)));

}

void Hud::setHudObus3(int newobus3)
{
    obus3=newobus3;
    aff_obus3.setPlainText(QString("obus 3 :"+conversion.number(obus3)));

}

void Hud::setHudAngleTourelle(int newangletourelle)
{
    angle_tourelle=newangletourelle;
    aff_angle_tourelle.setPlainText(QString("tourelle :"+conversion.number(angle_tourelle)));
}

void Hud::setHudAngleCanon(int newanglecanon)
{
    angle_canon=newanglecanon;
    aff_angle_canon.setPlainText(QString("canon :"+conversion.number(angle_canon)));
}
