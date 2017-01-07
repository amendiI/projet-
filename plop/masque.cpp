#include "masque.h"



Masque::Masque(Tank t)
{
    setRect(c.x(),c.y(),45,25);
    setRotation(c.rotation());
}

bool Masque::peutBouger(Caisse c,QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_D:
        setRotation(rotation()+45);
        break;
    case Qt::Key_Q:
        setRotation(rotation()-45);
        break;
    case Qt::Key_Z:
        switch (c.getAngle()%8)
        {
        case 0:
            setPos( x()+5, y());
            break;
        case 1:
            setPos( x()+5, y()+5);
            break;
        case 2:
            setPos( x(), y()+5);
            break;
        case 3:
            setPos( x()-5, y()+5);
            break;
        case 4:
            setPos( x()-5, y());
            break;
        case 5:
            setPos( x()-5, y()-5);
            break;
        case 6:
            setPos( x(), y()-5);
            break;
        case 7:
            setPos( x()+5, y()-5);
            break;
        default:
            break;
        }

        break;
    case Qt::Key_S:

        break;
    default:
        break;
    }
}
