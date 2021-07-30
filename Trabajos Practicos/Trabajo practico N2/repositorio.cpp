#include "repositorio.h"
#include "mutex.h"
#include <string>
#include <iostream>
#include <algorithm>

#define ERROR -1

Repositorio::Repositorio(const std::vector<std::string> &nombres) :
	elementos(nombres){}

Repositorio::Repositorio(){}

void Repositorio::agregar_elemento(std::string un_elemento){
	Lock l(m);
	this->elementos.push_back(un_elemento);
}

std::string Repositorio::obtener_elemento_si_tiene(){
	Lock l(m);

	if (this->elementos.empty()) {
		throw ERROR;
	}
	std::string elemento = this->elementos.front();
	this->elementos.erase(elementos.begin());
	return elemento;
}

void Repositorio::imprimir_elementos_ordenadamente(){
	std::sort(this->elementos.begin(), this->elementos.end());
	for (unsigned int i = 0; i < this->elementos.size(); i ++) {
		std::cout<<this->elementos.at(i)<<std::endl;
	}
}
