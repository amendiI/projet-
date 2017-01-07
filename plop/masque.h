#ifndef MASQUE_H
#define MASQUE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "tank.h"

class Masque: public QGraphicsRectItem
{
    private:

    public:
    Masque(Tank t,int angle);
};

#endif // MASQUE_H
