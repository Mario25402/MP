#ifndef P1_H
#define P1_H

// Estructura
struct Tiempo{
	
	// Variables
	int horas;
	int minutos;
	int segundos;

	// Sobrecarga Operadores
	Tiempo & operator += (int s)
	{
		if (s >= 3600){
			this->horas += (s / 3600);
			this->minutos += (s % 3600)/60;
			this->segundos += (s % 3600)%60;
		}

		else if (s >= 60){
			this->minutos += (s / 60);
			this->segundos += (s % 60);
		}

		else if (s < 60) this->segundos += s;

		if (this->minutos == 60){
			this->minutos = 0;
			this->horas++;
		}

		if (this->segundos == 60){
			this->segundos = 0;
			this->minutos++;
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
};

#endif