#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T22:08:57
#
#-------------------------------------------------

QT       += core gui

TARGET = tcpClient
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    submitdialog.cpp \
    seeallbiddialog.cpp \
    biditemdialog.cpp \
    bidpricedialog.cpp

HEADERS  += client.h \
    submitdialog.h \
    seeallbiddialog.h \
    biditemdialog.h \
    bidpricedialog.h

FORMS    += client.ui \
    submitdialog.ui \
    seeallbiddialog.ui \
    biditemdialog.ui \
    bidpricedialog.ui

QT += network
