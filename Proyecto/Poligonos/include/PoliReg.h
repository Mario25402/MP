#include "Punto2D.h"

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
    void generaVertices();
    
    PoliReg & operator = (PoliReg rhs);
    bool operator == (const PoliReg & rhs) const;
    bool operator != (const PoliReg & rhs) const;
    
public:
    PoliReg();
    PoliReg(int nroVert, const Punto2D & centro, float r);
    ~PoliReg();
    
    void agregaVertice();
    void eliminaVertice();
    void expande(const int & delta);
    void contrae(const int & delta);
    float perimetro() const;
    void rotar(const float & rads);
    bool colision(const PoliReg & otro) const;
    void mover(const float & dx, const float & dy);
    float getRadio() const;
    int getLados() const;
};