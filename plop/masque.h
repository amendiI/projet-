#ifndef MASQUE_H
#define MASQUE_H
#include <QGraphicsRectItem>
#include "caisse.h"

class Masque: public QGraphicsRectItem
{
private:
    int angle;
public:
    Masque(Caisse c);
    bool peutBouger(QKeyEvent* event);
    bool hitbox(Point impact);
};

#endif // MASQUE_H
