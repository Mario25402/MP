#include "PoliReg.h"
#include <cmath>
#include <iostream>
#include <cassert>
using namespace std;

const float PoliReg::MAX_RADIO = 200.0;
const float PoliReg::MIN_RADIO = 15.0;
const int PoliReg::MAX_VERT = 200;
const int PoliReg::MIN_VERT = 3;

/**************/

void PoliReg::reservaMemoria(int tam){
    if (tam > 0)
        vertices = new Punto2D [tam];
}

void PoliReg::liberaMemoria(){
    delete []vertices;
    vertices = 0;
}

void PoliReg::redimensiona(int tam){
    Punto2D *aux = new Punto2D[tam];
    
    for (int i = 0; i < tam-1; ++i)
        aux[i] = vertices[i]; 
    
    liberaMemoria();
    vertices = aux;
}

/**************/

PoliReg & PoliReg::operator = (const PoliReg & rhs){
    if (this != &rhs){
        liberaMemoria();

        N = rhs.N;
        centro = rhs.centro;
        radio = rhs.radio;
        
        reservaMemoria(rhs.N);
        
        for (int i = 0; i < N; ++i){
            vertices[i] = rhs.vertices[i];
        }
    }
    
    return *this;
}

bool PoliReg::operator == (const PoliReg & rhs) const{
    bool iguales = false;

    if (this->getLados() == rhs.getLados()){
        iguales = true;
        
        for (int i = 0; i < N and iguales; ++i){
            if (this->vertices[i] != rhs.vertices[i])
                iguales = false;
        }
    }
    
    return iguales;
}

bool PoliReg::operator != (const PoliReg & rhs) const{
    return !(*this == rhs);
}

bool PoliReg::operator < (const PoliReg & rhs){    
    return this->perimetro() < rhs.perimetro();
}

ostream & operator << (ostream & flujo, const PoliReg & p){
    flujo << "@centro " << p.getCentro() << endl;
    flujo << "@radio " << p.getRadio() << endl;
    flujo << "@Puntos " << p.getLados() << endl;

    for (int i = 0; i < p.getLados(); ++i)
        flujo << p.getVertice(i) << endl;

    flujo << endl;
    
    return flujo;
}

istream & operator >> (istream & flujo, const PoliReg & p){
    Punto2D centro, punto;
    int radio, puntos;
    string dato;

    flujo >> dato >> centro;
    flujo >> dato >> radio;
    flujo >> dato >> puntos;

    PoliReg nuevo(puntos, centro, radio);
    nuevo.vertices = new Punto2D[puntos];

    for (int i = 0; i < puntos; ++i){
        flujo >> punto;
        nuevo.vertices[i] = punto;
    }

    return flujo;
}

/**************/

PoliReg::PoliReg(){
    N = MIN_VERT;
    radio = MIN_RADIO;
    centro = Punto2D (0,0);
    vertices = 0;
    
    reservaMemoria(N);
    generaVertices();
}

PoliReg::PoliReg(const PoliReg & otro):centro(otro.centro){
    N = otro.N;
    radio = otro.radio;
    vertices = 0;

    reservaMemoria(otro.N);

    for (int i = 0; i < N; ++i){
        vertices[i] = otro.vertices[i];
    }
}

PoliReg::PoliReg(int nroVert, const Punto2D & center, float r):centro(center){
    N = nroVert;
    
    if (r < MIN_RADIO or r > MAX_RADIO) r = MIN_RADIO;
    else radio = r;
    
    reservaMemoria(N);
}

PoliReg::~PoliReg(){
    liberaMemoria();
}

/**************/

void PoliReg::generaVertices(){
    liberaMemoria();
    float angulo = 2 * M_PI / N;
    
    for (int i = 0; i < N; ++i){
        int x = centro.getX() + radio * cos(i * angulo);
        int y = centro.getY() + radio * sin(i * angulo);
        Punto2D vertice(x,y);
        
        this->vertices[i] = vertice;
    }
}

void PoliReg::agregaVertice(){ 
    if (N+1 <= MAX_VERT){
        redimensiona(this->N + 1);
        generaVertices();
    }
}

void PoliReg::eliminaVertice(){
    if (N-1 >= MIN_VERT){
        redimensiona(this->N - 1);
        generaVertices();
    }
}

void PoliReg::modificaTam(int delta){
    if (radio + delta <= MAX_RADIO and radio + delta >= MIN_RADIO){
        radio += delta;
        generaVertices();
    }
}

void PoliReg::expande(int delta){
    modificaTam(delta);
}

void PoliReg::contrae(int delta){
    modificaTam(delta);
}

float PoliReg::perimetro() const{
    float lado = this->vertices[0].distancia(this->vertices[1]);
    return lado * N;
}

void PoliReg::rotar(float rads){
    for (int i = 0; i < N; ++i)
        vertices[i].rotar(centro, rads);
}

bool PoliReg::colision(const PoliReg & otro) const{
    bool chocan = false;
    
    if (this != &otro){
        int distancia = this->centro.distancia(otro.centro);
        int radios = this->radio + otro.radio;
        
        if (radios >= distancia) chocan = true;
    }
    
    return chocan;
}

void PoliReg::mover(float dx, float dy){
    this->centro.mover(dx, dy);
    
    for (int i = 0; i < N; ++i)
        vertices[i].mover(dx, dy);
}

float PoliReg::getRadio() const{
    return radio;
}

int PoliReg::getLados() const{
    return N;
}

Punto2D PoliReg::getVertice(const int pos) const{
    assert(pos >= MAX_VERT or pos <= MIN_VERT);
    return vertices[pos];
}

Punto2D PoliReg::getCentro() const{
    return centro;
}