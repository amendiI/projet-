#include "tank.h"
#include "hitbox.h"

Tank::Tank(Grilleterrain *tab,string nomTank)
{
    //tourelle=new Tourelle();
    caisse=new Caisse(tab,nomTank,Point(100,100));


}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(caisse);
    scene->addItem(caisse->getTourelle());
}

int Tank::getobus2()
{
    return obus2;
}

int Tank::getobus3()
{
    return obus3;
}

void Tank::visee()
{
    //tourelle->setFocus();
}

void Tank::deplacement()
{
    caisse->setFocus();
}
