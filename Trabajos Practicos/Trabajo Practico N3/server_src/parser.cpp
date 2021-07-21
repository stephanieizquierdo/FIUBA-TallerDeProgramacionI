#include "parser.h"
#include "metodo.h"
#include <iostream>
#include <string>

#define ESPACIO ' '
#define TAB '\t'
#define SLASH '/'
#define PROTOCOLO "HTTP"
#define PROTOCOLO_SIN_RECURSO "/ HTTP"

Parser::Parser(){}

Parser::~Parser(){}

static std::string limpiar_string(const std::string &linea){
	std::string nueva_linea = linea;

	std::size_t pos = nueva_linea.find(ESPACIO);
	while (pos != std::string::npos) {
		nueva_linea.erase(pos);
		pos = nueva_linea.find(ESPACIO);
	}

	pos = nueva_linea.find(TAB);
	while (pos != std::string::npos) {
		nueva_linea.erase(pos);
		pos = nueva_linea.find(TAB);
	}
	return nueva_linea;
}

static std::string obtener_recurso(std::string &linea){
	std::size_t pos_barra = linea.find(SLASH);
	std::size_t pos_HTTP = linea.find(PROTOCOLO);
	std::string recurso = linea.substr(pos_barra + 1, pos_HTTP - 1);
	recurso = limpiar_string(recurso);
	return recurso;
}

std::string Parser::obtener_primera_linea(std::string& mensaje_total){
	std::size_t pos_primera_linea = mensaje_total.find("\n");
	return (mensaje_total.substr(0,pos_primera_linea));
}

static std::string obtener_requess(std::string& petitorio){
	std::size_t pos_barra = petitorio.find(SLASH);
	std::string requess = petitorio.substr(0,pos_barra);
	requess = limpiar_string(requess);
	return requess;
}

static Metodo* metodo_get(std::string &petitorio, std::string &archivo){
	std::size_t sin_recurso = petitorio.find(PROTOCOLO_SIN_RECURSO);
	if (sin_recurso != std::string::npos) {
		return new Get_SinRecurso(archivo);
	} else {
		std::string recurso = obtener_recurso(petitorio);
		return new Get_ConRecurso(recurso);
	}
}

static Metodo* metodo_post(std::string &petitorio, std::string &mensaje_total){
	std::size_t sin_recurso = petitorio.find(PROTOCOLO_SIN_RECURSO);
	if (sin_recurso != std::string::npos) {
		return new Post_sinRecurso();
	} else {
		std::string recurso = obtener_recurso(petitorio);
		std::size_t comienzo_body = mensaje_total.find("\n\n");
		std::string body = mensaje_total.substr(comienzo_body+2);
		return new Post_ConRecurso(recurso, body);
	}
}

static Metodo* metodo_invalido(std::string &petitorio){
	std::string recurso = obtener_requess(petitorio);
	return new Invalido(recurso);
}

Metodo* Parser::parsear(std::string & mensaje_total, std::string &archivo){ 
	std::string primera_linea = obtener_primera_linea(mensaje_total);
	
	std::size_t pos_post = primera_linea.find("POST");
	std::size_t pos_get = primera_linea.find("GET");
	
	if (pos_post != std::string::npos){
		return metodo_post(primera_linea, mensaje_total);
	} else if (pos_get != std::string::npos) {
		return metodo_get(primera_linea, archivo);
	} else {
		return metodo_invalido(primera_linea);
	}
}
