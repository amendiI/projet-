#include "tank.h"

Tank::Tank()
{
    spriteCaisse.setPixmap(QPixmap(IMG_tank1));
    spriteTourelle.setPixmap(QPixmap(":/images/Tourelle.png"));

    spriteCaisse.setShapeMode(QGraphicsPixmapItem::MaskShape);
    spriteTourelle.setShapeMode(QGraphicsPixmapItem::MaskShape);

    spriteCaisse.setTransformOriginPoint(22,12);
    spriteTourelle.setTransformOriginPoint(46,12);

    spriteCaisse.setFlag(QGraphicsItem::ItemIsFocusable);
    spriteTourelle.setFlag(QGraphicsItem::ItemIsFocusable);

}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(&spriteCaisse);
    scene->addItem(&spriteTourelle);
}


void Tank::deplacement()
{

    spriteCaisse.setFocus();
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
