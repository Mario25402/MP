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
#include <algorithm>

using namespace std;

void mostrar(const PoliReg & conj){
    int tam = conj.getLados();
    cout << tam << " lados. Vertices: {";
    for (int i = 0; i < tam - 1; i++) {
        cout << "(" << conj.getVertice(i) << "), ";
    }
    
    cout << "(" << conj.getVertice(tam-1) << ")}\n" << endl;
}

void test1(){
    cout << "Prueba constructor de copia" << endl;
    
    PoliReg a1;
    PoliReg a2(5, Punto2D(100, 100), 20);
    PoliReg a3(a1);
    PoliReg a4 = a2;
    
    // se utiliza la funcion mostrar por si no está implementado operator<<
    mostrar(a1);
    mostrar(a2);
    mostrar(a3);
    mostrar(a4);
    
}

void test2(){
   cout << "Prueba operator<<" << endl;
   PoliReg a1;
   PoliReg a2(4, Punto2D(50,50), 20);
   
   cout << "Salida 1" << endl;
   cout << a1 << endl;
   cout << a2 << endl;
   
   cout << "Salida 2" << endl;
   cout << a1 << a2 << endl;
}


void test3(){
    cout << "Prueba operator>>" << endl;
            
    PoliReg a1;
    PoliReg a2(10, Punto2D(), 50);
    cin >> a1 >> a2;
    cout << a1 << endl;
    cout << a2 << endl;
}

void test4(){
    cout << "Prueba operator==" << endl;
            
    PoliReg a1(4, Punto2D(), 20);
    PoliReg a2;
    
    assert(!(a1 == a2));
    
    a2 = a1;
    
    assert(a1 == a2);
    
    a2.expande(20);
    assert(!(a1 == a2));
    
    cout << "Prueba pasada" << endl; 
}


void test5(){
    cout << "Prueba operator<" << endl;
            
    PoliReg a1(4, Punto2D(), 100);
    PoliReg a2(4, Punto2D(), 100);
    //PoliReg a2(a1);
    
    a1 = a2;
    cout << a1.perimetro() << ", " << a2.perimetro() << endl;
    assert(!(a1 < a2));
    a2.expande(10);
    
    cout << a1.perimetro() << ", " << a2.perimetro() << endl;
    assert(a1 < a2);
    
    a2.contrae(11);
    cout << a1.perimetro() << ", " << a2.perimetro() << endl;
    assert(a2 < a1);
    
    cout << "Prueba pasada" << endl; 
}

void ordenar(){
    PoliReg *v = new PoliReg[10];

    for (int i = 0; i < 10; ++i){
        int lados = random()%(10-5) + 5;
        int coordX = random()%(20-0) + 0; 
        int coordY = random()%(20-0) + 0;
        int radio = random()%(150-20) + 20;

        Punto2D centro(coordX, coordY);

        PoliReg aux (lados, centro, radio);
        v[i] = aux;
        v[i].generaVertices();
    }
    
    //////////

    cout << "Sin Ordenar: " << endl;
    for (int i = 0; i < 10; ++i)
        cout << v[i].perimetro() << endl;

    //////////
    
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (v[j] < v[j + 1]) {
                PoliReg tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
    
    //////////

    cout << "Ordenados: " << endl;
    for (int i = 0; i < 10; ++i)
        cout << v[i].perimetro() << endl;
    
    delete []v;
}

/******************************************************************************/

int main(int argc, char ** argv){
    
 int opcion = atoi(argv[1]);
 
 switch (opcion){
     case 1: {test1(); break;}
     case 2: {test2(); break;}
     // para la prueba 3 utiliza el fichero datos.txt para la 
     // redireccion de la entrada
     case 3: {test3(); break;}
     case 4: {test4(); break;}
     case 5: {test5(); break;}
     case 6: {ordenar(); break;}
     
 }   

  return 0;
}
