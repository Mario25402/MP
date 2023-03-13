#include <iostream>
#include "registro.h"

using namespace std;

/*****************************************************************************/
// Funciones

float tiempoEnTramo (const Registro & r){
	float seg1 = tiempoEnSegundos(r.entrada);
	float seg2 = tiempoEnSegundos(r.salida);

	if (seg2 > seg1){
		float resta = seg2 - seg1;

		return resta / LIM_MIN_SEG;
	}
	
	return 0;
}

float velocidadPromedio (const Registro & r){
	float tiempo_horas = (tiempoEnTramo(r) / LIM_MIN_SEG);

	return LONG_TRAMO / tiempo_horas;
}

void corrigeRegistro (Registro & r){
	if (r.entrada.horas > r.salida.horas){
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

string toString (Registro & r){
	string salida = r.matricula + " entra: " + toString(r.entrada)
				  + " sale: " + toString(r.salida);

	return salida;
}

//////////

void extraeDatos (const ControlDiario & datos, ControlDiario & multa, ControlDiario & no_multa){
	multa.util = 0;
	no_multa.util = 0;

	for (int i = 0; i < datos.util; ++i){
		int vel = velocidadPromedio(datos.conjunto[i]);

		if (vel > VELOC_LIMITE){
			multa.conjunto[multa.util] = datos.conjunto[i];
			multa.util++;
		}

		else{
			no_multa.conjunto[no_multa.util] = datos.conjunto[i];
			no_multa.util++;
		}
	}
}