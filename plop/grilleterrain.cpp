#include "grilleterrain.h"



Grilleterrain::Grilleterrain(QGraphicsScene* scene)
{
    for(int i=0;i<W/5;i++)
    {
        for(int j=0;j<H/5;j++)
        {
            tabterrain[i][j]=new terrain('d',false,0);
            tabterrain[i][j]->setPixmap(QPixmap(IMG_default));
            tabterrain[i][j]->setOffset(i*5,j*5);
            scene->addItem(tabterrain[i][j]);
        }
    }
}

//generation du terrain

void Grilleterrain::creearbre(Point p)
{
    int r=aleat(4,7);
    int i,j;
    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())-r*r<0)	/*test si le carré est dans le cercle*/
            && i>0 && j>0
            && i<W/5 && j<H/5	/*test si le carré ne deborde pas de l'ecran*/
            && 'd'==tabterrain[i][j]->gettype())/*test si la case est nulle*/
            {
                tabterrain[i][j]->setterrain('a',false,1,IMG_arbre);
            }
        }
    }
}

// attention le carré généré par p doit etre entierement dans le terrain
//a modifier
void Grilleterrain::creerocher(Point p)
{

}

void Grilleterrain::creeriviere()
{
    Point p;
    int direction;
    p.setx(aleat(W/5));
    p.sety(0);

    for(int i=0;i<aleat(30,100);i++)
    {
        direction=aleat(2);
        for(int j=0;j<5;j++)
        {
            if(direction)
            {

            }
            else
            {

            }
        }
    }
}
