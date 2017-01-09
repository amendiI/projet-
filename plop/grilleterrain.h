#ifndef GRILLETERRAIN_H
#define GRILLETERRAIN_H

#include "point.h"
#include "terrain.h"
#include "option.h"
#include "segment.h"
#include "fct.h"

class Grilleterrain
{
public:
    Grilleterrain(QGraphicsScene* scene);
    void initterrain();

    void creearbre(Point p);
    void creerocher(Point p);
    void creeriviere();
    void creecrevasse(Point p);
    bool est_traversable(int x,int y);
    bool nontraversableobus(Point p);
    char getypeterrain(int i,int j){return tabterrain[i][j]->gettype();}
    void changeterrain(int i,int j){tabterrain[i][j]->setimage();}//pour debug
private:
    terrain* tabterrain[W/5][H/5];
};

#endif // GRILLETERRAIN_H
