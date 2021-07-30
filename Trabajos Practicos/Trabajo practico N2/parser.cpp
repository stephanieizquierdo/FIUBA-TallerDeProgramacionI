#include "parser.h"
#include <utility>

#include <iostream>

#define CANT_TOTAL_SALTOS 10
#define RETORNO "ret"
#define COMA ','
#define ESPACIO ' '
#define TAB '\t'
#define DECLARACION_DE_TAG ':'

void Parser::agregar_instruccion(std::string &instruccion){
	(this->lista_instrucciones).push_back(instruccion);
}

void Parser::inicializar_tabla(){
	for (std::size_t i = 0; i < (this->lista_instrucciones).size(); i++) {
		std::string linea_actual = (this->lista_instrucciones).at(i);

		std::size_t posicion = Parser::tiene_tag(linea_actual);
		if (posicion != std::string::npos) {
			std::string tag = linea_actual.substr(0, posicion);
			(this->tabla_de_tags).insert(make_pair(tag, i));
		}
	}
}

int Parser::obtener_posicion_tag(std::string tag){
	return (this->tabla_de_tags).at(tag);
}

std::string Parser::limpiar_string(const std::string &linea){
	std::string nueva_linea = linea;
	std::size_t pos = nueva_linea.find(ESPACIO);
	while (pos != std::string::npos) {
		nueva_linea.erase(pos, pos + 1);
		pos = nueva_linea.find(ESPACIO);
	}
	pos = nueva_linea.find(TAB);
	while (pos != std::string::npos) {
		nueva_linea.erase(pos);
		pos = nueva_linea.find(TAB);
	}
	pos = nueva_linea.find(COMA);
	while (pos != std::string::npos) {
		nueva_linea.erase(pos);
		pos = nueva_linea.find(COMA);
	}
	return nueva_linea;
}

bool Parser::es_comun(std::string &instruccion){
	bool encontre_salto = false;
	int i = 0;
	while (!encontre_salto && i < CANT_TOTAL_SALTOS) {
		std::size_t pos = instruccion.find(this->saltos.at(i));
		if (pos == std::string::npos) {
			i++;
		} else {
			encontre_salto = true;
		}
	}
	if (encontre_salto){
		return false;
	}
	std::size_t pos_ret = instruccion.find(RETORNO);
	if (pos_ret != std::string::npos) {
		return false;
	}
	return true;
}

std::size_t Parser::tiene_tag(std::string &instruccion){
	std::size_t pos = instruccion.find(DECLARACION_DE_TAG);
	return pos;
}

bool Parser::tiene_salto(std::string &instruccion, int& ultimapos){
	bool encontre = false;
	int i = 0;
	while (!encontre && i < CANT_TOTAL_SALTOS) {
		std::size_t pos = instruccion.find(this->saltos.at(i));
		if (pos == std::string::npos) {
			i++;
		} else {
			encontre = true;
			ultimapos = pos + (this->saltos.at(i)).length();
		}
	}
	return encontre;
}

bool Parser::tiene_return(std::string &instruccion){
	std::size_t pos = instruccion.find(RETORNO);
	return (pos != std::string::npos);
}

int Parser::cant_comas(std::string &instruccion){
	std::size_t pos_1 = 0;
	std::size_t pos_2 = 0;

	pos_1 = instruccion.find(COMA);

	pos_2 = instruccion.rfind(COMA);
	if (pos_2 == std::string::npos) {
		return 0;
	} else if (pos_1 == pos_2) {
		return 1;
	} else {
		return 2;
	}
}
