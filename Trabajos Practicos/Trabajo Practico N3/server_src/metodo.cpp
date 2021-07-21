#include "metodo.h"
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <utility>

#define DELIMITADOR '\n'

#define MENSAJE_POST_SIN_RECURSO "HTTP/1.1 403 FORBIDDEN\n"
#define MENSAJE_POST_CON_RECURSO "HTTP/1.1 200 OK\n\n"
#define MENSAJE_GET_SIN_RECURSO "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"
#define MENSAJE_GET_CON_RECURSO_ERROR "HTTP/1.1 404 NOT FOUND\n"
#define MENSAJE_GET_CON_RECURSO_OK "HTTP/1.1 200 OK\n"
#define MENSAJE_INVALIDO "HTTP/1.1 405 METHOD NOT ALLOWED\n\n"

/********************************** P O S T ***********************************/

Post_sinRecurso::Post_sinRecurso(){}

std::string Post_sinRecurso::correr(std::map <std::string, std::string> &mapa){
	return this->responder();
}

std::string Post_sinRecurso::responder(){
	return MENSAJE_POST_SIN_RECURSO;
}

Post_ConRecurso::Post_ConRecurso(const std::string &un_recurso,
	const std::string &un_body) : recurso(un_recurso), body(un_body){}

std::string Post_ConRecurso::correr(std::map <std::string, std::string> &mapa){
	mapa.insert(make_pair(this->recurso, this->body));
	return this->responder();
}

std::string Post_ConRecurso::responder(){
	return (MENSAJE_POST_CON_RECURSO + this->body);
}

/********************************** G E T *************************************/

Get_SinRecurso::Get_SinRecurso(const std::string &un_nombre)
	: nombre_archivo(un_nombre){}

std::string Get_SinRecurso::correr(std::map <std::string, std::string> &mapa){
	return this->responder();
}

std::string Get_SinRecurso::responder() {
	std::ifstream archivo(this->nombre_archivo);
	if (!archivo){
		return "No se pudo abrir el archivo";
	}
	std::string segundo_mensaje;
	std::string linea;
	while (std::getline(archivo,linea,DELIMITADOR)) {
		linea.push_back(DELIMITADOR);
		segundo_mensaje += linea;
	}
	segundo_mensaje.erase(segundo_mensaje.size() - 1);

	return (MENSAJE_GET_SIN_RECURSO + segundo_mensaje);
}

Get_ConRecurso::Get_ConRecurso(const std::string &un_recurso)
	: recurso(un_recurso){}

std::string Get_ConRecurso::correr(std::map <std::string, std::string> &mapa){
	try{
   		std::string body = mapa.at(this->recurso);
   		this->body = body;
   		return this->responder();
    }catch(...){
   	 	return MENSAJE_GET_CON_RECURSO_ERROR;
    }
}

std::string Get_ConRecurso::responder(){
	return (MENSAJE_GET_CON_RECURSO_OK + this->body);
}

/**************************** I N V A L I D ***********************************/

Invalido::Invalido(const std::string &un_reqques) : requess(un_reqques){}

std::string Invalido::correr(std::map <std::string, std::string> &mapa){
	return this->responder();
}

std::string Invalido::responder() {
	std::string primer_msj = MENSAJE_INVALIDO;
	std::string segundo_msj = " es un comando desconocido";
	return primer_msj + (this->requess) + segundo_msj;
}
