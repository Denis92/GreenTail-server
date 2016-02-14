#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T13:32:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += network

TARGET = green_tail
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gtserver.cpp

HEADERS  += mainwindow.h \
    gtserver.h

FORMS    += mainwindow.ui
