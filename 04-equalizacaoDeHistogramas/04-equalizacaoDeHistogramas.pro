#-------------------------------------------------
#
# Project created by QtCreator 2017-03-27T10:47:32
#
#-------------------------------------------------
CONFIG += c++14
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 04-equalizacaoDeHistogramas
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    histograma.cpp

HEADERS  += mainwindow.h \
    histograma.h

FORMS    += mainwindow.ui
