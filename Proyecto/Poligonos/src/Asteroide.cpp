/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Asteroide.h"

Asteroide::Asteroide(){
    int lados = rand() % 8 + 3; 
    int radio = rand() % 16 + 2;
    float coordX = rand()% 801 + 1;
    float coordY = rand()% 451 + 1;
    float velX = rand() % 7; // 0 a 6
    float velY = rand() % 7;
    velX -= 3; // -3 a 3
    velY -= 3;
    
    veloc = Punto2D(velX,velY);
    this->roca = PoliReg (lados, Punto2D(coordX, coordY), radio);
    this->giro = 5;
}

Asteroide::Asteroide(const PoliReg & pol, const Punto2D & vel, float rads)
:roca(pol), veloc(vel){
    this->giro = rads;
}

void Asteroide::mover(){
    int dy = this->veloc.getX();
    int dx = this->veloc.getY();
    
    this->roca.mover(dx, dy);
}

void Asteroide::rotar(){
    this->roca.rotar(this->giro);
}

void Asteroide::setVelocidad(const Punto2D & nuevaVel){
    this->veloc = nuevaVel;
}

void Asteroide::setRoca(const PoliReg & nuevaRoca){
    this->roca = nuevaRoca;
}

bool Asteroide::colision(const Asteroide & otro) const{
    return this->roca.colision(otro.roca);
}

Punto2D & Asteroide::getVelocidad(){
    return this->veloc;
}

PoliReg & Asteroide::getRoca(){
    return this->roca;
}

float Asteroide::getRotacion(){
    return this->giro;
}

Punto2D Asteroide::getCentro(){
    return this->getRoca().getCentro();
}

Asteroide & Asteroide::operator = (const Asteroide & rhs){
    if (this != &rhs){
        this->roca = rhs.roca;
        this->veloc = rhs.veloc;
        this->giro = rhs.giro;
    }
    
    return *this;
}