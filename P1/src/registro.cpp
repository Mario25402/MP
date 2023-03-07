#include <iostream>
#include "registro.h"

using namespace std;

/*****************************************************************************/
// Funciones

float tiempoEnTramo (Registro r){
	r.entrada - r.salida;

	return tiempoEnMinutos(r.entrada);
}

float velocidadPromedio (const Registro & r){
	float tiempo = (tiempoEnTramo(r) / 60);

	return (LONG_TRAMO / tiempo);
}

void corrigeRegistro (Registro & r){
	if (r.entrada > r.salida){
		Tiempo aux = r.entrada;
		r.entrada = r.salida;
		r.salida = aux;
	}
}

string controlVehiculo (const Registro & r){
	float vel = velocidadPromedio(r);

	string salida = "Vehículo matricula " + r.matricula +
				    ", velocidad promedio " + to_string(vel) + " km/h";

	if (vel > VELOC_LIMITE) salida += ". MULTA";

	return salida;
}

string toString (Registro r){
	string salida = r.matricula + " entra: " + toString(r.entrada)
				  + " sale: " + toString(r.salida);

	return salida;
}

//////////

void extraeDatos (const ControlDiario & c, Registro excedido[], Registro correcto[],
				 int & util_excedido, int & util_correcto){
	util_excedido = 0;
	util_correcto = 0;

	for (int i = 0; i < c.util; ++i){
		int vel = velocidadPromedio(c.conjunto[i]);

		if (vel > VELOC_LIMITE){
			excedido[util_excedido] = c.conjunto[i];
			util_excedido++;
		}

		else{
			correcto[util_correcto] = c.conjunto[i];
			util_correcto++;
		}
	}
}