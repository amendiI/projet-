#include "tank.h"

Tank::Tank()
{
    spriteCaisse.setPixmap(QPixmap(IMG_tank1));
    spriteTourelle.setPixmap(QPixmap(":/images/Tourelle.png"));
    angle = 0;

    spriteCaisse.setShapeMode(QGraphicsPixmapItem::MaskShape);
    spriteTourelle.setShapeMode(QGraphicsPixmapItem::MaskShape);

<<<<<<< HEAD
    spriteCaisse.setTransformOriginPoint(22,12);
    spriteTourelle.setTransformOriginPoint(46,12);

=======
>>>>>>> origin/master
    spriteCaisse.setFlag(QGraphicsItem::ItemIsFocusable);
    spriteTourelle.setFlag(QGraphicsItem::ItemIsFocusable);

    spriteCaisse.setTransformOriginPoint(56,12);
    spriteTourelle.setTransformOriginPoint(56,12);
}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(&spriteCaisse);
    scene->addItem(&spriteTourelle);
}


void Tank::deplacement()
{
<<<<<<< HEAD
    spriteCaisse.setFocus();
=======
    spriteCaisse.setOffset(p.getx(),p.gety());
    spriteTourelle.setOffset(p.getx()-24,p.gety());
>>>>>>> origin/master
}

int Tank::getobus2()
{
    return obus2;
}

int Tank::getobus3()
{
    return obus3;
}

void Tank::setfocuscaisse()
{
    spriteCaisse.setFocus();
}

void Tank::setfocustourelle()
{
    spriteTourelle.setFocus();
}
