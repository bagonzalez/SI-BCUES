# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:27:43
# -------------------------------------------------
QT += sql \
    svg \
    xml \
    xmlpatterns
TARGET = SI-BCUES
TEMPLATE = app
win32:LIBS += ../debug/ModuloContable.dll \
    ../debug/ModuloCatalogo.dll
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
DESTDIR = ../debug
RESOURCES += ContablesPrincipal.qrc
