# -------------------------------------------------
# Project created by QtCreator 2009-10-02T15:20:14
# -------------------------------------------------
QT -= core \
    gui
TARGET = ModuloContable
win32 {
    DESTDIR = ../release
} else {
        DESTDIR = ../bin
}

win32:LIBS += ../release/Basico.dll\
              ../release/Persistencia.dll

TEMPLATE = lib
DEFINES += MODULOCONTABLE_LIBRARY
SOURCES += modulocontable.cpp \
    ModuloContable/sources/Transaccion.cpp \
    ModuloContable/sources/Tiempo.cpp \
    ModuloContable/sources/Subcuenta.cpp \
    ModuloContable/sources/RegistroSistemaContable.cpp \
    ModuloContable/sources/PeriodoContable.cpp \
    ModuloContable/sources/LineaDeTransaccion.cpp \
    ModuloContable/sources/Fecha.cpp \
    ModuloContable/sources/Cuenta.cpp \
    ModuloContable/sources/Catalogo.cpp
HEADERS += modulocontable.h \
    ModuloContable_global.h \
    ModuloContable/headers/Transaccion.h \
    ModuloContable/headers/Tiempo.h \
    ModuloContable/headers/Subcuenta.h \
    ModuloContable/headers/RegistroSistemaContable.h \
    ModuloContable/headers/PeriodoContable.h \
    ModuloContable/headers/LineaDeTransaccion.h \
    ModuloContable/headers/Fecha.h \
    ModuloContable/headers/Cuenta.h \
    ModuloContable/headers/Catalogo.h


