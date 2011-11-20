#ifndef SECTORESGUI_H
#define SECTORESGUI_H

#include <QtGui/QDialog>
#include <QModelIndex>
#include <QSqlTableModel>
#include <QSqlError>
#include <QDebug>

#include "../../Basico/Basico_global.h"
#include "../../Basico/basico.h"

using namespace basico;

namespace Ui {
    class SectoresGUI;
}

class SectoresGUI : public QDialog {
    Q_OBJECT
public:
    SectoresGUI(Registro *regBasico, QWidget *parent = 0);
    ~SectoresGUI();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_tablaSectores_activated(QModelIndex index);
    void insertRow();
    void deleteRow();
    void modificarFila();

private:
    Ui::SectoresGUI *m_ui;
    Registro *regBasico;
};

#endif // SECTORESGUI_H
