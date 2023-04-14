/*
 
 * FICHERO: main.cpp
 * Autor: David A. Pelta
 * para guión de prácticas de Metodología de la Programación
 * Curso: 2022 - 2023
 
 */

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

// funcion auxiliar solo para main

void crearMatriz(Lienzo & img, char c);

int main(int argc, char* argv[]) {

    int opcion = atoi(argv[1]);
    switch (opcion){
        case 1: {test1(); break;}
        case 2: {test2(); break;}
        case 3: {test3(); break;}
        case 4: {test4(); break;}
        case 5: {test5(); break;}
        case 6: {test6(); break;}
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
    for(int i = 0; i < MAX; i++){
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