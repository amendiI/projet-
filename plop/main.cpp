
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
#include "tank.h"

using namespace std;

int main(int argc,char** argv)
{
    srand(time(NULL));//initialise la fonction rand() pour tout le programme

    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene();
    QGraphicsView* vue= new QGraphicsView(scene);
    Grilleterrain* grille= new Grilleterrain(scene);

    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    grille->initterrain();

    Tank* tank = new Tank();
    tank->afficheTank(scene);



    vue->show();
    vue->setFixedSize(W,H);
    scene->setSceneRect(0,0,W,H);

    tank->deplacement();
    vue->setScene(scene);
    return a.exec();
}
