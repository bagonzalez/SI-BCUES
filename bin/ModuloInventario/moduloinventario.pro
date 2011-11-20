# -------------------------------------------------
# Project created by QtCreator 2009-11-08T16:49:00
# -------------------------------------------------
QT += core \
    gui
TARGET = moduloinventario
TEMPLATE = lib
win32:DESTDIR = ../release
else:DESTDIR = ../bin
win32:LIBS += ../release/Basico.dll \
    ../release/ModuloCatalogo.dll \
    ../release/ModuloContable.dll \
    ../release/Persistencia.dll
else:LIBS += ../bin/libBasico.so \
    ../bin/libModuloCatalogo.so \
    ../bin/libModuloContable.so
DEFINES += MODULOINVENTARIO_LIBRARY
SOURCES += moduloinventario.cpp \
    sources/InventarioActivoFijo.cpp \
    sources/Bien.cpp
HEADERS += moduloinventario.h \
    moduloinventario_global.h \
    headers/InventarioActivoFijo.h \
    headers/Bien.h
