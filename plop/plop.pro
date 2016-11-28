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
        mainpage.cpp\
        terrain.cpp \
    tmp.cpp \
    point.cpp

HEADERS  += mainpage.h \
    terrain.h \
    tmp.h \
    option.h \
    fct.h \
    point.h

FORMS    += mainpage.ui
