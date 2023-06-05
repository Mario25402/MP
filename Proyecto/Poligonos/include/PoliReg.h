#include "Punto2D.h"
#include <iostream>
using namespace std;

class PoliReg{
private:
    static const int MAX_VERT;
    static const int MIN_VERT;
    static const float MAX_RADIO;
    static const float MIN_RADIO;
    
    Punto2D *vertices;
    Punto2D centro;

    int N;
    float radio;
    
    void reservaMemoria(int tam);
    void liberaMemoria();
    void redimensiona(int tam);
    void modificaTam(int delta);
    
public:
    PoliReg();
    PoliReg(const PoliReg & otro);
    PoliReg(int nroVert, const Punto2D & centro, float r);
    ~PoliReg();

    PoliReg & operator = (const PoliReg & rhs);
    bool operator < (const PoliReg & rhs);
    bool operator == (const PoliReg & rhs) const;
    bool operator != (const PoliReg & rhs) const;

    friend std::ostream & operator << (ostream & flujo, const PoliReg & p);
    friend std::istream & operator >> (istream & flujo, const PoliReg & p);
    
    void generaVertices();
    void agregaVertice();
    void eliminaVertice();
    void expande(int delta);
    void contrae(int delta);
    float perimetro() const;
    void rotar(float rads);
    bool colision(const PoliReg & otro) const;
    void mover(float dx, float dy);

    float getRadio() const;
    int getLados() const;
    Punto2D getVertice(const int pos) const;
    Punto2D getCentro() const;
};