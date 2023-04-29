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
    
    img.nc = n*4;
    img.nf = 0;

    for (int i = 0; i < n; ++i)
        if (barras[i] > img.nf) img.nf = barras[i];

    img.nf += 1;

    reservaMemoria(img);
    rellenar(img, '.');

    for (int i = 0, j = 0; i < img.nc, j < n; i+=4, ++j)
            dibujaRectangulo(img, 0, i+1, 2, barras[j], c);

    flipV(img);
}

void rotar(Lienzo & img){
    Lienzo tmp;
    tmp.nf = img.nc;
    tmp.nc = img.nf;

    reservaMemoria(tmp);

    for (int i = 0; i < img.nf; i++) {
        for (int j = 0; j < img.nc; j++) {
            tmp.M[j][tmp.nc - i - 1] = img.M[i][j];
        }
    }

    liberaMemoria(img);
    img = tmp;
}

bool sonIguales(const Lienzo & L1, const Lienzo & L2){
    bool iguales = false;

    if (L1.nf == L2.nf and L1.nc == L2.nc){
        iguales = true;

        for (int i = 0; i < L1.nf; ++i){
            for (int j = 0; j < L1.nc and iguales; ++j){
                if (L1.M[i][j] != L2.M[i][j]) iguales = false;
            }
        }
    }

    return iguales;
}

/*

El código para analizar o la función de prueba 6, dara error de ejecución
al intentar imprimir la matriz de img2, por que cuando hicimos img2 = img1, 
lo que realmente paso es que el objeto img2 pasó a apuntar al objeto img1,
y por tanto, al liberar la memoria de img1 no podremos acceder mediante img2.

*/