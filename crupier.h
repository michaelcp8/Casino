/*Clase CRUPIER: se trata de una clase heredada de PERSONA, que su funcion es la de crear un crupier*/

#ifndef CRUPIER_H
#define CRUPIER_H

#include <string>
#include <iostream>
#include "persona.h"

namespace Casino {

using namespace std;

class Crupier: public Persona {
	private: 
		string codigo_;

	public:
		Crupier(string DNI, string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setCodigo(string codigo) { codigo_=codigo;}		
		string getCodigo() const { return codigo_;}
		
		
};
}

#endif
