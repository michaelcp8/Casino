#include <string>
#include <fstream>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ruleta.h"

namespace Casino {

using namespace std;

void Ruleta:: addJugador(Jugador j) {
	jugadores_.push_back(j);
	
	string nomfich=j.getDNI()+".txt";

	ifstream fichero;
	fichero.open(nomfich.c_str());

	if(!fichero){
		ofstream fichero;
		fichero.open(nomfich.c_str());
		fichero.close();
	}
	else
	fichero.close();
}

void Ruleta:: setBola(int bola) {
	if (bola>-1 && bola<37)
		bola_=bola;
}

void Ruleta:: setBanca(int dinero) {
	if(dinero>=0)
		banca_=dinero;
}

int Ruleta:: deleteJugador(string DNI) {
	list <Jugador>:: iterator i;
	
	if(jugadores_.empty()) {
		return -1;
	}

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
		if( (*i).getDNI() == DNI ) {
			jugadores_.erase(i);
			return 1;
		}
	}
	
	return -2;
}

int Ruleta:: deleteJugador(Jugador j) {
	list <Jugador>:: iterator i;
	
	if(jugadores_.empty()) {
		return -1;
	}
	
	
	for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
		if( (*i).getDNI() == j.getDNI() ) {
			jugadores_.erase(i);
			return 1;
		}
	}
	
	return -2;
}

list <Jugador> Ruleta:: getJugadores() {
		return jugadores_;
}

void Ruleta:: escribeJugadores() {
	ofstream fichero("jugadores.txt");

	if (!fichero){
    		cout << "ERROR: El fichero no se ha podido crear\n";
    		exit(-1);
	}

	list <Jugador>:: iterator i;
	
	for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {
		fichero << (*i).getDNI() << "," << (*i).getCodigo() << "," << (*i).getNombre() << "," << (*i).getApellidos() << "," << 			(*i).getDireccion() << "," << (*i).getLocalidad() << "," << (*i).getProvincia() << "," << (*i).getPais() << "," << 			(*i).getDinero()<< "\n";

	}

	fichero.close();
}

void Ruleta:: leeJugadores() {
	ifstream fichero("jugadores.txt");

	if (!fichero){
    		cout << "ERROR: El fichero no se ha podido abrir\n";
    		exit(-1);
	}

	jugadores_.clear();
	
	char DNI[20], codigo[50], nombre[50], apellidos[50], direccion[50], localidad[50], provincia[50], pais[50], dinero[50];
	
	Jugador j("345", "345");

	while(fichero.getline(DNI, 20, ',')){
		        fichero.getline(codigo, 50, ',');
			fichero.getline(nombre, 50, ',');
			fichero.getline(apellidos, 50, ',');
			fichero.getline(direccion, 50, ',');
			fichero.getline(localidad, 50, ',');
			fichero.getline(provincia, 50, ',');
			fichero.getline(pais, 50, ',');
		        fichero.getline(dinero, 50, '\n');
			
			j.setDNI(DNI);
			j.setCodigo(codigo);
			j.setNombre(nombre);
			j.setApellidos(apellidos);
			j.setDireccion(direccion);	
			j.setLocalidad(localidad);
			j.setProvincia(provincia);
			j.setPais(pais);
			j.setDinero(atoi(dinero));

			jugadores_.push_back(j);
		}
		fichero.close();
}

void Ruleta:: giraRuleta() {
	srand(time(NULL));
	bola_=rand()%36;
	lanzamientosbola_++;
}

void Ruleta:: getPremios() {
	list <Jugador>:: iterator i;
	list <Apuesta>:: iterator j;
	list <Apuesta> l;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++) {			
		(*i).setApuestas();
		l=(*i).getApuestas();

		for(j=l.begin(); j!=l.end(); j++) {
			
			switch ((*j).tipo) {
			
				case 1: if(bola_==0) {
						(*i).setDinero((*i).getDinero()-(*j).cantidad);
						banca_=banca_+(*j).cantidad;
					}
					else {	
						if(bola_==atoi((*j).valor.c_str())) {
							(*i).setDinero((*i).getDinero()+(35*(*j).cantidad));
							banca_=banca_-(35*(*j).cantidad);
						}
						else {
							(*i).setDinero((*i).getDinero()-(*j).cantidad);
							banca_=banca_+(*j).cantidad;
						}
					}
					break;
					
				case 2: if(bola_==0) {
						(*i).setDinero((*i).getDinero()-(*j).cantidad);
						banca_=banca_+(*j).cantidad;
					}
					else {
						if((CompruebaRojo(bola_) && ((*j).valor=="rojo")) || (CompruebaNegro(bola_) && 						((*j).valor=="negro"))) {
							banca_=banca_-((*j).cantidad);
							(*i).setDinero((*i).getDinero()+(*j).cantidad);
						}
						else {
							(*i).setDinero((*i).getDinero()-(*j).cantidad);
							banca_=banca_+(*j).cantidad;
						}
					}
					break;
	
				case 3: if(bola_==0) {
						(*i).setDinero((*i).getDinero()-(*j).cantidad);
						banca_=banca_+(*j).cantidad;
					}
					else {
						if( ( (bola_%2==0) && ((*j).valor=="par") ) || ( (bola_%2!=0) && ((*j).valor=="impar") ) ){
							banca_=banca_-((*j).cantidad);
							(*i).setDinero((*i).getDinero()+(*j).cantidad);
						}
						else {
							(*i).setDinero((*i).getDinero()-(*j).cantidad);
							banca_=banca_+(*j).cantidad;
						}
					}
					break;

				case 4: if(bola_==0) {
						(*i).setDinero((*i).getDinero()-(*j).cantidad);
						banca_=banca_+(*j).cantidad;
					}
					else {
						if( ( (bola_>0) && (bola_<19) && ((*j).valor=="bajo") ) || ( (bola_>18) && (bola_<37) && 							((*j).valor=="alto") ) ) {
							banca_=banca_-((*j).cantidad);
							(*i).setDinero((*i).getDinero()+(*j).cantidad);
						}
						else {
							(*i).setDinero((*i).getDinero()-(*j).cantidad);
							banca_=banca_+(*j).cantidad;
						}
					}
				break;
			}
		}
		dineromesa_=dineromesa_+(*i).getDinero();
	}
		
}

bool Ruleta:: CompruebaRojo(int bola_){
	int rojo[]={1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	int i;

	for(i=0; i<18; i++){
		if(bola_==rojo[i]){
			return true;
		}
	}
	return false;
}

bool Ruleta:: CompruebaNegro(int bola_){
	int negro[]={2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
	int i;

	for(i=0; i<18; i++){
		if(bola_==negro[i]){
			return true;
		}
	}
	return false;
}

void Ruleta:: getEstadoRuleta(int &numjugadores, int &sumdinero, int &lanzamientos, int &dinero) {
		numjugadores=jugadores_.size();
		lanzamientos=lanzamientosbola_;
		sumdinero=dineromesa_;
		dinero=banca_-1000000;
}
}
