#include "catalogoactivofijogui.h"
#include "ui_catalogoactivofijogui.h"
#include "../ModuloCatalogo/ModuloCatalogo/headers/EspecActivoFijo.h"
#include <QList>
#include <QDateTime>
#include <QCompleter>
#include <list>

using namespace moduloinventario;

CatalogoActivoFijoGUI::CatalogoActivoFijoGUI(moduloinventario::RegistroCatalogo *reg, contabilidad::RegistroSistemaContable *regC, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::CatalogoActivoFijoGUI)
{
    m_ui->setupUi(this);
    this->registroCatalogo=reg;
    this->registroContable=regC;

    completer();

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

    lista=QList<string>::fromStdList(this->registroContable->getHijosCuenta("Inventario"));
    myQString.clear();
    for (int i = 0; i < lista.size(); ++i){
         myQString.push_back(QString(lista.at(i).c_str()));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->cuentaAsignada->setCompleter(completer2);

    lista=QList<string>::fromStdList(this->registroContable->getHijosCuenta("Inversiones en Activos Fijos"));
    myQString.clear();
    for (int i = 0; i < lista.size(); ++i){
         myQString.push_back(QString(lista.at(i).c_str()));
    }

    QCompleter *completer3 = new QCompleter(myQString, this);
    completer3->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->especifico->setCompleter(completer3);
}

void CatalogoActivoFijoGUI::on_botonGuardar_pressed(){

    QDateTime HoraFecha=QDateTime::currentDateTime();    

    Fecha *fech=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());
    Tiempo *tiempo=new Tiempo(HoraFecha.time().hour(), HoraFecha.time().minute());

    string clase=m_ui->nombreClase->text().toStdString();
    string madre=m_ui->cuentaAsignada->text().toStdString();
    string descripcion=m_ui->descripcion->text().toStdString();
    string marca=m_ui->marca->text().toStdString();
    string modelo=m_ui->modelo->text().toStdString();


    if(!(registroContable->getDireccionSubCuenta(clase) !=NULL))
    {
        contabilidad::Subcuenta *cuenta=registroContable->crearSubCuenta(madre, clase);
        int codIng=registroCatalogo->crearIngreso(fech, tiempo);
        registroCatalogo->crearEspecActivoF(cuenta, codIng, clase);
        registroCatalogo->introducirInformacion(descripcion, marca, modelo, modelo, codIng);
    }
    else{
        EspecActivoFijo *espec=this->registroCatalogo->getEspecificacion(clase);
        if(espec!=NULL)
        {
            registroCatalogo->setMarca(marca, espec);
            registroCatalogo->setModelo(marca, modelo, espec);
        }
    }




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
