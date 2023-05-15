#include "PoliReg.h"
#include <cmath>

const float PoliReg::MAX_RADIO = 200.0;
const float PoliReg::MIN_RADIO = 15.0;
const int PoliReg::MAX_VERT = 200;
const int PoliReg::MIN_VERT = 3;

/**************/

void PoliReg::reservaMemoria(int tam){
    if (tam != 0)
        vertices = new Punto2D [tam];
}

void PoliReg::liberaMemoria(){
    delete []vertices;
    vertices = 0;
}

void PoliReg::generaVertices(){
    if (N >= MIN_VERT){
        float alpha = 360 / N;
        float radianes = alpha * M_PI / 180;
        
        for (int i = 0; i < N; ++i){
            vertices[i] = Punto2D (radio, 0);
            
            if (i != 0)
                vertices[i].rotar(centro, i*radianes);
        }
    }
}

PoliReg & PoliReg::operator = (PoliReg rhs){
    if (*this != rhs){
        N = rhs.N;
        centro = rhs.centro;
        radio = rhs.radio;
        
        liberaMemoria();
        reservaMemoria(rhs.N);
        
        for (int i = 0; i < N; ++i)
            vertices[i] = rhs.vertices[i];
    }
    
    return *this;
}

bool PoliReg::operator == (const PoliReg & rhs) const{
    bool iguales = false;
    
    if (this->centro.getX() == rhs.centro.getX() and
        this->centro.getY() == rhs.centro.getY() and
        this->N == rhs.N and this->radio == rhs.radio){
        iguales = true;
        
        for (int i = 0; i < N and !iguales; ++i){
            if (this->vertices[i].getX() != rhs.vertices[i].getX() or
                this->vertices[i].getY() != rhs.vertices[i].getY())
                iguales = false;
        }
    }
    
    return iguales;
}

bool PoliReg::operator != (const PoliReg & rhs) const{
    return !(*this == rhs);
}

/**************/

PoliReg::PoliReg(){
    N = MIN_VERT;
    radio = MIN_RADIO;
    centro = Punto2D (0,0);
    reservaMemoria(N);
}

PoliReg::PoliReg(int nroVert, const Punto2D & centro, float r){
    N = nroVert;
    this->centro = centro;
    
    if (r < MIN_RADIO or r > MAX_RADIO) r = MIN_RADIO;
    else radio = r;
    
    reservaMemoria(N);
}

PoliReg::~PoliReg(){
    liberaMemoria();
    N = MIN_VERT;
    radio = MIN_RADIO;
    centro = Punto2D (0,0);
}

void PoliReg::agregaVertice(){
    if (N+1 <= MAX_VERT){
        N++;
        Punto2D *aux = new Punto2D[N];
        
        for (int i = 0; i < N-1; i++)
            aux[i] = vertices[i];
        
        liberaMemoria();
        vertices = aux;
    }
}

void PoliReg::eliminaVertice(){
    if (N-1 >= MIN_VERT){
        N--;
        Punto2D *aux = new Punto2D[N];
        
        for (int i = 0; i < N; i++)
            aux[i] = vertices[i];
        
        liberaMemoria();
        vertices = aux;
    }
}

void PoliReg::expande(const int & delta){
    if (delta > 0){
        if (radio + delta < MAX_RADIO){
            radio += delta;
            generaVertices();
        }
    }
}

void PoliReg::contrae(const int & delta){
    if (delta > 0){
        if (radio - delta > MIN_RADIO){
            radio -= delta;
            generaVertices();
        }
    }
}

float PoliReg::perimetro() const{
    float angulo = 2 * M_PI / N;
    float lado = 2 * radio * sin(angulo / 2);
    
    return N * lado;
}

void PoliReg::rotar(const float & rads){
    for (int i = 0; i < N; ++i)
        vertices[i].rotar(centro, rads);
}

bool PoliReg::colision(const PoliReg & otro) const{
    bool chocan = false;
    
    if (*this != otro){
        int distancia = this->centro.distancia(otro.centro);
        int radios = this->radio + otro.radio;
        
        if (radios >= distancia) chocan = true;
    }
    
    return chocan;
}

void PoliReg::mover(const float & dx, const float & dy){
    for (int i = 0; i < N; ++i)
        vertices[i].mover(dx, dy);
}

float PoliReg::getRadio() const{
    return radio;
}

int PoliReg::getLados() const{
    return N;
}