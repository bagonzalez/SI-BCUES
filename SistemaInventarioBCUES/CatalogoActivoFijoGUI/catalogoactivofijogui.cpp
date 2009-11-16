#include "catalogoactivofijogui.h"
#include "ui_catalogoactivofijogui.h"
#include "../ModuloCatalogo/ModuloCatalogo/headers/EspecActivoFijo.h"
#include <QList>
#include <QDateTime>
#include <QCompleter>
#include <list>
#include <QMessageBox>


#include "../../Persistencia/persistencia_global.h"
#include "../../Persistencia/persistencia.h"


using namespace moduloinventario;

CatalogoActivoFijoGUI::CatalogoActivoFijoGUI(moduloinventario::RegistroCatalogo *reg, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::CatalogoActivoFijoGUI)
{
    m_ui->setupUi(this);

    this->registroCatalogo=reg;
    this->registroContable=regC;
    this->regBasico=registroBasico;

    m_ui->nombreDpto->setText(QString(this->regBasico->getNombreUnidad().c_str()));
    QString codP1=QString(this->regBasico->codigoUnidadP1().c_str());
    QString codP2=QString(this->regBasico->codigoUnidadP2().c_str());
    m_ui->nombreUnidad->setText(codP1+ " "+ codP2);

    completer();

    m_ui->cuentaBiblio->setText(QString( this->listaCodigosCuentas[12090].c_str()  ));
    m_ui->especificoBiblio->setText(QString( this->listaCodigosEspecificos[51005].c_str()  ));
    m_ui->botonGuardar->setDisabled(true);
}

void CatalogoActivoFijoGUI::on_descripcion_editingFinished(){

    string descripcion=QString(m_ui->descripcion->text()).toStdString() ;
     QList<string> lista=QList<string>::fromStdList( this->registroCatalogo->getMarcas(descripcion));
     QList<QString> myQString;

    for (int i = 0; i < lista.size(); ++i){
         myQString.push_back(QString(lista.at(i).c_str()));
    }

    QCompleter *completer = new QCompleter(myQString, this);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     m_ui->marca->setCompleter(completer);
}

void CatalogoActivoFijoGUI::on_marca_editingFinished(){

    string _marca=QString(m_ui->marca->text()).toStdString() ;
     QList<string> lista=QList<string>::fromStdList( this->registroCatalogo->getModelos(_marca));
     QList<QString> myQString;

    for (int i = 0; i < lista.size(); ++i){
         myQString.push_back(QString(lista.at(i).c_str()));
    }
    QCompleter *completer = new QCompleter(myQString, this);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     m_ui->modelo->setCompleter(completer);     
     m_ui->botonGuardar->setDisabled(false);
}

void CatalogoActivoFijoGUI::completer()
{
    QList<string> lista=QList<string>::fromStdList(this->registroCatalogo->getDescripciones());    
    QList<QString> myQString;

    for (int i = 0; i < lista.size(); ++i){

         myQString.push_back(QString(lista.at(i).c_str()));
    }    


    QCompleter *completer = new QCompleter(myQString, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->descripcion->setCompleter(completer);



    listaCodigosCuentas=this->registroContable->getHijosCuentaCodigos("Inventario");
    myQString.clear();

    for
    (
            map<int, string>::iterator it = listaCodigosCuentas.begin();
            it != listaCodigosCuentas.end();
                ++it
     ){
          if(it->first!=12090)
           myQString.push_back(QString(QVariant::QVariant(it->first).toString()));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->numeroCuenta->setCompleter(completer2);

    listaCodigosEspecificos=this->registroContable->getHijosCuentaCodigos("Inversiones en Activos Fijos");
    myQString.clear();
    for
    (
            map<int, string>::iterator it = listaCodigosEspecificos.begin();
            it != listaCodigosEspecificos.end();
                ++it
     ){
           if(it->first!=51005)
              myQString.push_back(QString(QVariant::QVariant(it->first).toString()));
    }


    QCompleter *completer3 = new QCompleter(myQString, this);
    completer3->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->numeroEspecifico->setCompleter(completer3);
}


void CatalogoActivoFijoGUI::on_numeroCuenta_editingFinished (){
    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->numeroCuenta->text().toInt()].c_str()  ));
}

void CatalogoActivoFijoGUI::on_numeroEspecifico_editingFinished (){
    m_ui->especifico->setText(QString(  this->listaCodigosEspecificos[m_ui->numeroEspecifico->text().toInt()].c_str()  ));
}

void CatalogoActivoFijoGUI::on_nombreClase_editingFinished (){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
    {
        moduloinventario::EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
        m_ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        m_ui->descripcion->setReadOnly(true);
        m_ui->numeroEspecifico->setText(QString::number(espec->clase->idEspecifico->codigoCuenta));
        m_ui->especifico->setText(QString(this->listaCodigosEspecificos[m_ui->numeroEspecifico->text().toInt()].c_str()  ));
        m_ui->numeroEspecifico->setReadOnly(true);
        m_ui->especifico->setReadOnly(true);
    }
}

void CatalogoActivoFijoGUI::desactivar(bool activar){
    m_ui->numeroCuenta->setDisabled(activar);
    m_ui->numeroEspecifico->setDisabled(activar);
    m_ui->nombreClase->setDisabled(activar);
    m_ui->cuentaAsignada->setDisabled(activar);
    m_ui->descripcion->setDisabled(activar);
    m_ui->marca->setDisabled(activar);
    m_ui->modelo->setDisabled(activar);
    m_ui->especifico->setDisabled(activar);
    m_ui->botonGuardar->setDisabled(activar);
}

void CatalogoActivoFijoGUI::limpiar(){
    m_ui->numeroCuenta->clear();
    m_ui->numeroEspecifico->clear();
    m_ui->numeroEspecifico->setReadOnly(false);

    m_ui->nombreClase->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->descripcion->clear();
    m_ui->descripcion->setReadOnly(false);
    m_ui->marca->clear();
    m_ui->modelo->clear();
    m_ui->especifico->clear();
    m_ui->botonGuardar->setEnabled(true);    

}

void CatalogoActivoFijoGUI::on_botonGuardar_pressed(){

 if(! (m_ui->nombreClase->text().isEmpty() || m_ui->marca->text().isEmpty()) ){


    QDateTime HoraFecha=QDateTime::currentDateTime();    

    Fecha *fech=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());
    Tiempo *tiempo=new Tiempo(HoraFecha.time().hour(), HoraFecha.time().minute());

    string clase=m_ui->nombreClase->text().toStdString();
    string madre=m_ui->cuentaAsignada->text().toStdString();
    string descripcion=m_ui->descripcion->text().toStdString();
    string marca=m_ui->marca->text().toStdString();
    string modelo=m_ui->modelo->text().toStdString();
    string cuenta_clase= m_ui->numeroCuenta->text().toStdString() + "-"+clase ;

    string nespecifico=m_ui->especifico->text().toStdString();
   

    if(!(registroContable->getDireccionSubCuenta(cuenta_clase) !=NULL))
    {
        contabilidad::Subcuenta *cuenta=registroContable->crearSubCuenta(madre, cuenta_clase, 0, descripcion, 0, true);                                       
        contabilidad::Subcuenta *especifico=registroContable->getDireccionSubCuenta(nespecifico);
        int codIng=registroCatalogo->crearIngreso(fech, tiempo);


        registroCatalogo->crearEspecActivoF(cuenta, especifico, codIng, clase);
        registroCatalogo->introducirInformacion(codIng, descripcion, marca, modelo);

    }
    else{
        EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(clase, madre);
        if(espec!=NULL)
        {
            registroCatalogo->setMarca(marca, espec);
            registroCatalogo->setModelo(marca, modelo, espec);
            Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            servicioPersistencia->actualizarInfo(espec, marca, modelo);
        }
    }

     QMessageBox msgBox;
     msgBox.setText("    Ingresado con exito!.   ");
     msgBox.exec();
     this->desactivar(true);
 }
 else{
     QMessageBox msgBox;
     msgBox.setText("    Algunos datos faltan o estan incompletos!.   ");
     msgBox.exec();
 }
}

void CatalogoActivoFijoGUI::on_botonGuardarBiblio_pressed(){

    QDateTime HoraFecha=QDateTime::currentDateTime();

    Fecha *fech=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());
    Tiempo *tiempo=new Tiempo(HoraFecha.time().hour(), HoraFecha.time().minute());

    string clase=m_ui->claseBiblio->text().toStdString();
    string autor;
    string madre=m_ui->cuentaBiblio->text().toStdString();
    string apellidos=m_ui->apellidos->text().toStdString();
    string nombreAutor=m_ui->nombreAutor->text().toStdString();
    string modelo=m_ui->modelo->text().toStdString();    
    string nespecifico=m_ui->especificoBiblio->text().toStdString();
    string tituloBiblio=m_ui->tituloBiblio->text().toStdString();
    string descripcionBiblio=m_ui->descripcionBiblio->text().toStdString();
    string isbn=m_ui->isbn->text().toStdString();

    string cuenta_clase= QString(QVariant::QVariant(12090).toString()).toStdString()+ "-"+clase ;


     if(!(registroContable->getDireccionSubCuenta(cuenta_clase) !=NULL))
    {
        contabilidad::Subcuenta *cuenta=registroContable->crearSubCuenta(madre, cuenta_clase, 0, descripcionBiblio, 0, true);
        contabilidad::Subcuenta *especifico=registroContable->getDireccionSubCuenta(nespecifico);
        int codIng=registroCatalogo->crearIngreso(fech, tiempo);

        registroCatalogo->crearEspecMatBiblio(cuenta, especifico, codIng, clase);
        registroCatalogo->introducirInformacion(nombreAutor, tituloBiblio, apellidos ,codIng, descripcionBiblio, isbn);
    }
    else{
        EspecMaterialBibliografico *espec=this->registroCatalogo->getEspecificacionMB(clase, madre);
        if(espec!=NULL)
        {
            espec->setAutor(nombreAutor, apellidos);            
            espec->setTitulo(nombreAutor, apellidos, tituloBiblio, isbn);
            Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            servicioPersistencia->actualizarInfo(espec, nombreAutor, apellidos, tituloBiblio, isbn );
        }
    }

     QMessageBox msgBox;
     msgBox.setText("    Ingresado con exito!.   ");
     msgBox.exec();
     m_ui->botonGuardarBiblio->setDisabled(true);
}

void CatalogoActivoFijoGUI::on_claseBiblio_editingFinished (){
    string claseBiblio=m_ui->claseBiblio->text().toStdString();
    string madre=m_ui->cuentaBiblio->text().toStdString();

    if(this->registroCatalogo->existeClase(claseBiblio, madre ) )
    {
        moduloinventario::EspecMaterialBibliografico *espec=this->registroCatalogo->getEspecificacionMB(claseBiblio, madre);
        m_ui->descripcionBiblio->setText(QString( espec->getDescripcion().c_str()));
        m_ui->descripcionBiblio->setReadOnly(true);
    }
    completer_Autor();
    completer_Apellido();
}

void CatalogoActivoFijoGUI::completer_Autor(){

    string claseBiblio=m_ui->claseBiblio->text().toStdString();
    string madre=m_ui->cuentaBiblio->text().toStdString();

    if(this->registroCatalogo->existeClase(claseBiblio, madre )  )
    {
        moduloinventario::EspecMaterialBibliografico *espec=this->registroCatalogo->getEspecificacionMB(claseBiblio, madre);
        QList<string> lista=QList<string>::fromStdList(espec->getNAutores());
        QList<QString> myQString;

        for (int i = 0; i < lista.size(); ++i){
             myQString.push_back(QString(lista.at(i).c_str()));
        }

        QCompleter *completer = new QCompleter(myQString, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        m_ui->nombreAutor->setCompleter(completer);
    }
}


void CatalogoActivoFijoGUI::on_apellidos_editingFinished (){
    string claseBiblio=m_ui->claseBiblio->text().toStdString();
    string madre=m_ui->cuentaBiblio->text().toStdString();
    string _autor=m_ui->nombreAutor->text().toStdString();;
    string _apellidos=m_ui->apellidos->text().toStdString();

    if(this->registroCatalogo->existeClase(claseBiblio, madre )  )
    {
        moduloinventario::EspecMaterialBibliografico *espec=this->registroCatalogo->getEspecificacionMB(claseBiblio, madre);
        this->listaTitulos=espec->getTitulos( _autor, _apellidos);
        this->otrosTitulos=espec->getOtrosTitulos( _autor, _apellidos);

         QList<QString> myISBN;

         for
        (
            map<string, string>::iterator it = listaTitulos.begin();
            it != listaTitulos.end();
                ++it
         ){                    

                    myISBN.push_back(QString(it->first.c_str()));
         }        

        QCompleter *completer2 = new QCompleter(myISBN, this);
        completer2->setCaseSensitivity(Qt::CaseInsensitive);
        m_ui->isbn->setCompleter(completer2);
    }
}

void CatalogoActivoFijoGUI::on_isbn_editingFinished (){


    string isbn=m_ui->isbn->text().toStdString();
    if(!isbn.empty())
    {
        m_ui->tituloBiblio->setText(listaTitulos[isbn].c_str());
    }
    else{
         QList<QString> myTitulos;

         for
        (
            map<int, string>::iterator it = otrosTitulos.begin();
            it != otrosTitulos.end();
                ++it
         ){

                    myTitulos.push_back(QString(it->second.c_str()));
         }

         QCompleter *completer = new QCompleter(myTitulos, this);
         completer->setCaseSensitivity(Qt::CaseInsensitive);
         m_ui->tituloBiblio->setCompleter(completer);
    }
}


void CatalogoActivoFijoGUI::completer_Apellido(){
    string claseBiblio=m_ui->claseBiblio->text().toStdString();
    string madre=m_ui->cuentaBiblio->text().toStdString();

    if(this->registroCatalogo->existeClase(claseBiblio, madre )  )
    {
        moduloinventario::EspecMaterialBibliografico *espec=this->registroCatalogo->getEspecificacionMB(claseBiblio, madre);
        QList<string> lista=QList<string>::fromStdList(espec->getApellidosAutores());
        QList<QString> myQString;

        for (int i = 0; i < lista.size(); ++i){
             myQString.push_back(QString(lista.at(i).c_str()));
        }

        QCompleter *completer = new QCompleter(myQString, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        m_ui->apellidos->setCompleter(completer);
    }
}

void CatalogoActivoFijoGUI::on_botonNuevo_pressed(){
     limpiar();     
     this->desactivar(false);
     m_ui->botonGuardar->setDisabled(true);
}

CatalogoActivoFijoGUI::~CatalogoActivoFijoGUI()
{
    delete m_ui;
}

void CatalogoActivoFijoGUI::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
