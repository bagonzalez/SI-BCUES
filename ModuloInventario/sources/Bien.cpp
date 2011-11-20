#include "../headers/Bien.h"

#include "../../ModuloContable/ModuloContable_global.h"
#include "../../ModuloContable/modulocontable.h"

//#include "../../Persistencia/persistencia_global.h"
//#include "../../Persistencia/persistencia.h"

using namespace contabilidad;

namespace moduloinventario {

    Bien::Bien(){

    }

    Bien::Bien(EspecificacionBien *_especFijo, float _valor, Fecha *_fechaAdquisicion, string _correlativo, bool nuevo){
        this->especFijo=_especFijo;
        this->especBiblio=NULL;
        this->valor=_valor;
        this->fechaAdquisicion=_fechaAdquisicion;       
        this->correlativo=_correlativo;
        this->tipoBien=0;

        if(nuevo){
            especFijo->clase->cuentaAsignada->cargarCuenta(_valor);
            //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            //servicioPersistencia->actualizar(especFijo->clase->cuentaAsignada);
        }
    }


    Bien::Bien( float _valor, EspecificacionBien *_especBiblio, Fecha *_fechaAdquisicion, string _correlativo, bool nuevo){
        this->especBiblio=_especBiblio;
        this->especFijo=NULL;
        this->valor=_valor;
        this->fechaAdquisicion=_fechaAdquisicion;
        this->correlativo=_correlativo;
        this->tipoBien=1;

        if(nuevo){
            this->especBiblio->clase->cuentaAsignada->cargarCuenta(_valor);            
            //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            //servicioPersistencia->actualizar(especBiblio->clase->cuentaAsignada);
        }


        std::cout << "mi correlativo -->" <<correlativo;
    }

    void Bien::setDescargado(){

        especFijo->clase->cuentaAsignada->abonarCuenta(this->valor);
        //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        //servicioPersistencia->actualizar(especFijo->clase->cuentaAsignada);

    }

    void Bien::setDescargadoMB(){

        especBiblio->clase->cuentaAsignada->abonarCuenta(this->valor);
        //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
        //servicioPersistencia->actualizar(especBiblio->clase->cuentaAsignada);
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

    EspecificacionBien * Bien::getEspecAF(){
        return this->especFijo;
    }

    EspecificacionBien * Bien::getEspecMB(){
        return this->especBiblio;
    }

    int Bien::getTipoBien(){
        return this->tipoBien;
    }

    float Bien::getValor(){
        return this->valor;
    }

    void Bien::setValor(float valor){
        this->valor=valor;
    }

    string Bien::getSerie(){
        return this->serie;
    }

    void Bien::setEspecifico(string espec){
        this->especifico=espec;
    }

    string Bien::getEspecifico(){
        return this->especifico;
    }

    void Bien::setFechaAdquisicion(Fecha *fechaAdq){
        this->fechaAdquisicion=fechaAdq;
    }

    Fecha * Bien::getFechaAdquisicion(){
        return this->fechaAdquisicion;
    }

    void Bien::setDescripcionClase(string descripcionC){
        this->descripcionClase=descripcionC;
    }

    string Bien::getDescripcionClase(){
        return this->descripcionClase;
    }

    string Bien::getNombreEspecifico(){
        return this->nombreEspecifico;
    }

    void Bien::setNombreEspecifico(string nombre){
        this->nombreEspecifico=nombre;
    }

    int Bien::getOID(){
        return this->oid;
    }
}


