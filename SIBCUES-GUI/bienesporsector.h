#ifndef BIENESPORSECTOR_H
#define BIENESPORSECTOR_H

#include <QDialog>
#include "../Persistencia/persistencia.h"
#include "../Basico/Basico_global.h"
#include "../Basico/basico.h"


#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

namespace Ui {
    class BienesporSector;
}

class BienesporSector : public QDialog
{
    Q_OBJECT

public:
    explicit BienesporSector(basico::Registro  *registroBasico, QWidget *parent = 0);
    ~BienesporSector();

private:
    Ui::BienesporSector *ui;
    Persistencia *servicioPersistencia;

    basico::Registro *registroBasico;

private slots:
    void on_btnVerReporte_clicked();
    void on_btnCancelar_clicked();
};

#endif // BIENESPORSECTOR_H
