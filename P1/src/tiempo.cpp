#include <iostream>
#include "tiempo.h"

using namespace std;

/*****************************************************************************/
// Funciones

void corrigeValor (Tiempo & t){
	if (t.horas >= 0 and t.minutos >= 0 and t.segundos >= 0){
		if (t.segundos >= LIM_MIN_SEG){
			t.segundos %= LIM_MIN_SEG;
			t.minutos += t.minutos / LIM_MIN_SEG;
		}

		if (t.minutos >= LIM_MIN_SEG){
			t.minutos %= LIM_MIN_SEG;
			t.horas += t.minutos / LIM_MIN_SEG;
		}

		if (t.horas >= LIM_HOR) t.horas %= LIM_HOR;
	}

	else{
		t.horas = 0;
		t.minutos = 0;
		t.segundos = 0;
	}
}

bool esPosterior (Tiempo & t1, Tiempo & t2){
	corrigeValor(t1);
	corrigeValor(t2);

	return t1 > t2;
}

bool sonIguales (Tiempo & t1, Tiempo & t2){
	corrigeValor(t1);
	corrigeValor(t2);

	return t1 == t2;
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

	corrigeValor(t);
	salida = to_string(t.horas) + ':' + to_string(t.minutos)
   		   + ':' + to_string(t.segundos);

	return salida;
}

float tiempoEnMinutos (const Tiempo & t){
	return ((t.horas * LIM_MIN_SEG) + t.minutos + (t.segundos/LIM_MIN_SEG));
}