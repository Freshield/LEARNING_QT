#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T21:30:48
#
#-------------------------------------------------

QT       += core gui

TARGET = tcpServer
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    clientjobs.cpp

HEADERS  += server.h \
    clientjobs.h

FORMS    += server.ui

QT += network
