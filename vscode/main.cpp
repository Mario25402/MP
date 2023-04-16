#ifndef LIENZO_H
#define LIENZO_H

#ifdef __cplusplus
extern "C" {
#endif

    
/*
 
 * FICHERO: lienzo.h
 * Autor: David A. Pelta
 * para guión de prácticas de Metodología de la Programación
 * Curso: 2022 - 2023
 
 */

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


#ifdef __cplusplus
}
#endif

#endif /* LIENZO_H */

/*****************************************************************************/

#include <iostream>
//#include <string>
#include "lienzo.h"

using namespace std;

void test1(); // reserva-libera
void test2(); // dibuja rectangulos
void test3(); // redimensiona
void test4(); // flipV - flipH
void test5(); // pinta barras
void test6(); // misterio
void test7(); // prueba personalizada

// funcion auxiliar solo para main

void crearMatriz(Lienzo & img, char c);

int main(int argc, char* argv[]) {

    int opcion = 6;
    switch (opcion){
        case 1: {test1(); break;}
        case 2: {test2(); break;}
        case 3: {test3(); break;}
        case 4: {test4(); break;}
        case 5: {test5(); break;}
        case 6: {test6(); break;}
        case 7: {test7(); break;}
    }
    
    return 0;
}


void crearMatriz(Lienzo & img, char c){
 reservaMemoria(img);
 rellenar(img, '.');
}

void test1(){
    cout << "Reserva-Libera" << endl;
    Lienzo img;
    
    for(int i = 0; i < 10; i++){
        int n = random()%1000 + 10;
        img.nf = n;
        img.nc = n;
        reservaMemoria(img);
        liberaMemoria(img);
    }
}


void test2(){
 cout << "Prueba dibujar Rectangulos " << endl;
 Lienzo img;
 img.nf = img.nc = 5;
 
 crearMatriz(img,'.'); 
 dibujaRectangulo(img, 1,1,3,3,'X');
 imprimir(img);
 
 rellenar(img, '.');
 dibujaRectangulo(img, 3,3,3,3,'X');
 imprimir(img);
 
 rellenar(img, '.');
 dibujaRectangulo(img, -1,-1,3,3,'X');
 imprimir(img);
 cout << endl;
 
 liberaMemoria(img);

 cout << "\nBien" << endl;
}


void test3(){
    cout << "\n\nRedimensiona " << endl;
    Lienzo img;
    img.nf = img.nc = 2;
    reservaMemoria(img);
    rellenar(img, '*');
    
        
    for(int i = 0; i < 5; i++){
        imprimir(img);
        redimensiona(img, img.nf + 1, img.nc+1,'.');
    }
    
    liberaMemoria(img);
}

void test4(){
 cout << "flip v" << endl;
 Lienzo img;
 img.nf = 5;
 img.nc = 8;
 
 crearMatriz(img, '.'); 
 dibujaRectangulo(img, 0,0,3,3, 'A');
 dibujaRectangulo(img, 3,5,1,3, 'B');
 imprimir(img);
  
 flipV(img);
 imprimir(img);

 flipH(img);
 imprimir(img);

 flipV(img);
 imprimir(img);

 cout << endl;

 liberaMemoria(img);

}
  
void test5(){
    cout << "Grafico de Barras " << endl;
    int MAX = 6;
    int v[MAX] = {1,2,3,4,5,6};
    Lienzo G;
    for(int i = 0; i <= MAX; i++){
        pintaBarras(G, v, i, 'x');
        imprimir(G);
    }

    liberaMemoria(G);   
}

void test6(){
 cout << "Misterio" << endl;
 Lienzo img1, img2;
 img1.nf = 3;
 img1.nc = 3;
 
 reservaMemoria(img1);
 rellenar(img1, '.');

 dibujaRectangulo(img1, 1,1,1,1, 'A');
 imprimir(img1);
 img2 = img1;
 imprimir(img2);

 
 liberaMemoria(img1);
 imprimir(img2);
}

void test7(){
    cout << "Prueba" << endl;
    Lienzo img;
    
    for(int i = 0; i < 10; i++){
        int n = random()%1000 + 10;
        img.nf = n;
        img.nc = n;
        reservaMemoria(img);
        liberaMemoria(img);
    }
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
    if (img.M != 0 and img.nf > 0){
        for (int i = 0; i < img.nf; ++i){
            for (int j = 0; j < img.nc; ++j){
                img.M[i][j] = simbolo;
            }
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