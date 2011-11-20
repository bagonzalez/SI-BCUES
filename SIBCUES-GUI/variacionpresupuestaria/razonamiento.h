#ifndef RAZONAMIENTO_H
#define RAZONAMIENTO_H
#include <QSqlQuery>
#include <QtGui/QWidget>

namespace Ui {
    class Razonamiento;
}

class Razonamiento : public QWidget {
    Q_OBJECT
public:
    Razonamiento(QWidget *parent = 0);
    ~Razonamiento();

public slots:
     void on_AgregarButton_clicked();
     void on_cancelarButton_clicked();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Razonamiento *m_ui;
    QSqlQuery consulta,consulta2;
    QString QIdEspecificacion;
};

#endif // RAZONAMIENTO_H
