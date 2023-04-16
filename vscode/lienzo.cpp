#include "lienzo.h"
#include <iostream>
using namespace std;

void reservaMemoria(Lienzo & img){
    *img.M = new char [img.nf];
    
    for (int i = 0; i < img.nf; ++i){
        img.M[i] = new char [img.nc];
    }
}

void liberaMemoria(Lienzo & img){
    for (int i = 0; i < img.nf; ++i){
        delete[] img.M[i];
    }
    
    delete []img.M;
}

void imprimir(const Lienzo & img){
    for (int i = 0; i < img.nf; ++i){
        for (int j = 0; j < img.nc; ++j){
            cout << " " << img.M[i][j];
        }
    }
    
    cout << endl;
}

void rellenar(Lienzo & img, char simbolo){
    for (int i = 0; i < img.nf; ++i){
        for (int j = 0; j < img.nc; ++j){
            img.M[i][j] = simbolo;
        }
    }
}

void redimensiona(Lienzo & img, int nuevaF, int nuevaC, char c){
    Lienzo nuevo;
    nuevo.nf = nuevaF;
    nuevo.nc = nuevaC;
    
    reservaMemoria(nuevo);
    liberaMemoria(img);
    img = nuevo;
}

void dibujaRectangulo(Lienzo & img, int x, int y, int ancho, int alto, char c){
    if (img.nf > 0 or img.M != 0){
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        for (int i = x; i < ancho or i < img.nf; ++i){
            for (int j = y; j < alto or i < img.nc; ++j){
                img.M[i][j] = c;
            }
        }
    }
}
	
void flipV(Lienzo & img){
    for (int i = 0; i < img.nf/2; ++i){
        char *aux = *(img.M+i);
        *(img.M + i) = *(img.M + (img.nf-i));
        *(img.M + (img.nf-i)) = aux;
    }
}

void flipH(Lienzo & img){
    for (int i = 0; i < img.nf/2; ++i){
        for (int j = 0; j < img.nc; ++j){
            char aux = *(img.M[i] + j);
            *(img.M[i] + j) = *(img.M[i] + (img.nc-j));
            *(img.M[i] + (img.nc-j)) = aux;
        }
    }
}

void pintaBarras(Lienzo & img, int *barras, int n, char c){
    if (img.M != 0) liberaMemoria(img);
    
    img.nf = n*4;
    img.nc = n+1;
}