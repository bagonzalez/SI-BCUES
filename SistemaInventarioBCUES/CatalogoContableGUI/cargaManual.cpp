#include "cargaManual.h"
#include <QtGui>

CargaManual::CargaManual(RegistroSistemaContable *reg ,int num){

	ui.setupUi(this);
        registro=reg;
	numeroTran=num;
        crearPalo();
	cancelada=false;
	ui.aplicar->setEnabled(false);
	ui.importe->setEnabled(false);
	ui.cargo->setEnabled(false);

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
        //ui.responsable->setText(registro->getNombreContador());

	fila=0;
	partidaDoble=0;
}

void CargaManual::crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre ){

    QList<string> listaHijos=QList<string>::fromStdList(this->registro->getHijosCuenta(nombreCuenta));

    for (int i = 0; i < listaHijos.size(); ++i){
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

        QList<string> lista=QList<string>::fromStdList(this->registro->getHijosCatalogo());

        QList<QTreeWidgetItem *> listaItem;

        for (int i = 0; i < lista.size(); ++i) {
                listaItem.push_back(new QTreeWidgetItem(__item));
                listaItem.last()-> setText(0, QString(lista.at(i).c_str()));
                this->crearPaloR(lista.at(i), &listaItem, listaItem.last());
        }
}
/*
void CargaManual::crearPalo(){
	ui.catalogo->takeTopLevelItem(0);
	ui.catalogo->headerItem()->setText(0, QApplication::translate("ContGeneral", "Catalogo de Cuentas", 0, QApplication::UnicodeUTF8));
        //ui.catalogo=registro->getPalo(ui.catalogo);
	ui.numeroTrans->setText(QVariant::QVariant(numeroTran).toString());
}*/


void CargaManual::on_catalogo_currentItemChanged ()
{
	ui.debe->clear();
	ui.haber->clear();
	ui.descripcion->clear();
	ui.cuenta->setText((ui.catalogo->currentItem())->text(0));
        cuenta=(ui.catalogo->currentItem()->text(0)).toStdString();


        if(registro->getDireccionCuenta(cuenta)!=NULL)
	{
                ui.debe->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getDebe(), 0, 'f', 2));

                ui.haber->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getHaber(), 0, 'f', 2));

                ui.descripcion->setText(registro->getDireccionCuenta(cuenta)->getDescripcion().c_str());
	}
        if(registro->getDireccionSubCuenta(cuenta)!=NULL)
	{
                ui.debe->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getDebe(), 0, 'f', 2));

                ui.haber->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getHaber(), 0, 'f', 2));

                ui.descripcion->setText(QString((registro->getDireccionSubCuenta(cuenta)->getDescripcion()).c_str()));
	}

}


void CargaManual::on_importe_valueChanged(){
	importe=ui.importe->value();
}


void CargaManual::on_buttonBox_rejected(){
	cancelada=true;
}


void CargaManual::on_partidaDoble_pressed(){
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

void CargaManual::on_aplicar_pressed(){
        if(!cuenta.empty() && ui.importe->value()>0){

		ui.eliminar->setEnabled(true);
		columna=0;

		ui.asientosContables->insertRow(fila);

                QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(cuenta.c_str()));
		if(fila%2!=0)
			newCuenta->setBackground( QBrush::QBrush (Qt::darkGreen ));
		ui.asientosContables->setItem(fila, columna, newCuenta);

		columna++;


		QTableWidgetItem *newImporte = new QTableWidgetItem(QVariant::QVariant(importe).toString());
		if(fila%2!=0)
			newImporte->setBackground( QBrush::QBrush (Qt::darkGreen ));
		ui.asientosContables->setItem(fila, columna, newImporte);

		columna++;

		if(ui.cargo->isChecked())
		{
			QTableWidgetItem *newCargo = new QTableWidgetItem();
			newCargo->setIcon(QIcon(":/iconos/button_ok.png"));
			if(fila%2!=0)
				newCargo->setBackground( QBrush::QBrush (Qt::darkGreen ));

			ui.asientosContables->setItem(fila, columna, newCargo);

			columna++;

			QTableWidgetItem *newAbono = new QTableWidgetItem();
			if(fila%2!=0)
				newAbono->setBackground( QBrush::QBrush (Qt::darkGreen ));

			ui.asientosContables->setItem(fila, columna, newAbono);

		}
		else
		{

			QTableWidgetItem *newCargo = new QTableWidgetItem();
			if(fila%2!=0)
				newCargo->setBackground( QBrush::QBrush (Qt::darkGreen ));

			ui.asientosContables->setItem(fila, columna, newCargo);

			columna++;
			QTableWidgetItem *newAbono = new QTableWidgetItem();
			newAbono->setIcon(QIcon(":/iconos/button_ok.png"));
			if(fila%2!=0)
				newAbono->setBackground( QBrush::QBrush (Qt::darkGreen ));

			ui.asientosContables->setItem(fila, columna, newAbono);
		}

		fila++;
		partidaDoble++;
		if(partidaDoble>1){
			ui.aplicar->setEnabled(false);
			ui.importe->setEnabled(false);
			ui.cargo->setEnabled(false);
			ui.abono->setEnabled(false);
			ui.partidaDoble->setEnabled(true);
			ui.finalizar->setEnabled(true);
		}
		else{
			ui.importe->setEnabled(false);

			if(ui.cargo->isChecked()){
				ui.cargo->setEnabled(false);
				ui.abono->setChecked(true);
			}
			else{
				ui.abono->setEnabled(false);
				ui.cargo->setChecked(true);
			}
		}

	}

}

void CargaManual::on_finalizar_pressed()
{

}

void CargaManual::on_eliminar_pressed()
{
	if(ui.asientosContables->currentItem()!=NULL)
	{
		int filaActual=ui.asientosContables->currentRow();

		if(filaActual%2==0)
		{
			ui.asientosContables->removeRow (filaActual+1);
			ui.asientosContables->removeRow (filaActual);
		}
		else{
			ui.asientosContables->removeRow (filaActual);
			ui.asientosContables->removeRow (filaActual-1);
		}
		fila=fila-2;

	}
	else{

		QMessageBox::information(this, tr("Eliminar Partida Doble"),
		 tr("Seleccione una fila para poder eliminar!"), QMessageBox::Ok, QMessageBox::Ok);
	}

}

