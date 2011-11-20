#include <QCompleter>
#include <QStringList>
#include <QMessageBox>
#include "ingresobienes.h"
#include "ui_ingresobienes.h"


#include "../../Persistencia/Persistencia_global.h"
#include "../../Persistencia/persistencia.h"


ingresoBienes::ingresoBienes( contabilidad::RegistroSistemaContable *regC, basico::Registro  *registroBasico, InventarioActivoFijo *_inventario, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ingresoBienes)
{
    this->setWindowFlags(Qt::Window);
    m_ui->setupUi(this);

    connect(m_ui->numeroCuenta, SIGNAL(textChanged(QString)), this, SLOT(on_numeroCuenta_editingFinished()));
    connect(m_ui->nombreClase, SIGNAL(textChanged(QString)), this, SLOT(on_nombreClase_editingFinished()));

    nuevoIngreso=true;

    this->registroContable=regC;

    this->registroCatalogo=new RegistroCatalogo(registroBasico->getUsuario(), regC);


    // CARGAR EL CATALOGO CON  EL AÑO
    //this->registroCatalogo->cargarCatalogo();


    this->regBasico=registroBasico;
    this->inventario=_inventario;

    this->valorTotal=0.0;

    Fecha *fech=new Fecha(5, 10, 2009);
    this->regEspecificos=new RegistroSistemaContable(this->regBasico);
    regEspecificos->crearPeriodoContable(*fech, *fech);
     /*Revisar*/
    regEspecificos->crearCatalogo(*fech, true, false);

    m_ui->fondoGeneral->setChecked(true);
    m_ui->finalizarTransaccion->setDisabled(true);

    m_ui->fechaAcuerdo->setDate(QDateTime::currentDateTime().date());
    m_ui->fechaAdquisicion->setDate(QDateTime::currentDateTime().date());
    m_ui->fechaFactura->setDate(QDateTime::currentDateTime().date());

    servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);

    std::map<int, string> listaSectores=servicioPersistencia->cargarSectores();
    m_ui->sectorDestino->addItem("<< Seleccionar >>", QVariant::QVariant(-1));

    for
    (
            map<int, string>::iterator it = listaSectores.begin();
            it != listaSectores.end();
                ++it
     ){
          m_ui->sectorDestino->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }

    std::map<int, string> listaProveedores=servicioPersistencia->cargarProveedores();

    for
    (
            map<int, string>::iterator it = listaProveedores.begin();
            it != listaProveedores.end();
                ++it
     ){
          m_ui->nombreProveedor->addItem(QString(it->second.c_str()), QVariant::QVariant(it->first));
    }

    QMap<int, QString> listaAnioInventa=servicioPersistencia->getInventariosFijos();



    for(QMap<int, QString>::iterator it = listaAnioInventa.begin();
        it != listaAnioInventa.end();
        ++it
    ){
            m_ui->anioInventario->setInsertPolicy(QComboBox::InsertAtTop);;
            m_ui->anioInventario->addItem(QString(it.value()), QVariant::QVariant(it.key()));

    }

        m_ui->anioInventario->setCurrentIndex(listaAnioInventa.size()-1);



        QStringList labels;
        labels << tr("Cuenta") << tr("Clase") <<tr("Especifico") <<  tr("Descripcion del Bien") << tr("Marca") <<  tr("Modelo") << tr("Serie") << tr("Fecha Adq.") << tr("Valor ($)") << tr("Sector")  << tr("idBien");
        m_ui->tablaBienes->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
        m_ui->tablaBienes->setSelectionBehavior ( QAbstractItemView::SelectRows);
        m_ui->tablaBienes->setColumnCount(11);
        m_ui->tablaBienes->setHorizontalHeaderLabels(labels);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(0, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(1, 50);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(2, 60);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(3, 260);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(4, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(5, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(6, 100);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(7, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(8, 80);        
        m_ui->tablaBienes->horizontalHeader()->resizeSection(9, 80);
        m_ui->tablaBienes->horizontalHeader()->resizeSection(10, 80);


        m_ui->tablaBienes->setColumnHidden(10, true);
        completer();
        fila=0;

}


void ingresoBienes::on_anioInventario_currentIndexChanged ( ){
    string anio=QString(m_ui->anioInventario->currentText()).toStdString() ;
    this->registroCatalogo->cargarCatalogo(this->servicioPersistencia->getIDInvFijo(anio));
    this->inventario->cargarInventario(registroCatalogo,this->regBasico->getUnidad()->id, anio);
}

ingresoBienes::~ingresoBienes()
{
    delete m_ui;
}

void ingresoBienes::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void ingresoBienes::completer(){
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
    m_ui->numeroCuenta->setCompleter(completer2);
}


void ingresoBienes::on_numeroCuenta_editingFinished (){
    m_ui->cuentaAsignada->setText(QString(  this->listaCodigosCuentas[m_ui->numeroCuenta->text().toStdString()].c_str()  ));
}



void ingresoBienes::on_nombreClase_editingFinished (){

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();

    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
    {
        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
        m_ui->descripcion->setText(QString( espec->getDescipcion().c_str()));
        m_ui->descripcion->setReadOnly(true);
        //m_ui->nombreEspecifico->setText(QString::fromStdString(espec->clase->idEspecifico->codigoCuenta)+" "+QString( espec->clase->idEspecifico->nombreCuenta.c_str() ));
        m_ui->nombreEspecifico->setReadOnly(true);

        QList<string> lista;//=QList<string>::fromStdList(espec->getMarcas());
        m_ui->marca->clear();
        for (int i = 0; i < lista.size(); ++i){
            m_ui->marca->addItem(QString(lista.at(i).c_str()), QVariant::QVariant(i));
        }
    }else{
        m_ui->descripcion->clear();
    }
}


void ingresoBienes::on_marca_currentIndexChanged (){

    string _marca=QString(m_ui->marca->currentText()).toStdString() ;
    QList<string> lista;//=QList<string>::fromStdList( this->registroCatalogo->getModelos(_marca));
    QList<QString> myQString;
    m_ui->modelo->clear();

    for (int i = 0; i < lista.size(); ++i){
         m_ui->modelo->addItem(QString(lista.at(i).c_str()), QVariant::QVariant(i));
    }
}

void ingresoBienes::limpiar(){    
    m_ui->nombreClase->clear();    
    m_ui->descripcion->clear();    
    m_ui->marca->clear();
    m_ui->modelo->clear();
    m_ui->cuentaAsignada->clear();
    m_ui->serie->clear();
    m_ui->nombreEspecifico->clear();
    m_ui->numeroCuenta->clear();    
    m_ui->valorBien->clear();
    completer();
}


/*** DEFINIENDO OPERACIONES EN TABLA */

void ingresoBienes::on_botonAgregarBien_pressed(){

    m_ui->tablaBienes->repaint();

    string nombreClase=m_ui->nombreClase->text().toStdString();
    string cuentaAsignada= m_ui->cuentaAsignada->text().toStdString();
    string numCuenta=m_ui->numeroCuenta->text().toStdString();
    string marca=m_ui->marca->currentText().toStdString();
    string modelo=m_ui->modelo->currentText().toStdString();
    string serie=m_ui->serie->text().toStdString();
    QString fechaAdqui=m_ui->fechaAdquisicion->date().toString(Qt::ISODate);
    float valor=m_ui->valorBien->value();

    if(!m_ui->cuentaAsignada->text().isEmpty() && !m_ui->nombreClase->text().isEmpty() && !m_ui->nombreEspecifico->text().isEmpty() && m_ui->valorBien->value() > 0.0 && m_ui->sectorDestino->currentIndex()!=0){

        m_ui->finalizarTransaccion->setEnabled(true);

        if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
         {
            m_ui->botonEliminarBien->setEnabled(true);
            columna=0;
            m_ui->tablaBienes->insertRow(fila);

            QTableWidgetItem *newCuenta = new QTableWidgetItem(QString(numCuenta.c_str()));            
            m_ui->tablaBienes->setItem(fila, columna, newCuenta);
            columna++;

            QTableWidgetItem *newClase = new QTableWidgetItem(QString(nombreClase.c_str()));           
            m_ui->tablaBienes->setItem(fila, columna, newClase);


            moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );

            columna++;

            QTableWidgetItem *newEspecifico = new QTableWidgetItem(m_ui->numEspecifico->text());
            m_ui->tablaBienes->setItem(fila, columna, newEspecifico);

            columna++;

            QTableWidgetItem *newDescripcion = new QTableWidgetItem(QString(espec->descripcion.c_str()));         
            m_ui->tablaBienes->setItem(fila, columna, newDescripcion);

            columna++;

            QTableWidgetItem *newMarca = new QTableWidgetItem(QString(marca.c_str()));          
            m_ui->tablaBienes->setItem(fila, columna, newMarca);

            columna++;

            QTableWidgetItem *newModelo = new QTableWidgetItem(QString(modelo.c_str()));           
            m_ui->tablaBienes->setItem(fila, columna, newModelo);

            columna++;

            QTableWidgetItem *newSerie = new QTableWidgetItem(QString(serie.c_str()));            
            m_ui->tablaBienes->setItem(fila, columna, newSerie );

            columna++;

            QTableWidgetItem *newFechaAdq = new QTableWidgetItem(fechaAdqui);           
            m_ui->tablaBienes->setItem(fila, columna, newFechaAdq );

            columna++;

            QTableWidgetItem *newValorBien= new QTableWidgetItem(QString::number(valor));           
            m_ui->tablaBienes->setItem(fila, columna, newValorBien );

            columna++;

            QTableWidgetItem *newSector= new QTableWidgetItem(m_ui->sectorDestino->currentText());
            m_ui->tablaBienes->setItem(fila, columna, newSector );

            columna++;

            QTableWidgetItem *newIDBIEN= new QTableWidgetItem("0");
            m_ui->tablaBienes->setItem(fila, columna, newIDBIEN );

            this->valorTotal=this->valorTotal+valor;
            m_ui->totalIngreso->setText(QString("$ %1").arg(this->valorTotal, 0, 'f', 2));
            fila++;

            m_ui->serie->clear();
        }
    }

}

void ingresoBienes::setTabla(int idIngreso, QList<QTableWidgetItem *> items){
    columna=0;
    fila=0;
    m_ui->tablaBienes->insertRow(fila);

    int totalFilas=(items.size()/11-1 );


    for(int i=0; i< items.size() ; ++i ){

        //m_ui->tablaBienes->setItem(fila, columna, items.at(i));

        QTableWidgetItem *newFechaAdq = new QTableWidgetItem("hola");
        m_ui->tablaBienes->setItem(fila, columna, newFechaAdq );

        columna++;

        std::cout << items.at(i)->text().toStdString() << "fila: " << fila << "columna:" <<columna <<endl;

        if(columna > 10 && fila < totalFilas){
            fila++;
            columna=0;
            m_ui->tablaBienes->insertRow(fila);           
        }
    }

    fila=m_ui->tablaBienes->rowCount();


    std::cout << "Filas de la tabla" << fila;
    for(int i=0; i<fila; i++){
        this->valorTotal=this->valorTotal+m_ui->tablaBienes->model()->index(i, 8).data(0).toFloat();
    }

    m_ui->totalIngreso->setText(QString("$ %1").arg(QString::number(valorTotal)));

    nuevoIngreso=false;
    this->idIngreso=idIngreso;

    QString SQL="SELECT `cefNo`, `facturaNo`, `fechaFactura`, `acuerdoCSU_NO`, `fechaAcuerdo`, `fuenteIngreso`, `observaciones`, `codigoIngreso`  FROM ingresobienes WHERE idIngreso="+QString::number(idIngreso);
    QSqlQuery query(QSqlDatabase::database("sibcues"));;
    query.exec(SQL);

    while(query.next()){
        m_ui->CEF->setText(query.value(0).toString());
        m_ui->noFactura->setText(query.value(1).toString());
        m_ui->fechaFactura->setDate(QDate::fromString(query.value(2).toString(), Qt::ISODate));
        m_ui->numeroAcuerdoCSU->setText(query.value(3).toString());
        m_ui->fechaAcuerdo->setDate(QDate::fromString(query.value(4).toString(), Qt::ISODate));

        if(query.value(5).toString() == "fondospropios")
            m_ui->fondosPropios->setChecked(true);

        if(query.value(5).toString() == "fondogeneral")
            m_ui->fondoGeneral->setChecked(true);

        if(query.value(5).toString() == "donado")
            m_ui->donado->setChecked(true);

        m_ui->observaciones->setText(query.value(6).toString() );
        m_ui->numeroIngreso->setText(query.value(7).toString() );
    }

    m_ui->finalizarTransaccion->setEnabled(true);
}


void ingresoBienes::on_botonEliminarBien_pressed(){

    if(m_ui->tablaBienes->currentItem()!=NULL)
    {
            int filaActual=m_ui->tablaBienes->currentRow();

            int codBien=m_ui->tablaBienes->item(filaActual, 10)->data(0).toInt();

            if(codBien!=0){
                QString SQL="DELETE FROM lineaIngresoAF WHERE lineaIngresoAF.idBien =  "+QString::number(codBien);
                QSqlQuery query(QSqlDatabase::database("sibcues"));;
                query.exec(SQL);                
                query.clear();

                SQL="DELETE FROM bienactivofijo WHERE bienactivofijo.idBien =  "+QString::number(codBien);
                query.exec(SQL);

            }

                float valor=m_ui->tablaBienes->item(filaActual, 8)->data(0).toString().toFloat();
                m_ui->tablaBienes->removeRow (filaActual);
                this->valorTotal=this->valorTotal-valor;
                m_ui->totalIngreso->setText(QString("$ %1").arg(this->valorTotal, 0, 'f', 2));
                fila--;




    }
    else
    {
        QMessageBox::information(this, tr("Eliminar Fila"),
        tr("Seleccione una fila para poder eliminar!"), QMessageBox::Ok, QMessageBox::Ok);
    }
}

void ingresoBienes::on_nuevoBien_pressed(){
    limpiar();
}

void ingresoBienes::on_finalizarTransaccion_pressed(){
    this->estadoBien="activo";
    this->estadoIngreso="finalizado";
    this->guardar();
}

void ingresoBienes::on_cancelar_pressed(){
    //servicioPersistencia->cerrarConeccion();
    //this->registroContable->~RegistroSistemaContable();
    //this->regEspecificos->~RegistroSistemaContable();
    this->close();
}

void ingresoBienes::on_btmBuscarClases_clicked()
{
     CatalogoActivoFijoGUI *catalogoAF=new CatalogoActivoFijoGUI (this->registroCatalogo, this->registroContable, this->regBasico);
     catalogoAF->show();
     catalogoAF->exec();

     if(this->registroContable->getDireccionCuenta(catalogoAF->getMadre().toStdString())!=NULL){
         m_ui->numeroCuenta->setText(QString::fromStdString(this->registroContable->getDireccionCuenta(catalogoAF->getMadre().toStdString())->getcodigoCuenta()));
         m_ui->nombreClase->setText(catalogoAF->getClase());
     }

     catalogoAF->~CatalogoActivoFijoGUI();
}

void ingresoBienes::on_btmBuscarEspecifico_clicked()
{
     Fecha *fech=new Fecha(5, 10, 2009);
     this->regEspecificos=new RegistroSistemaContable(this->regBasico);
     regEspecificos->crearPeriodoContable(*fech, *fech);
     /*Revisar*/
     regEspecificos->crearCatalogo(*fech, true, false);

     CatalogoContable *catalogoEs=new CatalogoContable(this->regEspecificos);
     catalogoEs->exec();

     m_ui->numEspecifico->setText(catalogoEs->getCodigoCuenta());
     m_ui->nombreEspecifico->setText(catalogoEs->getNombreCuenta());     

     catalogoEs->~CatalogoContable();
}

void ingresoBienes::closeEvent(QCloseEvent *event){
     //servicioPersistencia->cerrarConeccion();
     //this->registroContable->~RegistroSistemaContable();
     //this->regEspecificos->~RegistroSistemaContable();
     /*event->accept();*/
     this->close();
     //this->~ingresoBienes();
}

void ingresoBienes::on_btmMarcas_clicked()
{
    marcas *dialogoMarcas=new marcas(this->regBasico->getUnidad()->id);
    dialogoMarcas->exec();
    m_ui->marca->addItem(dialogoMarcas->getMarca(), QVariant::QVariant(dialogoMarcas->getIDMarca()));
    m_ui->modelo->addItem(dialogoMarcas->getModelo(), QVariant::QVariant(dialogoMarcas->getIDModelo()));
}

void ingresoBienes::on_btmGuardar_pressed()
{
    this->estadoIngreso="enproceso";
    this->estadoBien="enproceso";
    guardar();
}


void ingresoBienes::guardar(){

    QMessageBox msgBox;
    msgBox.setText("Ingreso de Transacciones.");
    msgBox.setInformativeText("¿Desea guardar y terminar la transaccion?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec(), codigoIngreso=0;
    bool exitoTrans=true;

    switch (ret) {
        case QMessageBox::Save:{

                QDateTime HoraFecha=QDateTime::currentDateTime();
                Fecha *_fechaTran=new Fecha(HoraFecha.date().day(), HoraFecha.date().month(), HoraFecha.date().year());

                /*Variables del bien*/
                string nombreClase, cuentaAsignada;
                float valor=0.0;
                Fecha *fechaAdquisicion;
                QString fechaAq;
                QDate fAdquisicion;

                int inventarioAF=QVariant(m_ui->anioInventario->itemData(m_ui->anioInventario->currentIndex())).toInt();


                /**Variables Generales*/
                QString facturaProveedor, noCEF, fechaFactura, noCSU, fechaCSU, proveedor;
                QString fuentedeFondos, observaciones, tipoBien, Horatran, Fechatran, serie, marca, modelo, especifico, codigoBien, codCuenta, codIngreso;

                facturaProveedor=m_ui->noFactura->text();
                noCEF=m_ui->CEF->text();
                fechaFactura=m_ui->fechaFactura->date().toString(Qt::ISODate);
                noCSU=m_ui->numeroAcuerdoCSU->text();
                fechaCSU=m_ui->fechaAcuerdo->date().toString(Qt::ISODate);
                proveedor=m_ui->nombreProveedor->currentText();
                observaciones=m_ui->observaciones->text();
                tipoBien=QString("activofijo");
                Horatran=HoraFecha.time().toString(Qt::ISODate);
                Fechatran=HoraFecha.date().toString(Qt::ISODate);
                codIngreso=m_ui->numeroIngreso->text();

                int sector=0;

                //servicioPersistencia=new Persistencia(this->regBasico->getUnidad()->id);
                std::map<int, string> listaSectores=servicioPersistencia->cargarSectores();

                //servicioPersistencia->BEGIN();
                QSqlDatabase::database("sibcues").exec("begin");


                if(m_ui->fondoGeneral->isChecked())
                    fuentedeFondos="fondogeneral";
                if(m_ui->fondosPropios->isChecked())
                    fuentedeFondos="fondospropios";
                if(m_ui->donado->isChecked())
                    fuentedeFondos="donado";

                if(this->nuevoIngreso){
                 codigoIngreso=servicioPersistencia->guardarIngresoBienes(Fechatran, proveedor, noCEF, facturaProveedor, fechaFactura, noCSU , fechaCSU, fuentedeFondos, observaciones, tipoBien, Horatran, this->estadoIngreso, codIngreso );
                }
                else{
                  servicioPersistencia->actualizarIngresoBienes(this->idIngreso, proveedor, noCEF, facturaProveedor,  fechaFactura,  noCSU , fechaCSU,  fuentedeFondos,  observaciones,  estadoIngreso, codIngreso);
                  codigoIngreso=this->idIngreso;
                }


                /**Objeto Bien*/
                Bien *bien;
                int codBien;


                for(int i=0; i< m_ui->tablaBienes->rowCount(); i++)
                {

                    for
                    (
                            map<int, string>::iterator it = listaSectores.begin();
                            it != listaSectores.end();
                            ++it
                     ){
                                    if(m_ui->tablaBienes->item(i, 9)->data(0).toString()==QString::fromStdString(it->second))
                                        sector=it->first;
                    }

                    codCuenta=m_ui->tablaBienes->item(i, 0)->data(0).toString();
                    cuentaAsignada=QString(this->listaCodigosCuentas[m_ui->tablaBienes->item(i, 0)->data(0).toString().toStdString()].c_str() ).toStdString();
                    nombreClase=m_ui->tablaBienes->item(i, 1)->data(0).toString().toStdString();

                    especifico=m_ui->tablaBienes->item(i, 2)->data(0).toString();
                    valor=m_ui->tablaBienes->item(i, 8)->data(0).toString().toFloat();
                    fechaAq=m_ui->tablaBienes->item(i, 7)->data(0).toString();
                    fAdquisicion=m_ui->tablaBienes->item(i, 7)->data(0).toDate();

                    fechaAdquisicion=new Fecha(fAdquisicion.day(), fAdquisicion.month(), fAdquisicion.year() );

                    marca=m_ui->tablaBienes->item(i, 4)->data(0).toString();
                    modelo=m_ui->tablaBienes->item(i, 5)->data(0).toString();
                    serie=m_ui->tablaBienes->item(i, 6)->data(0).toString();

                    if(this->registroCatalogo->existeClase( nombreClase , cuentaAsignada))
                    {

                        moduloinventario::EspecificacionBien *espec=this->registroCatalogo->getEspecificacion(nombreClase , cuentaAsignada );
                        if(m_ui->tablaBienes->item(i, 10)->data(0).toInt()==0)
                            bien=this->inventario->crearBien(espec, valor, fechaAdquisicion, 1, true);
                        else
                            bien=this->inventario->crearBien(espec, valor, fechaAdquisicion, 1, false);

                        bien->setSerie(serie.toStdString());
                        bien->estadoBien=1;
                        bien->setSector(sector);

                        if(m_ui->tablaBienes->item(i, 10)->data(0).toInt()==0){
                            QList<QString> listaCorrelativos=servicioPersistencia->getListaCorelativosDisponiblesAF(espec->oid_especbien);
                            bien->correlativo=listaCorrelativos.takeFirst().toStdString();
                        }

                        QString codigUnidad=QString::fromStdString(this->regBasico->getUnidad()->codigoP1())+QString::fromStdString(this->regBasico->getUnidad()->codigoP2());
                        codigoBien=codCuenta+"-"+codigUnidad+"-"+QString::fromStdString(nombreClase)+"-"+QString::fromStdString(bien->correlativo)+"-"+especifico;

                        if(m_ui->tablaBienes->item(i, 10)->data(0).toInt()==0){
                            codBien=servicioPersistencia->guardarBien(espec, QString(bien->correlativo.c_str()), serie, valor, fechaAq, sector, modelo, marca, especifico, codigoBien, this->estadoBien, inventarioAF);
                            if(exitoTrans)
                                exitoTrans=servicioPersistencia->crearlineaIngresoAF(codBien, codigoIngreso );
                        }
                        else{
                            codBien=m_ui->tablaBienes->item(i, 10)->data(0).toInt();
                            servicioPersistencia->actualizarBien(codBien, espec, serie, valor, fechaAq, sector, modelo, marca, especifico, this->estadoBien);
                            if(exitoTrans)
                                exitoTrans=servicioPersistencia->crearlineaIngresoAF(codBien, codigoIngreso );
                        }
                        bien->oid=codBien;
                        bien->idModelo=servicioPersistencia->oidModelo(modelo);
                   }
                }

                if(exitoTrans){

                    QSqlDatabase::database("sibcues").commit();
                    QMessageBox msgBox;
                    msgBox.information(0,"Captura de Datos","    Ingresado con exito!.   ");

                    for(int i=m_ui->tablaBienes->rowCount() -1; i>=0; i--)
                    {
                        this->m_ui->tablaBienes->removeRow(i);
                    }
                    this->fila=0;
                    this->m_ui->finalizarTransaccion->setDisabled(true);
                    this->m_ui->btmGuardar->setDisabled(true);

                       servicioPersistencia->crearConexion();

                       NCReport *report = new NCReport();
                       report->reset(true);
                       report->setReportSource( NCReportSource::File  );
                       report->setReportFile("Reportes/ingresoBienesAF.xml");

                       report->addParameter( "idIngreso", QVariant(codigoIngreso) );

                       report->runReportToPreview();
                       QString error=report->lastErrorMsg();
                       std::cout<< error.toStdString();

                       if ( !report->hasError() ) {
                         NCReportPreviewWindow *pv = new NCReportPreviewWindow();
                         pv->setOutput( (NCReportPreviewOutput*)report->output() );
                         pv->setWindowModality( Qt::ApplicationModal );
                         //pv->setAttribute( Qt::WA_DeleteOnClose );
                         pv->show();
                       }
                 }

            }
            break;

      case QMessageBox::Cancel:{
                  QMessageBox msgBox;
                  msgBox.setText("    Puede continuar ingresando transacciones   ");
                  msgBox.exec();
            }
            break;
       default:
            break;
    }

}



