#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T15:28:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plop
TEMPLATE = app


SOURCES += main.cpp\
        terrain.cpp \
    Point.cpp \
    grilleterrain.cpp \
    fct.cpp \
    segment.cpp \
    tank.cpp \
    hud.cpp \
    mypixmap.cpp \
    caisse.cpp \
    tourelle.cpp

HEADERS  += \
    terrain.h \
    option.h \
    Point.h \
    grilleterrain.h \
    fct.h \
    segment.h \
    tank.h \
    hud.h \
    caisse.h \
    tourelle.h

RESOURCES += \
    res.qrc

