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
private:
    terrain* tabterrain[W][H];
    int tabresistance[W][H];
    terrain T[5];
};

#endif // GRILLETERRAIN_H