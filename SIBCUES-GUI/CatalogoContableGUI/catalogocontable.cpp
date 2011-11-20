#include "catalogocontable.h"
#include "ui_catalogocontable.h"
#include <QSqlQuery>
#include <QMessageBox>

CatalogoContable::CatalogoContable(RegistroSistemaContable *reg, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::CatalogoContable)
{
    m_ui->setupUi(this);

    registro=reg;
    crearPalo();
   m_ui->crearCuenta->setEnabled(false);
   m_ui->crearEspecifico->setEnabled(false);
   m_ui->crearRubro->setEnabled(false);
}

CatalogoContable::~CatalogoContable()
{
    delete m_ui;
}

void CatalogoContable::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void CatalogoContable::on_Catalogo_currentItemChanged ()
{   
   m_ui->codigoCuenta->setText(((m_ui->Catalogo->currentItem())->text(1)));
   m_ui->saldoDeudor->clear();
   m_ui->saldoAcreedor->clear();
   m_ui->debe->clear();
   m_ui->haber->clear();
   m_ui->textEdit->clear();

   string codigo=(m_ui->Catalogo->currentItem()->text(0)).toStdString();



    if (registro->getDireccionCuenta(codigo)!=NULL)
    {
       m_ui->debe->setText(QString("%1 $").arg(registro->getDireccionCuenta(codigo)->getDebe(), 0, 'f', 2));
       m_ui->haber->setText(QString("%1 $").arg(registro->getDireccionCuenta(codigo)->getHaber(), 0, 'f', 2));
       m_ui->textEdit->setText(QString(registro->getDireccionCuenta(codigo)->getDescripcion().c_str()));
    }

    if (registro->getSubCuentaCod(codigo)!=NULL)
    {
       m_ui->debe->setText(QString("%1 $").arg(registro->getSubCuentaCod(codigo)->getDebe(), 0, 'f', 2));
       m_ui->haber->setText(QString("%1 $").arg(registro->getSubCuentaCod(codigo)->getHaber(), 0, 'f', 2));
       m_ui->textEdit->setText(QString(registro->getSubCuentaCod(codigo)->getDescripcion().c_str()));
    }

    if (registro->getSubCuentaCod(codigo)!=NULL || registro->getDireccionCuenta(codigo)!=NULL)
    {
        float saldo=0.0;
        /*Verificar el saldo*/

        saldo=registro->getSaldoCuenta(codigo);

        if (saldo>=0)
        {
           m_ui->saldoDeudor->setText(QString("%1 $").arg(saldo, 0, 'f', 2));
        }
        else
        {
           saldo=saldo*(-1);
           m_ui->saldoAcreedor->setText(QString("%1 $").arg(saldo, 0, 'f', 2));
        }

        if (registro->getTipoCuenta(codigo)==contabilidad::especificos){
           m_ui->crearCuenta->setEnabled(false);
           m_ui->crearRubro->setEnabled(false);
           m_ui->crearEspecifico->setEnabled(false);
        }
        else{
            if(registro->getTipoCuenta(codigo)==contabilidad::rubro){
               m_ui->crearEspecifico->setEnabled(false);
               m_ui->crearRubro->setEnabled(false);
               m_ui->crearCuenta->setEnabled(true);
            }
            else{
                if(registro->getTipoCuenta(codigo)==contabilidad::agrupacionecomica){
                   m_ui->crearCuenta->setEnabled(false);
                   m_ui->crearRubro->setEnabled(true);
                   m_ui->crearEspecifico->setEnabled(false);
                }
                else{
                    if(registro->getTipoCuenta(codigo)==contabilidad::cuenta){
                       m_ui->crearCuenta->setEnabled(false);
                       m_ui->crearRubro->setEnabled(false);
                       m_ui->crearEspecifico->setEnabled(true);
                    }
                }
            }
        }
    }
}

void CatalogoContable::crearPaloR(string nombreCuenta, QList<QTreeWidgetItem *> *lista, QTreeWidgetItem *padre )
{

    map<string, string> listaHijos=this->registro->getHijosCuentaCodigos(nombreCuenta);

    for
    (
        map<string, string>::iterator et = listaHijos.begin();
        et != listaHijos.end();
        ++et
    )
    {
        lista->push_back(new QTreeWidgetItem(padre));
        lista->last()-> setText(1, QString(et->second.c_str()));
        lista->last()-> setText(0, QString(et->first.c_str()));
        this->crearPaloR(et->first, lista, lista->last());
    }
}

void CatalogoContable::crearPalo()
{
   m_ui->Catalogo->takeTopLevelItem(0);

    QTreeWidgetItem *__item = new QTreeWidgetItem(m_ui->Catalogo);
    __item->setText(0, "Agrupaciones Economicas");

    QTreeWidgetItem *ingresos = new QTreeWidgetItem(__item);
    ingresos->setText(0, "Ingresos");
    QTreeWidgetItem *gastos = new QTreeWidgetItem(__item);
    gastos->setText(0, "Gastos");

    map<string, string> lista=this->registro->getHijosCatalogo();

    QList<QTreeWidgetItem *> listaItem;

    for
    (
        map<string, string>::iterator et = lista.begin();
        et != lista.end();
        ++et
    )
    {
        if(registro->getDireccionCuenta(et->first)->getTipoDes()==contabilidad::ingreso)
            listaItem.push_back(new QTreeWidgetItem(ingresos));
        else
            listaItem.push_back(new QTreeWidgetItem(gastos));

        listaItem.last()-> setText(1, QString(et->second.c_str()));
        listaItem.last()-> setText(0, QString(et->first.c_str()));        
        this->crearPaloR(et->first, &listaItem, listaItem.last());
    }   
}

void CatalogoContable::on_pushButton_3_clicked()
{
    this->~CatalogoContable();
}

void CatalogoContable::CrearNuevaCuenta(string tipoCuenta)
{
    string cuenta=(m_ui->Catalogo->currentItem()->text(1)).toStdString();
    string codigo=(m_ui->Catalogo->currentItem()->text(0)).toStdString();
    bool categ=false;

    if (registro->getSubCuentaCod(codigo)!=NULL)
    {
        if (!(registro->getTipoCuenta(codigo)==contabilidad::especificos))
            categ=true;
    }

    if (registro->getDireccionCuenta(codigo)!=NULL)
    {
        if(!(registro->getTipoCuenta(codigo)==contabilidad::especificos))
            categ=true;
    }

    if (categ)
    {
        NuevaCuenta dialogo;
        dialogo.show();
        dialogo.exec();

        if (!dialogo.getNombreCuenta().isEmpty())
        {
            //if ((registro->getDireccionCuenta(dialogo.getNombreCuenta().toStdString()) ==NULL) && ( registro->getDireccionSubCuenta(dialogo.getNombreCuenta().toStdString())==NULL ))
            //{
                QString codigo=m_ui->Catalogo->currentItem()->text(0);
                QString tipoDestino=dialogo.getTipoDestino();

                registro->crearCategoria(codigo.toStdString(), dialogo.getNombreCuenta().toStdString(), dialogo.getCodigoManual().toStdString(), dialogo.getDescripcion().toStdString(), 0, true, tipoCuenta, tipoDestino.toStdString());
                crearPalo();

                QString nombreCuenta=dialogo.getNombreCuenta();
                QList<QTreeWidgetItem *> lista=m_ui->Catalogo->findItems(nombreCuenta, Qt::MatchRecursive, 1);

                for (int i = 0; i < lista.size(); ++i){
                    m_ui->Catalogo->setCurrentItem(lista.at(i));
                    m_ui->Catalogo->collapseItem(lista.at(i));
                }
            //}
            //else
             //   QMessageBox::warning(this, tr("Atencion"),tr("El nombre de la cuenta que ingreso, ya existe."), QMessageBox::Ok);

        }
    }
}

void CatalogoContable::on_transaccion_clicked()
{
    hide();
    QString cuenta1, cuenta2;
    int numeroTran =1;
    CargaManual dialogo(registro, numeroTran);
    dialogo.show();
    dialogo.exec();
    show();
}

void CatalogoContable::on_crearEspecifico_clicked()
{
    this->CrearNuevaCuenta("especificos");
}

void CatalogoContable::on_crearRubro_clicked()
{
    this->CrearNuevaCuenta("rubro");
}

void CatalogoContable::on_crearCuenta_clicked()
{
    this->CrearNuevaCuenta("cuenta");
}

void CatalogoContable::closeEvent(QCloseEvent *event){
     this->close();
}

void CatalogoContable::on_botonBuscar_clicked()
{
    dialogoBuscarCuenta *dialogoBuscar=new dialogoBuscarCuenta(this->registro, true);
    dialogoBuscar->show();
    dialogoBuscar->exec();

    string nombreCuenta=dialogoBuscar->getNombreCuenta();
    QList<QTreeWidgetItem *> lista=m_ui->Catalogo->findItems(QString::fromStdString(nombreCuenta), Qt::MatchRecursive);

    for (int i = 0; i < lista.size(); ++i){
       m_ui->Catalogo->setCurrentItem(lista.at(i));
       m_ui->Catalogo->collapseItem(lista.at(i));
    }
}


void CatalogoContable::on_btmSeleccionar_clicked()
{
    this->nombreCuenta=m_ui->Catalogo->currentItem()->text(1);
    this->codigo=m_ui->Catalogo->currentItem()->text(0);
    this->close();
}

QString CatalogoContable::getCodigoCuenta(){
    return this->codigo;
}

QString CatalogoContable::getNombreCuenta(){
    return this->nombreCuenta;
}
