#-------------------------------------------------
#
# Project created by QtCreator 2017-12-15T17:02:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = filemanager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    properties.cpp \
    copy.cpp \
    copyworker.cpp \
    createfile.cpp

HEADERS  += mainwindow.h \
    properties.h \
    copy.h \
    copyworker.h \
    createfile.h

FORMS    += mainwindow.ui \
    properties.ui \
    createfile.ui
