#include "accesousuario.h"
#include "ui_accesousuario.h"

AccesoUsuario::AccesoUsuario(basico::Registro *registroBasico, QMainWindow *ventanaprin, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::AccesoUsuario)
{
    m_ui->setupUi(this);    
    this->aceptado=false;    
    this->registroBasico=registroBasico;
    this->ventana=ventanaprin;
}

AccesoUsuario::~AccesoUsuario()
{
    delete m_ui;
}

bool AccesoUsuario::getAceptado(){
    return this->aceptado;
}

void AccesoUsuario::on_boton_accepted(){
    this->login= m_ui->login->text().toStdString();
    this->password= m_ui->password->text().toStdString();

    if(this->registroBasico->logear(this->login, this->password)){
        m_ui->login->clear();
        m_ui->password->clear();
        aceptado=true;        
        this->close();
        this->ventana->setWindowTitle(QString("Sistema de Inventario -")+QString(this->registroBasico->getNombreUnidad().c_str())+QString("- Bienvenido/a ")+
                                      QString(this->registroBasico->getNombre().c_str())+QString(" ")+
                                      QString(this->registroBasico->getApellido().c_str()));
    }
    else{        
        m_ui->login->clear();
        m_ui->password->clear();        
    }
}

void AccesoUsuario::on_boton_rejected (){    
    m_ui->login->clear();
    m_ui->password->clear();
    this->close();
    //this->parentWidget()->close();
}

void AccesoUsuario::changeEvent(QEvent *e)
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
