#-------------------------------------------------
#
# Project created by QtCreator 2016-08-05T23:10:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teste
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    notafiscal.cpp \
    ajuda.cpp

HEADERS  += mainwindow.h \
    notafiscal.h \
    ajuda.h

FORMS    += mainwindow.ui \
    ajuda.ui

RESOURCES += \
    incon.qrc
