#include "./include/PoliReg.h"
#include "./include/Punto2D.h"
#include <iostream>
#include <random>
using namespace std;

int getAleatorio(int min, int max){
    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

void ordenar(){
    PoliReg *v = new PoliReg[10];

    for (int i = 0; i < 10; ++i){
        int lados = getAleatorio(5,10);
        int coordX = getAleatorio(0, 20);
        int coordY = getAleatorio(0, 20);
        int radio = getAleatorio(20, 150);

        Punto2D centro(coordX, coordY);

        PoliReg aux (lados, centro, radio);
        v[i] = aux;
    }

    cout << "Sin Ordenar: " << endl;
    for (int i = 0; i < 10; ++i)
        cout << v[i] << endl;

    //////////

    for (int i = 0; i < 10; ++i){
        for (int j = 1; i < 10 - i; ++j){
            if (v[j] < v[j-1]){
                PoliReg tmp = v[j];
                v[j] = v[j-1];
                v[j-1] = tmp;
            }
        }
    }

    cout << "Ordenados: " << endl;
    for (int i = 0; i < 10; ++i)
        cout << v[i] << endl;
}

int main(){
    ordenar();
}