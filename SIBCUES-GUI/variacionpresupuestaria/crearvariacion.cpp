#include "crearvariacion.h"
#include "ui_crearvariacion.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include <QSqlQuery>

using namespace std;
CrearVariacion::CrearVariacion(QWidget *parent)
        :QWidget(parent),
 m_ui(new Ui::CrearVariacion)
{
        MontoTotal=0;
        m_ui->setupUi(this);
        QString QInicial="0", QInstitucion="3101 Universidad de El Salvador";

        /*char Fecha[10];
        _strdate(Fecha);
        QMessageBox::information(this, tr("Presupuesto Solicitado"),
        tr("Sus datos Fueron almacenados correctamente")+Fecha,QMessageBox::Ok, QMessageBox::Ok);*/

        QMontoTotal="$";
        m_ui->Institucion2->setText(QInstitucion);
        m_ui->montoTotallLine->setText(QMontoTotal);
        QString query ="SELECT codigoCuenta,nombreCuenta FROM `cuenta` WHERE codigoCuenta <=61107 && codigoCuenta>=51101";
        consulta.exec(query);
        columna=1;
  int i=0;
  while (consulta.next()){
            columna--;
            m_ui->tablaPresupuestoSolicitado->insertRow(i);
            QCodigo=consulta.value(0).toString();
            QDescripcion=consulta.value(1).toString();
            QTableWidgetItem *CodigoCuenta=new QTableWidgetItem(QCodigo);
            QTableWidgetItem *Descripcion=new QTableWidgetItem(QDescripcion);
            m_ui->tablaPresupuestoSolicitado->setItem(i,columna,CodigoCuenta);
            m_ui->tablaPresupuestoSolicitado->setItem(i,++columna,Descripcion);
            QTableWidgetItem *ValIniSolicitado= new QTableWidgetItem(QInicial);
            m_ui->tablaPresupuestoSolicitado->setItem(i,2,ValIniSolicitado);
            i++;
            m_ui->tablaPresupuestoSolicitado->resizeColumnsToContents();
 }
  consulta.clear();

}


CrearVariacion::~CrearVariacion()
{
    delete m_ui;
}

void CrearVariacion::changeEvent(QEvent *e)
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


void CrearVariacion::on_AgregarButton_clicked()
{

QSqlQuery query;
QString QFfinanciamiento, QMontoSolicitado,QCuenta, QIdLinea,consul;
QDate a,b;
int c;
QEjercicioFiscal=m_ui->EjercicioFiscal2->text();
QFfinanciamiento=m_ui->comboBox->currentText();
a=m_ui->dateElaboracion->date();
consul="SELECT *FROM variacionpresupuestaria WHERE idEspecificacion=";
consul+=QEjercicioFiscal;
query.exec(consul);
query.next();
c=query.value(0).toInt();
query.clear();
if (c==0){
    query.prepare("INSERT INTO variacionpresupuestaria (idEspecificacion,FuenteFinanciamiento,fechaElaboracion)" "VALUES ( :EjercicioFiscal, :Ffinanciamiento, :FechaElaboracion);");
    query.bindValue(":EjercicioFiscal ",QEjercicioFiscal);
    query.bindValue(":Ffinanciamiento",QFfinanciamiento);
    query.bindValue(":FechaElaboracion",a.toString(Qt::ISODate));
    query.exec();
    query.clear();
   int numfilas;
   numfilas=m_ui->tablaPresupuestoSolicitado->rowCount();
   for (int i=0;i< numfilas;i++)
   {  
    QIdLinea = QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QEjercicioFiscal;
    QMontoSolicitado=m_ui->tablaPresupuestoSolicitado->item(i,2)->text();
    QCuenta=m_ui->tablaPresupuestoSolicitado->item(i,0)->text();
    query.prepare("INSERT INTO lineadevariacion (idCuenta,idEspecificacion,IdLineaVariacion,PresupuestoSolicitado)" "VALUES (:cuenta, :IdEspecificacion,:IdLineaVariacion, :presupuestoSolicitado);");
    //query.bindValue(":idCatalogo",QString::number(1));
    query.bindValue(":cuenta",QCuenta);
    query.bindValue(":IdEspecificacion",QEjercicioFiscal);
    query.bindValue(":IdLineaVariacion",QIdLinea);
    query.bindValue(":presupuestoSolicitado",QMontoSolicitado);
    query.exec();
    query.clear();
   }
   m_ui->tablaPresupuestoSolicitado->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->Institucion2->clear();
   m_ui->comboBox->clear();
   m_ui->montoTotallLine->clear();
   m_ui->montoTotallLine->setText(QMontoTotal);
   m_ui->montoTotallLine->setText(QMontoTotal);
   QMessageBox::information(this, tr("Presupuesto Solicitado"),
    tr("Sus datos Fueron almacenados correctamente"),QMessageBox::Ok, QMessageBox::Ok);
 }
 else
    {
    QMessageBox::critical(this, tr("Presupuesto Solicitado"),
    tr("Los Datos Generales de Variacion Presupuestaria son incorrectos verifique el dato de Ejercicio Fiscal tiene que se un año mayor al seleccionado"),QMessageBox::Ok);
    }
}


void CrearVariacion::on_CancelarButton_clicked()
{
  int numfilas=m_ui->tablaPresupuestoSolicitado->rowCount();
   for (int i=0;i<numfilas;i++)
  {
    m_ui->tablaPresupuestoSolicitado->removeRow(i);
  }
   m_ui->tablaPresupuestoSolicitado->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->comboBox->clear();
   m_ui->Institucion2->clear();
   m_ui->dateElaboracion->clear();
   m_ui->montoTotallLine->clear();
   m_ui->montoTotallLine->setText(QMontoTotal);
}
 /*QString QDevol;
   QDevol=QDevol.setNum(monto);
   QMessageBox::information(this, tr("Codigo Invalido"),
       tr("Ffinanciamiento")+ QDevol, QMessageBox::Ok, QMessageBox::Ok);*/

void CrearVariacion::on_obtenerSolicitadoLinkButton_clicked()
{
   QString Prueba, QMtotal;
   float monto=0.0,MontoTotal=0.0;
   int i,numfilas;
   //m_ui->tablaPresupuestoSolicitado->selectColumn(3);
   numfilas=m_ui->tablaPresupuestoSolicitado->rowCount();
   for (i=0;i<numfilas;i++)
   {
   Prueba=m_ui->tablaPresupuestoSolicitado->item(i,2)->data(0).toString();
   monto=Prueba.toFloat();
   MontoTotal=MontoTotal+ monto;
  }
   QMtotal= QMontoTotal;
   QMtotal += QString("%1").arg(MontoTotal, 0, 'f', 2);
   total = QMtotal.toInt();
   m_ui->montoTotallLine->setText(QString::number(MontoTotal));
}









