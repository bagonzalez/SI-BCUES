#include "../headers/Bien.h"

#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"

#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"

using namespace contabilidad;

namespace moduloinventario {

    Bien::Bien(EspecActivoFijo *_especFijo, float _valor, Fecha *_fechaAdquisicion, string _correlativo){
        this->especFijo=_especFijo;
        this->valor=_valor;
        this->fechaAdquisicion=_fechaAdquisicion;       
        this->correlativo=_correlativo;
        this->tipoBien=0;
        especFijo->clase->cuentaAsignada->cargarCuenta(_valor);
        especFijo->clase->idEspecifico->abonarCuenta(_valor);

        Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->actualizar(especFijo->clase->cuentaAsignada);
        servicioPersistencia->actualizar(especFijo->clase->idEspecifico);
    }


    Bien::Bien(EspecMaterialBibliografico *_especBiblio, float _valor, Fecha *_fechaAdquisicion, string _correlativo){
        this->especBiblio=_especBiblio;
        this->valor=_valor;
        this->fechaAdquisicion=_fechaAdquisicion;
        this->correlativo=_correlativo;
        this->tipoBien=1;
        especBiblio->clase->cuentaAsignada->cargarCuenta(_valor);
        especBiblio->clase->idEspecifico->abonarCuenta(_valor);

        Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        servicioPersistencia->actualizar(especBiblio->clase->cuentaAsignada);
        servicioPersistencia->actualizar(especBiblio->clase->idEspecifico);

        std::cout << "mi correlativo -->" <<correlativo;
    }

    void Bien::setOID(int _oid){
        this->oid=_oid;
    }

    void Bien::setSerie(string _serie){
        this->serie=_serie;
    }

    void Bien::setSector(int idSector){
        this->idSectorDestino=idSector;
    }

    void Bien::setidTitulo(int _idTitulo){
        this->idTitulo=_idTitulo;
    }

    void Bien::setidModelo(int idModelo){
        this->idModelo=idModelo;
    }

    EspecActivoFijo * Bien::getEspecAF(){
        return this->especFijo;
    }

    EspecMaterialBibliografico * Bien::getEspecMB(){
        return this->especBiblio;
    }

    int Bien::getTipoBien(){
        return this->tipoBien;
    }

    float Bien::getValor(){
        return this->valor;
    }

    string Bien::getSerie(){
        return this->serie;
    }
}


