/*
NOMBRE Y APELLIDOS: MARIO PIÑA MUNERA
DNI: 26536550R
GRUPO DE PRÁCTICAS: MIÉRCOLES
*/

/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 10 de marzo de 2023,
 */

#include <iostream>
#include "palabras.h"
#include <cstring>
using namespace std;



void testBasico(const char frase[]) {
    cout << "\nLA FRASE LEIDA ES: " << frase << endl;
    int n = longitud(frase);
    int pals = cuentaPalabras(frase);
    cout << "Tiene " << n << " caracteres y " << pals << " palabras " << endl;

}

void testPalabras(const char frase[]) {
    char palabra[MAX_SIZE];

    cout << "\nDESCOMPOSICION EN PALABRAS nro -> palabra (long.)" << endl;
    int nro = 1;
    extraePalabra(frase, nro, palabra);
    while (longitud(palabra) > 0) {
        cout << nro << " -> " << palabra << " (" << longitud(palabra) << ")\n";
        nro++;
        extraePalabra(frase, nro, palabra);
    }


}

void testInvierte(const char frase[]) {

    char reves[MAX_SIZE];
    cout << "\nFRASE INVERSA " << endl;
    delReves(frase, reves);
    cout << "Frase Original: " << frase;
    cout << "\nFrase al Reves: " << reves << endl;
}


int main() {

    char frase[MAX_SIZE];

    cin.getline(frase, MAX_SIZE);
    testBasico(frase);
    testPalabras(frase);
    testInvierte(frase);

    return (0);
}