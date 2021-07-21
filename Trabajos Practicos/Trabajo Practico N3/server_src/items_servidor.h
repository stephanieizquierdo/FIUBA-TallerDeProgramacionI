#ifndef ITEMS_SERVIDOR_H
#define ITEMS_SERVIDOR_H

#include "../common_src/socket.h"
#include "parser.h"
#include <map>
#include <string>
#include <mutex>

class Items_servidor{
	private:
		std::mutex m;

		std::string ruta_archivo;
		std::string mensaje;
		std::map <std::string, std::string> mapa;
		Parser parseador;

	public:
		explicit Items_servidor(const char* una_ruta);
		/*
		 * Dado el mensaje_nuevo, lo parseará e identificará la operación que
		 * desea el cliente y devolverá la respuesta para esta.
		 */
		std::string modificar_y_procesar_Seguro(std::string & mensaje_nuevo);

		~Items_servidor();
};

#endif /*ITEMS_SERVIDOR_H*/
