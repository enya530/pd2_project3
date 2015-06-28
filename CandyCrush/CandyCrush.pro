#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T21:03:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CandyCrush
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blank.cpp \
    destroy.cpp \
    star.cpp \
    horizontal.cpp \
    vertical.cpp \
    nineblock.cpp \
    gameover.cpp

HEADERS  += mainwindow.h \
    blank.h \
    destroy.h \
    star.h \
    horizontal.h \
    vertical.h \
    nineblock.h \
    gameover.h

FORMS    += mainwindow.ui \
    gameover.ui

RESOURCES += \
    pic.qrc
