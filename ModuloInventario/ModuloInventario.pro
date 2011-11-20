#-------------------------------------------------
#
# Project created by QtCreator 2010-07-19T19:50:34
#
#-------------------------------------------------

QT       -= gui

TARGET = ModuloInventario
TEMPLATE = lib

win32:DESTDIR = ../release
else:DESTDIR = /home/bagonzalez/Desktop/SI-BCUES/bin/
win32:LIBS += ../release/Basico.dll \
    ../release/ModuloCatalogo.dll \
    ../release/ModuloContable.dll \
    ../release/Persistencia.dll
else:LIBS +=  /home/bagonzalez/Desktop/SI-BCUES/bin/libBasico.so \
     /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloCatalogo.so \
     /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloContable.so

DEFINES += MODULOINVENTARIO_LIBRARY

SOURCES += moduloinventario.cpp \
    sources/InventarioActivoFijo.cpp \
    sources/Bien.cpp

HEADERS += moduloinventario.h\
        ModuloInventario_global.h \
    headers/InventarioActivoFijo.h \
    headers/Bien.h
