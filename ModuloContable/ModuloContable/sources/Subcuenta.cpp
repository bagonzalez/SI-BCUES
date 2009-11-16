
#include "../headers/Subcuenta.h"


#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"


namespace contabilidad {

Subcuenta::Subcuenta(string nombreCuenta, int codSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo, int _id, bool nueva, tipoCuenta x): Cuenta(nombreCuenta, codSubcuenta, descripcion, catalogo, _id, madre, x)
{
    this->id=_id;
    this->cuentaMadre=madre;
    this->tipoC=x;
    this->setTipoC();


     if(nueva){        
        Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->guarda(this);        

    }
    else{       
         Persistencia::Persistencia *servicioPersistencia=new Persistencia();
         servicioPersistencia->cargar(this);         
     }
}

Subcuenta::Subcuenta(string nombreSubcuenta, int codigoSubcuenta, Cuenta * madre, string descripcion, Catalogo *catalogo):Cuenta(nombreCuenta, codigoSubcuenta, descripcion, catalogo)
{
    //this->nombreCuenta=nombreSubcuenta;
    this->cuentaMadre=madre;
    this->tipoC=cuenta;
   // this->tipoC=cuenta;
   // this->setTipoC();

    // Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    // servicioPersistencia->guarda(this);
}

Subcuenta::~Subcuenta(){
}

}
