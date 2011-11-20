#ifndef PROGRESOREPORTE_H
#define PROGRESOREPORTE_H

#include <QtGui/QDialog>


#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

namespace Ui {
    class progresoReporte;
}

class progresoReporte : public QDialog {
    Q_OBJECT
public:
    progresoReporte(NCReport *report, QWidget *parent = 0);
    ~progresoReporte();

public slots:
    void execReport();

protected:
    void changeEvent(QEvent *e);

private slots:
    void cambiarProgreso(int pagina);    

private:
    Ui::progresoReporte *m_ui;
    NCReport *report;
};

#endif // PROGRESOREPORTE_H
