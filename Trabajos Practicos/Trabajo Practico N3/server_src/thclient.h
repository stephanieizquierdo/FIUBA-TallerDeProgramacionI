#ifndef THCLIENT_H
#define THCLIENT_H

#include <sstream>
#include <atomic>

#include "thread.h"
#include "../common_src/socket.h"
#include "items_servidor.h"

class ThClient : public Thread{
	private:
		std::stringstream mensaje_cliente;
		Socket socket;
		Items_servidor & itemsServer;
		
		std::atomic<bool> keep_talking;
		std::atomic<bool> is_running;
		void procesar_pedido();
		
	public: 
		ThClient(Socket un_socket, Items_servidor & items);
		/*
		 * Atiende a un cliente. Procesa su pedido y le responde.
		 */
		void run() override;
		/*
		 * Indica si ya terminó de atenderse
		 */
		bool is_dead();
		/*
		 * corta con el proceso.
		 */
		void stop();
		~ThClient();
};

#endif /*THCLIENT_H*/
