#include <iostream>
#include "P1.h"
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
	return ((t.horas * 3600) + (t.minutos * 60) + t.segundos);
}

Tiempo & segundosEnTiempo (int s){
	Tiempo t ={0};

	return t += s;
}

void calcularNuevoTiempo (Tiempo & t, int s){
	t += s;
}

void toString(Tiempo t){
	cout << t.horas << ":" << t.minutos << ":" << t.segundos << endl;
}

/*****************************************************************************/
// Main

int main(){
	Tiempo t1;
	t1.horas = 50; 
	t1.minutos = 59;
	t1.segundos = 26;

	cout << "Tiempo 1: ";
	toString(t1);

	Tiempo t2;
	t2.horas = 53; 
	t2.minutos = 0;
	t2.segundos = 30;

	cout << "Tiempo 2: ";
	toString(t2);

	///////////////////////////////////

	if (esPosterior(t1,t2)) cout << "\nEl tiempo 1 es mayor que el tiempo 2" << endl;
	else cout << "\nEl tiempo 2 es mayor o igual que el tiempo 1" << endl;

	cout << "¿Iguales? ";
	if(sonIguales(t1,t2)) cout << "Sí" << endl;
	else cout << "No" << endl;

	///////////////////////////////////

	cout << "\nSumando 7264 segundos: ";
	calcularNuevoTiempo(t1, 7264);
	Tiempo suma = segundosEnTiempo(7264);
	toString(suma);
	cout << "Nuevo tiempo 1: ";
	toString(t1);
	
	int seg = tiempoEnSegundos(t1);
	cout << "Último tiempo en segundos: " << seg << endl;

	cout << "\n¿Iguales? ";
	if(sonIguales(t1,t2)) cout << "Sí\n\n";
	else cout << "No\n\n";

	cout << "Sumando 3663 segundos: ";
	calcularNuevoTiempo(t1, 3663);
	suma = segundosEnTiempo(3663);
	toString(suma);
	cout << "Nuevo tiempo 1: ";
	toString(t1);

	///////////////////////////////////

	if (esPosterior(t1,t2)) cout << "\nEl tiempo 1 es mayor que el tiempo 2" << endl;
	else cout << "\nEl tiempo 2 es mayor o igual que el tiempo 1" << endl;

	cout << "¿Iguales? ";
	if(sonIguales(t1,t2)) cout << "Sí" << endl;
	else cout << "No" << endl;

	return 0;
}