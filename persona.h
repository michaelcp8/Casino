/*Clase PERSONA: se trata de una clase que crea una persona*/

#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

namespace Casino {

using namespace std;

class Persona {
	private: 
		string nombre_, apellidos_, localidad_, provincia_, pais_, direccion_, DNI_;

	public:
		Persona(string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="");
		void setNombre(string nombre){ nombre_=nombre;}
		void setApellidos(string apellidos){ apellidos_=apellidos;}
		void setLocalidad(string localidad){ localidad_=localidad;}
		void setProvincia(string provincia){ provincia_=provincia;}
		void setPais(string pais){ pais_=pais;}
		void setDireccion(string direccion){ direccion_=direccion;}
		void setDNI(string DNI){ DNI_=DNI;}

		string getNombre() const {return nombre_;}
		string getApellidos() const {return apellidos_;}
		string getLocalidad() const {return localidad_;}
		string getProvincia() const {return provincia_;}
		string getPais() const {return pais_;}
		string getDireccion() const {return direccion_;}
		string getDNI() const {return DNI_;}
		string getApellidosyNombre() const {return (apellidos_+", "+nombre_);}
};
}

#endif
