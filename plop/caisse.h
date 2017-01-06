#ifndef CAISSE_H
#define CAISSE_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "option.h"
#include "Point.h"
#include "tourelle.h"

class Caisse : public QGraphicsPixmapItem
{
private:
    Tourelle* tourelle;
    int angle;
    int pm;
public:
    Caisse();
    void deplacement();
    void keyPressEvent(QKeyEvent* event);
    void setAngle(int x){angle=x;}
    void setPm(int x){pm=x;}
    Tourelle* getTourelle(){return tourelle;}
    int getPm(){return pm;}
    int getangle(){return angle;}
};

#endif // CAISSE_H
