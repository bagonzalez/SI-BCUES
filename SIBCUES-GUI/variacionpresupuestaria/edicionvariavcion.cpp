#include "edicionvariavcion.h"
#include "ui_edicionvariavcion.h"
#include <QSqlQuery>
#include <iostream>
#include <QMessageBox>

edicionvariavcion::edicionvariavcion(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::edicionvariavcion)
{
    m_ui->setupUi(this);
     int columna;
    QString  QFuenteFinanciamiento,QFechaElaboracion,QInstitucion="3101 Universidad de El Salvador",QCodigo,QDescripcion,QIdLinea,QAprobado,QSolicitado,QIdEspecificacion2,QRazonamiento;
    m_ui->Institucion2->setText(QInstitucion);
    QString query=" SELECT MAX( idEspecificacion )FROM variacionpresupuestaria";
    consulta.exec(query);
    consulta.next();
    QIdEspecificacion=consulta.value(0).toString();
    consulta.clear();
    query="SELECT idEspecificacion, FuenteFinanciamiento, fechaElaboracion FROM variacionpresupuestaria WHERE IdEspecificacion=";
    query+=QIdEspecificacion;
    consulta.exec(query);
    consulta.next();
    QIdEspecificacion2=consulta.value(0).toString();
    QFuenteFinanciamiento=consulta.value(1).toString();
    QFechaElaboracion=consulta.value(2).toString();
    m_ui->EjercicioFiscal2->setText(QIdEspecificacion2);
    m_ui->FuenteFinanciamiento->setText(QFuenteFinanciamiento);
    m_ui->Fecha->setText(QFechaElaboracion);
    consulta.clear();
    query ="SELECT codigoCuenta,nombreCuenta FROM `cuenta` WHERE codigoCuenta <=61107 && codigoCuenta>=51101";
    consulta.exec(query);
    columna=1;
    int i=0;
    while (consulta.next()){
            columna--;
            m_ui->tablaVariacion->insertRow(i);
            QCodigo=consulta.value(0).toString();
            QDescripcion=consulta.value(1).toString();
            QTableWidgetItem *CodigoCuenta=new QTableWidgetItem(QCodigo);
            QTableWidgetItem *Descripcion=new QTableWidgetItem(QDescripcion);
            m_ui->tablaVariacion->setItem(i,columna,CodigoCuenta);
            m_ui->tablaVariacion->setItem(i,++columna,Descripcion);
            i++;
    }
     consulta.exec(query);
   int numfilas;
   numfilas=m_ui->tablaVariacion->rowCount();
   for (i=0;i<numfilas;i++)
   {
    QIdLinea=QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QIdEspecificacion;
    consulta2.prepare("SELECT PresupuestoOtorgado,PresupuestoSolicitado,Razonamiento FROM `lineadevariacion` WHERE IdLineaVariacion=:IdLineaVariacion");
    consulta2.bindValue(":IdLineaVariacion",QIdLinea);
    consulta2.exec();
    consulta2.next();
    QAprobado=consulta2.value(0).toString();
    QSolicitado=consulta2.value(1).toString();
    QRazonamiento=consulta2.value(2).toString();
    QTableWidgetItem *MontoAprobado=new QTableWidgetItem(QAprobado);
    QTableWidgetItem *MontoSolicitado=new QTableWidgetItem(QSolicitado);
    QTableWidgetItem *Razonamiento=new QTableWidgetItem(QRazonamiento);
    m_ui->tablaVariacion->setItem(i,2,MontoAprobado);
    m_ui->tablaVariacion->setItem(i,3,MontoSolicitado);
    m_ui->tablaVariacion->setItem(i,4,Razonamiento);
    m_ui->tablaVariacion->resizeColumnsToContents();
    consulta2.clear();
   }
    m_ui->tablaVariacion->resizeColumnsToContents();
   }


void edicionvariavcion::on_AgregarButton_clicked()
{
    QString QRazonamiento,QCuenta,QIdLinea,QSolicitado, QAprobado;
    int numfilas, i;
   numfilas=m_ui->tablaVariacion->rowCount();
   for (i=0;i<numfilas;i++)
   {
    QIdLinea=QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QIdEspecificacion;
    QMessageBox::information(this, tr("Presupuesto Solicitado"),
    tr("QIdLinea:  ")+QIdLinea,QMessageBox::Ok, QMessageBox::Ok);
    QRazonamiento=m_ui->tablaVariacion->item(i,4)->text();
    QSolicitado=m_ui->tablaVariacion->item(i,3)->text();
    QAprobado=m_ui->tablaVariacion->item(i,2)->text();
    consulta.prepare("UPDATE lineadevariacion SET  Razonamiento=:Razonamiento, PresupuestoOtorgado=:Otorgado, PresupuestoSolicitado=:Solicitado  WHERE IdLineaVariacion=:IdLineaVariacion");
    consulta.bindValue(":Razonamiento",QRazonamiento);
    consulta.bindValue(":Otorgado",QAprobado);
    consulta.bindValue(":Solicitado",QSolicitado);
    consulta.bindValue(":IdLineaVariacion",QIdLinea);
    consulta.exec();
    consulta.clear();
   }
   m_ui->tablaVariacion->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
    m_ui->Institucion2->clear();
   QMessageBox::information(this, tr("Actualizacion de Datos"),
   tr("Sus datos Fueron almacenados correctamente"),QMessageBox::Ok, QMessageBox::Ok);
}






void edicionvariavcion::on_CancelarButton_clicked()
{
  int numfilas=m_ui->tablaVariacion->rowCount();
   for (int i=0;i<numfilas;i++)
  {
    m_ui->tablaVariacion->removeRow(i);
  }
   m_ui->tablaVariacion->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
   m_ui->Institucion2->clear();
   m_ui->Fecha->clear();
}



edicionvariavcion::~edicionvariavcion()
{
    delete m_ui;
}

void edicionvariavcion::changeEvent(QEvent *e)
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
