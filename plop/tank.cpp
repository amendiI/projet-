#include "tank.h"
#include "hitbox.h"

Tank::Tank(Grilleterrain *grille, string nomTank, Point pos, QGraphicsScene *scene,Hud* mainhud)
{
    obus2=10;
    obus3=5;
    setPos(pos.getx(),pos.gety());
    tourelle= new Tourelle(nomTank,scene,mainhud,tab);
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
    this->scene=scene;
    centre.setx(x()/5-4);
    centre.sety(y()/5-6);
    tab=grille;
    hud=mainhud;
    hud->setHudPm(pm);
    hud->setHudObus2(obus2);
    hud->setHudObus3(obus3);
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

bool Tank::estVivant()
{
    return true;
}

void Tank::keyPressEvent(QKeyEvent *event)
{
    int cx=centre.getx();
    int cy=centre.gety();
    int xp=0;
    int yp=0;
    int ap=0;
    int aff_rot;
    int op=angle;
    Tank* c=new Tank(tab,"tiger",Point(x(),y()),scene,hud);

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
           /* if(tourelle->getType()=="kv1")
            {
                tourelle->setTransformOriginPoint(x()+19,y()+12);
            } */
        }

        c->setAngle(op);
        c->setRotation(rotation()+ap);
        c->tourelle->setRotation(tourelle->rotation()+ap);
        c->tourelle->setPos(tourelle->x()+xp,tourelle->y()+yp);
        c->setPos( x()+xp, y()+yp);
        c->centre.setx(cx+xp/5);
        c->centre.sety(cy+yp/5);

        if(c->peutBouger(tab))
        {
            angle=c->getAngle();
            setRotation(c->rotation());
            tourelle->setRotation(c->tourelle->rotation());
            tourelle->setPos(c->tourelle->pos());
            setPos(c->pos());
            centre=c->centre;
            pm--;
            hud->setHudPm(pm);
            aff_rot=tourelle->rotation();
            aff_rot=aff_rot%360;
            if(aff_rot<0)aff_rot=aff_rot+360;
            hud->setHudAngleTourelle(aff_rot);
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
            if(hitbox(i,j) &&est_dans_ecrant(i,j,W,H)&&
                    tab->est_traversable(x+i,y+j))
            {
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
