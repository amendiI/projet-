#include "tourelle.h"

Tourelle::Tourelle()
{
    setPixmap(QPixmap(":/images/Tourelle.png"));
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setTransformOriginPoint(46,12);
    setFlag(QGraphicsItem::ItemIsFocusable);
    angle_canon=0;
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
    switch (angle_canon/10)
    {
    case 0:
        setPixmap(QPixmap(":/images/Tourelle.png"));
        break;
    case 1:
        setPixmap(QPixmap(":/images/Tourelle10.png"));
        break;
    case 2:
        setPixmap(QPixmap(":/images/Tourelle20.png"));
        break;
    case 3:
        setPixmap(QPixmap(":/images/Tourelle30.png"));
        break;
    case 4:
        setPixmap(QPixmap(":/images/Tourelle40.png"));
        break;
    case 5:
        setPixmap(QPixmap(":/images/Tourelle50.png"));
        break;
    case 6:
        setPixmap(QPixmap(":/images/Tourelle60.png"));
        break;
    case 7:
        setPixmap(QPixmap(":/images/Tourelle70.png"));
        break;
    case 8:
        setPixmap(QPixmap(":/images/Tourelle80.png"));
        break;
    case 9:
        setPixmap(QPixmap(":/images/Tourelle90.png"));
        break;
    default:
        break;
    }

}


