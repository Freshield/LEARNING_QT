#-------------------------------------------------
#
# Project created by QtCreator 2013-02-27T14:11:23
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = DNS
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    cserver.cpp \
    ctaskthd.cpp

HEADERS += \
    qt.h \
    cserver.h \
    ctaskthd.h
