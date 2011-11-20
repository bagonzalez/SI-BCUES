#ifndef MANTENIMIENTOTITULO_H
#define MANTENIMIENTOTITULO_H

#include <QtGui/QDialog>
#include <QModelIndex>

namespace Ui {
    class mantenimientoTitulo;
}

class mantenimientoTitulo : public QDialog {
    Q_OBJECT
public:
    mantenimientoTitulo(int idUnidad, QWidget *parent = 0);
    ~mantenimientoTitulo();
    QString getTitulo();
    QString getISBN();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::mantenimientoTitulo *m_ui;
    QString titulo;
    QString isbn;

private slots:
    void on_seleccionarTitulo_clicked();
    void on_btmBuscar_clicked();
    void on_titulos_activated(QModelIndex index);
};

#endif // MANTENIMIENTOTITULO_H
