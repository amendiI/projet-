#ifndef TOURELLE_H
#define TOURELLE_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "option.h"
#include "Point.h"

class Tourelle : public QGraphicsPixmapItem
{
private:
    int angle=0;
public:
    void keyPressEvent(QKeyEvent* event);
};

#endif // TOURELLE_H
