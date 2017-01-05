#include "caisse.h"
#include "tourelle.h"

//void Caisse::keyPressEvent(QKeyEvent *event,Tourelle t)
//{
//    if(angle<0)
//    {
//        angle=angle+8;
//    }
//    if(event->key() ==Qt::Key_D)
//    {
//        setRotation(rotation()+45);
//        t.setRotation(rotation()+45);
//        angle++;
//    }
//    else if(event->key() ==Qt::Key_Q)
//       {
//           setRotation(rotation()-45);
//           t.setRotation(rotation()-45);
//            angle--;
//        }
//        else if(event->key() ==Qt::Key_Z)
//        {
//            if(angle%8==0)
//            {
//                 setPos( x()+5, y());
//                 t.setPos( t.x()+5, t.y());
//            }
//            else if(angle%8==1)
//            {
//                 setPos( x()+5, y()+5);
//                 t.setPos( t.x()+5, t.y()+5);
//            }
//            else if(angle%8==2)
//            {
//                 setPos( x(), y()+5);
//                 t.setPos( t.x(), t.y()+5);
//            }
//            else if(angle%8==3)
//            {
//                 setPos( x()-5, y()+5);
//                 t.setPos( t.x()-5, t.y()+5);

//            }
//            else if(angle%8==4)
//            {
//                 setPos( x()-5, y());
//                 t.setPos( t.x()-5, t.y());
//            }
//            else if(angle%8==5)
//            {
//                setPos( x()-5, y()-5);
//                t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==6)
//            {
//                 setPos( x(), y()-5);
//                 t.setPos( t.x(), t.y()-5);

//            }
//            else if(angle%8==7)
//            {
//                 setPos( x()+5, y()-5);
//                 t.setPos( t.x()+5, t.y()-5);
//            }
//        }
//        else   if(event->key() ==Qt::Key_S)
//        {
//            if(angle%8==0)
//            {
//                 setPos( x()-5, y());
//                 t.setPos( t.x()-5, t.y());


//            }
//            else if(angle%8==1)
//            {
//                 setPos( x()-5, y()-5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==2)
//            {
//                 setPos( x(), y()-5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==3)
//            {
//                 setPos( x()+5, y()-5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==4)
//            {
//                 setPos( x()+5, y());
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==5)
//            {
//                 setPos( x()+5, y()+5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==6)
//            {
//                 setPos( x(), y()+5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//            else if(angle%8==7)
//            {
//                 setPos( x()-5, y()+5);
//                 t.setPos( t.x()-5, t.y()-5);
//            }
//        }
//}

void Caisse::keyPressEvent(QKeyEvent *event)
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
            if(angle%8==0)
            {
                 setPos( x()+5, y());
            }
            else if(angle%8==1)
            {
                 setPos( x()+5, y()+5);
            }
            else if(angle%8==2)
            {
                 setPos( x(), y()+5);
            }
            else if(angle%8==3)
            {
                 setPos( x()-5, y()+5);
            }
            else if(angle%8==4)
            {
                 setPos( x()-5, y());
            }
            else if(angle%8==5)
            {
                setPos( x()-5, y()-5);
            }
            else if(angle%8==6)
            {
                 setPos( x(), y()-5);
            }
            else if(angle%8==7)
            {
                 setPos( x()+5, y()-5);
            }
        }
        else   if(event->key() ==Qt::Key_S)
        {
            if(angle%8==0)
            {
                 setPos( x()-5, y());

            }
            else if(angle%8==1)
            {
                 setPos( x()-5, y()-5);
            }
            else if(angle%8==2)
            {
                 setPos( x(), y()-5);
            }
            else if(angle%8==3)
            {
                 setPos( x()+5, y()-5);
            }
            else if(angle%8==4)
            {
                 setPos( x()+5, y());
            }
            else if(angle%8==5)
            {
                 setPos( x()+5, y()+5);
            }
            else if(angle%8==6)
            {
                 setPos( x(), y()+5);
            }
            else if(angle%8==7)
            {
                 setPos( x()-5, y()+5);
            }
        }
}
