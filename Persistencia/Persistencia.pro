# -------------------------------------------------
# Project created by QtCreator 2009-11-01T09:58:40
# -------------------------------------------------
QT += gui core sql

TARGET = Persistencia
TEMPLATE = lib

win32{
    LIBS += ../release/Basico.dll \
    ../release/ModuloContable.dll \
    ../release/moduloinventario.dll \
    ../release/ModuloCatalogo.dll
}else{
    LIBS += /home/bagonzalez/Desktop/SI-BCUES/bin/libBasico.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloContable.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloInventario.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloCatalogo.so
}

DEFINES += PERSISTENCIA_LIBRARY
SOURCES += persistencia.cpp \
    persist_basico.cpp \
    persist_catalogo.cpp \
    persist_contable.cpp \
    persist_inventario.cpp
HEADERS += persistencia.h \
    Persistencia_global.h

win32:DESTDIR = ../release
else:DESTDIR = /home/bagonzalez/Desktop/SI-BCUES/bin
