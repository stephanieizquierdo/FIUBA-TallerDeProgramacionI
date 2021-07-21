#include "aceptador.h"
#include "../common_src/socket.h"
#include "../common_src/socket_error_aceptar.h"

#include "thclient.h"

#include <utility>
#include <algorithm>  
#include <vector>

Aceptador::Aceptador(Socket &un_socket, Items_servidor& items) : 
	socket_listener(un_socket),
	itemsServer(items){}

static void liberar_terminados(std::vector<ThClient*> &clientes){
	std::vector<ThClient*> temp;
    std::vector<ThClient*>::iterator iterador_clientes = clientes.begin();
    while (iterador_clientes != clientes.end()){    
        if ((*iterador_clientes)->is_dead()){
            (*iterador_clientes)->join();   
            delete(*iterador_clientes);
        }else{
            temp.push_back(*iterador_clientes);
        }
        ++iterador_clientes;
    }  
    clientes.swap(temp);
}

void Aceptador::run(){
	bool socket_es_valido = true;
	while (socket_es_valido){
		try{
			Socket peer = this->socket_listener.aceptar();
			clientes.push_back(new ThClient(std::move(peer), this->itemsServer));
			clientes.back()->start();
			liberar_terminados(clientes);
		} catch (SocketErrorAceptar &exc) {
			socket_es_valido = false;
		}
	}
	this->socket_listener.cerrar();
	this->cerrar();
}

void Aceptador::cerrar(){
	for (std::size_t i = 0; i < clientes.size(); i++){
		clientes.at(i)->stop();
        clientes.at(i)->join();    
        delete(clientes.at(i));
    }
}
