#include "../headers/Fecha.h"
#include <iostream>

Fecha::Fecha()
{
}

Fecha::Fecha(int _dia, int _mes, int _anio)
{

    this->dia=_dia;
    this->mes=_mes;
    this->anio=_anio;
}

int Fecha::getMes()
{
    return this->mes;
}

void Fecha::setMes(int _mes)
{
    this->mes=_mes;
}

int Fecha::getDia()
{
    return this->dia;
}

void Fecha::setDia(int _dia)
{
    this->dia=_dia;
}

int Fecha::getAnio()
{
    return this->anio;
}

void Fecha::setAnio(int _anio)
{
    this->anio=_anio;
}

void Fecha::imprimirFecha()
{
    std::cout << this->dia << "/" << this->mes << "/" << this->anio << std::endl;
}


