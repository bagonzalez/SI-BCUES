#include "cargaManual.h"
#include <QtGui>

CargaManual::CargaManual(RegistroSistemaContable::RegistroSistemaContable *reg ,int num)
{

    ui.setupUi(this);
    registro=reg;
    numeroTran=num;
    crearPalo();
    cancelada=false;
    ui.aplicar->setEnabled(false);
    ui.importe->setEnabled(false);
    ui.cargo->setEnabled(false);

    ui.fecha->setDate(QDateTime::currentDateTime().date());

    QStringList labels;
    labels << tr("Cuenta") << tr("Importe") << tr("Cargo") <<tr("Abono");
    ui.asientosContables->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
    ui.asientosContables->setSelectionBehavior ( QAbstractItemView::SelectRows);
    ui.asientosContables->setColumnCount(4);
    ui.asientosContables->setHorizontalHeaderLabels(labels);
    ui.asientosContables->horizontalHeader()->resizeSection(0, 320);
    ui.asientosContables->horizontalHeader()->resizeSection(1, 80);
    ui.asientosContables->horizontalHeader()->resizeSection(2, 80);
    ui.asientosContables->horizontalHeader()->resizeSection(3, 80);

    ui.abono->setEnabled(false);
    ui.finalizar->setEnabled(false);
    ui.eliminar->setEnabled(false);
    ui.numeroTrans->setText(QVariant::QVariant(this->registro->totalTansacciones()+1).toString());

    fila=0;
    partidaDoble=0;
}

void CargaManual::crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre )
{

    QList<string> listaHijos=QList<string>::fromStdList(this->registro->getHijosCuenta(nombreCuenta));

    for (int i = 0; i < listaHijos.size(); ++i)
    {
        lista->push_back(new QTreeWidgetItem(padre));
        lista->last()-> setText(0, QString(listaHijos.at(i).c_str()));
        this->crearPaloR(listaHijos.at(i), lista, lista->last());
    }
}

void CargaManual::crearPalo()
{

    ui.catalogo->takeTopLevelItem(0);

    QTreeWidgetItem *__item = new QTreeWidgetItem(ui.catalogo);
    __item->setText(0, "Rubros");

    map<string, string> lista=this->registro->getHijosCatalogo();

    QList<QTreeWidgetItem *> listaItem;

    for
    (
        map<string, string>::iterator et = lista.begin();
        et != lista.end();
        ++et
    )
    {
        listaItem.push_back(new QTreeWidgetItem(__item));
        listaItem.last()-> setText(0, QString(et->second.c_str()));
        listaItem.last()->setText(1, QString(et->first.c_str()));
        this->crearPaloR(et->second, &listaItem, listaItem.last());
    }
}


void CargaManual::on_catalogo_currentItemChanged ()
{
    ui.debe->clear();
    ui.haber->clear();
    ui.descripcion->clear();
    ui.cuenta->setText((ui.catalogo->currentItem())->text(0));
    cuenta=(ui.catalogo->currentItem()->text(0)).toStdString();


    if (registro->getDireccionCuenta(cuenta)!=NULL)
    {
        ui.debe->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getDebe(), 0, 'f', 2));

        ui.haber->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getHaber(), 0, 'f', 2));

        ui.descripcion->setText(registro->getDireccionCuenta(cuenta)->getDescripcion().c_str());
    }
    if (registro->getDireccionSubCuenta(cuenta)!=NULL)
    {
        ui.debe->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getDebe(), 0, 'f', 2));

        ui.haber->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getHaber(), 0, 'f', 2));

        ui.descripcion->setText(QString((registro->getDireccionSubCuenta(cuenta)->getDescripcion()).c_str()));
    }

}


void CargaManual::on_importe_valueChanged()
{
    importe=ui.importe->value();
}


void CargaManual::on_buttonBox_rejected()
{
    cancelada=true;
}


void CargaManual::on_partidaDoble_pressed()
{
    ui.cargo->setChecked(true);
    ui.finalizar->setEnabled(false);
    ui.aplicar->setEnabled(true);
    ui.importe->setEnabled(true);
    ui.cargo->setEnabled(true);
    ui.abono->setEnabled(true);
    ui.partidaDoble->setEnabled(false);
    ui.importe->setValue(0.00);
    partidaDoble=0;
}

void CargaManual::on_aplicar_pressed()
{

    if (!cuenta.empty() && ui.importe->value()>0)
    {

        ui.eliminar->setEnabled(true);
        columna=0;

        ui.asientosContables->insertRow(fila);

        QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(cuenta.c_str()));
        ui.asientosContables->setItem(fila, columna, newCuenta);

        columna++;


        QTableWidgetItem *newImporte = new QTableWidgetItem(QString::number(importe));
        ui.asientosContables->setItem(fila, columna, newImporte);

        columna++;

        if (ui.cargo->isChecked())
        {
            QTableWidgetItem *newCargo = new QTableWidgetItem();
            newCargo->setIcon(QIcon(":/iconos/button_ok.png"));


            ui.asientosContables->setItem(fila, columna, newCargo);

            columna++;

            QTableWidgetItem *newAbono = new QTableWidgetItem();



            ui.asientosContables->setItem(fila, columna, newAbono);

        }
        else
        {

            QTableWidgetItem *newCargo = new QTableWidgetItem();


            ui.asientosContables->setItem(fila, columna, newCargo);

            columna++;
            QTableWidgetItem *newAbono = new QTableWidgetItem();
            newAbono->setIcon(QIcon(":/iconos/button_ok.png"));


            ui.asientosContables->setItem(fila, columna, newAbono);
        }

        fila++;
        partidaDoble++;
        if (partidaDoble>1)
        {
            ui.aplicar->setEnabled(false);
            ui.importe->setEnabled(false);
            ui.cargo->setEnabled(false);
            ui.abono->setEnabled(false);
            ui.partidaDoble->setEnabled(true);
            ui.finalizar->setEnabled(true);
        }
        else
        {
            ui.importe->setEnabled(false);

            if (ui.cargo->isChecked())
            {
                ui.cargo->setEnabled(false);
                ui.abono->setChecked(true);
            }
            else
            {
                ui.abono->setEnabled(false);
                ui.cargo->setChecked(true);
            }
        }
    }
}

void CargaManual::on_finalizar_pressed()
{
    QMessageBox msgBox;
    msgBox.setText("Ingreso de Transacciones.");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret)
    {
    case QMessageBox::Save:
    {

        QDateTime HoraFecha=QDateTime::currentDateTime();

        Fecha *_fechaTran=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());
        int codTran=this->registro->crearTransaccion(_fechaTran);
        string cuentaDoble1, cuentaDoble2;
        float montoDoble1=0.0, montoDoble2=0.0;
        bool cargo;

        for (int i=0; i< ui.asientosContables->rowCount(); i++)
        {
            cuentaDoble1=QString(this->ui.asientosContables->item(i, 0)->data(0).toString()).toStdString();


            montoDoble1=this->ui.asientosContables->item(i,1)->data(0).toString().toFloat();
            std::cout << "ESta mierda" <<montoDoble1 ;

            if (this->ui.asientosContables->item(i,2)->icon().isNull())
                cargo=false;
            else
                cargo=true;



            this->registro->introducirInformacionTransaccion(montoDoble1, cargo, cuentaDoble1, codTran);

            i++;

            cuentaDoble2=QString(this->ui.asientosContables->item(i, 0)->data(0).toString()).toStdString();


            montoDoble2=this->ui.asientosContables->item(i,1)->data(0).toString().toFloat();
            std::cout << "ESta mierda" <<montoDoble2 ;

            if (this->ui.asientosContables->item(i,2)->icon().isNull())
                cargo=false;
            else
                cargo=true;

            //Podemos hacer una transaccion contable

            this->registro->introducirInformacionTransaccion(montoDoble2, cargo, cuentaDoble2,codTran);
        }

        QMessageBox msgBox;
        msgBox.setText("    Ingresado con exito!.   ");
        msgBox.exec();
        ui.numeroTrans->setText(QVariant::QVariant(this->registro->totalTansacciones()+1).toString());

        for (int i=ui.asientosContables->rowCount() -1; i>=0; i--)
        {
            this->ui.asientosContables->removeRow(i);
        }
        this->fila=0;
        this->ui.finalizar->setDisabled(true);
    }
    break;

    case QMessageBox::Cancel:
    {
        QMessageBox msgBox;
        msgBox.setText("    Puede continuar ingresando transacciones   ");
        msgBox.exec();

    }
    break;
    default:
        break;
    }
}

void CargaManual::on_nuevaTransaccion_pressed()
{

    if (ui.asientosContables->rowCount()!=0)
    {
        QMessageBox msgBox;
        msgBox.setText("Ingreso de Transacciones.");
        msgBox.setInformativeText("No se ha almacenado la transaccion, ¿desea cancelarla?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();

        switch (ret)
        {
        case QMessageBox::Yes:
        {
            for (int i=0; i< ui.asientosContables->rowCount(); i++)
            {
                this->ui.asientosContables->removeRow(i);
            }
            this->fila=0;
        }
        break;

        case QMessageBox::No:
        {
        }
        break;
        }
    }
    else
    {
        ui.numeroTrans->setText(QVariant::QVariant(this->registro->totalTansacciones()+1).toString());
    }
}

void CargaManual::on_cancelarTran_pressed()
{
    this->close();
}

void CargaManual::on_eliminar_pressed()
{
    if (ui.asientosContables->currentItem()!=NULL)
    {
        int filaActual=ui.asientosContables->currentRow();

        if (filaActual%2==0)
        {
            ui.asientosContables->removeRow (filaActual+1);
            ui.asientosContables->removeRow (filaActual);
        }
        else
        {
            ui.asientosContables->removeRow (filaActual);
            ui.asientosContables->removeRow (filaActual-1);
        }
        fila=fila-2;

    }
    else
    {

        QMessageBox::information(this, tr("Eliminar Partida Doble"),
                                 tr("Seleccione una fila para poder eliminar!"), QMessageBox::Ok, QMessageBox::Ok);
    }

}

