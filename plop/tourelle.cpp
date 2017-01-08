#include "tourelle.h"

Tourelle::Tourelle(string nomTank, QGraphicsScene *scene)
{
    type=nomTank;
    if(type=="tiger")
    {
        setPixmap(QPixmap(":/images/tigertourelle.png"));
    }
    else if(type=="kv1")
    {
        setPixmap(QPixmap(":/images/kv1tourelle.png"));
    }
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setTransformOriginPoint(46,12);
    setFlag(QGraphicsItem::ItemIsFocusable);
    angle_canon=0;
    this->scene=scene;
}

void Tourelle::keyPressEvent(QKeyEvent *event)
{
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
    else if(event->key() ==Qt::Key_Space)
    {
        Tir* t=new Tir(Point (0,0),45,45,3);

        //t->trajectoire(scene);
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
            setPixmap(QPixmap(":/images/tigertourelle.png"));
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
            setPixmap(QPixmap(":/images/kv1ourelle90.png"));
            break;
        default:
            break;
        }
    }
}


