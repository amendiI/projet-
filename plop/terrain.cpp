#include "terrain.h"

 //terrain::terrain(QObject *parent) : QObject(parent){}
int aleat(int min,int max)
{
    return (rand()%(max-min+1))+min;
}

int aleat(int n)
{
    return rand()%n;
}


 terrain::terrain(char t,bool b,int r)
 {
     type=t;
     bloque=b;
     resistance=r;
 }

 void terrain::impact()
 {

 }

char terrain::gettype()         const{return type;}
bool terrain::getbloque()       const{return bloque;}
int  terrain::getresistance()   const{return resistance;}

void terrain::setall(char type,bool bloque,int resistance)
{
    this->type=type;
    this->bloque=bloque;
    this->resistance=resistance;
}

void terrain::settype(char type)            {this->type=type;}
void terrain::setbloque(bool bloque)        {this->bloque=bloque;}
void terrain::setresistance(int resistance) {this->resistance=resistance;}
void terrain::setaff(int x,int y)           {this->aff=new QRect(x,y,5,5);}

//generation du terrain

void terrain::creearbre(Point p,terrain*** T)
{
    int r=aleat(3,6);
    int i,j;
    for(i=p.getx()-r;i<2*r+1;i++)
    {
        for(j=p.gety()-r;j<2*r+1;j++)
        {
            if(i*i+j*j-r*r<=0	/*test si le carré est dans le cercle*/
            && i>0 && j>0
            && i<W && j<H	/*test si le carré ne deborde pas de l'ecran*/
            && T[i][j]==NULL)/*test si la case est nulle*/
                T[i][j]=new terrain('a',false,Resarbre);
        }
    }
}


// attention le carré généré par p doit etre entierement dans le terrain

void terrain::creerocher(Point p,terrain*** T)
{
/*    int n=aleat(30,200);
    int ttmp[30][30];
    int vrand;
    Liste<int> l;
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
            T[i][j]=new terrain('e',false,12);

        }
    }
*/
}
