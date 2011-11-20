#ifndef CONEX_H
#define CONEX_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QtGui/QMessageBox>

bool crearConexion()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("sibcues_a");
        db.setUserName("root");
        db.setPassword("");
        db.setPort(3306);
        if (!db.open()) {
                QMessageBox::critical(0, qApp->tr("No se puede Conectar a la Base de Datos"),qApp->tr("No se establecio la conexion.\n"	"Click para salir."), QMessageBox::Cancel);
                return false;
        }
        return true;


}	
#endif

