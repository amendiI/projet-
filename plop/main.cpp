
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

    Grilleterrain* grille= new Grilleterrain();

    Point p;
    p.setx(20);
    p.sety(20);
    grille->creearbre(p);
    grille->affichegrille(scene);



    vue->show();
    vue->setFixedSize(W,H);
    scene->setSceneRect(0,0,W,H);

    return a.exec();
}
