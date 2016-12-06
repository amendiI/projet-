
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

    Grilleterrain* grille= new Grilleterrain(scene);

    Point p;
    for(int i=0;i<20;i++)
    {
        p.setx(aleat(W/5));
        p.sety(aleat(H/5));
        grille->creearbre(p);
}



    vue->show();
    //vue->setFixedSize(W,H);
    //scene->setSceneRect(0,0,W,H);

    return a.exec();
}
