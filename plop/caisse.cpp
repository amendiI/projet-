#include "caisse.h"

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
    centre.setx(x()/5+4);
    centre.sety(y()/5-2);

}

void Caisse::keyPressEvent(QKeyEvent *event,Grilleterrain tab)
{
    int cx=centre.getx();
    int cy=centre.gety();
    Caisse* c=new Caisse();

    if(pm>0)
    {
        if(angle<0){angle=angle+8;}//pour que le modulo ne calcul pas des negatifs
        if(event->key() ==Qt::Key_D )
        {
            c->setRotation(rotation()+45);
            c->tourelle->setRotation(tourelle->rotation()+45);
            c->setAngle(angle+1);
        }
        else if(event->key() ==Qt::Key_Q )
        {
           setRotation(rotation()-45);
           tourelle->setRotation(tourelle->rotation()-45);
           angle--;
        }
        else if(event->key() ==Qt::Key_Z )
        {
            switch (angle%8)
            {
            case 0:
                setPos( x()+5, y());
                tourelle->setPos( tourelle->x()+5, tourelle->y());
                centre.setx(cx+5);
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
        if(c->peutBouger(tab))
        {
            prendpos(c);
        }
    }
    else if(event->key() ==Qt::Key_Space || pm==0)
    {
        clearFocus();
        tourelle->setFocus();
    }
}

bool Caisse::peutBouger(Grilleterrain tab)
{
    int x=centre.getx();
    int y=centre.gety();
    x-=-4;
    y-=-4;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(hitbox(i,j) && !tab.est_traversable(i,j))
            {
                    return false;
            }
        }
    }
    return true;
}

bool Caisse::hitbox(int x,int y)
{
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

void Caisse::prendpos(Caisse* c)
{
    this->angle=c->getAngle();
    this->pm=c->getPm();
    this->centre=c->getcentre();
}
