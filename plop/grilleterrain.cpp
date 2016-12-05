#include "grilleterrain.h"



Grilleterrain::Grilleterrain()
{
    T[0].setterrain('n',0);
    T[1].setterrain('a',1);
    T[2].setterrain('r',1);
    T[3].setterrain('c',false);
    T[4].setterrain('e',1);
    for(int i=0;i<W/5;i++)
    {
        for(int j=0;j<H/5;j++)
        {
            tabterrain[i][j]=&T[0];
            tabresistance[i][j]=0;

            image[i][j]=new QGraphicsPixmapItem();
            image[i][j]->setPixmap(QPixmap(IMG_default));
            image[i][j]->setPixmap(QPixmap(IMG_crevasse));
        }
    }
}

//generation du terrain

void Grilleterrain::creearbre(Point p)
{
    int r=aleat(3,6);
    cout<<"p.x="<<p.getx()<<endl;
    cout<<"p.y="<<p.gety()<<endl;
    cout<<"r= "<<r<<endl;
    int i,j;
    for(i=p.getx()-r;i<p.getx()+r;i++)
    {
        for(j=p.gety()-r;j<p.gety()+r;j++)
        {
            cout<<(i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())+r*r<<endl;
            if(((i-p.getx())*(i-p.getx())+(j-p.gety())*(j-p.gety())+r*r<=0)	/*test si le carré est dans le cercle*/
            && i>0 && j>0
            && i<W/5 && j<H/5	/*test si le carré ne deborde pas de l'ecran*/
            && &T[0]==tabterrain[i][j])/*test si la case est nulle*/
            {
                cout<<"p="<<i<<" "<<j<<endl;
                tabterrain[i][j]=&T[1];
                tabresistance[i][j]=1;
                image[i][j]->setPixmap(QPixmap(IMG_arbre));
            }
        }
    }
}

// attention le carré généré par p doit etre entierement dans le terrain
//a modifier
void Grilleterrain::creerocher(Point p)
{
/*
    int n=aleat(30,200);
    int ttmp[W][H];
    int vrand;
    Liste<Point> l;
    Point destr,ptmp;
    Node<Point>* node;

    //initialisation du tableau
    for(int i=0; i < n ; i++)
    {
        for(int j=0; j < n ; j++)
        {
            ttmp[i][j]=1;
        }
    }

    for(int i=0; i < 3 ; i++)
    {

        //determine les coordonnées du point initialement détruit
        vrand=aleat(4);
        switch(vrand)
        {
            case 1:
            destr.setx(0);
            destr.sety(aleat(n));
            break;
            case 2:
            destr.setx(n-1);
            destr.sety(aleat(n));
            break;
            case 3:
            destr.sety(0);
            destr.setx(aleat(n));
            break;
            case 4:
            destr.sety(3-1);
            destr.setx(aleat(n));
            break;
            default:
            cerr<<"erreur dans le case"<<endl;
            break;
        }

        ttmp[destr.getx()][destr.gety()]=0;

        //detruit en cascade 1/9eme du roché crée
        for(int j=0;j<n/9;j++)
        {
            ptmp.setx(destr.getx());
            ptmp.sety(destr.gety());

            //4 test pour voir si l'on sort du tableau et que la case contient un "pixel" de rocher
            if(ttmp[destr.getx()+1<n &&destr.getx()+1][destr.gety()]==1)
            {
                ptmp.setx(ptmp.getx()+1);
                l.setnext(ptmp);
            }
            if(ttmp[destr.gety()+1<n && destr.getx()][destr.gety()+1]==1)
            {
                ptmp.sety(ptmp.gety()+1);
                l.setnext(ptmp);
            }
            if(ttmp[destr.getx()-1>0 && destr.getx()][destr.gety()-1]==1)
            {
                ptmp.sety(ptmp.gety()-1);
                l.setnext(ptmp);
            }
            if(ttmp[destr.getx()-1>0 && destr.getx()-1][destr.gety()]==1)
            {
                ptmp.setx(ptmp.getx()-1);
                l.setnext(ptmp);
            }

            vrand=aleat(l.size());
            node=l.getHead();
            for(int k=0;k<vrand;k++)
            {
                node=node->getNext();
            }
            destr=node->getVal();
            ttmp[destr.getx()][destr.gety()]=0;
            tabterrain[i][j]=&T[2];
            tabresistance[i][j]=7;

        }
    }
*/
}


//affichage

void Grilleterrain::affichegrille(QGraphicsScene* scene)
{
    for (int i = 0; i < W/5; i++)
    {
        for (int j = 0; j < H/5; j++)
        {
            image[i][j]->setOffset(i*5,j*5);
            scene->addItem(image[i][j]);
        }
    }
}
