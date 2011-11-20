#include <QtGui/QApplication>
#include "variacionpresupuestaria.h"
#include "crearvariacion.h"
#include "presupuestoaprobado.h"
#include "verdocumentovariacion.h"
#include "razonamiento.h"
#include "conex.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    crearConexion();

    VariacionPresupuestaria w;
    w.show();
    return a.exec();
}
