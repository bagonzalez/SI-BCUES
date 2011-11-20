# -------------------------------------------------
# Project created by QtCreator 2009-10-02T22:27:43
# -------------------------------------------------
QT += sql \
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
    ../release/moduloinventario.dll
else:LIBS += /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloContable.so.1.0.0 \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloCatalogo.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libBasico.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libModuloInventario.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libPersistencia.so \
    /home/bagonzalez/Desktop/SI-BCUES/bin/libncreport.so.2.5.4
INCLUDEPATH = ../ncReport/includes
SOURCES += main.cpp \
    CatalogoContableGUI/nuevaCuenta.cpp \
    CatalogoContableGUI/cargaManual.cpp \
    VentanaPrincipalContables.cpp \
    CatalogoActivoFijoGUI/catalogoactivofijogui.cpp \
    UsuariosGUI/accesousuario.cpp \
    ConsultaIngresoGUI/consultaingreso.cpp \
    inicio/primerinicio.cpp \
    InventarioBienesGUI/ingresobienes.cpp \
    InventarioBienesGUI/descargobienes.cpp \
    InventarioBienesGUI/trasladoactivofijo.cpp \
    UsuariosGUI/agregarusuario.cpp \
    ConsultaDescargos/consultadescargos.cpp \
    ConsultaTraslados/consultatraslados.cpp \
    InventarioBienesGUI/ingresobienesbiblio.cpp \
    InventarioBienesGUI/descargobienesmb.cpp \
    InventarioBienesGUI/trasladobienesbiblio.cpp \
    gestionUsuarios/mainwindow.cpp \
    gestionUsuarios/libs/md5wrapper.cpp \
    gestionUsuarios/libs/md5.cpp \
    manualusuario.cpp \
    variacionpresupuestaria/verdocumentovariacion.cpp \
    variacionpresupuestaria/variacionpresupuestaria.cpp \
    variacionpresupuestaria/razonamiento.cpp \
    variacionpresupuestaria/presupuestoaprobado.cpp \
    variacionpresupuestaria/edicionvariavcion.cpp \
    variacionpresupuestaria/crearvariacion.cpp \
    inicio/seleccionarunidad.cpp \
    CatalogoActivoFijoGUI/dialogobuscarcuenta.cpp \
    CatalogoContableGUI/catalogocontable.cpp \
    CatalogoActivoFijoGUI/marcas.cpp \
    InventarioBienesGUI/sectoresgui.cpp \
    InventarioBienesGUI/mantenimientotitulo.cpp \
    progresoreporte.cpp \
    ConsultaIngresoGUI/ingresoenproceso.cpp \
    InventarioBienesGUI/consultabienes.cpp \
    ConsultaDescargos/descargosproceso.cpp \
    InventarioBienesGUI/manttoinventario.cpp \
    bienesporsector.cpp
HEADERS += CatalogoContableGUI/nuevaCuenta.h \
    CatalogoContableGUI/cargaManual.h \
    VentanaPrincipalContables.h \
    CatalogoActivoFijoGUI/catalogoactivofijogui.h \
    UsuariosGUI/accesousuario.h \
    ConsultaIngresoGUI/consultaingreso.h \
    inicio/primerinicio.h \
    InventarioBienesGUI/ingresobienes.h \
    InventarioBienesGUI/descargobienes.h \
    InventarioBienesGUI/trasladoactivofijo.h \
    UsuariosGUI/agregarusuario.h \
    ConsultaDescargos/consultadescargos.h \
    ConsultaTraslados/consultatraslados.h \
    InventarioBienesGUI/ingresobienesbiblio.h \
    InventarioBienesGUI/descargobienesmb.h \
    InventarioBienesGUI/trasladobienesbiblio.h \
    gestionUsuarios/mainwindow.h \
    gestionUsuarios/libs/md5wrapper.h \
    gestionUsuarios/libs/md5.h \
    manualusuario.h \
    variacionpresupuestaria/verdocumentovariacion.h \
    variacionpresupuestaria/variacionpresupuestaria.h \
    variacionpresupuestaria/razonamiento.h \
    variacionpresupuestaria/presupuestoaprobado.h \
    variacionpresupuestaria/edicionvariavcion.h \
    variacionpresupuestaria/crearvariacion.h \
    inicio/seleccionarunidad.h \
    CatalogoActivoFijoGUI/dialogobuscarcuenta.h \
    CatalogoContableGUI/catalogocontable.h \
    CatalogoActivoFijoGUI/marcas.h \
    InventarioBienesGUI/sectoresgui.h \
    InventarioBienesGUI/mantenimientotitulo.h \
    progresoreporte.h \
    ConsultaIngresoGUI/ingresoenproceso.h \
    InventarioBienesGUI/consultabienes.h \
    ConsultaDescargos/descargosproceso.h \
    InventarioBienesGUI/manttoinventario.h \
    bienesporsector.h
FORMS += CatalogoContableGUI/nuevaCuenta.ui \
    CatalogoContableGUI/cargaManual.ui \
    VentanaPrincipalContables.ui \
    CatalogoActivoFijoGUI/catalogoactivofijogui.ui \
    UsuariosGUI/accesousuario.ui \
    ConsultaIngresoGUI/consultaingreso.ui \
    inicio/primerinicio.ui \
    InventarioBienesGUI/ingresobienes.ui \
    InventarioBienesGUI/descargobienes.ui \
    InventarioBienesGUI/trasladoactivofijo.ui \
    UsuariosGUI/agregarusuario.ui \
    ConsultaDescargos/consultadescargos.ui \
    ConsultaTraslados/consultatraslados.ui \
    InventarioBienesGUI/ingresobienesbiblio.ui \
    InventarioBienesGUI/descargobienesmb.ui \
    InventarioBienesGUI/trasladobienesbiblio.ui \
    gestionUsuarios/mainwindow.ui \
    manualusuario.ui \
    variacionpresupuestaria/verdocumentovariacion.ui \
    variacionpresupuestaria/variacionpresupuestaria.ui \
    variacionpresupuestaria/razonamiento.ui \
    variacionpresupuestaria/presupuestoaprobado.ui \
    variacionpresupuestaria/edicionvariavcion.ui \
    variacionpresupuestaria/crearvariacion.ui \
    inicio/seleccionarunidad.ui \
    CatalogoActivoFijoGUI/dialogobuscarcuenta.ui \
    CatalogoContableGUI/catalogocontable.ui \
    CatalogoActivoFijoGUI/marcas.ui \
    InventarioBienesGUI/sectoresgui.ui \
    InventarioBienesGUI/mantenimientotitulo.ui \
    progresoreporte.ui \
    ConsultaIngresoGUI/ingresoenproceso.ui \
    InventarioBienesGUI/consultabienes.ui \
    ConsultaDescargos/descargosproceso.ui \
    InventarioBienesGUI/manttoinventario.ui \
    bienesporsector.ui
win32:DESTDIR = ../release
else:DESTDIR = /home/bagonzalez/Desktop/SI-BCUES/bin/
RC_FILE = si.rc
RESOURCES += ContablesPrincipal.qrc \
    recursosIconos.qrc
