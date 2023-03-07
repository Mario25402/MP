#ifndef TIEMPO_H
#define TIEMPO_H

/*****************************************************************************/
// Variables Globales

const int H_TO_S = 3600;
const int LIM_MIN_SEG = 60;
const int LIM_HOR = 24;

/*****************************************************************************/
// Estructura

struct Tiempo{
	
	// Variables
	int horas;
	int minutos;
	int segundos;

	// Sobrecarga Operadores
	Tiempo & operator += (int s)
	{
		if (s >= 0){
			if (s >= H_TO_S){
				this->horas += (s / H_TO_S);
				this->minutos += (s % H_TO_S) / LIM_MIN_SEG;
				this->segundos += (s % H_TO_S) % LIM_MIN_SEG;
			}

			else if (s >= LIM_MIN_SEG){
				this->minutos += (s / LIM_MIN_SEG);
				this->segundos += (s % LIM_MIN_SEG);
			}

			else if (s < LIM_MIN_SEG) this->segundos += s;


			if (this->minutos == LIM_MIN_SEG){
				this->minutos = 0;
				this->horas++;
			}

			if (this->segundos == LIM_MIN_SEG){
				this->segundos = 0;
				this->minutos++;
			}

			if (this->horas >= LIM_HOR) this->horas %= LIM_HOR;
		}

		return *this;
	}

	bool operator == (Tiempo t){
		bool iguales = false;

		if ((this->horas == t.horas) and (this->minutos == t.minutos) and (this->segundos == t.segundos))
			iguales = true;

		return iguales;
	}

	bool operator > (Tiempo t){
		bool mayor = false;

		if (this->horas > t.horas) mayor = true;

		else if (this->horas == t.horas){
			if (this->minutos > t.minutos) mayor = true;

			else if (this->minutos == t.minutos){
				if (this->segundos > t.segundos) mayor = true;
			}
		}

		if (*this == t) mayor = false;

		return mayor;
	}

	void operator - (Tiempo &t){
		if (t > *this){
			int seg1 = ((this->horas * H_TO_S) + (this->minutos * LIM_MIN_SEG) + this->segundos);
			int seg2 = ((t.horas * H_TO_S) + (t.minutos * LIM_MIN_SEG) + t.segundos);

			seg2 -= seg1;
			
			*this = {0};
			*this += seg2;
		}
	}
};

/*****************************************************************************/
// Cabeceras

void corrigeValor(Tiempo & t);
bool esPosterior (Tiempo & t1, Tiempo & t2);
bool sonIguales (Tiempo & t1, Tiempo & t2);
int tiempoEnSegundos (const Tiempo & t);
Tiempo & segundosEnTiempo (const int s);
void calcularNuevoTiempo (Tiempo & t, const int s);
std::string toString(Tiempo & t);
float tiempoEnMinutos (const Tiempo & t);

#endif