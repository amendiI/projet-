#ifndef GRILLETERRAIN_H
#define GRILLETERRAIN_H

#include "point.h"
#include "terrain.h"
#include "option.h"

class Grilleterrain
{
public:
    Grilleterrain();
    void creearbre(Point p);
    void creerocher(Point p);

    void affichegrille(QGraphicsScene* scene);
private:
    terrain* tabterrain[W/5][H/5];
    int tabresistance[W/5][H/5];
    QGraphicsPixmapItem* image[W/5][H/5];
    terrain T[5];
};

#endif // GRILLETERRAIN_H
