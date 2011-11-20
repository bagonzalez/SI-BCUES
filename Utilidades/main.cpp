#include <QtGui/QApplication>
#include "clasesdecvs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clasesdecvs w;
    w.show();
    return a.exec();
}
