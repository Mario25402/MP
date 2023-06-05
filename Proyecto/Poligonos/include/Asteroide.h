#include "PoliReg.h"
#include "Punto2D.h"

class Asteroide{
private:
    PoliReg roca;
    Punto2D veloc;
    float giro;
    
public:
    Asteroide();
    Asteroide(const PoliReg & pol, const Punto2D & vel, float rads=10);
    
    void mover();
    void rotar();
    void moverNave(bool sentido);
    
    void setVelocidad(const Punto2D & nuevaVel);
    void setRoca(const PoliReg & nuevaRoca);
    
    bool colision(const Asteroide & otro);
    
    Punto2D getVelocidad();
    PoliReg getRoca();
};