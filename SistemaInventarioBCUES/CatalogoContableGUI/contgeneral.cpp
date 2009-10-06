
#include <QtGui>
#include <QSqlQuery>
#include <QList>
#include <list>
#include <QMessageBox>
#include "contgeneral.h"
#include "nuevaCuenta.h"


using namespace contabilidad;

ContGeneral::ContGeneral(RegistroSistemaContable *reg)
{
	ui.setupUi(this);
	registro=reg;

        crearPalo();
    }

void ContGeneral::on_Catalogo_currentItemChanged ()
{

	QSqlQuery query;
        ui.codigoCuenta->setText(((ui.Catalogo->currentItem())->text(0)));
	ui.saldoDeudor->clear();
	ui.saldoAcreedor->clear();
	ui.debe->clear();
	ui.haber->clear();
	ui.textEdit->clear();
        string cuenta=(ui.Catalogo->currentItem()->text(0)).toStdString();

        if(registro->getDireccionCuenta(cuenta)!=NULL)
	{
                ui.debe->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getDebe(), 0, 'f', 2));

                ui.haber->setText(QString("%1").arg(registro->getDireccionCuenta(cuenta)->getHaber(), 0, 'f', 2));

                ui.textEdit->setText(QString(registro->getDireccionCuenta(cuenta)->getDescripcion().c_str()));
	}
        if(registro->getDireccionSubCuenta(cuenta)!=NULL)
	{
                ui.debe->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getDebe(), 0, 'f', 2));

                ui.haber->setText(QString("%1").arg(registro->getDireccionSubCuenta(cuenta)->getHaber(), 0, 'f', 2));

                ui.textEdit->setText(QString(registro->getDireccionSubCuenta(cuenta)->getDescripcion().c_str()));
	}

        if(registro->getDireccionSubCuenta(cuenta)!=NULL || registro->getDireccionCuenta(cuenta)!=NULL){
		float saldo=0.0;

                saldo=registro->getSaldoCuenta(cuenta);
		if(saldo>=0){
			ui.saldoDeudor->setText(QString("%1").arg(saldo, 0, 'f', 2));

		}
		else{
			saldo=saldo*(-1);
			ui.saldoAcreedor->setText(QString("%1").arg(saldo, 0, 'f', 2));
		}
	}	
}

void ContGeneral::crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre ){

    QList<string> listaHijos=QList<string>::fromStdList(this->registro->getHijosCuenta(nombreCuenta));

    for (int i = 0; i < listaHijos.size(); ++i){
         lista->push_back(new QTreeWidgetItem(padre));
         lista->last()-> setText(0, QString(listaHijos.at(i).c_str()));
         this->crearPaloR(listaHijos.at(i), lista, lista->last());
     }
}

void ContGeneral::crearPalo()
{
        ui.Catalogo->takeTopLevelItem(0);

        QTreeWidgetItem *__item = new QTreeWidgetItem(ui.Catalogo);
        __item->setText(0, "Rubros");

        QList<string> lista=QList<string>::fromStdList(this->registro->getHijosCatalogo());

        QList<QTreeWidgetItem *> listaItem;

        for (int i = 0; i < lista.size(); ++i) {
                listaItem.push_back(new QTreeWidgetItem(__item));
                listaItem.last()-> setText(0, QString(lista.at(i).c_str()));
                this->crearPaloR(lista.at(i), &listaItem, listaItem.last());
        }        
}

void ContGeneral::on_pushButton_clicked()
{
    this->CrearNuevaCuenta(false);
}

void ContGeneral::on_pushButton_2_clicked()       
{
    this->CrearNuevaCuenta(true);
}

void ContGeneral::CrearNuevaCuenta(bool cat)
{
     string cuenta=(ui.Catalogo->currentItem()->text(0)).toStdString();
     bool categ=false;

        if(registro->getDireccionSubCuenta(cuenta)!=NULL)
        {
            if(registro->getTipoCuenta(cuenta)==contabilidad::categoria)
                categ=true;
        }

        if(registro->getDireccionCuenta(cuenta)!=NULL){
             if(registro->getTipoCuenta(cuenta)==categoria)
                        categ=true;
        }


        if(categ)
	{
		NuevaCuenta dialogo;
		dialogo.show();
		dialogo.exec();

		if(!dialogo.getNombreCuenta().isEmpty())
		{
                        if((registro->getDireccionCuenta(dialogo.getNombreCuenta().toStdString()) ==NULL) && ( registro->getDireccionSubCuenta(dialogo.getNombreCuenta().toStdString())==NULL ))
			{
                                QString cuentaMadre=ui.Catalogo->currentItem()->text(0);

                                if(dialogo.getManual()){
                                      if(cat)
                                        registro->crearCategoria(cuentaMadre.toStdString(), dialogo.getNombreCuenta().toStdString(), dialogo.getCodigoManual().toInt());
                                    else
                                        registro->crearSubCuenta(cuentaMadre.toStdString(), dialogo.getNombreCuenta().toStdString(), dialogo.getCodigoManual().toInt());

                                }else{

                                    if(cat)
                                        registro->crearCategoria(cuentaMadre.toStdString(), dialogo.getNombreCuenta().toStdString());
                                    else
                                        registro->crearSubCuenta(cuentaMadre.toStdString(), dialogo.getNombreCuenta().toStdString());
                                }

                                //registro->crearCuenta(dialogo.getNombreCuenta(), cuentaMadre, dialogo.getDescripcion(), cat);
				crearPalo();
			}
			else
				QMessageBox::warning(this, tr("Atencion"),tr("El nombre de la cuenta que ingreso, ya existe."), QMessageBox::Ok);
		}
        }
}

void ContGeneral::on_transaccion_clicked(){

	hide();

        //bool salir=false;
        //float cargo, abono;
        QString cuenta1, cuenta2;

        int numeroTran =1;//registro->contenedorTransaccion.count()+1;
	CargaManual dialogo(registro, numeroTran);
	dialogo.show();
	dialogo.exec();


	/*while(salir==false){
		for(int i=1; i<3; i++)
		{
			dialogo.show();
			dialogo.exec();

			if(dialogo.cuenta!=NULL){

				if(dialogo.cargo){
					cargo=dialogo.importe;
					cuenta1=dialogo.cuenta;
					dialogo.ui.abono->setChecked ( true );
					dialogo.cargo=false;
				}
				else{
					cuenta2=dialogo.cuenta;
					abono=dialogo.importe;
					dialogo.ui.abono->setChecked ( false );
					dialogo.cargo=true;
				}
			}
			else
				i=2;

		}

		if(!dialogo.cancelada)
		{
			registro->crearTransaccion();
			registro->introducirInformacionTransaccion(cargo, true, cuenta1, numeroTran);
			registro->introducirInformacionTransaccion(abono, false, cuenta2, numeroTran);

		}

		QMessageBox msgBox;
		msgBox.setText("Realizar asientos contables.");
		msgBox.setInformativeText("Desea continuar? Recuerde que se debe cumplir partida doble");
		msgBox.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
		//msgBox.setDefaultButton(QMessageBox::No);
		int ret = msgBox.exec();

		switch (ret) {
			case QMessageBox::Yes:
				salir=false;
				break;
			case QMessageBox::No:
				salir=true;
				break;
			default:
				salir=true;
				break;
		}

	}*/

	show();

}


