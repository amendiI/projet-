#include "caisse.h"
#include "tourelle.h"

//void Caisse::keyPressEvent(QKeyEvent *event,Tourelle t)
//{
//    if(pm>0)
//    {
//        if(angle<0)
//        {
//            angle=angle+8;
//        }
//        if(event->key() ==Qt::Key_D)
//        {
//            setRotation(rotation()+45);
//            t.setRotation(rotation()+45);
//            angle++;
//        }
//        else if(event->key() ==Qt::Key_Q)
//        {
//           setRotation(rotation()-45);
//           t.setRotation(rotation()+45);
//            angle--;
//        }
//        else if(event->key() ==Qt::Key_Z)
//        {
//            switch (angle%8)
//            {
//            case 0:
//                setPos( x()+5, y());
//                t.setPos( t.x()+5, t.y());
//                break;
//            case 1:
//                setPos( x()+5, y()+5);
//                t.setPos( t.x()+5, t.y()+5);
//                break;
//            case 2:
//                setPos( x(), y()+5);
//                t.setPos( t.x(), t.y()+5);
//                break;
//            case 3:
//                setPos( x()-5, y()+5);
//                t.setPos( t.x()-5, t.y()+5);
//                break;
//            case 4:
//                setPos( x()-5, y());
//                t.setPos( t.x()-5, t.y());
//                break;
//            case 5:
//                setPos( x()-5, y()-5);
//                t.setPos( t.x()-5, t.y()-5);
//                break;
//            case 6:
//                setPos( x(), y()-5);
//                t.setPos( t.x(), t.y()-5);
//                break;
//            case 7:
//                setPos( x()+5, y()-5);
//                t.setPos( t.x()+5, t.y()-5);
//                break;
//            default:
//                break;
//            }
//            pm--;
//        }
//        else if(event->key() ==Qt::Key_S)
//        {
//            switch (angle%8)
//            {
//            case 0:
//                setPos( x()-5, y());
//                t.setPos( t.x()-5, t.y());
//                break;
//            case 1:
//                setPos( x()-5, y()-5);
//                t.setPos( t.x()-5, t.y()-5);
//                break;
//            case 2:
//                setPos( x(), y()-5);
//                t.setPos( t.x(), t.y()-5);
//                break;
//            case 3:
//                setPos( x()+5, y()-5);
//                t.setPos( t.x()+5, t.y()-5);
//                break;
//            case 4:
//                setPos( x()+5, y());
//                t.setPos( t.x()+5, t.y());
//                break;
//            case 5:
//                setPos( x()+5, y()+5);
//                t.setPos( t.x()+5, t.y()+5);
//                break;
//            case 6:
//                setPos( x(), y()+5);
//                t.setPos( t.x(), t.y()+5);
//                break;
//            case 7:
//                setPos( x()-5, y()+5);
//                t.setPos( t.x()-5, t.y()+5);
//                break;
//            default:
//                break;
//            }
//            pm--;
//        }
//    }
//}

void Caisse::keyPressEvent(QKeyEvent *event)
{
    if(pm>0)
    {
        if(angle<0)
        {
            angle=angle+8;
        }
        if(event->key() ==Qt::Key_D)
        {
            setRotation(rotation()+45);
            angle++;
        }
        else if(event->key() ==Qt::Key_Q)
        {
           setRotation(rotation()-45);
            angle--;
        }
        else if(event->key() ==Qt::Key_Z)
        {
            switch (angle%8)
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
            pm--;
        }
        else if(event->key() ==Qt::Key_S)
        {
            switch (angle%8)
            {
            case 0:
                setPos( x()-5, y());
                break;
            case 1:
                setPos( x()-5, y()-5);
                break;
            case 2:
                setPos( x(), y()-5);
                break;
            case 3:
                setPos( x()+5, y()-5);
                break;
            case 4:
                setPos( x()+5, y());
                break;
            case 5:
                setPos( x()+5, y()+5);
                break;
            case 6:
                setPos( x(), y()+5);
                break;
            case 7:
                setPos( x()-5, y()+5);
                break;
            default:
                break;
            }
            pm--;
        }
    }
}
