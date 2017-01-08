#include "hud.h"

Hud::Hud(Tank t)
{
    aff_pv.setPlainText(QString("pv :"+t.getPv()));
    aff_pm.setPlainText(QString("pm :"+t.getPm()));
    aff_obus2.setPlainText(QString("obus 2 :"+t.getobus2()));
    aff_obus3.setPlainText(QString("obus 3 :"+t.getobus3()));
    aff_angle_tourelle.setPlainText(QString("angle tourelle :"+t.getTourelle()->get_angle_tourelle()));
    aff_angle_canon.setPlainText(QString("angle canon :"+t.getTourelle()->get_angle_canon()));


    aff_pv.setDefaultTextColor(QColor(255,255,255,255));
    aff_pm.setDefaultTextColor(QColor(255,255,255,255));
    aff_obus2.setDefaultTextColor(QColor(255,255,255,255));
    aff_obus3.setDefaultTextColor(QColor(255,255,255,255));
    aff_angle_tourelle.setDefaultTextColor(QColor(255,255,255,255));
    aff_angle_canon.setDefaultTextColor(QColor(255,255,255,255));

    aff_pv.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_pm.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_obus2.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_obus3.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_angle_tourelle.setTextInteractionFlags(Qt::NoTextInteraction);
    aff_angle_canon.setTextInteractionFlags(Qt::NoTextInteraction);

    aff_pv.setTextWidth(150);
    aff_pm.setTextWidth(150);
    aff_obus2.setTextWidth(150);
    aff_obus3.setTextWidth(150);
    aff_angle_tourelle.setTextWidth(150);
    aff_angle_canon.setTextWidth(150);

    aff_pv.setPos(25,25);
    aff_pm.setPos(aff_pv.x()+50,aff_pv.y());
    aff_obus2.setPos(aff_pm.x()+50,aff_pv.y());
    aff_obus3.setPos(aff_obus2.x()+50,aff_pv.y());
    aff_angle_tourelle.setPos(aff_obus3.x()+50,aff_pv.y());
    aff_angle_canon.setPos(aff_angle_tourelle.x()+50,aff_pv.y());
}
