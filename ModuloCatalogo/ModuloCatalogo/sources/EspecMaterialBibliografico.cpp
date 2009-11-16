
#include "../headers/EspecMaterialBibliografico.h"
#include <iostream>
#include <cstring>

namespace moduloinventario {

EspecMaterialBibliografico::EspecMaterialBibliografico(int _id, Clase *claseAsig):EspecificacionBien(_id, claseAsig)
{


}

void EspecMaterialBibliografico::setTitulo(string _autor, string _apellidos, string _titulo, string isbn){


    int codTitulo;

    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){

           if( ((*from)->nombreAutor)==_autor && ((*from)->apellidoAutor) == _apellidos ){

                    if(!isbn.empty()){
                        (*from)->listaTitulos[isbn]=_titulo;
                    }
                    else{
                        codTitulo=(*from)->otrosTitulos.size();
                        (*from)->otrosTitulos[codTitulo]=_titulo;
                    }
            }
    }
}


void EspecMaterialBibliografico::setAutor(string _autor, string _apellidoAutor){

    bool existe=false;
    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){
            if(((*from)->nombreAutor)==_autor && ((*from)->apellidoAutor)==_apellidoAutor)
                existe=true;

            std::cout << "Autor -->" << _autor << std::endl;
    }

        if(!existe){
             autor *nuevo=new autor();
             nuevo->nombreAutor=_autor;
             nuevo->apellidoAutor=_apellidoAutor;
             this->contedorAutores.push_back(nuevo);
        }
}


void EspecMaterialBibliografico::setDescripcion(string _descripcion){
    this->descripcion=_descripcion;
}

string EspecMaterialBibliografico::getDescripcion(){
    return this->descripcion;
}

std::map <string, string> EspecMaterialBibliografico::getTitulos(string _autor, string _apellidos){
    std::map <string, string> listaT;

    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){
            if( ((*from)->nombreAutor)==_autor && ((*from)->apellidoAutor) == _apellidos ){
                return listaT=(*from)->listaTitulos;
            }
    }

    return listaT;
}

std::map <int, string> EspecMaterialBibliografico::getOtrosTitulos(string _autor, string _apellidos){
    std::map <int, string> listaT;

    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){
            if( ((*from)->nombreAutor)==_autor && ((*from)->apellidoAutor) == _apellidos ){
                return listaT=(*from)->otrosTitulos;
            }
    }

    return listaT;
}

std::list <string> EspecMaterialBibliografico::getNAutores(){
     std::list <string> listaAutores;

    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){
             listaAutores.push_back((*from)->nombreAutor);

    }
    return listaAutores;
}

std::list <string> EspecMaterialBibliografico::getApellidosAutores(){
     std::list <string> listaAutores;

    for
    (
        list<autor*>::iterator from = this->contedorAutores.begin();
        from != this->contedorAutores.end();
        ++from
    ){
             listaAutores.push_back((*from)->apellidoAutor);
    }
    return listaAutores;
}

}
