#include <string>
#include <iostream>
#include "crupier.h"

namespace Casino {

using namespace std;

Crupier:: Crupier(string DNI, string codigo, string nombre, string apellidos, string direccion, string localidad, string provincia, string pais): Persona(DNI, nombre, apellidos,direccion, localidad, provincia, pais) {
		codigo_=codigo;
}
}

