#ifndef CLIENTE_H
#define CLIENTE_H

#include "../common_src/socket.h"
#include <string>
#include <sstream>

class Cliente{
	private: 
		Socket socket;
		std::stringstream mensaje_servidor;
		
		void correr();

		void procesar_respuesta_servidor();

	public:
		Cliente(const char* host, const char* server_port);

		void operator()() {
            this->correr();
        }
		~Cliente();
};

#endif /*CLIENTE_H*/
