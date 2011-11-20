#ifndef EDICIONVARIAVCION_H
#define EDICIONVARIAVCION_H

#include <QtGui/QWidget>
#include <QSqlQuery>
#include <iostream>


namespace Ui {
    class edicionvariavcion;
}

class edicionvariavcion : public QWidget {
    Q_OBJECT
public:
    edicionvariavcion(QWidget *parent = 0);
    ~edicionvariavcion();

protected:
    void changeEvent(QEvent *e);

public slots:
     void on_AgregarButton_clicked();
     void on_CancelarButton_clicked();

private:
    Ui::edicionvariavcion *m_ui;
    QSqlQuery consulta,consulta2;
    QString QIdEspecificacion;
};

#endif // EDICIONVARIAVCION_H
