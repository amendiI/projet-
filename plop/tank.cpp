#include "tank.h"
#include "hitbox.h"

Tank::Tank()
{
    //tourelle=new Tourelle();
    caisse=new Caisse();


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

//calcul des hitbox selons l'angle du char
bool Tank::hitbox(Point impacte)
{
    int x=impacte.getx();
    int y=impacte.gety();
    int angle=caisse->getangle();
    if(angle==0)
    {
        if(y>6){return false;}//dessus de la caisse
        else if(y<2){return false;}//dessous de la caisse
        else if(x==0&&(y==6||y==2)){return false;}//derière de la caisse qui n'est pas completement rectangulaire
        return true;
    }
    else if(angle==180)
    {
        if(y>6){return false;}//dessus de la caisse
        else if(y<2){return false;}//dessous de la caisse
        else if(x==8&&(y==6||y==2)){return false;}//derière de la caisse qui n'est pas completement rectangulaire
        return true;
    }
    else if(angle==90)
    {
        if(x>6){return false;}//dessus de la caisse
        else if(x<2){return false;}//dessous de la caisse
        else if(y==0&&(x==6||x==2)){return false;}//derière de la caisse qui n'est pas completement rectangulaire
        return true;
    }
    else if(angle==270)
    {
        if(x>6){return false;}//dessus de la caisse
        else if(x<2){return false;}//dessous de la caisse
        else if(y==8&&(x==6||x==2)){return false;}//derière de la caisse qui n'est pas completement rectangulaire
        return true;
    }
    else if(angle==45||angle==225)
    {
        int h45[9][9]=hitbox45d;

        if(h45[x][y]==0){return false;}
        return true;
    }
    else
    {
        int h135[9][9]=hitbox45d;

        if(h135[9-y][x]==0){return false;}//rotation de la hitbox dans le sens inverse en changant le x et le y
        return true;
    }

    exit (2);
}
