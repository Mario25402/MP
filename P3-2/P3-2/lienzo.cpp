#include "lienzo.h"
#include <iostream>
using namespace std;

void reservaMemoria(Lienzo & img){
    img.M = new char *[img.nf];
    
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

        cout << endl;
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
    rellenar (nuevo, c);
    liberaMemoria(img);
    img = nuevo;
}

void dibujaRectangulo(Lienzo & img, int x, int y, int ancho, int alto, char c){
    if (img.nf > 0 and img.M != 0){
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        for (int i = x; i < img.nf and i < x+alto; ++i){
            for (int j = y; j < img.nc and j < y+ancho; ++j){
                img.M[i][j] = c;
            }
        }
    }
}
	
void flipV(Lienzo & img){
    for (int i = 0; i < img.nf/2 ; ++i){
        char *ini = *((img.M) + i);
        char *fin = *(img.M + (img.nf-i-1));
        
        *(img.M + (img.nf-i-1)) = ini;
        *(img.M + i) = fin;
    }
}

void flipH(Lienzo & img){
    for (int i = 0; i < img.nf; ++i){
        for (int j = 0; j < img.nc/2; ++j){
            char ini = *(img.M[i] + j);
            char fin = *(img.M[i] +(img.nc-j-1));

            *(img.M[i] + (img.nc-j-1)) = ini;
            *(img.M[i] + j) = fin;
        }
    }
}

void pintaBarras(Lienzo & img, int *barras, int n, char c){
    if (img.M != 0) liberaMemoria(img);
    
    img.nf = n*4;
    img.nc = n+1;
}