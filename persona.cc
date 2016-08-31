#include <string>
#include <iostream>
#include "persona.h"

namespace Casino {

using namespace std;

Persona:: Persona(string DNI, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais) {
	DNI_=DNI;
	nombre_=nombre;
	apellidos_=apellidos;
	localidad_=localidad;
	provincia_=provincia;
	pais_=pais;
	direccion_=direccion;
}
}
