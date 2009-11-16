

#include "../headers/DescargoBienes.h"
#include "../headers/InventarioActivoFijo.h"
#include <QString>



#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"


namespace moduloinventario {

InventarioActivoFijo::InventarioActivoFijo(){    
}


Bien * InventarioActivoFijo::crearBien(EspecActivoFijo *especBien, float valor, Fecha *fechaAdquisicion){
        Bien  *nuevo;
        string correlativoString;
        int correlativonum=this->contenedorBienes.size()+1;
        correlativoString=correlativo(especBien->clase->nombreClase, true);
        std::cout << "Coreelativo--->"  << correlativoString;

        nuevo=new Bien(especBien, valor, fechaAdquisicion,correlativoString );
        contenedorBienes[correlativonum]=nuevo;
        return nuevo;
}

Bien * InventarioActivoFijo::crearBien(EspecMaterialBibliografico *especBien, float valor, Fecha *fechaAdquisicion){
        Bien  *nuevo;
        string correlativoString;
        int correlativonum=this->contenedorBienes.size()+1;
        correlativoString=correlativo(especBien->clase->nombreClase, false);
        std::cout << "Correlativo--->"  << correlativoString << endl;
        nuevo=new Bien(especBien, valor, fechaAdquisicion,correlativoString );
        contenedorBienes[correlativonum]=nuevo;
        return nuevo;
}

string InventarioActivoFijo::correlativo(string nombreClase, bool activofijo){
    string correlativoString;
    int cuenta=1;

    EspecificacionBien *especBien;

    for
    (
         map<int, Bien*>::iterator it = contenedorBienes.begin();
         it != contenedorBienes.end();
         ++it
     ){
             if(activofijo)
               especBien=(it->second)->getEspecAF();
             else
               especBien=(it->second)->getEspecMB();

               if(especBien->clase->nombreClase==nombreClase)
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


std::list<string> InventarioActivoFijo::getCorrelativos(string clase, string cuentaAsignada){

    std::list<string> listaCorrelativos;

    for
     (
                map<int, Bien*>::iterator it = contenedorBienes.begin();
                it != contenedorBienes.end();
                ++it
     ){

                    if((it->second)->getEspecAF()->getClase()->getCuentaAsignada()==cuentaAsignada){
                        if((it->second)->getEspecAF()->getClase()->getNombreClase()==clase)
                            listaCorrelativos.push_back((it->second)->correlativo);
                    }
     }

     return listaCorrelativos;
}

Bien * InventarioActivoFijo::getBien(string clase, string cuentaAsignada, string correlativo){
    
     for
     (
                map<int, Bien*>::iterator it = contenedorBienes.begin();
                it != contenedorBienes.end();
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

void InventarioActivoFijo::cargarInventario(moduloinventario::RegistroCatalogo *regCatalogo){
    Persistencia::Persistencia *servicioPersistencia=new Persistencia();
    servicioPersistencia->cargar(this, regCatalogo );
}

}

