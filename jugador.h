/*Clase JUGADOR: se trata de una clase heredada de PERSONA, que su funcion es la de crear un jugador y leer las apuestas del mismo de un fichero para guardarlo en una lista*/

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <iostream>
#include <list>
#include "persona.h"

namespace Casino {

struct Apuesta {
	int tipo;
	string valor;
	int cantidad;
}; 

using namespace std;

class Jugador: public Persona {
	private: 
		int dinero_;
		string codigo_;
		list <Apuesta> lista_; 
		
	public:
		Jugador(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setCodigo(string codigo) {codigo_=codigo;}	
		void setDinero(int dinero) {dinero_=dinero;}		
		string getCodigo() const {return codigo_;}	
		int getDinero() const {return dinero_;}
		list <Apuesta> getApuestas()const {return lista_;}
		void setApuestas();   
};
}

#endif
