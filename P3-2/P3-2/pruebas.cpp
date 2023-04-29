/*
 
 * FICHERO: pruebas.cpp
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
    int opcion = atoi(argv[1]);
    if ((opcion > 1)&& (argc > 2))
        print = atoi(argv[2]);
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
