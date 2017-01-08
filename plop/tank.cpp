#include "tank.h"
#include "hitbox.h"

Tank::Tank(Grilleterrain *grille, string nomTank, Point pos)
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

Tank::~Tank()
{

}

void Tank::afficheTank(QGraphicsScene* scene)
{
    scene->addItem(this);
    scene->addItem(getTourelle());
}

int Tank::getobus2()
{
    return obus2;
}

int Tank::getobus3()
{
    return obus3;
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    int cx=centre.getx();
    int cy=centre.gety();
    int xp=0;
    int yp=0;
    int ap=0;
    int op=angle;
    Tank* c=new Tank(tab,"tiger",Point(x(),y()));

    if(pm>0)
    {
        if(op<0){op=op+8;}//pour que le modulo ne calcule pas des negatifs
        if(event->key() == Qt::Key_D )
        {
            ap=45;
            op++;
        }
        else if(event->key() == Qt::Key_Q )
        {
            ap=-45;
            op--;
        }
        else if(event->key() == Qt::Key_Z ||event->key() == Qt::Key_S)
        {
            switch (angle%8)
            {
            case 0:
                xp=5;
                break;
            case 1:
                xp=5;
                yp=5;
                break;
            case 2:
                yp=5;
                break;
            case 3:
                xp=-5;
                yp=5;
                break;
            case 4:
                xp=-5;
                break;
            case 5:
                xp=-5;
                yp=-5;
                break;
            case 6:
                yp=-5;
                break;
            case 7:
                xp=5;
                yp=-5;
                break;
            default:
                break;
            }

            if(event->key() == Qt::Key_S)//si on recule
            {
                xp=-xp;
                yp=-yp;
            }
        }
        else if(event->key() ==Qt::Key_Space || pm==0)
        {
            clearFocus();
            tourelle->setFocus();
        }

        c->setAngle(op);
        c->setRotation(rotation()+ap);
        c->tourelle->setRotation(tourelle->rotation()+ap);
        c->tourelle->setPos(tourelle->x()+xp,tourelle->y()+yp);
        c->setPos( x()+xp, y()+yp);
        c->centre.setx(cx+xp);
        c->centre.sety(cy+yp);

        if(c->peutBouger(tab))
        {
            angle=c->getAngle();
            setRotation(c->rotation());
            tourelle->setRotation(c->tourelle->rotation());
            tourelle->setPos(c->tourelle->pos());
            setPos(c->pos());
            centre=c->centre;
            //pm--;
        }
        c->~Tank();
    }
}

bool Tank::peutBouger(Grilleterrain *tab)
{
    int x=centre.getx();
    int y=centre.gety();
    x-=-4;
    y-=-4;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<hitbox(i,j)<<";"<<tab->est_traversable(x+i,y+j)<<"|";
            if(hitbox(i,j) && tab->est_traversable(x+i,y+j))
            {
                cout<<endl;
                cout<<i<<";"<<j<<endl;
                return false;
            }
        }
        cout<<endl;
    }
    return true;
}

bool Tank::hitbox(int x, int y)
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

void Tank::visee()
{
    //tourelle->setFocus();
}

void Tank::deplacement()
{
    setFocus();
}
