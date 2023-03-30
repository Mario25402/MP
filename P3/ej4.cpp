#include <iostream>
#include <cstdlib>
using namespace std;

void ordena (int *v, int longitud){
    int *ini = v;
    int *fin = v+longitud-1;

    int i = 0;
    int j = 0;

    while ((i < longitud) and (j < longitud) and (ini+i <= fin-j)){
        while (*(ini+i) <= v[0] and i < longitud) i++;
        while (*(fin-j) >= v[0] and j < longitud) j++;

        if (ini+i <= fin-j){
            int aux = *(ini+i);
            *(ini+i) = *(fin-j);
            *(fin-j) = aux;
        }
    }
}

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
    const int N = 20;
    int datos[N];

    srand(time(0));
    rellenar(datos, N, -10, 10);

    datos[0] = 0;
    cout << "E: ";
    mostrar(datos, N);

    ordena(datos, N);
    cout << "S: ";
    mostrar(datos, N);
}