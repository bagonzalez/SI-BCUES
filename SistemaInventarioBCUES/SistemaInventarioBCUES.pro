# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:27:43
# -------------------------------------------------
QT += sql \
    svg \
    xml \
    gui \
    core \
    webkit
TARGET = SI-BCUES
TEMPLATE = app
CONFIG += warn_on \
    qt \
    thread \
    release
win32:LIBS += ../release/ModuloContable.dll \
    ../release/ModuloCatalogo.dll \
    ../release/Basico.dll \
    ../ncReport/lib/ncreport2.dll \
    ../release/Persistencia.dll \
    ../release/ModuloInventario.dll
INCLUDEPATH = ../ncReport/includes
SOURCES += main.cpp \
    CatalogoContableGUI/nuevaCuenta.cpp \
    CatalogoContableGUI/contgeneral.cpp \
    CatalogoContableGUI/cargaManual.cpp \
    VentanaPrincipalContables.cpp \
    CatalogoActivoFijoGUI/catalogoactivofijogui.cpp \
    UsuariosGUI/accesousuario.cpp \
    ConsultaIngresoGUI/consultaingreso.cpp \
    inicio/primerinicio.cpp \
    InventarioBienesGUI/ingresobienes.cpp \
    InventarioBienesGUI/descargobienes.cpp \
    InventarioBienesGUI/trasladoactivofijo.cpp
HEADERS += CatalogoContableGUI/nuevaCuenta.h \
    CatalogoContableGUI/contgeneral.h \
    CatalogoContableGUI/cargaManual.h \
    VentanaPrincipalContables.h \
    CatalogoActivoFijoGUI/catalogoactivofijogui.h \
    UsuariosGUI/accesousuario.h \
    ConsultaIngresoGUI/consultaingreso.h \
    inicio/primerinicio.h \
    InventarioBienesGUI/ingresobienes.h \
    InventarioBienesGUI/descargobienes.h \
    InventarioBienesGUI/trasladoactivofijo.h
FORMS += CatalogoContableGUI/nuevaCuenta.ui \
    CatalogoContableGUI/contgeneral.ui \
    CatalogoContableGUI/cargaManual.ui \
    VentanaPrincipalContables.ui \
    CatalogoActivoFijoGUI/catalogoactivofijogui.ui \
    UsuariosGUI/accesousuario.ui \
    ConsultaIngresoGUI/consultaingreso.ui \
    inicio/primerinicio.ui \
    InventarioBienesGUI/ingresobienes.ui \
    InventarioBienesGUI/descargobienes.ui \
    InventarioBienesGUI/trasladoactivofijo.ui
DESTDIR = ../release
RESOURCES += ContablesPrincipal.qrc
