#include "tank.h"

Tank::Tank()
{
    spriteCaisse.setPixmap(QPixmap(IMG_tank1));
    spriteTourelle.setPixmap(QPixmap(":/images/Tourelle.png"));
    angle = 0;

    spriteCaisse.setShapeMode(QGraphicsPixmapItem::MaskShape);
    spriteTourelle.setShapeMode(QGraphicsPixmapItem::MaskShape);

    spriteCaisse.setTransformOriginPoint(56,12);
    spriteTourelle.setTransformOriginPoint(56,12);

    spriteCaisse.setFlag(QGraphicsItem::ItemIsFocusable);
    spriteTourelle.setFlag(QGraphicsItem::ItemIsFocusable);
}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(&spriteCaisse);
    scene->addItem(&spriteTourelle);
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    if(event->key() ==Qt::Key_D)
    {
        spriteCaisse.setRotation(45);
        spriteTourelle.setRotation(45);
        angle++;
    }
    else if(event->key() ==Qt::Key_Q)
    {
        spriteCaisse.setRotation(-45);
        spriteTourelle.setRotation(-45);
        angle--;
    }
    else if(event->key() ==Qt::Key_Z)
    {
        if(angle%8==0)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y());
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y());
        }
        else if(angle%8==1)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y()+5);
        }
        else if(angle%8==2)
        {
              spriteCaisse.setPos(  spriteCaisse.x(),  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x(),  spriteTourelle.y()+5);
        }
        else if(angle%8==3)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y()+5);
        }
        else if(angle%8==4)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y());
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y());
        }
        else if(angle%8==5)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y()-5);
        }
        else if(angle%8==6)
        {
              spriteCaisse.setPos(  spriteCaisse.x(),  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x(),  spriteTourelle.y()-5);
        }
        else if(angle%8==7)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y()-5);
        }
    }
    else   if(event->key() ==Qt::Key_S)
    {
        if(angle%8==0)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y());
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y());
        }
        else if(angle%8==1)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y()-5);
        }
        else if(angle%8==2)
        {
              spriteCaisse.setPos(  spriteCaisse.x(),  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x(),  spriteTourelle.y()-5);
        }
        else if(angle%8==3)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y()-5);
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y()-5);
        }
        else if(angle%8==4)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y());
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y());
        }
        else if(angle%8==5)
        {
              spriteCaisse.setPos(  spriteCaisse.x()+5,  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x()+5,  spriteTourelle.y()+5);
        }
        else if(angle%8==6)
        {
              spriteCaisse.setPos(  spriteCaisse.x(),  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x(),  spriteTourelle.y()+5);
        }
        else if(angle%8==7)
        {
              spriteCaisse.setPos(  spriteCaisse.x()-5,  spriteCaisse.y()+5);
              spriteTourelle.setPos(  spriteTourelle.x()-5,  spriteTourelle.y()+5);
        }
    }
    else   if(event->key() ==Qt::Key_Space)
    {

    }
}

void Tank::deplacement(Point p)
{
    spriteCaisse.setOffset(p.getx(),p.gety());
    spriteTourelle.setOffset(p.getx(),p.gety());
}

int Tank::getobus2()
{
    return obus2;
}

int Tank::getobus3()
{
    return obus3;
}
