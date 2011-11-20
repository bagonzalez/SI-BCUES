#include <QCompleter>
#include <QStringList>
#include "consultabienes.h"
#include "ui_consultabienes.h"

#include <QtSql>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>

#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


ConsultaBienes::ConsultaBienes(moduloinventario::RegistroCatalogo *reg, contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsultaBienes)
{
    ui->setupUi(this);



    this->regBasico=registroBasico;
    this->registroCatalogo=reg;


    this->registroContable=regC;
    this->inventario=_inventario;


     Persistencia::Persistencia *servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

   //this->idInvAF=servicioPersistencia->getIdInvAF();

    if(this->registroCatalogo==NULL){
        this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);
        this->registroCatalogo->cargarCatalogo(servicioPersistencia->getIDInvFijo("2011"));
    }



   ui->tablaBienes->setItemDelegate(new QSqlRelationalDelegate(ui->tablaBienes));

   std::map<int, string> listaSectores=servicioPersistencia->cargarSectores();
   ui->sectores->addItem("<< Seleccionar >>", QVariant::QVariant(-1));

   for
   (
           map<int, string>::iterator it = listaSectores.begin();
           it != listaSectores.end();
               ++it
    ){
         ui->sectores->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
   }
   this->on_buttonBox_accepted();

   completer();
}

ConsultaBienes::~ConsultaBienes()
{
    delete ui;
}

void ConsultaBienes::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void ConsultaBienes::completer(){
    QList<QString> myQString;

    listaCodigosCuentas=this->registroContable->getHijosCatalogo();
    myQString.clear();

    for
    (
            map<string, string>::iterator it = listaCodigosCuentas.begin();
            it != listaCodigosCuentas.end();
                ++it
     ){
          if(it->first!="12090")
           myQString.push_back(QString::fromStdString(it->first));
    }

    QCompleter *completer2 = new QCompleter(myQString, this);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    ui->numeroCuenta->setCompleter(completer2);
}


void ConsultaBienes::on_btmBuscarClases_pressed()
{
    CatalogoActivoFijoGUI *dialogoAF=new CatalogoActivoFijoGUI(this->registroCatalogo, this->registroContable, this->regBasico);
    dialogoAF->exec();

    if(this->registroContable->getDireccionCuenta(dialogoAF->getMadre().toStdString())!=NULL){

        ui->numeroCuenta->setText(QString::fromStdString(this->registroContable->getDireccionCuenta(dialogoAF->getMadre().toStdString())->getcodigoCuenta()));
        ui->nombreClase->setText(dialogoAF->getClase());


        string nombreClase=ui->nombreClase->text().toStdString();
        string cuentaAsignada=this->registroContable->getDireccionCuenta(dialogoAF->getMadre().toStdString())->getNombreCuenta();

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
        {
            moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
            ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
            ui->descripcion->setReadOnly(true);


        }
    }
}


void ConsultaBienes::iniciarConsulta(){



    QSqlQueryModel *model=new QSqlQueryModel(ui->tablaBienes);
    float valorConsulta=0.0;



    //model->setTable("bienactivofijo");
    //model->select();
    //model->setRelation(2, QSqlRelation("sectores", "idSector", "descripcionSector"));
    //model->setRelation(3, QSqlRelation("especbien", "idEspec", "descripcionClase"));
    //model->setRelation(4, QSqlRelation("especcuenta", "idEspecCuenta", "codigoCuenta"));
    //model->select();
    //model->setRelation(5, QSqlRelation("modelo", "idModelo", "modelo"));
    //model->setRelation(6, QSqlRelation("marca", "idMarca", "nombreMarca"));

    if(ui->checkClase->isChecked() && ui->checkSector->isChecked())
    {
        QString SQL;
        SQL="SELECT bienactivofijo.idBien, bienactivofijo.codigo, inventario.anioInventario,  especbien.descripcionClase, marca.nombreMarca, modelo.modelo, sectores.descripcionSector,  bienactivofijo.valor, bienactivofijo.fechaAdquisicion, bienactivofijo.serie   FROM bienactivofijo ";
        SQL+=" LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
        SQL+=" LEFT JOIN marca ON marca.idMarca=bienactivofijo.idMarca ";
        SQL+=" LEFT JOIN modelo ON modelo.idModelo=bienactivofijo.idModelo ";
        SQL+=" LEFT JOIN sectores ON sectores.idSector=bienactivofijo.idSector ";
        SQL+=" LEFT JOIN invactivofijo ON invactivofijo.idInvAF=bienactivofijo.idInvAF    ";
        SQL+=" LEFT JOIN inventario ON invactivofijo.idInventario=inventario.idInventario    ";
        SQL+="  WHERE estadoBien='activo' AND descripcionClase='"+ui->descripcion->text()+"' AND descripcionSector='"+ui->sectores->currentText()+"'   ORDER BY bienactivofijo.codigo ";
        model->setQuery(SQL,  QSqlDatabase::database("sibcues"));
    }

    if( ui->checkSector->isChecked() && !(ui->checkClase->isChecked()))
    {
        QString SQL;

        SQL="SELECT bienactivofijo.idBien, bienactivofijo.codigo, inventario.anioInventario, especbien.descripcionClase, marca.nombreMarca, modelo.modelo, sectores.descripcionSector,  bienactivofijo.valor, bienactivofijo.fechaAdquisicion, bienactivofijo.serie   FROM bienactivofijo ";
        SQL+=" LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
        SQL+=" LEFT JOIN marca ON marca.idMarca=bienactivofijo.idMarca ";
        SQL+=" LEFT JOIN modelo ON modelo.idModelo=bienactivofijo.idModelo ";
        SQL+=" LEFT JOIN sectores ON sectores.idSector=bienactivofijo.idSector ";
        SQL+=" LEFT JOIN invactivofijo ON invactivofijo.idInvAF=bienactivofijo.idInvAF    ";
        SQL+=" LEFT JOIN inventario ON invactivofijo.idInventario=inventario.idInventario    ";
        SQL+="WHERE estadoBien='activo' AND  descripcionSector='"+ui->sectores->currentText()+"'   ORDER BY bienactivofijo.codigo ";
        model->setQuery(SQL,  QSqlDatabase::database("sibcues"));

        //bienactivofijo.idInvAF="+QString::number(this->idInvAF)+"

    }

    if(ui->checkClase->isChecked() && !(ui->checkSector->isChecked()))
    {
        QString SQL;

        SQL="SELECT bienactivofijo.idBien, bienactivofijo.codigo, inventario.anioInventario,  especbien.descripcionClase, marca.nombreMarca, modelo.modelo, sectores.descripcionSector,  bienactivofijo.valor, bienactivofijo.fechaAdquisicion, bienactivofijo.serie   FROM bienactivofijo ";
        SQL+=" LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
        SQL+=" LEFT JOIN marca ON marca.idMarca=bienactivofijo.idMarca ";
        SQL+=" LEFT JOIN modelo ON modelo.idModelo=bienactivofijo.idModelo ";
        SQL+=" LEFT JOIN sectores ON sectores.idSector=bienactivofijo.idSector ";
        SQL+=" LEFT JOIN invactivofijo ON invactivofijo.idInvAF=bienactivofijo.idInvAF    ";
        SQL+=" LEFT JOIN inventario ON invactivofijo.idInventario=inventario.idInventario    ";
        SQL+=" WHERE estadoBien='activo' AND descripcionClase='"+ui->descripcion->text()+"'   ORDER BY bienactivofijo.codigo ";
        model->setQuery(SQL,  QSqlDatabase::database("sibcues"));
    }

    if(!(ui->checkClase->isChecked()) && !(ui->checkSector->isChecked()))
    {
        QString SQL;

        SQL="SELECT bienactivofijo.idBien, bienactivofijo.codigo, inventario.anioInventario,  especbien.descripcionClase, marca.nombreMarca, modelo.modelo, sectores.descripcionSector,  bienactivofijo.valor, bienactivofijo.fechaAdquisicion, bienactivofijo.serie   FROM bienactivofijo ";
        SQL+=" LEFT JOIN especbien ON especbien.idEspec=bienactivofijo.idEspec ";
        SQL+=" LEFT JOIN marca ON marca.idMarca=bienactivofijo.idMarca ";
        SQL+=" LEFT JOIN modelo ON modelo.idModelo=bienactivofijo.idModelo ";
        SQL+=" LEFT JOIN sectores ON sectores.idSector=bienactivofijo.idSector ";
        SQL+=" LEFT JOIN invactivofijo ON invactivofijo.idInvAF=bienactivofijo.idInvAF    ";
        SQL+=" LEFT JOIN inventario ON invactivofijo.idInventario=inventario.idInventario    ";
        SQL+="WHERE estadoBien='activo'   ORDER BY bienactivofijo.codigo ";
        model->setQuery(SQL,  QSqlDatabase::database("sibcues"));
    }

    ui->tablaBienes->setModel(model);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Codigo"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Inventario"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Descripcion"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Marca"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Modelo"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Sector"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Valor"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Fecha Adquisicion"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Serie"));


    for(int i=0; i<model->rowCount(); i++){
        valorConsulta=model->index(i, 7).data(0).toFloat()+valorConsulta;
    }

     //model->select();
     ui->tablaBienes->setModel(model);     
     ui->tablaBienes->sortByColumn(1);
     ui->tablaBienes->hideColumn(0);
     ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
     ui->tablaBienes->alternatingRowColors();
     ui->labelResultados->setText("Resultados: "+QString::number(model->rowCount()) + " encontrados.");

     ui->valorListado->setText("Valor total del listado: "+QString(" $ %1").arg(valorConsulta, 0, 'f', 2 ));
 }


void ConsultaBienes::on_buttonBox_accepted()
{
    this->iniciarConsulta();
}

void ConsultaBienes::on_seleccionarBien_pressed()
{
    QAbstractItemModel  *model=ui->tablaBienes->model();
    int fila=ui->tablaBienes->currentIndex().row();
    this->idBienSeleccionado=model->index(fila,0).data(0).toInt();
    this->close();
}

int ConsultaBienes::getBienSeleccionado(){
    return this->idBienSeleccionado;    
}

void ConsultaBienes::on_numeroCuenta_editingFinished()
{    

        QList<QString> myQString;

        QString cuentaAsignada=QString::fromStdString(this->listaCodigosCuentas[ui->numeroCuenta->text().toStdString()].c_str());

        list<string> listaClases=this->registroCatalogo->getClases(cuentaAsignada.toStdString() );

        for
        (
            list<string>::iterator from = listaClases.begin();
            from != listaClases.end();
            ++from
        ){
                myQString.push_back(QString(QVariant::QVariant((*from).c_str()).toString()));
        }

        QCompleter *completer2 = new QCompleter(myQString, this);
        completer2->setCaseSensitivity(Qt::CaseInsensitive);
        ui->nombreClase->setCompleter(completer2);

}

void ConsultaBienes::on_nombreClase_editingFinished()
{
    QString cuentaAsignada=QString::fromStdString(this->listaCodigosCuentas[ui->numeroCuenta->text().toStdString()].c_str());
    QString nombreClase=ui->nombreClase->text();



    if(this->registroCatalogo->existeClase( nombreClase.toStdString() , cuentaAsignada.toStdString()))
    {
        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase.toStdString() , cuentaAsignada.toStdString() );
        ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        ui->descripcion->setReadOnly(true);
    }
}
