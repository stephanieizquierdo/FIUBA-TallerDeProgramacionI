#include "nodo.h"
#include <string>

Nodo::Nodo(std::string & una_instruccion) :
	tiene_return(false),
	instruccion(una_instruccion),
	cant_vecinos(0){}

Nodo::~Nodo(){}

void Nodo::agregar_vecino(int una_posicion){
	unsigned int i = 0;
	bool lo_tiene = false;
	while (i < this->vecinos.size() && !lo_tiene) {
		if (una_posicion == this->vecinos.at(i)) {
			lo_tiene = true;
		}
		i++;
	}
	if (!lo_tiene) {
		this->vecinos.push_back(una_posicion);
		this->cant_vecinos = this->cant_vecinos + 1;
	}	
}

std::vector<int> Nodo::get_vecinos(){
	return this->vecinos;
}

std::string Nodo::get_instruccion(){
	return(this->instruccion);
}

void Nodo::set_tiene_return(){
	this->tiene_return = true;
}

bool Nodo::get_tiene_return(){
	return this->tiene_return;
}
