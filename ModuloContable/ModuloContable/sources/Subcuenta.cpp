#include "../headers/Subcuenta.h"


#include "../Persistencia/Persistencia_global.h"
#include "../Persistencia/persistencia.h"


namespace contabilidad
{

    Subcuenta::Subcuenta(string nombreCuenta, string codSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo, int _id, bool nueva, tipoCuenta x, tipoDestino _tipoDes): Cuenta(nombreCuenta, codSubcuenta, descripcion, catalogo, _id, madre, x, _tipoDes)
    {
        this->id=_id;
        this->cuentaMadre=madre;
        this->tipoC=x;
        this->setTipoC();
        this->tipoDes=_tipoDes;
        this->setTipoDes();


        if (nueva)
        {
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(catalogo->unidad->id);
            servicioPersistencia->guardarSubcuenta(this);

        }
        else
        {
            Persistencia::Persistencia *servicioPersistencia=new Persistencia(catalogo->unidad->id);
            servicioPersistencia->cargarSubcuentas(this);
        }
    }

    Subcuenta::Subcuenta(string nombreSubcuenta, string codigoSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo):Cuenta(nombreCuenta, codigoSubcuenta, descripcion, catalogo)
    {
        //this->nombreCuenta=nombreSubcuenta;
        this->cuentaMadre=madre;
        this->tipoC=cuenta;
        // this->tipoC=cuenta;
        // this->setTipoC();

         Persistencia::Persistencia *servicioPersistencia=new Persistencia(catalogo->unidad->id);
        servicioPersistencia->guardarSubcuenta(this);
    }

    Subcuenta::~Subcuenta()
    {
    }

}
