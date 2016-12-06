#ifndef GRILLETERRAIN_H
#define GRILLETERRAIN_H

#include "point.h"
#include "terrain.h"
#include "option.h"
#include "segment.h"

class Grilleterrain
{
public:
    Grilleterrain(QGraphicsScene* scene);
    void creearbre(Point p);
    void creerocher(Point p);
    void creeriviere();
private:
    terrain* tabterrain[W/5][H/5];
};

#endif // GRILLETERRAIN_H
