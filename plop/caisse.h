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
    int angle=0;
public:
    //void keyPressEvent(QKeyEvent* event,Tourelle t);
    void keyPressEvent(QKeyEvent* event);
};

#endif // CAISSE_H
