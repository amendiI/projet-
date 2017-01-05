
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include <time.h>
#include <iostream>

#include "terrain.h"
#include "option.h"
#include "grilleterrain.h"

using namespace std;

int main(int argc,char** argv)
{
    srand(time(NULL));//initialise la fonction rand() pour tout le programme

    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene();
    QGraphicsView* vue= new QGraphicsView(scene);

    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Grilleterrain* grille= new Grilleterrain(scene);

    Point p;

    grille->creeriviere();

    for(int i=0;i<50;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        grille->creearbre(p);
    }
    for(int i=0;i<30;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        grille->creerocher(p);
    }



    vue->show();
    //vue->setFixedSize(W,H);
    //scene->setSceneRect(0,0,W,H);

    return a.exec();
}
