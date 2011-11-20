#ifndef _TIEMPO_H
#define _TIEMPO_H
#include "../../ModuloContable_global.h"

class MODULOCONTABLESHARED_EXPORT Tiempo
{
public:
    Tiempo();
    Tiempo(int _hora, int _minutos);

public:
    int hora;
    int minutos;
};
#endif
