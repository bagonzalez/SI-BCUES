
#include "../headers/EspecMaterialBibliografico.h"

namespace moduloinventario {

EspecMaterialBibliografico::EspecMaterialBibliografico(int _id, Subcuenta *cuentaAsig)
{
    this->idEspecificacion=_id;
    this->cuentaAsignada=cuentaAsig;
}


void EspecMaterialBibliografico::setAutor(string _autor){
    this->autor=_autor;
}

void EspecMaterialBibliografico::setTitulo(string _titulo){
    int id=titulo.size()+1;
    this->titulo[id]=_titulo;
}

void EspecMaterialBibliografico::setISBN(string _isbn){
    this->isbn=_isbn;
}
}
