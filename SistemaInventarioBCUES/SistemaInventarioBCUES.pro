# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:27:43
# -------------------------------------------------
QT += sql \
    svg \
    xml \
    xmlpatterns
TARGET = SistemaInventarioBCUES
TEMPLATE = app
win32:LIBS += ../bin/ModuloContable.dll \
    ../bin/ModuloCatalogo.dll \
    ../bin/ncreport.dll
SOURCES += main.cpp \
    CatalogoContableGUI/nuevaCuenta.cpp \
    CatalogoContableGUI/contgeneral.cpp \
    CatalogoContableGUI/cargaManual.cpp \
    VentanaPrincipalContables.cpp \
    CatalogoActivoFijoGUI/catalogoactivofijogui.cpp
HEADERS += CatalogoContableGUI/nuevaCuenta.h \
    CatalogoContableGUI/contgeneral.h \
    CatalogoContableGUI/cargaManual.h \
    VentanaPrincipalContables.h \
    CatalogoActivoFijoGUI/catalogoactivofijogui.h
FORMS += CatalogoContableGUI/nuevaCuenta.ui \
    CatalogoContableGUI/contgeneral.ui \
    CatalogoContableGUI/cargaManual.ui \
    VentanaPrincipalContables.ui \
    CatalogoActivoFijoGUI/catalogoactivofijogui.ui
DESTDIR = ../bin
RESOURCES += ContablesPrincipal.qrc
