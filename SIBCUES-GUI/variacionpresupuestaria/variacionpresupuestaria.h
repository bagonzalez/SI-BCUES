#ifndef VARIACIONPRESUPUESTARIA_H
#define VARIACIONPRESUPUESTARIA_H
#include <QtGui/QMainWindow>
#include "crearvariacion.h"
#include "ui_crearvariacion.h"
#include "ui_presupuestoaprobado.h"
#include "presupuestoaprobado.h"
#include "verdocumentovariacion.h"
#include "razonamiento.h"
#include "edicionvariavcion.h"



namespace Ui
{
    class VariacionPresupuestaria;
}


class VariacionPresupuestaria : public QMainWindow
{
    Q_OBJECT

    private:
        CrearVariacion *variacionP;
        PresupuestoAprobado *AprobadoP;
        VerDocumentoVariacion *VerDocumento;
        Razonamiento *RazonamientoV;
        edicionvariavcion *EdicionV;

    public:
        VariacionPresupuestaria(QWidget *parent = 0);
         ~VariacionPresupuestaria();



private slots:
     void on_actionRegistro_de_Presupuesto_Solicitado_activated();
     void on_actionRegistro_de_Presupuesto_Aprobado_activated();
     void on_actionDocumento_de_Variacion_Presupuestaria_activated();
     void on_actionRegistro_de_Razonamiento_Variacion_Presupuestaria_activated();
     void on_actionVariacion_Presupuestaria_activated();


private:

    Ui::VariacionPresupuestaria *ui;


};

#endif // VARIACIONPRESUPUESTARIA_H
