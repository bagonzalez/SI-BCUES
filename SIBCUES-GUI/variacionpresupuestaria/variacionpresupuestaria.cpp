#include "variacionpresupuestaria.h"
#include "ui_variacionpresupuestaria.h"
#include "ui_crearvariacion.h"
#include "ui_presupuestoaprobado.h"
#include "presupuestoaprobado.h"
#include "verdocumentovariacion.h"
#include "ui_verdocumentovariacion.h"
#include "razonamiento.h"
#include "ui_razonamiento.h"

VariacionPresupuestaria::VariacionPresupuestaria(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::VariacionPresupuestaria)
{
    ui->setupUi(this);
}

VariacionPresupuestaria::~VariacionPresupuestaria()
{
    delete ui;
}
void VariacionPresupuestaria::on_actionRegistro_de_Presupuesto_Solicitado_activated(){
variacionP=new CrearVariacion();
variacionP->show();
variacionP->setFocus();
variacionP->setVisible(true);
}

void VariacionPresupuestaria:: on_actionRegistro_de_Presupuesto_Aprobado_activated(){
 //if (SolicitadoHecho!=0){
AprobadoP=new PresupuestoAprobado();
AprobadoP->show();
AprobadoP->setFocus();
AprobadoP->setVisible(true);
//}
  //  else{
    //QMessageBox::critical(this, tr("Creacion de Variacion Presupuestaria"),
    //tr("Debe crear en primera instancia Variacion de Presupuesto Solicitado"),QMessageBox::Ok);

//}
}

void VariacionPresupuestaria::on_actionDocumento_de_Variacion_Presupuestaria_activated()
{
 VerDocumento=new VerDocumentoVariacion();
 VerDocumento->show();
 VerDocumento->setFocus();
 VerDocumento->setVisible(true);
}

void VariacionPresupuestaria::on_actionRegistro_de_Razonamiento_Variacion_Presupuestaria_activated()
{
 RazonamientoV=new Razonamiento();
 RazonamientoV->show();
 RazonamientoV->setFocus();
 RazonamientoV->setVisible(true);
}

void VariacionPresupuestaria::on_actionVariacion_Presupuestaria_activated()
{
 EdicionV=new edicionvariavcion();
 EdicionV->show();
 EdicionV->setFocus();
 EdicionV->setVisible(true);
}
