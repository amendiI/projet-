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
    int angle_tourelle;
    int angle_canon;
public:
    Tourelle();
    void keyPressEvent(QKeyEvent* event);
    void set_angle_tourelle(int x){angle_tourelle=x;}
    void set_angle_canon(int x){angle_canon=x;}
};

#endif // TOURELLE_H
