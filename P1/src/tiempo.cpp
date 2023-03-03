#include <iostream>
#include "tiempo.h"

using namespace std;

/*****************************************************************************/
// Funciones

bool esPosterior (Tiempo t1, Tiempo t2){
	return t1 > t2;
}

bool sonIguales (Tiempo t1, Tiempo t2){
	return t1 == t2;
}

int tiempoEnSegundos (Tiempo t){
	return ((t.horas * H_TO_S) + (t.minutos * LIM_MIN_SEG) + t.segundos);
}

Tiempo & segundosEnTiempo (int s){
	Tiempo t = {0};

	return t += s;
}

void calcularNuevoTiempo (Tiempo & t, int s){
	t += s;
}

string toString (Tiempo t){
	string salida;

	if (t.horas < 0 or t.minutos < 0 or t.segundos < 0){
		salida = "##:##:##";
	}

	else{
		if (t.horas >= LIM_HOR) t.horas %= LIM_HOR;

		salida = to_string(t.horas) + ':' + to_string(t.minutos)
	   		   + ':' + to_string(t.segundos);
	}

	return salida;
}

float tiempoEnMinutos (Tiempo t){
	return ((t.horas * LIM_MIN_SEG) + t.minutos + (t.segundos/LIM_MIN_SEG));
}