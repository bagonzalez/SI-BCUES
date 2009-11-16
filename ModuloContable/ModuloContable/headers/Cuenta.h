/***************************************************************************
 *   Copyright (C) 2008-2009 by Bruno Gonzalez                             *
 *   El Salvador                                                           *
 *   bruno2d@linux.ues.edu.sv                                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#ifndef _CUENTA_H
#define _CUENTA_H



using namespace std;
#include <map>
#include <list>
#include <string>
#include "../../ModuloContable_global.h"

namespace contabilidad {
class Subcuenta;
class Catalogo;


enum tipoCuenta {
  rubro,
  categoria,
  cuenta

};
class MODULOCONTABLESHARED_EXPORT Cuenta {
  public:
    Cuenta(string _nombreCuenta, int _codigoCuenta, string descripcion, Catalogo *catalogo, int id, Cuenta *_cuentaMadre, tipoCuenta x  );

    Cuenta(string _nombreCuenta, int _codigoCuenta, string _descripcion, Catalogo *catalogo);

    virtual ~Cuenta();

    Cuenta(string _nombre, int _codigo, tipoCuenta x, string descripcion, Catalogo *catalogo , bool nueva, int _id);

    void cargarCuenta(float cantidadImporte);

    void abonarCuenta(float cantidadImporte);

    void setSaldarCuenta();

    float getSaldo();

    void ajustarCuenta(float cantidadAjustar);

    string getNombreCuenta();

    bool getSaldada();

    virtual float getDebe();

    void setTipoC();

    bool existeCodigoSubcuenta(int codigo);

    virtual float getHaber();

    virtual string getDescripcion();

    int getcodigoCuenta();

    Subcuenta * crearSubCuenta(string nombreSubcuenta, tipoCuenta x, string descricion);
    
    Subcuenta * crearSubCuenta(string nombreSubcuenta, tipoCuenta x, int codigo, string descricion, int id, bool nueva);

    Subcuenta * getSubCuenta(string nombreCuenta);

    tipoCuenta getTipoC();

    std::list<string> getListaHijos();

    map<int, string> getCodigosHijos();

    Cuenta * cuentaMadre;

    void setID();

    void setID(int id);

    int getID();

  public:
    virtual void setNombreCuenta(string _nombreCuenta);

    float debe;

    float haber;

    int codigoCuenta;

    string nombreCuenta;

    string descripcion;

    bool cuentaSaldada;

    tipoCuenta tipoC;

    string tipoCuent;

    map<string,Subcuenta*> mySubcuenta;

    int id;

  public:
    Catalogo * myCatalogo;

};

}
#endif
