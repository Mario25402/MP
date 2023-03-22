/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 * Created on 10 de marzo de 2023
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
/*
const int FIL = 20;
const int COL = 200;


void mostrar(const char pag[][COL], int n){
    for(int i = 0; i < n; i++)
       cout << pag[i] << endl;

}

void cartel(string texto){
    cout << "\n\n********************************************* \n";
    cout << " ******* " << texto << endl;
    cout << " ********************************************* \n\n";
}

void test1(string texto){
    cartel(texto);
    char msg[MAX_SIZE] = "prueba de la funcion expande texto ";
    char aux[MAX_SIZE];
    int n = longitud(msg);
    
    // expande el texto de manera incremental, para ver la insercion de espacios
    // siempre trabaja con el texto original
    strcpy(aux, msg);
    for(int i = n; i < 50; i+=2){
        expande(aux, i);
        cout << aux << endl;
        strcpy(aux, msg);
    }
        
    
}

void lee_linea(char c[], int tamano){
    do{
        cin.getline(c, tamano);
    } while (c[0] == '\0');
}


// expande un conjunto de cadenas a la longitud máxima encontrada
void test3(string texto){
    cartel(texto);
    char m[FIL][COL];
    
    int nro = 0;
    cin >> nro;
    cin.get();

    int tam = 0; int cual = 0;
    cout << "\n **** Cadenas leidas *** " << nro << endl;
    for(int i = 0; i < nro; i++){
        //lee_linea(m[i], COL);
        cin.getline(m[i], COL);
        int aux = longitud(m[i]);
        cout << m[i] << " -> " << aux << endl;
        if ( aux > tam){
            tam = aux; 
            cual = i;
        }
    }


   for(int i = 0; i < nro; i++){
        expande(m[i],tam);
   }

   
   cout << "\n\n****** Texto justificado ****** \n\n" << endl;
   for(int i = 0; i < nro; i++)
        cout << m[i] << " \t -> " << longitud(m[i]) << endl;
   
}

int main() {
    
    
    test1("Prueba basica");
    test3("Prueba extendida");
    return (0);
}*/