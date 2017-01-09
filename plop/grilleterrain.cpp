#include "grilleterrain.h"



Grilleterrain::Grilleterrain(QGraphicsScene* scene)
{
    for(int i=0;i<W/5;i++)
    {
        for(int j=0;j<H/5;j++)
        {
            tabterrain[i][j]=new terrain('d',false,0,false);
            tabterrain[i][j]->setPixmap(QPixmap(IMG_default));
            tabterrain[i][j]->setOffset(i*5,j*5);
            scene->addItem(tabterrain[i][j]);
        }
    }
}

void Grilleterrain::initterrain()
{
    Point p;

    //creeriviere();

    for(int i=0;i<0;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        creearbre(p);
    }
    for(int i=0;i<0;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        creerocher(p);
    }
    for(int i=0;i<0;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        creecrevasse(p);
    }
}


//generation du terrain
//elle se base sur des cercles et l'equation (x-a)²+(y-b)²=r²
//le cercles sont positionné de façon plus ou moins aléatoire en fonction
//du terrain voulu.beaucoup de constantes dans ces fonctions sont utilisé
//pour faire un terrain esthétique.

void Grilleterrain::creearbre(Point p)
{
    int r=aleat(4,7);
    int var_terrain=aleat(2);
    int i,j;
    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
            && est_dans_ecrant(i,j,W,H)	/*test si le carré ne deborde pas de l'ecran*/
            && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
            {
                if(var_terrain)
                {
                    tabterrain[i][j]->setterrain('a',true,1,IMG_arbre2,true);
                }
                else tabterrain[i][j]->setterrain('a',true,1,IMG_arbre,true);

            }
        }
    }
}

void Grilleterrain::creerocher(Point p)
{
    int var_terrain=aleat(3);
    int r=aleat(3,7);
    int i,j;
    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
            && est_dans_ecrant(i,j,W,H)	/*test si le carré ne deborde pas de l'ecran*/
            && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
            {
                switch (var_terrain) {
                case 0:
                    tabterrain[i][j]->setterrain('r',true,7,IMG_rocher,true);
                    break;
                case 1:
                    tabterrain[i][j]->setterrain('r',true,7,IMG_rocher2,true);
                    break;
                case 2:
                    tabterrain[i][j]->setterrain('r',true,7,IMG_rocher3,true);
                    break;
                default:
                    break;
                }
            }
        }
    }
    //second cercle pour faire un rocher en patatoïde
    p.setx(p.getx()+aleat(r*2)-5);
    p.sety(p.gety()+(aleat(r*2)-5));
    r=aleat(2,7);

    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
            && est_dans_ecrant(i,j,W,H)	/*test si le carré ne deborde pas de l'ecran*/
            && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
            {
                tabterrain[i][j]->setterrain('r',true,7,IMG_rocher,true);
            }
        }
    }
}

void Grilleterrain::creeriviere()
{
    int var_terrain=aleat(2);
    Point p;
    p.setx(aleat(W/5));
    p.sety(0);
    int r=8;

    for(int k=0;k<20;k++)
    {
        for(int i=p.getx()-r;i<p.getx()+r;i++)
        {
            for(int j=p.gety()-r;j<p.gety()+r;j++)
            {
                if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
                && est_dans_ecrant(i,j,W,H)	/*test si le carré ne deborde pas de l'ecran*/
                && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
                {
                    if(var_terrain)
                    {
                        tabterrain[i][j]->setterrain('r',true,1,IMG_eau2,false);
                    }
                    else tabterrain[i][j]->setterrain('r',true,1,IMG_eau,false);

                }
            }
        }
        p.sety(p.gety()+r/2);
        p.setx(p.getx()+aleat(r*2)-r);
    }
}

void Grilleterrain::creecrevasse(Point p)
{
    int r=aleat(4,7);
    int i,j;
    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
            && est_dans_ecrant(i,j,W,H)	/*test si le carré ne deborde pas de l'ecran*/
            && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
            {
                tabterrain[i][j]->setterrain('a',false,1,IMG_crevasse,false);
            }
        }
    }

}

bool Grilleterrain::est_traversable(int x,int y)
{
    return tabterrain[x][y]->getbloque();
}
