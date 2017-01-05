#include "tank.h"

Tank::Tank()
{
    caisse.setPixmap(QPixmap(IMG_tank1));
    tourelle.setPixmap(QPixmap(":/images/Tourelle.png"));

    caisse.setShapeMode(QGraphicsPixmapItem::MaskShape);
    tourelle.setShapeMode(QGraphicsPixmapItem::MaskShape);

    caisse.setTransformOriginPoint(22,12);
    tourelle.setTransformOriginPoint(46,12);

    caisse.setFlag(QGraphicsItem::ItemIsFocusable);
    tourelle.setFlag(QGraphicsItem::ItemIsFocusable);

    caisse.setAngle(0);
    caisse.setPm(W/50);

}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(&caisse);
    scene->addItem(&tourelle);
}


void Tank::deplacement()
{

    caisse.setFocus();
}

int Tank::getobus2()
{
    return obus2;
}

int Tank::getobus3()
{
    return obus3;
}
