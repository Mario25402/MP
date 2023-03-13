#include <iostream>
#include "tiempo.h"

using namespace std;

/*****************************************************************************/
// Funciones

void corrigeValor (Tiempo & t){
	if (t.horas >= 0 and t.minutos >= 0 and t.segundos >= 0){
		if (t.segundos >= LIM_MIN_SEG){
			t.minutos += (t.segundos / LIM_MIN_SEG);
			t.segundos %= LIM_MIN_SEG;
		}

		if (t.minutos >= LIM_MIN_SEG){
			t.horas += (t.minutos / LIM_MIN_SEG);
			t.minutos %= LIM_MIN_SEG;
		}

		if (t.horas >= LIM_HOR) t.horas %= LIM_HOR;
	}

	else{
		t.horas = 0;
		t.minutos = 0;
		t.segundos = 0;
	}
}

bool esPosterior (const Tiempo & t1, const Tiempo & t2){
		bool mayor = false;

		if (t1.horas > t2.horas) mayor = true;

		else if (t1.horas == t2.horas){
			if (t1.minutos > t2.minutos) mayor = true;

			else if (t1.minutos == t2.minutos){
				if (t1.segundos > t2.segundos) mayor = true;
			}
		}

		if (t1.horas == t2.horas and t1.minutos == t2.minutos
			                  	 and t1.segundos == t1.segundos) mayor = false;

		return mayor;
}

bool sonIguales (const Tiempo & t1, const Tiempo & t2){
		bool iguales = false;

		if ((t1.horas == t2.horas) and (t1.minutos == t2.minutos) and (t1.segundos == t2.segundos))
			iguales = true;

		return iguales;
}

int tiempoEnSegundos (const Tiempo & t){
	return ((t.horas * H_TO_S) + (t.minutos * LIM_MIN_SEG) + t.segundos);
}

Tiempo & segundosEnTiempo (const int s){
	Tiempo t = {0};

	return t += s;
}

void calcularNuevoTiempo (Tiempo & t, const int s){
	t += s;
}

string toString (Tiempo & t){
	string salida;

	salida = to_string(t.horas) + ':' + to_string(t.minutos)
   		   + ':' + to_string(t.segundos);

	return salida;
}

float tiempoEnMinutos (const Tiempo & t){
	return ((t.horas * LIM_MIN_SEG) + t.minutos + (t.segundos/LIM_MIN_SEG));
}