#include <iostream>
#include <cstdlib>
using namespace std;

void mostrar(int *v, int k){
    for (int i = 0; i < k; i++)
        cout << v[i] << ", ";
    cout << endl;
}

void rellenar(int *v, int k, int min, int max){
    for (int i = 0; i < k; i++)
        v[i] = (random() % (max - min)) + min;
}

int main(){
    const int N = 10;
    int datos[N];
    int min, max;

    srand(time(0));
    rellenar(datos, N, min, max);


    // Alterna entre un número positivo y otro negativo
    int signo = 1;
    for (int i = 0; i < N; i++){
        datos[i] = i * signo;
        signo *= -1;
    }

    mostrar(datos, N);

    int *p = &datos[2];
    mostrar(p,5);

    int *p1, *p2;
    p1 = &datos[3]; // Direccion del elemento 3
    p2 = &datos[8]; // Direccion del elemento 8
    cout << "Salida 1: " << p2 - p1 << endl;    // 8-3=5

    p1 = &datos[0]; // Direccion del elemento 0
    cout << "Salida 2: " << p2 - p1 << endl;    // 8-0=0

    p1 = datos; // Apunta al primer elemento
    cout << "Salida 1: " << p2 - p1 << endl; // 8-0=0

    p1 = &datos[5]; // Direccion del elemento 5
    cout << "Salida 1: " << *p2 << " - " << *p1 // 8 - (-5) = 13
         << " = " << *p2 - *p1 << endl;
}