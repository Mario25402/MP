#include <iostream>
using namespace std;

const int EXTRA = 3;
const int N = 100;

void compruebaMemoria(int* &vec, const int actual, int &tam) {
    if (actual == tam) {

        if (tam + actual > EXTRA) {
            tam = actual + EXTRA - ((actual + EXTRA) - N);
        }
        else if (tam == actual){
            tam = actual + EXTRA;
        }

        int *vec_ampliado = new int[tam];

        for (int i = 0; i < actual; ++i) vec_ampliado[i] = vec[i];
        delete[]vec;

        vec = vec_ampliado;
    }
}

void rellenaSucesion(int* &vec, int &actual, int &tam) {
    compruebaMemoria(vec, actual, tam);
    *(vec + actual) = *(vec + actual - 1) + *(vec + actual - 2);
    actual++;
}

void salida(int *vec, int tam) {
    cout << "Sucesión: ";

    int i = 0;
    for (i; i < tam; ++i) {
        cout << *(vec + i) << " ";
    }

    cout << "\nRecuento: " << i << endl;
}

void liberaMemoria (int* &vec){
    delete []vec;
}

int main() {
    int n = 2;
    int total = n;
    int *v = new int[2];

    v[0] = 0;
    v[1] = 1;

    while (n < N) rellenaSucesion(v, n, total);
    salida(v, n);
    liberaMemoria(v);

    return 0;
}

