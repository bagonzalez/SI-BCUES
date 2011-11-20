#include "razonamiento.h"
#include "ui_razonamiento.h"
#include <QSqlQuery>
#include <QMessageBox>

Razonamiento::Razonamiento(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Razonamiento)
{
    m_ui->setupUi(this);
    int columna;
    float variacion;
    QString  QFuenteFinanciamiento,QFechaElaboracion,QInstitucion="3101 Universidad de El Salvador",QCodigo,QDescripcion,QIdLinea,QAprobado,QSolicitado,QIdEspecificacion2,QValIniSolicitado="---",a,b,QVariacion;
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
            m_ui->tablaRazonamiento->insertRow(i);
            QCodigo=consulta.value(0).toString();
            QDescripcion=consulta.value(1).toString();
            QTableWidgetItem *CodigoCuenta=new QTableWidgetItem(QCodigo);
            QTableWidgetItem *Descripcion=new QTableWidgetItem(QDescripcion);
            m_ui->tablaRazonamiento->setItem(i,columna,CodigoCuenta);
            m_ui->tablaRazonamiento->setItem(i,++columna,Descripcion);
            i++;
    }
     consulta.exec(query);

   int numfilas;
   numfilas=m_ui->tablaRazonamiento->rowCount();
   for (i=0;i<numfilas;i++)
   {
    QIdLinea =QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QIdEspecificacion;
    consulta2.prepare("SELECT PresupuestoOtorgado,PresupuestoSolicitado FROM `lineadevariacion` WHERE IdLineaVariacion=:IdLineaVariacion");
    consulta2.bindValue(":IdLineaVariacion",QIdLinea);
    consulta2.exec();
    consulta2.next();
    QAprobado=consulta2.value(0).toString();
    QSolicitado=consulta2.value(1).toString();
    QTableWidgetItem *MontoAprobado=new QTableWidgetItem(QAprobado);
    QTableWidgetItem *MontoSolicitado=new QTableWidgetItem(QSolicitado);
    QTableWidgetItem *ValInicial=new QTableWidgetItem(QValIniSolicitado);
    m_ui->tablaRazonamiento->setItem(i,2,MontoAprobado);
    m_ui->tablaRazonamiento->setItem(i,3,MontoSolicitado);
    m_ui->tablaRazonamiento->setItem(i,5,ValInicial);
    a=m_ui->tablaRazonamiento->item(i,2)->text();
    b=m_ui->tablaRazonamiento->item(i,3)->text();
    variacion= b.toFloat()-a.toFloat();
    QVariacion = QString("%1").arg(variacion, 0, 'f', 2);
    QTableWidgetItem *Variacion=new QTableWidgetItem(QVariacion);
     m_ui->tablaRazonamiento->setItem(i,4,Variacion);

    consulta2.clear();
   }
    m_ui->tablaRazonamiento->resizeColumnsToContents();
}


void Razonamiento::on_AgregarButton_clicked()
{   QString QRazonamiento,QCuenta,QIdLinea;
    int numfilas, i;
    numfilas=m_ui->tablaRazonamiento->rowCount();
   for (i=0;i<numfilas;i++)
   {
    QIdLinea = QString::number(i);
    QIdLinea+="_";
    QIdLinea+=QIdEspecificacion;
    QRazonamiento=m_ui->tablaRazonamiento->item(i,5)->text();
    consulta.prepare("UPDATE lineadevariacion SET  Razonamiento=:Razonamiento WHERE IdLineaVariacion= :IdLineaVariacion ");
    consulta.bindValue(":Razonamiento",QRazonamiento);
    consulta.bindValue(":IdLineaVariacion",QIdLinea);
    consulta.exec();
    consulta.clear();
   }
   m_ui->tablaRazonamiento->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
    m_ui->Institucion2->clear();
   QMessageBox::information(this, tr("Presupuesto Aprobado"),
   tr("Sus datos Fueron almacenados correctamente"),QMessageBox::Ok, QMessageBox::Ok);
  }

void Razonamiento::on_cancelarButton_clicked()
{
  int numfilas=m_ui->tablaRazonamiento->rowCount();
   for (int i=0;i<numfilas;i++)
  {
    m_ui->tablaRazonamiento->removeRow(i);
  }
   m_ui->tablaRazonamiento->clearContents();
   m_ui->EjercicioFiscal2->clear();
   m_ui->FuenteFinanciamiento->clear();
   m_ui->Institucion2->clear();
   m_ui->Fecha->clear();
}

Razonamiento::~Razonamiento()
{
    delete m_ui;
}

void Razonamiento::changeEvent(QEvent *e)
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


