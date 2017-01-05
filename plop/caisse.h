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
    int angle;
    int pm;
public:
//  void keyPressEvent(QKeyEvent* event,Tourelle t);
    void keyPressEvent(QKeyEvent* event);
    void setAngle(int x){angle=x;}
    void setPm(int x){pm=x;}
};

#endif // CAISSE_H
