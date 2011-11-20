#include "catalogoactivofijogui.h"
#include "ui_catalogoactivofijogui.h"
//#include "../ModuloCatalogo/ModuloCatalogo/headers/EspecActivoFijo.h"
#include <QList>
#include <QDateTime>
#include <QCompleter>
#include <list>
#include <QMessageBox>



using namespace moduloinventario;

CatalogoActivoFijoGUI::CatalogoActivoFijoGUI(moduloinventario::RegistroCatalogo *reg, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::CatalogoActivoFijoGUI)
{
    m_ui->setupUi(this);

    //this->registroCatalogo=reg;
    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);



    this->registroContable=regC;
    this->regBasico=registroBasico;

    m_ui->nombreDpto->setText(QString(this->regBasico->getNombreUnidad().c_str()));
    QString codP1=QString(this->regBasico->codigoUnidadP1().c_str());
    QString codP2=QString(this->regBasico->codigoUnidadP2().c_str());
    m_ui->nombreUnidad->setText(codP1+ " "+ codP2);

    /*completer();
    m_ui->cuentaBiblio->setText(QString( this->listaCodigosCuentas["12090"].c_str()  ));
    m_ui->especificoBiblio->setText(QString( this->listaCodigosEspecificos["51005"].c_str()  ));
    m_ui->botonGuardar->setDisabled(true);*/

    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosFijos();

    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){

            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));
    }

    reg=this->registroCatalogo;
}


void CatalogoActivoFijoGUI::on_anioInventario_currentIndexChanged ( ){
    string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
    this->registroCatalogo->cargarCatalogo(this->servicioPersistencia->getIDInvFijo(anio));
    crearPalo();
}

void CatalogoActivoFijoGUI::crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre )
{
    QList<string> listaHijos=QList<string>::fromStdList(this->registroContable->getHijosCuenta(nombreCuenta));
    for (int i = 0; i < listaHijos.size(); ++i){
        lista->push_back(new QTreeWidgetItem(padre));
        lista->last()-> setText(0, QString(listaHijos.at(i).c_str()));
        this->crearPaloR(listaHijos.at(i), lista, lista->last());
    }
}

void CatalogoActivoFijoGUI::crearPalo()
{
    m_ui->catalogoInventario->takeTopLevelItem(0);

    QTreeWidgetItem *__item = new QTreeWidgetItem(m_ui->catalogoInventario);
    __item->setText(0, "Catalogo Activo Fijo");

    map<string, string> lista=this->registroContable->getHijosCatalogo();

    QList<QTreeWidgetItem *> listaItem;

    for
    (
        map<string, string>::iterator et = lista.begin();
        et != lista.end();
        ++et
    )
    {
        listaItem.push_back(new QTreeWidgetItem(__item));
        listaItem.last()-> setText(0, QString(et->second.c_str()));
        listaItem.last()-> setText(1, QString(et->first.c_str()));
        this->crearPaloR(et->first, &listaItem, listaItem.last());
    }    
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

    listaCodigosCuentas=this->registroContable->getHijosCatalogo();
    myQString.clear();

    for
    (
            map<string, string>::iterator it = listaCodigosCuentas.begin();
            it != listaCodigosCuentas.end();
                ++it
     ){
          if(it->first!="12090")
           myQString.push_back(QString::fromStdString(it->first));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    m_ui->numeroCuenta->setCompleter(completer2);

}


void CatalogoActivoFijoGUI::on_numeroCuenta_editingFinished (){
    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->numeroCuenta->text().toStdString()].c_str()  ));
}


void CatalogoActivoFijoGUI::on_nombreClase_editingFinished (){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
    {
        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada);
        m_ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        m_ui->descripcion->setReadOnly(true);
    }
    m_ui->botonGuardar->setEnabled(true);
}

void CatalogoActivoFijoGUI::desactivar(bool activar){
    m_ui->numeroCuenta->setDisabled(activar);

    m_ui->nombreClase->setDisabled(activar);
    m_ui->cuentaAsignada->setDisabled(activar);
    m_ui->descripcion->setDisabled(activar);



    m_ui->botonGuardar->setDisabled(activar);
}

void CatalogoActivoFijoGUI::limpiar()
{
    m_ui->numeroCuenta->clear();
    m_ui->nombreClase->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->descripcion->clear();
    m_ui->descripcion->setReadOnly(false);
    m_ui->botonGuardar->setEnabled(true);    
}

void CatalogoActivoFijoGUI::on_botonGuardar_pressed(){

 if(! (m_ui->nombreClase->text().isEmpty()) ){

    QDateTime HoraFecha=QDateTime::currentDateTime();    
    Fecha *fech=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());
    Tiempo *tiempo=new Tiempo(HoraFecha.time().hour(), HoraFecha.time().minute());

    string clase=m_ui->nombreClase->text().toStdString();
    string madre=m_ui->cuentaAsignada->text().toStdString();
    string descripcion=m_ui->descripcion->text().toStdString();

    string cuenta_clase= m_ui->numeroCuenta->text().toStdString() + "-"+clase ;   

    if(!(registroContable->getDireccionSubCuenta(cuenta_clase) !=NULL))
    {
        contabilidad::Subcuenta *cuenta=registroContable->crearCategoria(madre, cuenta_clase, "0", descripcion, 0, true, "cuenta", "ingreso");
        int codIng=registroCatalogo->crearIngreso(fech, tiempo);
        registroCatalogo->crearEspec(cuenta, codIng, clase);
        //registroCatalogo->introducirInformacion(codIng, descripcion, marca, modelo);

    }
    else{
        EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(clase, madre);
        if(espec!=NULL)
        {
            //registroCatalogo->setMarca(marca, espec);
            //registroCatalogo->setModelo(marca, modelo, espec);
            //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            //servicioPersistencia->actualizarInfo(espec, marca, modelo);
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
    string descripcionBiblio=m_ui->descripcionBiblio->text().toStdString();    
    string cuenta_clase= QString(QVariant::QVariant(12090).toString()).toStdString()+ "-"+clase ;


     if(!(registroContable->getDireccionSubCuenta(cuenta_clase) !=NULL))
    {
        contabilidad::Subcuenta *cuenta=registroContable->crearSubCuenta(madre, cuenta_clase, 0, descripcionBiblio, 0, true);

        int codIng=registroCatalogo->crearIngreso(fech, tiempo);

        registroCatalogo->crearEspec(cuenta, codIng, clase);
        //registroCatalogo->introducirInformacion(nombreAutor, tituloBiblio, apellidos ,codIng, descripcionBiblio, isbn);
    }
    else{
        EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(clase, madre);
        if(espec!=NULL)
        {
            //espec->setAutor(nombreAutor, apellidos);
            //espec->setTitulo(nombreAutor, apellidos, tituloBiblio, isbn);
            //Persistencia::Persistencia *servicioPersistencia=new Persistencia();
            //servicioPersistencia->actualizarInfo(espec, nombreAutor, apellidos, tituloBiblio, isbn );
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
        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(claseBiblio, madre);
        //m_ui->descripcionBiblio->setText(QString( espec->getDescripcion().c_str()));
        m_ui->descripcionBiblio->setReadOnly(true);
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

void CatalogoActivoFijoGUI::on_catalogoInventario_currentItemChanged(QTreeWidgetItem* current, QTreeWidgetItem* previous)
{

    m_ui->codigoCuenta->setText((current->text(0)));
    m_ui->saldoDeudor->clear();
    m_ui->saldoAcreedor->clear();
    m_ui->debe->clear();
    m_ui->haber->clear();
    m_ui->textEdit->clear();

    string codigo=(current->text(1)).toStdString();
    string cuenta=(current->text(0)).toStdString();

    Cuenta *cuentaMadre;

    if (registroContable->getDireccionCuenta(codigo)!=NULL)
    {
        m_ui->debe->setText(QString("%1 $").arg(registroContable->getDireccionCuenta(codigo)->getDebe(), 0, 'f', 2));
        m_ui->haber->setText(QString("%1 $").arg(registroContable->getDireccionCuenta(codigo)->getHaber(), 0, 'f', 2));
        m_ui->textEdit->setText(QString(registroContable->getDireccionCuenta(codigo)->getDescripcion().c_str()));
    }

    if (registroContable->getDireccionSubCuenta(cuenta)!=NULL)
    {
        string codigoMadre=current->parent()->text(1).toStdString();
        cuentaMadre=registroContable->getDireccionCuenta(codigoMadre);


        m_ui->debe->setText(QString("%1 $").arg(cuentaMadre->getSubCuenta(cuenta)->getDebe(), 0, 'f', 2));
        m_ui->haber->setText(QString("%1 $").arg(cuentaMadre->getSubCuenta(cuenta)->getHaber(), 0, 'f', 2));
        m_ui->textEdit->setText(QString(cuentaMadre->getSubCuenta(cuenta)->getDescripcion().c_str()));
    }

    if (registroContable->getDireccionSubCuenta(cuenta)!=NULL || registroContable->getDireccionCuenta(cuenta)!=NULL)
    {
        float saldo=0.0;

        if(cuentaMadre!=NULL)
            saldo=cuentaMadre->getSubCuenta(cuenta)->getSaldo();
        else
            saldo=registroContable->getSaldoCuenta(cuenta);

        if (saldo>=0)
        {
            m_ui->saldoDeudor->setText(QString("%1 $").arg(saldo, 0, 'f', 2));
        }
        else
        {
            saldo=saldo*(-1);
            m_ui->saldoAcreedor->setText(QString("%1 $").arg(saldo, 0, 'f', 2));
        }

        if (registroContable->getTipoCuenta(cuenta)==contabilidad::especificos){
            m_ui->botonNuevo->setDisabled(true);
            /*m_ui.crearCuenta->setEnabled(false);
            m_ui.crearRubro->setEnabled(false);
            m_ui.crearEspecifico->setEnabled(false);*/
        }
        else{
            if(registroContable->getTipoCuenta(cuenta)==contabilidad::inventario){
                m_ui->botonNuevo->setDisabled(false);
                /*m_ui.crearEspecifico->setEnabled(false);
                m_ui.crearRubro->setEnabled(false);
                m_ui.crearCuenta->setEnabled(true);*/
            }
            else{

            }
        }
    }
}

void CatalogoActivoFijoGUI::on_btmBuscar_clicked()
{
    dialogoBuscarCuenta *dialogoBuscar=new dialogoBuscarCuenta(this->registroContable, false);
    dialogoBuscar->show();
    dialogoBuscar->exec();

    string nombreCuenta=dialogoBuscar->getNombreCuenta();    
    string nombreMadre=dialogoBuscar->getMadre();

    QList<QTreeWidgetItem *> lista=m_ui->catalogoInventario->findItems(QString::fromStdString(nombreCuenta), Qt::MatchRecursive);

    std::cout << "Tamano" << lista.size() <<nombreCuenta;

    for (int i = 0; i < lista.size(); ++i){
        if(lista.at(i)->parent()->text(0)==QString::fromStdString(nombreMadre)){
            m_ui->catalogoInventario->setCurrentItem(lista.at(i));
            m_ui->catalogoInventario->collapseItem(lista.at(i));
        }
    }
}

void CatalogoActivoFijoGUI::on_btmSeleccionar_clicked()
{
    this->madre=m_ui->catalogoInventario->currentItem()->parent()->text(1);
    this->clase=m_ui->catalogoInventario->currentItem()->text(0);
    this->close();
}

void CatalogoActivoFijoGUI::on_pushButton_clicked()
{
    this->close();
}

QString CatalogoActivoFijoGUI::getMadre(){
    return this->madre;
}

QString CatalogoActivoFijoGUI::getClase(){
    return this->clase;
}

