#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H


#include "Persistencia_global.h"

#include <QtGui/QApplication>
#include <QtCore/QMap>
#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"
#include "../ModuloInventario/ModuloInventario_global.h"
#include "../ModuloInventario/moduloinventario.h"
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"





using namespace basico;
using namespace contabilidad;
using namespace moduloinventario;


class PERSISTENCIASHARED_EXPORT  Persistencia {
public:


    Persistencia(int IDUnidad);


    Persistencia(Registro *registro);

    Persistencia(RegistroSistemaContable *regContable);

    Persistencia(RegistroCatalogo *regCatalogo);


    bool crearConexion(); 
    void cerrarConeccion();


    void guardarUnidad( basico::Unidad *);
    void cargarUnidad( basico::Unidad *);

    void guardarUsuario( basico::Usuario *usuario,  int oidunidad);

    void cargarCatalogoContable(contabilidad::Catalogo *catalogo, string tipoCuentaMadre);
    void guardarCatalogoContable(contabilidad::Catalogo *catalogo);

    void cargarCuentas(contabilidad::Cuenta *cuenta, int idCatalogo);
    void guardarCuenta(contabilidad::Cuenta *cuenta);
    void actualizarCuenta(contabilidad::Cuenta *cuenta);

    void cargarSubcuentas(contabilidad::Subcuenta *cuenta);
    void guardarSubcuenta(contabilidad::Subcuenta *cuenta);

    void guarda(moduloinventario::IngresoClaseCatalogo *ingreso);
    void actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecificacionBien *espec);    

    void cargarCatalogoAF(CatalogoActivoFijo *catalogo, int invActivoFijo);
    void cargarBienesInventario(InventarioActivoFijo *inventario, RegistroCatalogo *regCatalogo, string anioInventario);
    int getIDInvFijo(string anio);
    int getIDInvMB(QString anioInventario);


    int oidModelo(QString  modelo);
    int oidUnidad(QString unidad);

    int guardarIngresoBienes(QString Fecha, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString tipoBien, QString Hora, QString estadIngreso, QString codigoIngreso);
    void actualizarIngresoBienes(int idIngreso, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString estadoIngreso, QString codigoIngreso);
    int guardarBien(EspecificacionBien *espec, QString correlativo, QString serie, float valor, QString fAdquisicion, int sector, QString modelo, QString marca, QString codESpecifco, QString codigoBien, QString estadoBien, int idInventario);
    void actualizarBien(int idBien, EspecificacionBien *espec,  QString serie, float valor, QString fAdquisicion, int sector, QString modelo, QString marca, QString codESpecifco, QString estadoBien);

    int guardarBien(EspecificacionBien *espec, QString correlativo, float valor, QString fAdquisicion, QString titulo, QString isbn, QString especifico, QString codigo);

    bool crearlineaIngresoAF(int codBien, int codigoIngreso );
    bool crearlineaIngresoMB(int codBien, int codigoIngreso);
    //void crearlineaIngreso(int codBien, int codigoIngreso, EspecificacionBien *espec);

    int oidTitulo(QString titulo, QString isbn);
    int oidTituloAutor(QString titulo, QString isbn);

    std::map<int, string> cargarSectores();
    std::map<int, string> cargarProveedores();
    std::map<int, string> cargarNombreUnidades(int oidUnidad);
    std::map<int, string> cargarNombreUnidades();

    void setID(contabilidad::Cuenta *cuenta);

    void setID(moduloinventario::IngresoClaseCatalogo *ingreso);
    string getModelo(int oidModelo);
    string getMarca(int oidMarca);
    string getEspecifico(int oidEspecifico);
    string getNombreEspecifico(string codEspec);
    QString getTitulo(int idTitulo);
    QString getAutor(int idAutor);
    QString getApellido(int idAutor);
    QString getISBN(int idTitulo, int idAutor);
    int getIdInvAF();
    int getIdInvBiblio();

    QMap<QString, QString>  getListaBienesInvBiblio(QString anio, QString clase);

    void cambiaEstadoDescargado(Bien *bien);
    void cambiaEstadoDescargadoMB(Bien *bien);
    void cambiaEstadoTrasladado(Bien *bien);
    void cambiaEstadoTrasladadoMB(Bien *bien);

    int guardarDescargoBienes(QString FechaDescargo,  QString HoraDescargo,  QString observaciones, QString motivo, QString tipoBien, QString codigoBien,  QString estadoDescargo);
    bool actualizarDescargoBienes(int idDescargo, QString observaciones, QString motivo, QString codigoDescargo, QString estadoDescargo );
    void crearlineaDescargoAF(int codBien, int codigoDescargo);
    void crearlineaDescargoMB(int codBien, int codigoDescargo);

    int guardarTrasladoBienes(  int unidadRecibe,  QString tipoTraslado, QString tipoBien, QString FechaTraslado, QString HoraTraslado, QString observaciones, QString estadoDescargo,  QString codigoTraslado);
    void crearlineaTraslado(int codBien, int codigoTraslado);
    void crearlineaTrasladoMB(int codBien, int codigoTraslado);


    Bien * getBienMB(QString anioInventario, QString cuenta, QString correlativo, QString clase );

    QList<QString>  getListaCorelativosDisponiblesAF(int idEspec);
    QList<QString>  getListaCorelativosDisponiblesMB(int idEspec);
    QMap<int, QString>  getInventariosFijos();
    QMap<int, QString>  getInventariosBiblio();
    QList<QString>  getDatosBien(int idBien);

    void ingresarInventario(int anio, int unidad);
    void eliminarInventario(int idInventario );

    bool BEGIN();
    bool COMMINT();
    bool ROLLBACK();

    basico::Registro *registroBasico;

    RegistroSistemaContable *regContable;   

    RegistroCatalogo *regCatalogo;

    int idInventarioGeneral;
    int idInventarioBibliografico;
    int idInventarioActivoFijo;
    int idCatalogoCont;
    int IDUnidad;

};

#endif // PERSISTENCIA_H
