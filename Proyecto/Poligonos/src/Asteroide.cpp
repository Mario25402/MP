/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Asteroide.h"

Asteroide::Asteroide(){
    
    int lados = random()%(10-5) + 5;
    int coordX = random()%(20-0) + 0; 
    int coordY = random()%(20-0) + 0;
    int radio = random()%(150-20) + 20;
    Punto2D centro(coordX, coordY);

    PoliReg aux (lados, centro, radio);
    aux.generaVertices();
    
    
    this->roca = aux;
    this->veloc = Punto2D(0,0);
    this->giro = 0;
}

Asteroide::Asteroide(const PoliReg & pol, const Punto2D & vel, float rads){
    
}

void Asteroide::mover(){
    int dy = this->veloc.getX();
    int dx = this->veloc.getY();
    
    this->roca.mover(dx, dy);
}

void Asteroide::rotar(){
    this->roca.rotar(this->giro);
}

void Asteroide::moverNave(bool sentido){
    // Solo utilizar para mover la nave
    // el valor "true" significa derecha
    // el valor "false" significa izquierda
    
    if (sentido)
        this->roca.mover(this->veloc, 0);
    else
        this->roca.mover(-this->veloc, 0);
        
}

void Asteroide::setVelocidad(const Punto2D & nuevaVel){
    this->veloc = nuevaVel;
}

void Asteroide::setRoca(const PoliReg & nuevaRoca){
    this->roca = nuevaRoca;
}

bool Asteroide::colision(const Asteroide & otro){
    return this->roca.colision(otro.roca);
}

Punto2D Asteroide::getVelocidad(){
    return this->veloc;
}

PoliReg Asteroide::getRoca(){
    return this->roca;
}