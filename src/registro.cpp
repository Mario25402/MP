#include <iostream>
#include "registro.h"

using namespace std;

/*****************************************************************************/
// Funciones

float tiempoEnTramo (const Registro & r){
	if (r.salida.horas > r.entrada.horas and
		r.salida.minutos > r.entrada.minutos and
		r.salida.segundos > r.entrada.segundos){


		int seg1 = tiempoEnSegundos(r.entrada); //((r.entrada.horas * H_TO_S) + (r.entrada.minutos * LIM_MIN_SEG) + r.entrada.segundos);
		int seg2 = tiempoEnSegundos(r.salida); //((t.horas * H_TO_S) + (t.minutos * LIM_MIN_SEG) + t.segundos);

		seg2 -= seg1;

		Tiempo aux = segundosEnTiempo(seg2);
		return tiempoEnMinutos(aux);
	}
}

float velocidadPromedio (const Registro & r){
	float tiempo_horas = (tiempoEnTramo(r) / LIM_HOR);

	return (LONG_TRAMO / tiempo_horas);
}

void corrigeRegistro (Registro & r){
	if (r.salida.horas > r.entrada.horas and
	r.salida.minutos > r.entrada.minutos and
	r.salida.segundos > r.entrada.segundos){

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

string toString (const Registro & r){
	string salida = r.matricula + " entra: " + toString(r.entrada)
				  + " sale: " + toString(r.salida);

	return salida;
}

//////////

void extraeDatos (const ControlDiario & datos, ControlDiario & multa, ControlDiario & no_multa){
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