#ifndef MASQUE_H
#define MASQUE_H
#include <QGraphicsRectItem>
#include "caisse.h"

class Masque: public QGraphicsRectItem
{
    private:

    public:
    Masque(Caisse c);
    bool peutBouger(Caisse c,QKeyEvent* event);
    bool hitbox(Caisse c, Point impact);
};

#endif // MASQUE_H
