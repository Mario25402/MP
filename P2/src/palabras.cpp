
/* 
 * File:   palabras.cpp
 * Author: David Pelta
 * 
 * Created on 10 de marzo de 2023,
 */

#include "palabras.h"

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


int posPalabra(const char msg[], int nroPal) {
 
}

int longPalabra(const char s[], int nroPal) {
    
}


int cuentaPalabras(const char msg[]) {

}

void extraePalabra(const char msg[], int nroPal, char salida[]) {

}

void delReves(const char msg[], char msg_reves[]) {

}

void agregaPalabra(char msg[], const char pal[]) {

}
