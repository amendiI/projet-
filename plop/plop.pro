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
    liste.cpp \
    grilleterrain.cpp \
    fct.cpp \
    segment.cpp

HEADERS  += \
    terrain.h \
    option.h \
    Point.h \
    liste.h \
    grilleterrain.h \
    fct.h \
    segment.h

RESOURCES += \
    res.qrc

