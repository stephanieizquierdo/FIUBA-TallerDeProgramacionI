#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include "metodo.h"

/*
 *Se encargara de chequear el pedido del cliente
 */
class Parser{
	public: 
		Parser();

		/*
		 *Parsea el mensaje y devuelve el metodo que se pidio en el petitorio
		 */
		Metodo* parsear(std::string& mensaje_total, std::string& archivo);

		std::string obtener_primera_linea(std::string& mensaje_total);
		
		~Parser();
};

#endif /*PARSER_H*/
