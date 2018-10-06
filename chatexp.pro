#-------------------------------------------------
#
# Project created by QtCreator 2018-10-02T16:48:47
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatexp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chattable.cpp \
    chatitem.cpp \
    font/fontawesomeicons.cpp

HEADERS  += mainwindow.h \
    chattable.h \
    chatitem.h \
    font/fontawesomeicons.h

FORMS    += mainwindow.ui \
    chattable.ui

RESOURCES += \
    res.qrc
