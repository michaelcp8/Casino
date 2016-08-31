#include <string>
#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>
#include "jugador.h"

namespace Casino {

using namespace std;

Jugador:: Jugador(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais): Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais) {
	codigo_=codigo;
	dinero_=1000;
}

void Jugador:: setApuestas() {
		struct Apuesta a;
		lista_.clear();
		
		char codigo[50], cantidadapuesta[50], valorapuesta[50];
		
		string nomfich=getDNI()+".txt";
	
		ifstream fichero(nomfich.c_str());

		if (!fichero){
    			cout << "ERROR: El fichero no se ha podido abrir\n";
    			exit(-1);
		}
	
		while(fichero.getline(codigo, 50, ',')){
		        fichero.getline(valorapuesta, 50, ',');
		        fichero.getline(cantidadapuesta, 50, '\n');
			
			a.tipo=atoi(codigo);
			a.valor=valorapuesta;
			a.cantidad=atoi(cantidadapuesta);

			lista_.push_back(a);
		}
		fichero.close();
}
}
