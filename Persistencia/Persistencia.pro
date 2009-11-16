#-------------------------------------------------
#
# Project created by QtCreator 2009-11-01T09:58:40
#
#-------------------------------------------------

QT       += sql

TARGET = Persistencia
TEMPLATE = lib

win32:LIBS += ../release/Basico.dll \
            ../release/ModuloContable.dll \
            ../release/ModuloInventario.dll \
            ../release/ModuloCatalogo.dll


DEFINES += PERSISTENCIA_LIBRARY

SOURCES += persistencia.cpp

HEADERS += persistencia.h\
        Persistencia_global.h

win32 {
    DESTDIR = ../release
} else {
        DESTDIR = ../bin
}



