#include "caisse.h"
#include "tourelle.h"

Caisse::Caisse()
{
    tourelle= new Tourelle();
    setPixmap(QPixmap(":/images/Tank.png"));
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setTransformOriginPoint(22,12);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setAngle(0);
    setPm(W/50);
    setPos(x()+25,y());
    refMasque.setx(x());
    refMasque.sety(y());

}

void Caisse::keyPressEvent(QKeyEvent *event)
{

    if(pm>0)
    {
        if(angle<0)
        {
            angle=angle+8;
        }
        if(event->key() ==Qt::Key_D)
        {
            setRotation(rotation()+45);
            tourelle->setRotation(tourelle->rotation()+45);
            angle++;
        }
        else if(event->key() ==Qt::Key_Q)
        {
           setRotation(rotation()-45);
           tourelle->setRotation(tourelle->rotation()-45);
           angle--;
        }
        else if(event->key() ==Qt::Key_Z)
        {
            switch (angle%8)
            {
            case 0:
                setPos( x()+5, y());
                tourelle->setPos( tourelle->x()+5, tourelle->y());
                break;
            case 1:
                setPos( x()+5, y()+5);
                tourelle->setPos( tourelle->x()+5, tourelle->y()+5);
                break;
            case 2:
                setPos( x(), y()+5);
                tourelle->setPos( tourelle->x(), tourelle->y()+5);
                break;
            case 3:
                setPos( x()-5, y()+5);
                tourelle->setPos( tourelle->x()-5, tourelle->y()+5);
                break;
            case 4:
                setPos( x()-5, y());
                tourelle->setPos( tourelle->x()-5, tourelle->y());
                break;
            case 5:
                setPos( x()-5, y()-5);
                tourelle->setPos( tourelle->x()-5, tourelle->y()-5);
                break;
            case 6:
                setPos( x(), y()-5);
                tourelle->setPos( tourelle->x(), tourelle->y()-5);
                break;
            case 7:
                setPos( x()+5, y()-5);
                tourelle->setPos( tourelle->x()+5, tourelle->y()-5);
                break;
            default:
                break;
            }
            pm--;
        }
        else if(event->key() ==Qt::Key_S)
        {
            switch (angle%8)
            {
            case 0:
                setPos( x()-5, y());
                tourelle->setPos( tourelle->x()-5, tourelle->y());
                break;
            case 1:
                setPos( x()-5, y()-5);
                tourelle->setPos( tourelle->x()-5, tourelle->y()-5);
                break;
            case 2:
                setPos( x(), y()-5);
                tourelle->setPos( tourelle->x(), tourelle->y()-5);
                break;
            case 3:
                setPos( x()+5, y()-5);
                tourelle->setPos( tourelle->x()+5, tourelle->y()-5);
                break;
            case 4:
                setPos( x()+5, y());
                tourelle->setPos( tourelle->x()+5, tourelle->y());
                break;
            case 5:
                setPos( x()+5, y()+5);
                tourelle->setPos( tourelle->x()+5, tourelle->y()+5);
                break;
            case 6:
                setPos( x(), y()+5);
                tourelle->setPos( tourelle->x(), tourelle->y()+5);
                break;
            case 7:
                setPos( x()-5, y()+5);
                tourelle->setPos( tourelle->x()-5, tourelle->y()+5);
                break;
            default:
                break;
            }
            pm--;
        }
    }
    else if(event->key() ==Qt::Key_Space || pm==0)
    {
        clearFocus();
        tourelle->setFocus();
    }
}
