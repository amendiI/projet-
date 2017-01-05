#include "tank.h"

Tank::Tank()
{
    this->spriteCaisse->setPixmap(QPixmap(":/images/Tank.png"));
    this->spriteTourelle->setPixmap(QPixmap(":/images/Tourelle.png"));
    this->angle = 0;

    this->spriteCaisse->setShapeMode(QGraphicsPixmapItem::MaskShape);
    this->spriteTourelle->setShapeMode(QGraphicsPixmapItem::MaskShape);

    this->spriteCaisse->setTransformOriginPoint(22,12);
    this->spriteTourelle->setTransformOriginPoint(46,12);

    this->spriteCaisse->setFlag(QGraphicsItem::ItemIsFocusable);
    this->spriteTourelle->setFlag(QGraphicsItem::ItemIsFocusable);
}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(this->spriteCaisse);
    scene->addItem(this->spriteTourelle);
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    if(event->key() ==Qt::Key_D)
    {
        this->spriteCaisse->setRotation(45);
        this->spriteTourelle->setRotation(45);
        this->angle++;
    }
    else if(event->key() ==Qt::Key_Q)
    {
        this->spriteCaisse->setRotation(-45);
        this->spriteTourelle->setRotation(-45);
        this->angle--;
    }
    else   if(event->key() ==Qt::Key_Z)
    {
        if(angle%8==0)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y());
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y());
        }
        else if(angle%8==1)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y()+5);
        }
        else if(angle%8==2)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x(),this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x(),this->spriteTourelle->y()+5);
        }
        else if(angle%8==3)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y()+5);
        }
        else if(angle%8==4)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y());
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y());
        }
        else if(angle%8==5)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y()-5);
        }
        else if(angle%8==6)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x(),this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x(),this->spriteTourelle->y()-5);
        }
        else if(angle%8==7)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y()-5);
        }
    }
    else   if(event->key() ==Qt::Key_S)
    {
        if(angle%8==0)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y());
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y());
        }
        else if(angle%8==1)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y()-5);
        }
        else if(angle%8==2)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x(),this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x(),this->spriteTourelle->y()-5);
        }
        else if(angle%8==3)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y()-5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y()-5);
        }
        else if(angle%8==4)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y());
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y());
        }
        else if(angle%8==5)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()+5,this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()+5,this->spriteTourelle->y()+5);
        }
        else if(angle%8==6)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x(),this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x(),this->spriteTourelle->y()+5);
        }
        else if(angle%8==7)
        {
            this->spriteCaisse->setPos(this->spriteCaisse->x()-5,this->spriteCaisse->y()+5);
            this->spriteTourelle->setPos(this->spriteTourelle->x()-5,this->spriteTourelle->y()+5);
        }
    }
    else   if(event->key() ==Qt::Key_Space)
    {

    }
}
