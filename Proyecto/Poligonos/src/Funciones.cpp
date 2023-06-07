/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Funciones.cpp
 * Author: mario
 * 
 * Created on 5 de junio de 2023, 13:06
 */

#include "Funciones.h"

/*******************************************************************/

void MoverAsteroides(Asteroide* campo, int util){
    for (int i = 0; i < util; ++i) {
        campo[i].mover();
        campo[i].rotar();
    }
}

void MoverMisiles(Asteroide* disparos, int util){
    for (int i = 0; i < util; ++i)
        disparos[i].getRoca().mover(0, -disparos[i].getVelocidad().getY());
}

void ColisionMB(Asteroide* disparos, int & util){
    if (disparos[INICIO].getCentro().getY() <=
            disparos[INICIO].getRoca().getRadio()) {

        for (int i = 1; i <= util; i++)
            disparos[i - 1] = disparos[i];

        util--;
        cout << "Misil perdido" << endl;
    }
}

void ColisionAA(Asteroide* campo, int util){
    for (int i = 0; i < util; i++) {
        for (int j = i + 1; j < util; j++) {
            if (campo[i].colision(campo[j])) {
                Punto2D tmp = campo[i].getVelocidad();
                campo[i].setVelocidad(campo[j].getVelocidad());
                campo[j].setVelocidad(tmp);
            }
        }
    }
}

void ColisionAB(Asteroide* campo, int util){
    for (int i = 0; i < util; ++i) {
        if (campo[i].getRoca().getCentro().getX() <
                campo[i].getRoca().getRadio() or
                campo[i].getRoca().getCentro().getY() <
                campo[i].getRoca().getRadio()) {

            Punto2D actual = campo[i].getVelocidad();
            Punto2D nueva = Punto2D(-actual.getX(), -actual.getY());
        }
    }
}

void ColisionMA(Asteroide* campo, int & utilA, Asteroide* disparos, int & utilD){
    for (int i = 0; i < utilD; i++) {
        for (int j = utilA - 1; j <= 0; j--) {
            if (disparos[i].colision(campo[j])) {

                // Eliminar misil
                for (int k = i + 1; k < utilD; k++)
                    disparos[k - 1] = disparos[k];

                utilD--;

                // Modificar asteroide
                if (campo[j].getRoca().getLados() > 3) {
                    int lados = campo[j].getRoca().getLados() - 1;
                    Punto2D centro = campo[j].getRoca().getCentro();
                    float radio = campo[j].getRoca().getRadio();

                    PoliReg nueva(lados, centro, radio);
                    campo[j].setRoca(nueva);
                }
                
                else {
                    if (j != utilA)
                        campo[j] = campo[utilA];

                    utilA--;
                } // else
            } // if
        } // for intero
    } // for externo
}

bool ChoqueNA(const Asteroide & nave, Asteroide* campo, int util){
    bool choque = false;
    
    for (int i = 0; i < util and !choque; ++i) {
        if (nave.colision(campo[i]))
            choque = true;
    }
    
    return choque;
}

void moverNave(Asteroide & nave, bool sentido){
    // Solo utilizar para mover la nave
    // el valor "true" significa derecha
    // el valor "false" significa izquierda
    
    if (sentido)
        nave.getRoca().mover(nave.getVelocidad().getX(), 0);
    else
        nave.getRoca().mover(-nave.getVelocidad().getX(), 0);
        
}

void disparar(Asteroide nave, Asteroide* disparos, int & util){
    PoliReg forma(3, Punto2D(nave.getCentro().getX(), nave.getCentro().getY()), 0.5);
    Asteroide misil(forma, Punto2D(0,3), 180);
    misil.rotar();
    
    if (util < MAX_DISPAROS) {
        disparos[util] = misil;
        util++;
    }
    else cout << "Disparos máximos alcanzados" << endl;
}

void IniciaCampo(Asteroide* campo, int & util){
    while (util < MAX_ASTEROIDES) {
        Asteroide nuevo;
        campo[util] = nuevo;
        util++;
    }
}

/*******************************************************************/