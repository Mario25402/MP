/*
Mi programa produce la salida esperada con todos los ejemplos
NOMBRE Y APELLIDOS: MARIO PIÑA MUNERA
DNI: 26536550R
GRUPO DE PRÁCTICAS: MIÉRCOLES
*/

/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 10 de marzo de 2023,
 */

#include "../P2/include/palabras.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int longitud(const char s[]) {
    int cont = 0;

    while (s[cont] != TERMINADOR)
        cont++;

    return cont;
}

// funcion privada. 
// el valor j siempre debe estar en el rango correcto
bool empiezaPalabra(const char s[], int j) {
// empieza una palabra si el carácter en la posición j es distinto de espacio
// y, además, si j > 0, en la posición anterior había un espacio    
    
    bool es_letra_actual;
    bool hay_sep_previo = true;
    
    es_letra_actual = s[j] != SEP;
    if ( j > 0)
       hay_sep_previo = (s[j - 1] == SEP);
    
    
    return (es_letra_actual && hay_sep_previo);
}

// funcion privada. 
// el valor j siempre debe estar en el rango correcto
bool terminaPalabra(const char s[], int j) {
// termina una palabra si el carácter en la posición j es distinto de espacio
// y, además, en la posición j+1 aparece un espacio o el terminador (es la última palabra)
    
    bool es_letra_actual = (s[j] != SEP);
    bool hay_sep_sig = (s[j + 1] == SEP) || (s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}

// funcion privada.
// Si una cadena está inicializada con basura inserta en la
// primera posición un terminador de cadena
void corrige(char msg[]){
    if (!((msg[0] >= 'a' && msg[0] <= 'z') or
        (msg[0] >= 'A' && msg[0] <= 'Z') or
        msg[0] == SEP or msg[0] == TERMINADOR)){
            msg[0] = TERMINADOR;
        }
}

int posPalabra(const char msg[], int nroPal) {
    int pos = -1;
    int total = cuentaPalabras(msg);

    if (nroPal <= total){
        int i = 0;
        int pal = 0;

        while (msg[i] != TERMINADOR and pos == -1){
            if (empiezaPalabra(msg,i)) pal++;
            if (pal == nroPal) pos = i;
            i++;
        }
    }

    return pos;
}

int longPalabra(const char s[], int nroPal) {
    int long_pal = -1;
    int total = cuentaPalabras(s);

    if (nroPal <= total){
        int i = 0;
        int pal = 0;

        while (s[i] != TERMINADOR and long_pal == -1){
            if (empiezaPalabra(s,i)){
                pal++;

                if (pal == nroPal){
                    while (!terminaPalabra(s,i)){
                        long_pal++; 
                        i++;
                    }
                }
            }

            i++;
        }
    }

    return long_pal;
}


int cuentaPalabras(const char msg[]) {
    int pal = 0;
    int i = 0;

    while (msg[i] != TERMINADOR){
        if (terminaPalabra(msg, i)) pal++;
        i++;
    }

    return pal;
}

void extraePalabra(const char msg[], int nroPal, char salida[]) {
    int ini = posPalabra(msg, nroPal);
    int longitud = 0;

    int actual = ini;
    while (!terminaPalabra(msg, actual)){
        actual++;
        longitud++;
    }

    for (int i = 0; i <= longitud; i++) salida[i] = msg[ini+i];

    salida[longitud+1] = TERMINADOR;
}

void delReves(const char msg[], char msg_reves[]) {
    int num_pal = cuentaPalabras(msg);

    if (num_pal != 0){
        int i = 0;
        
        corrige(msg_reves);

        while (i < num_pal){
            char palabra[MAX_SIZE];

            extraePalabra(msg, num_pal-i, palabra);
            agregaPalabra(msg_reves, palabra);

            i++;
        }

        if (i == num_pal){
            int long_reves = longitud(msg_reves);
            msg_reves[long_reves] = TERMINADOR;
        }
    }
}

void agregaPalabra(char msg[], const char pal[]) {
    int esc = longitud(msg);
    int palabras = cuentaPalabras(msg);

    if (palabras > 0){
        msg[esc] = '-';
        esc++;
    }

    int lec = 0;

    while (pal[lec] != TERMINADOR){
        msg[esc] = pal[lec];
        esc++;
        lec++;
    }

    msg[esc] = TERMINADOR;
}

void expande(char msg[], const int tam){
    int palabras = cuentaPalabras(msg);
    int espacios = palabras-1;

    if (espacios > 0){
        corrige(msg);
        int long_msg = longitud(msg);

        if (msg[0] == SEP) espacios++;
        if (msg[long_msg] == SEP) espacios++;
        
        if (msg[0] != TERMINADOR){
            char aux[MAX_SIZE];
            int aniadir = floor(tam/espacios);
            int long_aux = long_msg + tam;
            int lec = 0, esc = 0;

            while (esc < long_aux){
                if (empiezaPalabra(msg, lec)){
                    while (!terminaPalabra(msg, lec)){
                        aux[esc] = msg[lec];
                        esc++;
                        lec++;
                    }

                    aux[esc] = msg[lec];
                    esc++;
                }

                else{
                    for (int i = 0; i < aniadir; i++, esc++) aux[esc] = '.';
                }

                lec++;
            }

            aux[esc] = TERMINADOR;
            strcpy (msg, aux);
        }
    }
}

/*****************************************************************************/

const int FIL = 20;
const int COL = 200;


void mostrar(const char pag[][COL], int n){
    for(int i = 0; i < n; i++)
       cout << pag[i] << endl;

}

void cartel(string texto){
    cout << "\n\n********************************************* \n";
    cout << " ******* " << texto << endl;
    cout << " ********************************************* \n\n";
}

void test1(string texto){
    cartel(texto);
    char msg[MAX_SIZE] = "prueba de la funcion expande texto ";
    char aux[MAX_SIZE];
    int n = longitud(msg);
    
    // expande el texto de manera incremental, para ver la insercion de espacios
    // siempre trabaja con el texto original
    strcpy(aux, msg);
    for(int i = n; i < 50; i+=2){
        expande(aux, i);
        cout << aux << endl;
        strcpy(aux, msg);
    }
        
    
}

void lee_linea(char c[], int tamano){
    do{
        cin.getline(c, tamano);
    } while (c[0] == '\0');
}


// expande un conjunto de cadenas a la longitud máxima encontrada
void test3(string texto){
    cartel(texto);
    char m[FIL][COL];
    
    int nro = 0;
    cin >> nro;
    cin.get();

    int tam = 0; int cual = 0;
    cout << "\n **** Cadenas leidas *** " << nro << endl;
    for(int i = 0; i < nro; i++){
        //lee_linea(m[i], COL);
        cin.getline(m[i], COL);
        int aux = longitud(m[i]);
        cout << m[i] << " -> " << aux << endl;
        if ( aux > tam){
            tam = aux; 
            cual = i;
        }
    }


   for(int i = 0; i < nro; i++){
        expande(m[i],tam);
   }

   
   cout << "\n\n****** Texto justificado ****** \n\n" << endl;
   for(int i = 0; i < nro; i++)
        cout << m[i] << " \t -> " << longitud(m[i]) << endl;
   
}

int main() {
    
    
    test1("Prueba basica");
    test3("Prueba extendida");
    return (0);
}