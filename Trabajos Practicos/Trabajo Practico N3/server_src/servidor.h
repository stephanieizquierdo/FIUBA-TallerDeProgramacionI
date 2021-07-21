#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "../common_src/socket.h"
#include "parser.h"
#include "items_servidor.h"

#include <string>

class Servidor{
	private: 
		Socket socket;
		std::string puerto;
		Items_servidor items;
		
	public:
		Servidor(const char* un_puerto, const char* una_ruta);
		/*
		 * Enlaza el socket y comienza a atender los clientes mientras que
		 * no ingresen 'q'
		 */
		void correr();

		~Servidor();
};

#endif /*SERVIDOR_H*/
