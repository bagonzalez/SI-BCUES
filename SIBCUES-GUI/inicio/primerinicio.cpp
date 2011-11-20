#include <QFile>
#include <QVariant>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "gestionUsuarios/libs/md5wrapper.h"
#include "primerinicio.h"
#include "ui_primerinicio.h"

PrimerInicio::PrimerInicio(RegistroCatalogo *_regCatalogo, contabilidad::RegistroSistemaContable *regC, basico::Registro  *_registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::PrimerInicio)
{
    m_ui->setupUi(this);

    this->registroBasico=_registroBasico;
     this->registroContable=regC;
    this->registroCatalogo=_regCatalogo;
    this->inventario=_inventario;

}

PrimerInicio::~PrimerInicio()
{
    delete m_ui;
}

void PrimerInicio::changeEvent(QEvent *e)
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


void PrimerInicio::on_botonAceptar_clicked(){

     {

     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("config.db");
     if (!db.open()) {
         QMessageBox::critical(0, qApp->tr("Cannot open database"),
             qApp->tr("Unable to establish a database connection.\n"
                      "This example needs SQLite support. Please read "
                      "the Qt SQL driver documentation for information how "
                      "to build it.\n\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
         return;

     }

     QSqlQuery query;
     query.exec("create table configuracion (id int primary key, "
                                      "host varchar(20), "
                                      "base varchar(20), "
                                      "usuario varchar(20), "
                                      "puerto int, "
                                      "contraseniaDB varchar(20),"
                                      "unidad int)");
      QString servidor=m_ui->servidor->text();
      QString base=m_ui->nombreBase->text();
      QString usuario=m_ui->usuarioBase->text();
      QString puerto=m_ui->numeroPuerto->text();
      QString contraseniaDB=m_ui->contraseniaBase->text();

       query.prepare("INSERT INTO configuracion(id, host, base, usuario, puerto, contraseniaDB, unidad)" "VALUES (:id, :host, :base, :usuario, :puerto, :contraseniaDB, :unidad);");

       query.bindValue(":id", QString::number(1));
       query.bindValue(":host", servidor);
       query.bindValue(":base", base);
       query.bindValue(":usuario", usuario);
       query.bindValue(":puerto", puerto);
       query.bindValue(":contraseniaDB", contraseniaDB);
       query.bindValue(":unidad", QString::number(0));
       query.exec();
       query.clear();     

       db.close();
       db=QSqlDatabase::addDatabase("QMYSQL");

   }

   QSqlDatabase::removeDatabase("QSQLITE");

   QString idUni;

   if((this->configuracionNueva)){
     string nombreUnidad=this->m_ui->nombreUnidad->text().toStdString();
     string codigoP1=this->m_ui->codigoUnidad->text().toStdString();
     string codigoP2=this->m_ui->lineaUnidad->text().toStdString();

     string nombreUsuario=this->m_ui->nombreUsuario->text().toStdString();
     string apellidoUsuario=this->m_ui->apelldosUsuario->text().toStdString();
     string cuenta=this->m_ui->cuenta->text().toStdString();
     string password=this->m_ui->password->text().toStdString();
     string repassword=this->m_ui->repassword->text().toStdString();
     string director=this->m_ui->director->text().toStdString();
     string jefeAF=this->m_ui->jefeActivo->text().toStdString();

     if(password==repassword){

         md5wrapper md5;
         std::string temp = md5.getHashFromString(password);         
         password=temp;

         int idUnidad=this->registroBasico->crearUnidad(codigoP1, codigoP2, nombreUnidad, director, jefeAF);
         this->registroBasico->crearUsuario(nombreUsuario, apellidoUsuario, cuenta, password, basico::administrador);
         idUni=QVariant::QVariant(idUnidad).toString();
         QString idCatalogo=QVariant::QVariant(this->registroBasico->getUnidad()->idCatalogo).toString();
     }

   }
   else{
       SeleccionarUnidad *dialogoUnidad=new SeleccionarUnidad(this->registroBasico->getUnidad()->id);
       dialogoUnidad->show();
       dialogoUnidad->exec();
       idUni=dialogoUnidad->getIdUnidad();
   }



    {
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("config.db");
     if (!db.open()) {
         QMessageBox::critical(0, qApp->tr("Cannot open database"),
             qApp->tr("Unable to establish a database connection.\n"
                      "This example needs SQLite support. Please read "
                      "the Qt SQL driver documentation for information how "
                      "to build it.\n\n"
                      "Click Cancel to exit."), QMessageBox::Cancel);
         return;
     }
     QSqlQuery query;
     query.exec("UPDATE configuracion SET unidad = '"+idUni+"' WHERE unidad =0;");
     db=QSqlDatabase::addDatabase("QMYSQL");
   }

   QSqlDatabase::removeDatabase("QSQLITE");

   /*QFile file("configuacion.conf");

    if (!file.open(QFile::WriteOnly | QFile::Text)) {

   }*/

     Fecha *fech=new Fecha(5, 10, 2009);

     this->registroContable=new RegistroSistemaContable(this->registroBasico);
     this->registroContable->crearPeriodoContable(*fech, *fech);
     this->registroContable->crearCatalogo(*fech, false, false);
     /*this->registroCatalogo=new RegistroCatalogo(this->registroBasico->getUsuario(), this->registroContable);
     this->registroCatalogo->cargarCatalogo();*/
     /*this->inventario->cargarInventario(this->registroCatalogo);*/

    //QTextStream out(&file);
    //QApplication::setOverrideCursor(Qt::WaitCursor);
    //out << idUni << endl << idCatalogo;
    //QApplication::restoreOverrideCursor();
    //file.close();
    this->close();
}

void PrimerInicio::on_botonCancelar_clicked()
{
    this->close();
}



void PrimerInicio::on_btnNuevaConf_clicked()
{
    m_ui->codigoUnidad->setDisabled(false);
    m_ui->lineaUnidad->setDisabled(false);
    m_ui->nombreUnidad->setDisabled(false);

    m_ui->nombreUsuario->setDisabled(false);
    m_ui->apelldosUsuario->setDisabled(false);
    m_ui->cuenta->setDisabled(false);
    m_ui->password->setDisabled(false);
    m_ui->repassword->setDisabled(false);
    this->configuracionNueva=true;
}

void PrimerInicio::on_btnExisteConf_clicked()
{
    m_ui->codigoUnidad->setDisabled(true);
    m_ui->lineaUnidad->setDisabled(true);
    m_ui->nombreUnidad->setDisabled(true);


    m_ui->nombreUsuario->setDisabled(true);
    m_ui->apelldosUsuario->setDisabled(true);
    m_ui->cuenta->setDisabled(true);
    m_ui->password->setDisabled(true);
    m_ui->repassword->setDisabled(true);    
    this->configuracionNueva=false;

}
