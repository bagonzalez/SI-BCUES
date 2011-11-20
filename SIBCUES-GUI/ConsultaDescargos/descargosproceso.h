#ifndef DESCARGOSPROCESO_H
#define DESCARGOSPROCESO_H

#include <QDialog>
#include <QTableWidgetItem>

namespace Ui {
    class DescargosProceso;
}

class DescargosProceso : public QDialog {
    Q_OBJECT
public:
    DescargosProceso(int idUnidad, QWidget *parent = 0);
    ~DescargosProceso();

    int getIdDescargo();
    QList<QTableWidgetItem *>  getListaItems();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::DescargosProceso *ui;
    int idDescargo;
    QList<QTableWidgetItem *> listaItem;

private slots:
    void on_btmSeleccionar_pressed();
};

#endif // DESCARGOSPROCESO_H
