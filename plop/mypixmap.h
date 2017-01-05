#ifndef MYPIXMAP_H
#define MYPIXMAP_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

#include "option.h"
#include "Point.h"

class MyPixmap : public QGraphicsPixmapItem
{
private:
    int angle=0;
public:
    void keyPressEvent(QKeyEvent* event);
};
#endif // MYPIXMAP_H
