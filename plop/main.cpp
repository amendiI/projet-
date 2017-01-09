
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include <time.h>
#include <iostream>


#include "terrain.h"
#include "tank.h"
#include "tir.h"

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
    Hud* hud=new Hud(1);
    Hud* hud2=new Hud(2);
    Tank* tank = new Tank(grille,"tiger",Point(100,100),scene,hud);
    Tank* tank2 = new Tank(grille,"kv1",Point(W-100,H-100),scene,hud2);

    grille->creedefault(tank->getcentre());
    grille->creedefault(tank2->getcentre());

    tank2->setRotation(tank2->rotation()+180);
    tank2->getTourelle()->setRotation(tank2->getTourelle()->rotation()+180);
    tank->afficheTank(scene);
    tank2->afficheTank(scene);
    hud->afficheHud(scene);
    hud2->afficheHud(scene);

    vue->setFixedSize(W,H);
    scene->setSceneRect(0,0,W,H);
    vue->setScene(scene);
    vue->show();


    //while(!tank2->perdu()&&!tank2->perdu())
    //{
        tank2->deplacement();
        tank->deplacement();
    //}

    return a.exec();
}
