#include <iostream>
#include <cstdlib>
using namespace std;

void burbuja(int **v, int util){
    for (int i = 0; i < util-1; i++) {
        for (int j = i+1; j < util; j++) {
            if (*v[i] > *v[j]) {
                int* tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            } // if
        } // for
    } // for
} // funcion

void ordena (int *v, int util, int **salida){
    for (int i = 0; i < util; i++) salida[i] = &v[i];
    burbuja(salida, util);
}

void mostrar(int *v, int k){
    for (int i = 0; i < k; i++)
        cout << v[i] << ", ";
    cout << endl;
}

void mostrar_ptr(int **ptr, int util){
    for (int i = 0; i < util; i++){
        cout << *ptr[i] << ", ";
    }

    cout << endl;
}

void rellenar(int *v, int k, int min, int max){
    for (int i = 0; i < k; i++)
        v[i] = (random() % (max - min)) + min;
}

int main(){
    const int MAX = 12;
    int vec[MAX];
    int *ptr[MAX];

    srand(time(0));
    rellenar(vec, MAX, 0, 20);

    cout << "E: ";
    mostrar(vec, MAX);

    ordena(vec, MAX, ptr);
    cout << "S: ";
    mostrar_ptr(ptr, MAX);
}