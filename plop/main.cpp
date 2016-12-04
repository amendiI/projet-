
#include <QApplication>
#include <QPushButton>
#include <QWidget>

#include <time.h>
#include <iostream>

#include "terrain.h"
#include "mainpage.h"
#include "tmp.h"
#include "option.h"
#include "fct.h"

using namespace std;


int main(int argc,char** argv)
{
    //srand (time(NULL));//initialise la fonction rand() pour tout le programme


    int t,vr1,vr2;
    char c;
    terrain* plat[320][180];

    QApplication app(argc,argv);
    mainpage w;
    w.show();
    QWidget fenetre;
    fenetre.setFixedSize(W,H);


    for(int i=0;i<320;i++)
    {
        for(int j=0;j<180;j++)
        {
            plat[i][j]=new terrain('v',true,0);
            plat[i][j]->setaff(i,j);
        }
    }
    for(int i=0;i<100;i++)
    {
        qsrand(20);
        t=(qrand()*10)%4;
        vr1=(qrand()*100)%320;
        vr2=(qrand()*100)%180;

        if(t==1)    c='a';
        if(t==2)    c='r';
        if(t==3)    c='c';
        else        c='o';
        plat[vr1][vr2]->settype(c);

    }

    Liste<int> l;
    return app.exec();
}
