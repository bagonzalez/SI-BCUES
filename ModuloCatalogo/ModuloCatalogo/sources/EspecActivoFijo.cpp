#include <QSqlQuery>
#include  <iostream>
#include "../headers/EspecActivoFijo.h"

namespace moduloinventario {

EspecActivoFijo::EspecActivoFijo(int _id, Clase *claseAsig) : EspecificacionBien(_id, claseAsig)
{
}


void EspecActivoFijo::setDescripcion(string _descripcion){    
    this->descripcion=_descripcion;    
    std::cout << " MI DESCRIPCION ---> " << descripcion;
}

void EspecActivoFijo::setMarca(string _marca){
    bool existe=false;



    for
    (
        list<fabricante*>::iterator from = this->_fabricante.begin();
        from != this->_fabricante.end();
        ++from
    ){
            if(((*from)->marca)==_marca)
                existe=true;
    }

        if(!existe){
             fabricante *nuevo=new fabricante();
             nuevo->marca=_marca;
             this->_fabricante.push_back(nuevo);

        }
}

void EspecActivoFijo::setModelo(string marca, string _modelo){
    bool existe=false;
    for
    (
        list<fabricante*>::iterator from = this->_fabricante.begin();
        from != this->_fabricante.end();
        ++from
    ){
            if( ((*from)->marca)==marca){

                for
                (
                list<string>::iterator item = (*from)->modelo.begin();
                item != (*from)->modelo.end();
                ++item
                ){
                    if((*item)==_modelo)
                        existe=true;

                }
                if(!existe)
                    (*from)->modelo.push_back(_modelo);
            }
    }
}

string  EspecActivoFijo::getDescipcion(){
    return this->descripcion;
}


std::list<string> EspecActivoFijo::getMarcas(){    
    std::list<string> lista;

    for
    (
        list<fabricante*>::iterator from = this->_fabricante.begin();
        from != this->_fabricante.end();
        ++from
    ){
            lista.push_back((*from)->marca);
    }

     return lista;
 }

std::list<string> EspecActivoFijo::getModelos(string marca){

    std::list<string> lista;

    for
    (
        list<fabricante*>::iterator from = this->_fabricante.begin();
        from != this->_fabricante.end();
        ++from
    ){
            if(((*from)->marca)==marca)
            {
                for
                (
                    list<string>::iterator item = (*from)->modelo.begin();
                    item != (*from)->modelo.end();
                    ++item
                ){
                        lista.push_back(*item);
                }
            }
    }

     return lista;
 }

int EspecActivoFijo::getOID(){
    return this->oid;
}

void EspecActivoFijo::guardar(){
    //QSqlQuery query;
       // query.exec("INSERT INTO");

}

}
