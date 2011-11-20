#include "presupuestoaprobado.h"
#include "ui_presupuestoaprobado.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include <QSqlQuery>

PresupuestoAprobado::PresupuestoAprobado(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::PresupuestoAprobado)
{

    m_ui->setupUi(this);

    QString  QFuenteFinanciamiento,QFechaElaboracion,QInstitucion="3101 Universidad de El Salvador",QInicial="0";
    QMontoTotal="$";
    m_ui->Institucion2->setText(QInstitucion);
    m_ui->montoTotallLine->setText(QMontoTotal);
    QString query=" SELECT MAX( idEspecificacion )FROM variacionpresupuestaria";
    consulta.exec(query);
    consulta.next();
    QIdEspecificacion=consulta.value(0).toString();
    consulta.clear();
    query="SELECT idEspecificacion, FuenteFinanciamiento, fechaElaboracion FROM variacionpresupuestaria WHERE IdEspecificacion=";
    query+=QIdEspecificacion;
    consulta.exec(query);
    consulta.next();
    QIdEspecificacion=consulta.value(0).toString();
    QFuenteFinanciamiento=consulta.value(1).toString();
    QFechaElaboracion=consulta.value(2).toString();
    m_ui->EjercicioFiscal2->setText(QIdEspecificacion);
    m_ui->FuenteFinanciamiento->setText(QFuenteFinanciamiento);
    m_ui->Fecha->setText(QFechaElaboracion);
    consulta.clear();
    query ="SELECT codigoCuenta,nombreCuenta FROM `cuenta` WHERE codigoCuenta <=61107 && codigoCuenta>=51101";
    consulta.exec(query);
    columna=1;
    int i=0;
    while (consulta.next()){
            columna--;
            m_ui->tablaPresupuestoAprobado->insertRow(i);
            QCodigo=consulta.value(0).toString();
            QDescripcion=consulta.value(1).toString();
            QTableWidgetItem *CodigoCuenta=new QTableWidgetItem(QCodigo);
            QTableWidgetItem *Descripcion=new QTableWidgetItem(QDescripcion);
            m_ui->tablaPresupuestoAprobado->setItem(i,columna,CodigoCuenta);
            m_ui->tablaPresupuestoAprobado->setItem(i,++columna,Descripcion);
            QTableWidgetItem *ValIniSolicitado= new QTableWidgetItem(QInicial);
            m_ui->tablaPresupuestoAprobado->setItem(i,2,ValIniSolicitado);
            i++;

    }
     m_ui->tablaPresupuestoAprobado->resizeColumnsToContents();
    consulta.clear();

}


PresupuestoAprobado::~PresupuestoAprobado()
{
    delete m_ui;
}


void PresupuestoAprobado::on_AgregarButton_clicked()
{   QString QMontoAprobado,QCuenta,QIdLinea;
    int numfilas, i;
    numfilas=m_ui->tablaPresupuestoAprobado->rowCount();
   for (i=0;i<numfilas;i++)
   {
    QIdLinea = QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QIdEspecificacion;
    QMontoAprobado=m_ui->tablaPresupuestoAprobado->item(i,2)->text();
    consulta.prepare("UPDATE lineadevariacion SET  PresupuestoOtorgado=:PresupuestoOtorgado WHERE IdLineaVariacion= :IdLineaVariacion ");
    consulta.bindValue(":PresupuestoOtorgado",QMontoAprobado);
    consulta.bindValue(":IdLineaVariacion",QIdLinea);
    consulta.exec();
    consulta.clear();
   }
   m_ui->tablaPresupuestoAprobado->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
   m_ui->montoTotallLine->clear();
   m_ui->montoTotallLine->setText(QMontoTotal);
   QMessageBox::information(this, tr("Presupuesto Aprobado"),
   tr("Sus datos Fueron almacenados correctamente"),QMessageBox::Ok, QMessageBox::Ok);
  }


void PresupuestoAprobado::on_cancelarButton_clicked()
{
  int numfilas=m_ui->tablaPresupuestoAprobado->rowCount();
   for (int i=0;i<numfilas;i++)
  {
    m_ui->tablaPresupuestoAprobado->removeRow(i);
  }
   m_ui->tablaPresupuestoAprobado->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
   m_ui->Institucion2->clear();
   m_ui->Fecha->clear();
   m_ui->montoTotallLine->clear();
   m_ui->montoTotallLine->setText(QMontoTotal);
}

void PresupuestoAprobado::on_TotalAprobadoLinkButton_clicked()
{
    QString Prueba, QMtotal;
   float monto=0.0,MontoTotal=0.0;
   int i,numfilas;
   //m_ui->tablaPresupuestoSolicitado->selectColumn(3);
   numfilas=m_ui->tablaPresupuestoAprobado->rowCount();
   for (i=0;i<numfilas;i++)
   {
   Prueba=m_ui->tablaPresupuestoAprobado->item(i,2)->data(0).toString();
   monto=Prueba.toFloat();
   MontoTotal=MontoTotal+ monto;
  }
   QMtotal= QMontoTotal;
   QMtotal += QString("%1").arg(MontoTotal, 0, 'f', 2);
   total = QMtotal.toInt();
   m_ui->montoTotallLine->setText(QString::number(MontoTotal));
}


void PresupuestoAprobado::changeEvent(QEvent *e)
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
