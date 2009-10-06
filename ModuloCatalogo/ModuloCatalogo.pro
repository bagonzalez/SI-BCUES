# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:36:09
# -------------------------------------------------
QT -= core \
    gui
TARGET = ModuloCatalogo
TEMPLATE = lib
DEFINES += MODULOCATALOGO_LIBRARY
win32 {
    DESTDIR = ../bin
} else {
        DESTDIR = ../bin
}
SOURCES += modulocatalogo.cpp \
    ModuloCatalogo/sources/RegistroCatalogo.cpp \
    ModuloCatalogo/sources/IngresoClaseCatalogo.cpp \
    ModuloCatalogo/sources/EspecMaterialBibliografico.cpp \
    ModuloCatalogo/sources/EspecificacionBien.cpp \
    ModuloCatalogo/sources/EspecActivoFijo.cpp \
    ModuloCatalogo/sources/CatalogoActivoFijo.cpp \
    ModuloCatalogo/sources/ActualizacionCatalogo.cpp
HEADERS += modulocatalogo.h \
    ModuloCatalogo_global.h \
    ModuloCatalogo/headers/RegistroCatalogo.h \
    ModuloCatalogo/headers/IngresoClaseCatalogo.h \
    ModuloCatalogo/headers/EspecMaterialBibliografico.h \
    ModuloCatalogo/headers/EspecificacionBien.h \
    ModuloCatalogo/headers/EspecActivoFijo.h \
    ModuloCatalogo/headers/CatalogoActivoFijo.h \
    ModuloCatalogo/headers/ActualizacionCatalogo.h
