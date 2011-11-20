# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:36:09
# -------------------------------------------------
QT -= core \
    gui
QT += sql
TARGET = ModuloCatalogo
TEMPLATE = lib
INCLUDEPATH = ../Persistencia

DEFINES += MODULOCATALOGO_LIBRARY

win32:DESTDIR = ../release
else:DESTDIR = /home/bagonzalez/Desktop/SI-BCUES/bin/

win32{
    LIBS += ../release/ModuloContable.dll \
    ../release/Basico.dll \
    ../release/Persistencia.dll
}else{
    LIBS +=  /home/bagonzalez/Desktop/SI-BCUES/bin/libBasico.so \
             /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloContable.so \
             /home/bagonzalez/Desktop/SI-BCUES/bin/libPersistencia.so
}


SOURCES += modulocatalogo.cpp \
    ModuloCatalogo/sources/RegistroCatalogo.cpp \
    ModuloCatalogo/sources/IngresoClaseCatalogo.cpp \
    ModuloCatalogo/sources/EspecificacionBien.cpp \
    ModuloCatalogo/sources/CatalogoActivoFijo.cpp \
    ModuloCatalogo/sources/ActualizacionCatalogo.cpp \
    ModuloCatalogo/sources/clase.cpp
HEADERS += modulocatalogo.h \
    ModuloCatalogo_global.h \
    ModuloCatalogo/headers/RegistroCatalogo.h \
    ModuloCatalogo/headers/IngresoClaseCatalogo.h \
    ModuloCatalogo/headers/EspecificacionBien.h \
    ModuloCatalogo/headers/CatalogoActivoFijo.h \
    ModuloCatalogo/headers/ActualizacionCatalogo.h \
    ModuloCatalogo/headers/clase.h
