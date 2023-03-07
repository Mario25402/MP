#include <iostream>
#include "tiempo.h"
#include "registro.h"

using namespace std;

/*****************************************************************************/
// Main

int main(){
	Tiempo t1;
	t1.horas = 34; 
	t1.minutos = 59;
	t1.segundos = 26;

	cout << "Tiempo 1: " << toString(t1) << endl;

	Tiempo t2;
	t2.horas = 13; 
	t2.minutos = 0;
	t2.segundos = 30;

	cout << "Tiempo 2: " << toString(t2);

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
	cout << toString(suma) << endl;
	cout << "Nuevo tiempo 1: " << toString(t1) << endl;
	
	int seg = tiempoEnSegundos(t1);
	cout << "Último tiempo en segundos: " << seg << endl;

	cout << "\n¿Iguales? ";
	if(sonIguales(t1,t2)) cout << "Sí\n\n";
	else cout << "No\n\n";

	cout << "Sumando 3663 segundos: ";
	calcularNuevoTiempo(t1, 3663);
	suma = segundosEnTiempo(3663);
	cout << toString(suma) << endl;
	cout << "Nuevo tiempo 1: " << toString(t1);

	///////////////////////////////////

	if (esPosterior(t1,t2)) cout << "\nEl tiempo 1 es mayor que el tiempo 2" << endl;
	else cout << "\nEl tiempo 2 es mayor o igual que el tiempo 1" << endl;

	cout << "¿Iguales? ";
	if(sonIguales(t1,t2)) cout << "Sí" << endl;
	else cout << "No" << endl;

	///////////////////////////////////

	cout << "\n/************************************************/\n" << endl;

	///////////////////////////////////

	ControlDiario c;

	int num_coches; 
	cin >> num_coches;

	c.util = num_coches;
	Registro r[num_coches];

	for (int i = 0; i < num_coches; ++i){
		int tiempo;
		string matricula;

		cin >> tiempo;
		r[i].entrada = segundosEnTiempo(tiempo);

		cin >> tiempo;
		r[i].salida = segundosEnTiempo(tiempo);

		cin >> matricula;
		r[i].matricula = matricula;

		corrigeRegistro(r[i]);
		c.conjunto[i] = r[i];
	}

	///////////////////////////////////

	cout << "Datos coche nº4: " << toString(r[7]) << endl
		 << "Tiempo en tramo: " << tiempoEnTramo(r[7]) << " minutos" << endl;

	///////////////////////////////////

	int util_multa, util_no_multa;
	Registro multa[util_multa];
	Registro no_multa[util_no_multa];

	///////////////////////////////////

	extraeDatos(c, multa, no_multa, util_multa, util_no_multa);

	for (int i = 0; i < util_multa; i++){
		cout << "\nMultado: " << controlVehiculo(multa[i]) << endl;
	}

	cout << endl;

	for (int i = 0; i < util_no_multa; i++){
		cout << "No multado: " << controlVehiculo(no_multa[i]) << endl;
	}

	return 0;
}
