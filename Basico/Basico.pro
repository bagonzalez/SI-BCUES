# -------------------------------------------------
# Project created by QtCreator 2009-10-11T21:02:47
# -------------------------------------------------
QT -= core \
    gui
TARGET = Basico
TEMPLATE = lib
win32 {
    DESTDIR = ../release
} else {
        DESTDIR = ../bin
}


win32:LIBS += ../release/Persistencia.dll


DEFINES += BASICO_LIBRARY
SOURCES += basico.cpp \
    sources/Usuario.cpp \
    sources/Unidad.cpp \
    sources/SistemaInventario.cpp \
    sources/Registro.cpp
HEADERS += basico.h \
    Basico_global.h \
    headers/Usuario.h \
    headers/Unidad.h \
    headers/SistemaInventario.h \
    headers/Registro.h
