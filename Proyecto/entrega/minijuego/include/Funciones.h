#include "Asteroide.h"

const int INICIO = 0;
const int MAX_DISPAROS = 20;
const int MAX_ASTEROIDES = 40;

const int WIDTH = 800;
const int HEIGHT = 450;

void MoverAsteroides(Asteroide* campo, int util);
void MoverMisiles(Asteroide* disparos, int util);
void moverNave(Asteroide & nave, bool sentido);

void ColisionMB(Asteroide* disparos, int & util);
void ColisionAA(Asteroide* campo, int util);
void ColisionAB(Asteroide* campo, int util);
void ColisionMA(Asteroide* campo, int & utilA, Asteroide* disparos, int & utilD);
bool ChoqueNA(const Asteroide & nave, Asteroide* campo, int util);

void disparar(Asteroide nave, Asteroide* disparos, int & util);
void IniciaCampo(Asteroide* campo, int & util);