
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
    //srand(time(NULL));//initialise la fonction rand() pour tout le programme

    QApplication a(argc,argv);
    QGraphicsScene* scene= new QGraphicsScene();


    //Grilleterrain* grille= new Grilleterrain();
    //grille->affichegrille(scene);

    //terrain* t= new terrain();
    //t->affichage(scene);
    //t->setOffset(5,5);

    QGraphicsPixmapItem* p=new QGraphicsPixmapItem();
    p->setPixmap(QPixmap(":/images/river1.png"));
    p->setOffset(50,50);
    scene->addItem(p);

    QGraphicsView* vue= new QGraphicsView(scene);
    vue->show();
    //vue->setFixedSize(W,H);
    //scene->setSceneRect(0,0,W,H);

23
    return a.exec();
}
