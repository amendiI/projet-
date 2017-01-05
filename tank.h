#ifndef TANK_H
#define TANK_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Tank//:public QGraphicsPixmapItem
{
private:
    QGraphicsPixmapItem * spriteCaisse;
    QGraphicsPixmapItem * spriteTourelle;
    int angle;

public:
    Tank();
    void keyPressEvent(QKeyEvent* event);
    void afficheTank(QGraphicsScene *scene);
};




#endif // TANK_H
