#include "masque.h"
#include "hitbox.h"


Masque::Masque(Caisse c)
{
    setRect(c.x(),c.y(),45,25);
    setRotation(c.rotation());
    angle=c.getAngle();
}

bool Masque::peutBouger(int orientation)
{
    x=refHitbox.getx();
    y=refHitbox.gety();
    switch((angle+orientation)%8)
    {
    case 0:
        return !(hitbox(Point(hitx+9,hity))&&hitbox(Point(hitx+9,hity+1))&&hitbox(Point(hitx+9,hity+2))&&hitbox(Point(hitx+9,hity+3))&&hitbox(Point(hitx+9,hity+4)));
        break;
    case 1:
        return !(hitbox(Point(hitx+9,hity+4))&&hitbox(Point(hitx+9,hity+5))&&hitbox(Point(hitx+8,hity+5))&&hitbox(Point(hitx+8,hity+6))&&hitbox(Point(hitx+7,hity+6))&&hitbox(Point(hitx+7,hity+7))&&hitbox(Point(hitx+6,hity+7)));
        break;
    case 2:
        return !(hitbox(Point(hitx+2,hity+7))&&hitbox(Point(hitx+3,hity+7))&&hitbox(Point(hitx+4,hity+7))&&hitbox(Point(hitx+5,hity+7))&&hitbox(Point(hitx+6,hity+7)));
        break;
    case 3:
        return !(hitbox(Point(hitx+9,hity+4))&&hitbox(Point(hitx+9,hity+5))&&hitbox(Point(hitx+8,hity+5))&&hitbox(Point(hitx+8,hity+6))&&hitbox(Point(hitx+7,hity+6))&&hitbox(Point(hitx+7,hity+7))&&hitbox(Point(hitx+6,hity+7)));
        break;
    case 4:
        return !(hitbox(Point(hitx-1,hity))&&hitbox(Point(hitx-1,hity+1))&&hitbox(Point(hitx-1,hity+2))&&hitbox(Point(hitx-1,hity+3))&&hitbox(Point(hitx-1,hity+4)));
        break;
    case 5:
        setPos( x()-5, y()-5);
        break;
    case 6:
        return !(hitbox(Point(hitx+2,hity-3))&&hitbox(Point(hitx+3,hity-3))&&hitbox(Point(hitx+4,hity-3))&&hitbox(Point(hitx+5,hity-3))&&hitbox(Point(hitx+6,hity-3)));
        break;
    case 7:
        setPos( x()+5, y()-5);
        break;
    default:
        break;
    }

        break;
    case Qt::Key_S:
        switch (angle%8)
            {
            case 0:
                setPos( x()-5, y());
                break;
            case 1:
                setPos( x()-5, y()-5);
                break;
            case 2:
                setPos( x(), y()-5);
                break;
            case 3:
                setPos( x()+5, y()-5);
                break;
            case 4:
                setPos( x()+5, y());
                break;
            case 5:
                setPos( x()+5, y()+5);
                break;
            case 6:
                setPos( x(), y()+5);
                break;
            case 7:
                setPos( x()-5, y()+5);
                break;
            default:
                break;
            }
        break;
    default:
        break;
    }
    return true;
}

//calcul des hitbox selons l'angle du char, return true quand point a l'intetrieur du tank
bool Masque::hitbox(Point impact)
{
    int x=impact.getx();
    int y=impact.gety();
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
