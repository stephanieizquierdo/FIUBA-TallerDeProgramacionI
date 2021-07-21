#include "items_servidor.h"
#include "mutex.h"
#include <string>

Items_servidor::Items_servidor(const char* una_ruta) : ruta_archivo(una_ruta){}

static void mostrar_primera_linea(const std::string &primera_linea){
	std::cout<<primera_linea<<std::endl;
}

std::string Items_servidor::modificar_y_procesar_Seguro
											(std::string & mensaje_nuevo){
	Lock l(m);

	this->mensaje = mensaje_nuevo;
	mensaje_nuevo.clear();
	std::string primera_linea = this->parseador.obtener_primera_linea(mensaje);
	mostrar_primera_linea(primera_linea);

	Metodo* un_metodo = this->parseador.parsear(mensaje, (this->ruta_archivo));
	std::string respuesta = un_metodo->correr(this->mapa);

	this->mensaje.clear();
	delete un_metodo;
	
	return respuesta;
}

Items_servidor::~Items_servidor(){}
