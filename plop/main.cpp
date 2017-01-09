
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
    int tour=0;
    vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    grille->initterrain();
    Hud* hud=new Hud(1);
    Hud* hud2=new Hud(2);
    Tank* tank = new Tank(grille,"tiger",Point(100,100),scene,hud);
    Tank* tank2 = new Tank(grille,"kv1",Point(W-100,H-100),scene,hud2);
    tank2->setRotation(tank2->rotation()+180);
    tank2->getTourelle()->setRotation(tank2->getTourelle()->rotation()+180);
    tank->afficheTank(scene);
    tank2->afficheTank(scene);
    hud->afficheHud(scene);
    hud2->afficheHud(scene);

    vue->show();
    vue->setFixedSize(W,H);
    scene->setSceneRect(0,0,W,H);

    if(tank->estVivant()&&tank2->estVivant())
    {
        if(tour%2)
        {
            tank2->deplacement();
        }
        else tank->deplacement();
    }
    else
    {
        QGraphicsTextItem gagne;
        gagne.setTextInteractionFlags(Qt::NoTextInteraction);
        gagne.setPos(310,300);
        gagne.setTextWidth(200);
        gagne.setDefaultTextColor(QColor(255,255,255,255));
        if(tank->estVivant())
        {
            gagne.setPlainText(QString("Joueur 1 (Tiger) a gagné !"));
        }
        else gagne.setPlainText(QString("Joueur 1 (Tiger) a gagné !"));
        scene->addItem(&gagne);
    }


    vue->setScene(scene);

    return a.exec();
}
