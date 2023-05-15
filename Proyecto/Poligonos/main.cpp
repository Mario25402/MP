/*
 PROGRAMA DE PRUEBAS BASICAS PARA LA PARTE 2 DEL PROYECTO FINAL
 
 */

#include <iostream>
#include "Punto2D.h"
#include "PoliReg.h"
#include <cassert>
#include <cstdlib>
#include <cmath>

using namespace std;

void test1(){

   Punto2D centro(400, 400);
   PoliReg p1(25, centro, 200);
   PoliReg p2(3, centro, 300);
    
    cout << "\nPRUEBA 1: agrega - elimina vertices " << endl; 
   

    while (p1.getLados() >= p2.getLados()){
        cout << "Lados Polig. 1: " << p1.getLados() << " - Lados Polig. 2: " << p2.getLados() << endl;
        p2.agregaVertice();
        p1.eliminaVertice();
    }
}

void test2(){
    cout << "\nPRUEBA 2: agrega vertices hasta ajustar a circunferencia " << endl; 
    Punto2D centro(400, 400);
   
    PoliReg pol(3, centro, 100);
    double peri = pol.perimetro();
    double longitud = 2* M_PI * 100; // la longitud de la circunferencia que contiene al poligono
    int pasos = 0;
    double delta = longitud - peri;
    while(delta > 2.0){
        pol.agregaVertice();
        peri = pol.perimetro();
        delta = longitud - peri;
        cout << "Con " << pol.getLados() << " lados, el perimetro es:  " << peri << " Long. circunferencia: " << longitud << " Diferencia: " << delta <<endl;
    }
    
    cout << "\n" << pol.getLados() << endl;
    assert(pol.getLados() == 23);
}

void test3(){
    cout << "\nPRUEBA 3: contrae-expande poligono " << endl; 
 
  Punto2D centro(400, 400);
  PoliReg pol3(3, centro, 100);
  for(int i = 0; i < 10; i++){
     cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro() << endl;
     pol3.expande(10);
}
  
    
  for(int i = 0; i < 10; i++){
     cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro() << endl;
     pol3.contrae(10);
}
}

void test4(){
    cout << "\nPRUEBA 4: expande poligonos mientras no colisionen " << endl; 

    Punto2D c1(300, 300);
    PoliReg pol1(5, c1, 50);
    Punto2D c2(500, 500);
    PoliReg pol2(5, c2, 50);
    int steps = 0;
    
    cout << "\nDistancia: " << c1.distancia(c2) << endl;
    while(!pol1.colision(pol2)){
        pol1.expande(10);
        pol2.expande(10);
        cout << "Polig 1, Radio: " << pol1.getRadio() << " Perim. " << pol1.perimetro() 
                << "\tPolig. 2, Radio: " << pol2.getRadio() << " Perim. " << pol2.perimetro() << endl; 
        steps++;
    }
    
    cout << "\n" << steps << endl;
    assert(steps == 11);
}

void test5(){
PoliReg p;
    
}

int main(int argc, char ** argv){

// llamada a todos los constructores;
    
 int opcion = atoi(argv[1]);
 
 switch (opcion){
     case 1: {test1(); break;}
     case 2: {test2(); break;}
     case 3: {test3(); break;}
     case 4: {test4(); break;}
     case 5: {test5(); break;}
 }   
   

    return 0;
}


