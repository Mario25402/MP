/*
 
 * FICHERO: lienzo.h
 * Autor: David A. Pelta
 * para guión de prácticas de Metodología de la Programación
 * Curso: 2022 - 2023
 
 */

#ifndef LIENZO_H
#define LIENZO_H

struct Lienzo{
    char **M = 0;
    int nf = 0, nc = 0;
};



/**
 * @brief reserva memoria para el lienzo. Requiere que img.nf, img.nc sean válidos 
 * @param img el lienzo donde crearemos la matriz.
  */
void reservaMemoria(Lienzo & img);


/**
 * @brief libera la memoria del lienzo. Requiere que img.nf, img.nc sean válidos 
 * @param img el lienzo que contiene la memoria a liberar.
  */
void liberaMemoria(Lienzo & img);


/**
 * @brief muestra por pantalla el contenido del lienzo
 * @param img el lienzo a imprimir.
  */
void imprimir(const Lienzo & img);


/**
 * @brief rellena el lienzo con un valor
 * @param img el lienzo.
 * @param simbolo es el carácter de relleno
  */
void rellenar(Lienzo & img, char simbolo);


/**
 * @brief redimensiona el lienzo, solamente si la nueva dimension es 
 * mayor que la actual. En otro caso, no hace nada.
 * @param img el lienzo.
 * @param nuevaF, nuevaC  nuevos valores para filas y columnas
 * @param c es el carácter de relleno para las nuevas posiciones
  */
void redimensiona(Lienzo & img, int nuevaF, int nuevaC, char c);


/**
 * @brief "dibuja" un rectángulo en el lienzo. Supone que el lienzo esta 
 * inicializado correctamente. El origen de coordenadas (0,0) se corresponde 
 * con el extremo superior izquierdo del lienzo. 
 * @param img el lienzo.
 * @param x,y  coordenadas del vértice superior izquierdo del rectángulo. 
 * Si alguno de los valores es negativo, se pone a cero
 * @param ancho, alto las dimensiones del rectángulo. Si el rectángulo "se sale" del lienzo, 
 * debe ignorar las posiciones inválidas.
 * @param simbolo es el carácter de relleno
  */
void dibujaRectangulo(Lienzo & img, int x, int y, int ancho, int alto, char c);
    

/**
 * @brief voltea la imagen en el eje arriba/abajo. El resultado se almacena en la misma variable
 * @param img el lienzo 
  */
void flipV(Lienzo & img);

/**
 * @brief voltea la imagen en el eje izq/derecha. El resultado se almacena en la misma variable
 * @param img el lienzo 
  */
void flipH(Lienzo & img);


/**
 * @brief crea un gráfico de barras en un lienzo. Debe reservar la memoria necesaria 
 * y dibujar las barras utilizando la función dibujaRectangulo
 * 
 * @param img el lienzo 
 * @param barras un array de valores enteros
 * @param n el tamaño del array
 * @param c el simbolo para "pintar" las barras
  */

void pintaBarras(Lienzo & img, int *barras, int n, char c);

/**
 * @brief rota el lienzo 90º en sentido horario
 *        cuidado si el lienzo no es cuadrado!!
 * @param img es el lienzo a rotar
 */

void rotar(Lienzo & img);

/**
 * @brief comprueba si dos lienzos son iguales
 * devuelve true si tienen las mismas dimensiones
 * y coinciden todos los elementos. 
 * @param L1, L2 son los datos de tipo Lienzo a comparar
 */
bool sonIguales(const Lienzo & L1, const Lienzo & L2);

#endif

/*****************************************************************************/

/*
 
 * FICHERO: main.cpp
 * Autor: David A. Pelta
 * para guión de prácticas de Metodología de la Programación
 * Curso: 2022 - 2023
 
 */

#include <iostream>
#include "lienzo.h"
#include <cassert>

using namespace std;

void test1(); // pintaBarras
void test2(bool print); // flips
void test3(bool print); // rotar


// funcion auxiliar solo para main

void crearMatriz(Lienzo & img, char c);

int main(int argc, char* argv[]) {

    if (argc < 2){
        cout << "Uso: prueba <nro test> <print> " << endl;
        cout << "nro test: {1,2,3}" << endl;
        cout << "print: {0,1} solo se tiene en cuenta si nro test > 1" << endl;
        exit(-1);
    }
    
    int print = 0;
    int opcion = 3;//atoi(argv[1]);
    /*if ((opcion > 1)&& (argc > 2))
        print = atoi(argv[2]);*/
    
    print = 0;

    switch (opcion){
        case 1: {test1(); break;}
        case 2: {test2(print); break;}
        case 3: {test3(print); break;}
    }
    
    return 0;
}


void crearMatriz(Lienzo & img, char c){
 reservaMemoria(img);
 rellenar(img, '.');
}


void test1(){
    cout << "Grafico de Barras " << endl;
    int MAX = 7;
    int v[MAX] = {1,2,3,4,3,2,1};
    Lienzo G;
    for(int i = 1; i <= MAX; i++){
        pintaBarras(G, v, i, 'x');
        imprimir(G);
    }
    liberaMemoria(G);   
}


void test3(bool print){
    cout << " ROTACION " << endl;
    Lienzo imgBase, img;
    imgBase.nc = 6;
    imgBase.nf = 5;
    
    img.nc = 6;
    img.nf = 5;
    
    crearMatriz(imgBase, '.');
    dibujaRectangulo(imgBase, 2,0, 6, 1, ')');
    dibujaRectangulo(imgBase, 1,5,1,3, ')');

    crearMatriz(img, '.');
    dibujaRectangulo(img, 2,0, 6, 1, ')');
    dibujaRectangulo(img, 1,5,1,3, ')');
    
    if (print){
        imprimir(imgBase);
        imprimir(img);
    }
    
    assert(sonIguales(imgBase, img) && " fallo 1");
    
    rotar(img);
    if (print)
         imprimir(img);
    
    assert(!sonIguales(imgBase, img) && " fallo 2");
    
    rotar(img);
    if (print)
       imprimir(img);

    assert(!sonIguales(imgBase, img)  && " fallo 3");
    
    rotar(img);
    if (print)
         imprimir(img);
    rotar(img);
    if (print)
         imprimir(img);

    assert(sonIguales(imgBase, img)  && " fallo 4");
    
    
    liberaMemoria(imgBase);
    liberaMemoria(img);
            
}


void test2(bool print){
    cout << "  Test FLIPs " << endl;
    Lienzo imgBase, img;
    imgBase.nc = 6;
    imgBase.nf = 5;
    
    img.nc = 6;
    img.nf = 5;
    
    crearMatriz(imgBase, '.');
    dibujaRectangulo(imgBase, 2,0, 4, 4, ')');

    crearMatriz(img, '.');
    dibujaRectangulo(img, 2,0, 4, 4, ')');
    
    if (print)
         imprimir(img);

    assert(sonIguales(imgBase, img)&& " fallo 1");
    
    flipV(img);
    if (print)
         imprimir(img);
    
    assert(!sonIguales(imgBase, img) && " fallo 2");
    
    flipV(img);
    if (print)
         imprimir(img);

    assert(sonIguales(imgBase, img) && " fallo 3");
    
    flipH(img);
    if (print)
         imprimir(img);
    
    assert(!sonIguales(imgBase, img)&& " fallo 4 ");
    
    flipH(img);
    if (print)
         imprimir(img);

    assert(sonIguales(imgBase, img) && " fallo 5");  
    
    flipV(img);
    flipH(img);
    flipH(img);
    flipV(img);
    if (print)
         imprimir(img);

    assert(sonIguales(imgBase, img) && " fallo 6 ");
    
    liberaMemoria(imgBase);
    liberaMemoria(img);
            
}

/*****************************************************************************/

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
            char fin = *(img.M[i] + (img.nc-j-1));

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

/*

El código para analizar o la función de prueba 6, dara error de ejecución
al intentar imprimir la matriz de img2, por que cuando hicimos img2 = img1, 
lo que realmente paso es que el objeto img2 pasó a apuntar al objeto img1,
y por tanto, al liberar la memoria de img1 no podremos acceder mediante img2.

*/

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

/*********** YO PRUEBAS ********************/

void reservaMemoria(Lienzo & img){
    img.M = new char* [img.nf];

    for (int i = 0; i < img.nf; ++i){
        img.M[i] = new char[img.nc];
    }
}

void liberaMemoria(Lienzo & img){
    for (int i = 0; i < img.nf; ++i){
        delete [] img.M[i];
    }

    delete [] img.M;
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

void redimensiona(Lienzo & img, int nuevaF, int nuevaC, char c){
    Lienzo tmp;
    tmp.nf = nuevaF;
    tmp.nc = nuevaC;

    reservaMemoria(tmp);
    liberaMemoria(img);
    rellenar(tmp, c);
    img = tmp;
}

void dibujaRectangulo(Lienzo & img, int x, int y, int ancho, int alto, char c){
    
}
	
void flipV(Lienzo & img){
    for (int i = 0; i < img.nf/2; ++i){
        char *ini =  *(img.M + i);
        char *fin = *(img.M + img.nf - i - 1);

        *(img.M + i) = fin;
        *(img.M + i - 1 + img.nf) = ini;
    }
}

void flipH(Lienzo & img){
    for (int i = 0; i < img.nf; ++i){
        for (int j = 0; j < img.nc/2; ++j){
            char ini = *(img.M[i] + j);
            char fin = *(img.M[i] + j + img.nc - 1);

            *(img.M[i] + j) = fin;
            *(img.M[i] + j + img.nc -1) = ini;
        }
    }
}

void pintaBarras(Lienzo & img, int *barras, int n, char c){
   
}

void rotar(Lienzo & img){

}

bool sonIguales(const Lienzo & L1, const Lienzo & L2){
   
}