#include "tourelle.h"

Tourelle::Tourelle(string nomTank, QGraphicsScene *scene, Hud *mainhud, Grilleterrain *tab,Point centre)
{
    type=nomTank;
    obus2=10;
    obus3=5;
    if(type=="tiger")
    {
        setPixmap(QPixmap(":/images/tigertourelle.png"));
        setTransformOriginPoint(46,12);
    }
    else if(type=="kv1")
    {
        setPixmap(QPixmap(":/images/kv1tourelle.png"));
        setTransformOriginPoint(41,12);
    }
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setFlag(QGraphicsItem::ItemIsFocusable);
    angle_canon=0;
    this->scene=scene;
    hud=mainhud;
    hud->setHudAngleTourelle(rotation());
    hud->setHudAngleCanon(angle_canon);
    this->tab=tab;
    this->centre=centre;

}

void Tourelle::keyPressEvent(QKeyEvent *event)
{
    int aff_rot;
    if(event->key() ==Qt::Key_D)
    {
        setRotation(rotation()+1);
    }
    else if(event->key() ==Qt::Key_Q)
    {
        setRotation(rotation()-1);
    }
    else if(event->key() ==Qt::Key_Z)
    {
        if(angle_canon<90)angle_canon++;
    }
    else if(event->key() ==Qt::Key_S)
    {
        if(angle_canon>0)angle_canon--;
    }
    else if(event->key()==Qt::Key_1||event->key()==Qt::Key_2||event->key()==Qt::Key_3)
    {
        if(event->key()==Qt::Key_1)
        {
            Tir* t=new Tir(centre,rotation(),angle_canon,3,tab);
        }
        else if(event->key()==Qt::Key_2)
        {
            Tir* t=new Tir(centre,rotation(),angle_canon,3,tab);
            hud->setHudObus2(obus2-1);
        }
        else if(event->key()==Qt::Key_3)
        {
            Tir* t=new Tir(centre,rotation(),angle_canon,3,tab);
            hud->setHudObus3(obus3-1);
        }
        t->trajectoire(scene);
        clearFocus();

    }
    if(type=="tiger")
    {
        switch (angle_canon/10)
        {
        case 0:
            setPixmap(QPixmap(":/images/tigertourelle.png"));
            break;
        case 1:
            setPixmap(QPixmap(":/images/tigertourelle10.png"));
            break;
        case 2:
            setPixmap(QPixmap(":/images/tigertourelle20.png"));
            break;
        case 3:
            setPixmap(QPixmap(":/images/tigertourelle30.png"));
            break;
        case 4:
            setPixmap(QPixmap(":/images/tigertourelle40.png"));
            break;
        case 5:
            setPixmap(QPixmap(":/images/tigertourelle50.png"));
            break;
        case 6:
            setPixmap(QPixmap(":/images/tigertourelle60.png"));
            break;
        case 7:
            setPixmap(QPixmap(":/images/tigertourelle70.png"));
            break;
        case 8:
            setPixmap(QPixmap(":/images/tigertourelle80.png"));
            break;
        case 9:
            setPixmap(QPixmap(":/images/tigertourelle90.png"));
            break;
        default:
            break;
        }
    }
    else if(type=="kv1")
    {
        switch (angle_canon/10)
        {
        case 0:
            setPixmap(QPixmap(":/images/kv1tourelle.png"));
            break;
        case 1:
            setPixmap(QPixmap(":/images/kv1tourelle10.png"));
            break;
        case 2:
            setPixmap(QPixmap(":/images/kv1tourelle10.png"));
            break;
        case 3:
            setPixmap(QPixmap(":/images/kv1tourelle30.png"));
            break;
        case 4:
            setPixmap(QPixmap(":/images/kv1tourelle30.png"));
            break;
        case 5:
            setPixmap(QPixmap(":/images/kv1tourelle50.png"));
            break;
        case 6:
            setPixmap(QPixmap(":/images/kv1tourelle50.png"));
            break;
        case 7:
            setPixmap(QPixmap(":/images/kv1tourelle70.png"));
            break;
        case 8:
            setPixmap(QPixmap(":/images/kv1tourelle70.png"));
            break;
        case 9:
            setPixmap(QPixmap(":/images/kv1tourelle90.png"));
            break;
        default:
            break;
        }
    }
    aff_rot=rotation();
    aff_rot=aff_rot%360;
    if(aff_rot<0)aff_rot=aff_rot+360;
    this->hud->setHudAngleTourelle(aff_rot);
    this->hud->setHudAngleCanon(angle_canon);
}

int Tourelle::getobus2()
{
    return obus2;
}

int Tourelle::getobus3()
{
    return obus3;
}
