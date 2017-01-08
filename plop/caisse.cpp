#include "caisse.h"

Caisse::Caisse(Grilleterrain *grille, string nomTank, Point pos)
{
    setPos(pos.getx(),pos.gety());
    tourelle= new Tourelle(nomTank);
    if(nomTank=="tiger")
    {
        setPixmap(QPixmap(":/images/tigercaisse.png"));
        tourelle->setPos(x()-24,y());
    }
    else if(nomTank=="kv1")
    {
        setPixmap(QPixmap(":/images/kv1caisse.png"));
        tourelle->setPos(x()-19,y());
    }
    setShapeMode(QGraphicsPixmapItem::MaskShape);
    setTransformOriginPoint(22,12);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setAngle(0);
    setPm(W/50);
    centre.setx(x()/5+4);
    centre.sety(y()/5-2);
    tab=grille;

}

Caisse::~Caisse(){}

void Caisse::keyPressEvent(QKeyEvent *event)
{
    int cx=centre.getx();
    int cy=centre.gety();
    Caisse* c=new Caisse(tab,"tiger",Point(x(),y()));

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
           c->setRotation(rotation()-45);
           c->setRotation(tourelle->rotation()-45);
           c->angle--;
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
                c->setPos( x()+5, y()+5);
                c->tourelle->setPos( tourelle->x()+5, tourelle->y()+5);
                c->centre.setx(cx+5);
                c->centre.sety(cy+5);
                break;
            case 2:
                c->setPos( x(), y()+5);
                c->tourelle->setPos( tourelle->x(), tourelle->y()+5);
                c->centre.sety(cy+5);
                break;
            case 3:
                c->setPos( x()-5, y()+5);
                c->tourelle->setPos( tourelle->x()-5, tourelle->y()+5);
                c->centre.setx(cx-5);
                c->centre.sety(cy+5);
                break;
            case 4:
                c->setPos( x()-5, y());
                c->tourelle->setPos( tourelle->x()-5, tourelle->y());
                c->centre.setx(cx-5);
                break;
            case 5:
                c->setPos( x()-5, y()-5);
                c->tourelle->setPos( tourelle->x()-5, tourelle->y()-5);
                c->centre.setx(cx-5);
                c->centre.sety(cy-5);
                break;
            case 6:
                c->setPos( x(), y()-5);
                c->tourelle->setPos( tourelle->x(), tourelle->y()-5);
                c->centre.sety(cy-5);
                break;
            case 7:
                c->setPos( x()+5, y()-5);
                c->tourelle->setPos( tourelle->x()+5, tourelle->y()-5);
                c->centre.setx(cx+5);
                c->centre.sety(cy-5);
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
                c->setPos( x()-5, y());
                c->tourelle->setPos( tourelle->x()-5, tourelle->y());
                c->centre.sety(cx-5);
                break;
            case 1:
                c->setPos( x()-5, y()-5);
                c->tourelle->setPos( tourelle->x()-5, tourelle->y()-5);
                c->centre.sety(cx-5);
                c->centre.sety(cy-5);
                break;
            case 2:
                c->setPos( x(), y()-5);
                c->tourelle->setPos( tourelle->x(), tourelle->y()-5);
                c->centre.sety(cy-5);
                break;
            case 3:
                c->setPos( x()+5, y()-5);
                c->tourelle->setPos( tourelle->x()+5, tourelle->y()-5);
                c->centre.setx(cx+5);
                c->centre.sety(cy-5);
                break;
            case 4:
                c->setPos( x()+5, y());
                c->tourelle->setPos( tourelle->x()+5, tourelle->y());
                c->centre.setx(cx+5);
                break;
            case 5:
                c->setPos( x()+5, y()+5);
                c->tourelle->setPos( tourelle->x()+5, tourelle->y()+5);
                c->centre.setx(cx+5);
                c->centre.sety(cy+5);
                break;
            case 6:
                c->setPos( x(), y()+5);
                c->tourelle->setPos( tourelle->x(), tourelle->y()+5);
                c->centre.sety(cy+5);
                break;
            case 7:
                c->setPos( x()-5, y()+5);
                c->tourelle->setPos( tourelle->x()-5, tourelle->y()+5);
                c->centre.setx(cx-5);
                c->centre.sety(cy+5);
                break;
            default:
                break;
            }
            pm--;
        }
        if(c->peutBouger(tab))
        {
            cout<<centre.getx()<<endl;
            cout<<"passage"<<endl;
            prendpos(c);
            cout<<centre.getx()<<endl;
        }
    }
    else if(event->key() ==Qt::Key_Space || pm==0)
    {
        clearFocus();
        tourelle->setFocus();
    }
    c->~Caisse();
}

bool Caisse::peutBouger(Grilleterrain* tab)
{
    int x=centre.getx();
    int y=centre.gety();
    x-=-4;
    y-=-4;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(hitbox(i,j) && tab->est_traversable(i,j))
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
    this->tourelle=c->tourelle;
    cout<<centre.getx()<<endl;
}
