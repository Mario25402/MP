#ifndef REGISTRO_H
#define REGISTRO_H

#include "tiempo.h"

/*****************************************************************************/
// Variables Globales

const float LONG_TRAMO = 17.45;
const int VELOC_LIMITE = 90;
const int MAX = 100;

/*****************************************************************************/
// Estructuras

struct Registro
{
	Tiempo entrada;
	Tiempo salida;
	std::string matricula;
};

//////////

struct ControlDiario{
	Registro conjunto[MAX];
	int util;
};

/*****************************************************************************/
// Cabeceras

float tiempoEnTramo (const Registro & r);
float velocidadPromedio (const Registro & r);
void corrigeRegistro (Registro & r);
std::string controlVehiculo (const Registro & r);
std::string toString (Registro & r);

//////////

void extraeDatos (const ControlDiario & datos, ControlDiario & multa, ControlDiario & no_multa);

#endif