


#include "../headers/InventarioActivoFijo.h"
#include <QString>



#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


namespace moduloinventario {

InventarioActivoFijo::InventarioActivoFijo(){    
}


Bien * InventarioActivoFijo::crearBien(EspecificacionBien *especBien, float valor, Fecha *fechaAdquisicion, int estado, bool nuevoBien){
        Bien  *nuevo;

        string correlativoString="0000";

        int correlativonum=this->contenedorBienesAF.size()+1;

        nuevo=new Bien(especBien, valor, fechaAdquisicion,correlativoString, nuevoBien );
        nuevo->estadoBien=estado;
        contenedorBienesAF[correlativonum]=nuevo;
        return nuevo;
}

Bien * InventarioActivoFijo::crearBien(Fecha *fechaAdquisicion, EspecificacionBien *especBien, float valor, int estado, bool nuevoBien){
        Bien  *nuevo;
        string correlativoString;
        int correlativonum=this->contenedorBienesMB.size()+1;
        correlativoString=correlativoMB(especBien->clase->nombreClase);
        std::cout << "Correlativo--->"  << correlativoString << endl;

        nuevo=new Bien( valor, especBien, fechaAdquisicion,correlativoString, nuevoBien );
        nuevo->estadoBien=estado;
        contenedorBienesMB[correlativonum]=nuevo;
        return nuevo;
}

string InventarioActivoFijo::correlativoAF(string nombreClase){
    string correlativoString;
    int cuenta=1;
    EspecificacionBien *especAF;

    for
    (
         map<int, Bien*>::iterator it = contenedorBienesAF.begin();
         it != contenedorBienesAF.end();
         ++it
     ){
               especAF=(it->second)->getEspecAF();
               if(especAF->clase->nombreClase==nombreClase)
                   cuenta++;
     }

       if(cuenta%10000>0 && cuenta/10000==0){
            correlativoString=QString::number(cuenta).toStdString();
        }

        if(cuenta%1000>0  && cuenta/1000==0){
            correlativoString=QString("0"+QString::number(cuenta)).toStdString();
        }

        if(cuenta%100>0 && cuenta/100==0 ){
            correlativoString=QString("00"+QString::number(cuenta)).toStdString();
        }

        if(cuenta%10>0 && cuenta/10==0 ){
            correlativoString=QString("000"+QString::number(cuenta)).toStdString();
        }
        return correlativoString;
}


string InventarioActivoFijo::correlativoMB(string nombreClase){
    string correlativoString;
    int cuenta=1;


    EspecificacionBien *especBienBB;
    EspecificacionBien *especAF;

    for
    (
         map<int, Bien*>::iterator it = contenedorBienesMB.begin();
         it != contenedorBienesMB.end();
         ++it
     ){

               especBienBB=(it->second)->getEspecMB();
                if(especBienBB->clase->nombreClase==nombreClase)
                   cuenta++;
      }

       if(cuenta%100000>0 && cuenta/100000==0){
              correlativoString=QString::number(cuenta).toStdString();
       }


       if(cuenta%10000>0 && cuenta/10000==0){
            correlativoString=QString::number(cuenta).toStdString();
        }

        if(cuenta%1000>0  && cuenta/1000==0){
            correlativoString=QString("0"+QString::number(cuenta)).toStdString();
        }

        if(cuenta%100>0 && cuenta/100==0 ){
            correlativoString=QString("00"+QString::number(cuenta)).toStdString();
        }

        if(cuenta%10>0 && cuenta/10==0 ){
            correlativoString=QString("000"+QString::number(cuenta)).toStdString();
        }
        return correlativoString;
}



std::list<string> InventarioActivoFijo::getCorrelativosAF(string clase, string cuentaAsignada){

    std::list<string> listaCorrelativos;

    for
     (
                map<int, Bien*>::iterator it = contenedorBienesAF.begin();
                it != contenedorBienesAF.end();
                ++it
     ){

                    if((it->second)->getEspecAF()->getClase()->getCuentaAsignada()==cuentaAsignada){
                        if((it->second)->getEspecAF()->getClase()->getNombreClase()==clase){
                            if((it->second)->estadoBien==1){
                                listaCorrelativos.push_back((it->second)->correlativo);
                            }
                        }
                    }
     }

     return listaCorrelativos;
}

std::list<string> InventarioActivoFijo::getCorrelativosMB(string clase, string cuentaAsignada){

    std::list<string> listaCorrelativos;

    for
     (
                map<int, Bien*>::iterator it = contenedorBienesMB.begin();
                it != contenedorBienesMB.end();
                ++it
     ){

                    if((it->second)->getEspecMB()->getClase()->getCuentaAsignada()==cuentaAsignada){
                        if((it->second)->getEspecMB()->getClase()->getNombreClase()==clase){
                            if((it->second)->estadoBien==1){
                                listaCorrelativos.push_back((it->second)->correlativo);
                            }
                        }
                    }
     }
     return listaCorrelativos;
}

Bien * InventarioActivoFijo::getBienAF(string clase, string cuentaAsignada, string correlativo){
    
     for
     (
                map<int, Bien*>::iterator it = contenedorBienesAF.begin();
                it != contenedorBienesAF.end();
                ++it
     ){

                    if((it->second)->getEspecAF()->getClase()->getCuentaAsignada()==cuentaAsignada){
                        if((it->second)->getEspecAF()->getClase()->getNombreClase()==clase){
                            if((it->second)->correlativo==correlativo)
                                return (it->second);
                        }
                    }
     }
      return NULL;
    
}


Bien * InventarioActivoFijo::getBienMB(string clase, string cuentaAsignada, string correlativo){

     for
     (
                map<int, Bien*>::iterator it = contenedorBienesMB.begin();
                it != contenedorBienesMB.end();
                ++it
     ){

                    if((it->second)->getEspecMB()->getClase()->getCuentaAsignada()==cuentaAsignada){
                        if((it->second)->getEspecMB()->getClase()->getNombreClase()==clase){
                            if((it->second)->correlativo==correlativo)
                                return (it->second);
                        }
                    }
     }
      return NULL;

}

void InventarioActivoFijo::cargarInventario(moduloinventario::RegistroCatalogo *regCatalogo, int idUnidad, string anio){
    Persistencia::Persistencia *servicioPersistencia=new Persistencia(idUnidad);
    servicioPersistencia->cargarBienesInventario(this, regCatalogo,  anio);
}

void InventarioActivoFijo::limpiarContenedor(){
    this->contenedorBienesAF.clear();
    this->contenedorBienesMB.clear();
}

}

