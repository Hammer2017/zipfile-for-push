#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T19:23:34
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = untitled
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += NOCRYPT


SOURCES += main.cpp \
        ./_Public_util_sources/ziphelper.cpp \
        ./_Public_util_sources/unzip.c \
        ./_Public_util_sources/zip.c \
        ./_Public_util_sources/ioapi.c


HEADERS += ./_Public_util_sources/ziphelper.h

INCLUDEPATH += "./_Public_util_sources"

INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/include/QtZlib

LIBS += -lsetupapi


