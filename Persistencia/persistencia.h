#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "../ModuloContable/ModuloContable_global.h"
#include "../ModuloContable/modulocontable.h"
#include "../ModuloCatalogo/ModuloCatalogo_global.h"
#include "../ModuloCatalogo/modulocatalogo.h"
#include "../ModuloInventario/ModuloInventario_global.h"
#include "../ModuloInventario/ModuloInventario.h"
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"

#include "Persistencia_global.h"


using namespace basico;
using namespace contabilidad;
using namespace moduloinventario;

class PERSISTENCIASHARED_EXPORT  Persistencia {
public:

    friend class Usuario;

    friend class Unidad;



    Persistencia();

    Persistencia(Registro *registro);

    Persistencia(RegistroSistemaContable *regContable);

    Persistencia(RegistroCatalogo *regCatalogo);


    bool crearConexion(); 
    void cerrarConeccion();

    void guarda( basico::Unidad *);
    void cargar( basico::Unidad *);    

    void guarda( basico::Usuario *usuario);

    void cargar(contabilidad::Catalogo *catalogo);
    void guarda(contabilidad::Catalogo *catalogo);

    void cargar(contabilidad::Cuenta *cuenta);
    void guarda(contabilidad::Cuenta *cuenta);
    void actualizar(contabilidad::Cuenta *cuenta);

    void cargar(contabilidad::Subcuenta *cuenta);
    void guarda(contabilidad::Subcuenta *cuenta);

    void guarda(moduloinventario::IngresoClaseCatalogo *ingreso);
    void actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecActivoFijo *espec);
    void actualizar(moduloinventario::IngresoClaseCatalogo *ingreso, EspecMaterialBibliografico *espec);

    void guardarInfo(moduloinventario::EspecMaterialBibliografico *espec, string autor, string titulo, string apellido, string descripcion, string isbn );
    void guardarInfo(moduloinventario::EspecActivoFijo *espec, string marca, string modelo, string descripcion);

    void actualizarInfo(moduloinventario::EspecActivoFijo *espec, string marca, string modelo);
    void actualizarInfo(moduloinventario::EspecMaterialBibliografico *espec, string autor, string apellido, string titulo,  string isbn );

    void guarda(moduloinventario::Clase *clase);
    void cargar(CatalogoActivoFijo *catalogo);
    void cargar(InventarioActivoFijo *inventario, RegistroCatalogo *regCatalogo);

    int oidModelo(QString  modelo);

    int guardarIngresoBienes(QString Fecha, QString proveedor, QString noCEF, QString facturaProveedor, QString fechaFactura, QString noCSU , QString fechaCSU, QString fuentedeFondos, QString observaciones, QString tipoBien, QString Hora);
    int guardarBien(EspecActivoFijo *espec, QString correlativo, QString serie, float valor, QString fAdquisicion, int sector, QString modelo);

    void crearlineaIngreso(int codBien, int codigoIngreso,EspecActivoFijo *espec );

    std::map<int, string> cargarSectores();
    std::map<int, string> cargarProveedores();

    void setID(contabilidad::Cuenta *cuenta);
    void setID(moduloinventario::Clase *cuenta);
    void setID(moduloinventario::IngresoClaseCatalogo *ingreso);
    string getModelo(int oidModelo);
    string getMarca(int oidModelo);


    basico::Registro *registroBasico;

    RegistroSistemaContable *regContable;   

    RegistroCatalogo *regCatalogo;





};

#endif // PERSISTENCIA_H
