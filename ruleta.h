/*Clase RULETA: su función es simular el giro de una ruleta y actualizar el dinero de los jugadores según sus apuestas*/

#ifndef RULETA_H
#define RULETA_H

#include <string>
#include <iostream>
#include <list>
#include "jugador.h"
#include "crupier.h"

namespace Casino {

using namespace std;

class Ruleta {
	private:
		Crupier crupier_;
		int bola_;
		int banca_;
		int lanzamientosbola_, dineromesa_;
		list <Jugador> jugadores_;
		bool CompruebaRojo(int bola_);
		bool CompruebaNegro(int bola_);

	public:
		Ruleta(Crupier c): crupier_(c), bola_(-1), banca_(1000000), lanzamientosbola_(0), dineromesa_(0) {} ;
		void addJugador(Jugador j);
		void setBola(int bola);
		void setBanca(int dinero);
		int getBola() const {return bola_;}
		int getBanca()  const {return banca_;}
		Crupier getCrupier() const {return crupier_;}
		int deleteJugador(string DNI);
		int deleteJugador(Jugador j);
		list <Jugador> getJugadores();
		void escribeJugadores();
		void leeJugadores();
		void giraRuleta();
		void getPremios();
		void getEstadoRuleta(int &numjugadores, int &sumdinero, int &lanzamientos, int &dinero);
};
}

#endif
