#ifndef VERDOCUMENTOVARIACION_H
#define VERDOCUMENTOVARIACION_H

#include <QtGui/QWidget>
#include <QSqlQuery>

#include "ncreport.h"
#include "ncreportoutput.h"
#include "ncreportpreviewoutput.h"
#include "ncreportpreviewwindow.h"

namespace Ui {
    class VerDocumentoVariacion; 
  }

class VerDocumentoVariacion : public QWidget {
    Q_OBJECT
public:
    VerDocumentoVariacion(QWidget *parent = 0);
    ~VerDocumentoVariacion();

public slots:
     void on_Seleccionar_clicked();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::VerDocumentoVariacion *m_ui;
     QSqlQuery consulta;
};

#endif // VERDOCUMENTOVARIACION_H
