/*
 PROGRAMA DE PRUEBAS BASICAS PARA LA CLASE PoliReg
 Metodologías de la Programación
 Grupo A
 
 */

#include <iostream>
#include "Punto2D.h"
#include "PoliReg.h"
#include <cassert>
#include <cstdlib>

using namespace std;


void test1(){
  cout << "\nPRUEBA Constructor-Destructor " << endl; 
   
  PoliReg p;
  PoliReg(5, Punto2D(), 10);
}

void test2(){
    cout << "\nPRUEBA Agrega vertices hasta ajustar a circunferencia " << endl; 
    Punto2D centro(400, 400);
    int radio = 25;
   
    PoliReg pol(3, centro, radio);
    double peri = pol.perimetro();
    double longitud = 2* M_PI * radio; // la longitud de la circunferencia que contiene al poligono
    int pasos = 0;
    double delta = longitud - peri;
    while(delta > 2.0){
        pol.agregaVertice();
        peri = pol.perimetro();
        delta = longitud - peri;
        cout << "Lados PoliReg:" << pol.getLados() << " Perim: " << peri << " Long. Circ: " << longitud << " Dif.: " << delta <<endl;
    }
    
    assert(pol.getLados() == 12);
}

void test3(){
    cout << "\nPRUEBA: Contrae-Expande poligono " << endl; 
 
  int radio = 100;  
  Punto2D centro(400, 400);
  PoliReg pol3(3, centro, radio);
  double perimRef = pol3.perimetro();
  
  for(int i = 0; i < 10; i++){
     pol3.expande(10);
     cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro() << endl;  
    }
  
    
  for(int i = 0; i < 10; i++){
     pol3.contrae(10);
     cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro() << endl;
    }

  assert((pol3.getRadio() == radio)&&(pol3.perimetro() == perimRef));
}

void test4(){
    cout << "\nPRUEBA Expande poligonos mientras no colisionen " << endl; 

    Punto2D c1(100, 100);
    PoliReg pol1(5, c1, 15);
    Punto2D c2(300, 300);
    PoliReg pol2(5, c2, 30);
    int steps = 0;
    cout << "Distancia entre centros " << c1.distancia(c2) << endl;
    while(!pol1.colision(pol2)){
        pol1.expande(10);
        pol2.expande(10);
        cout << "Suma de radios: " << pol1.getRadio() << " + " << pol2.getRadio() << " = " << pol1.getRadio()+pol2.getRadio() << endl; 
        steps++;
    }
    
    //cout << steps << endl;
    assert(steps == 12);
}


void test5(){

   Punto2D centro(400, 400);
   PoliReg p1(25, centro, 200);
   PoliReg p2(3, centro, 300);
   int pasos = 0;
    
    cout << "\nPRUEBA agrega - elimina vertices " << endl; 
   

    while (p1.getLados() >= p2.getLados()){
        p2.agregaVertice();
        p1.eliminaVertice();
        cout << "Lados Polig. 1: " << p1.getLados() << " - Lados Polig. 2: " << p2.getLados() << endl;
        pasos++;
    }
    
    cout << pasos << endl;
    assert(p1.getLados() < p2.getLados() && (pasos == 12));
}


void mostrar(const PoliReg & conj){
    int tam = conj.getLados();
    cout << tam << " lados. Vertices: {";
    for (int i = 0; i < tam - 1; i++) {
        cout << conj.getVertice(i).toString() << ", ";
    }
    
    cout << conj.getVertice(tam-1).toString() << "}\n" << endl;
}

void test6(){
   PoliReg p1(4, Punto2D(100,100), 40);
   PoliReg p2(3, Punto2D(200,200), 30);
   
   PoliReg aux;
   cout << " Poligonos iniciales " << endl;
   mostrar(p1);
   
   mostrar(p2);
   
   aux = p1;
   p1 = p2;
   p2 = aux;
   
   cout << " Poligonos intercambiados " << endl;
   mostrar(p1);
   mostrar(p2);
   
}

int main(int argc, char ** argv){
    
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
