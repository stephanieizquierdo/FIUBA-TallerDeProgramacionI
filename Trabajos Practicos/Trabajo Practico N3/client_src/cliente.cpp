#include "cliente.h"
#include <iostream>
#include <fstream>
#include <string>

#define BUFFER_TAM 50
#define ERROR -1

#define SOCKET_CERRADO 0

Cliente::Cliente(const char* host, const char* server_port) : socket(){
	this->socket.conectar(host, server_port);
}

void Cliente::procesar_respuesta_servidor(){
	char buffer[BUFFER_TAM];
    for (int i = 0; i < BUFFER_TAM; i++) {
        buffer[i] = 0;
    }

	bool socket_cerrado = false;
    bool error_al_recibir = false;

    while (!socket_cerrado && !error_al_recibir) {
        int cant_recibida = this->socket.recibir(buffer,BUFFER_TAM);

        if (cant_recibida == ERROR){
            error_al_recibir = true;
        } else if (cant_recibida == SOCKET_CERRADO){
            socket_cerrado = true;
        } else {
            this->mensaje_servidor.write(buffer, cant_recibida);
        }
    }
    if (error_al_recibir) {
        std::cout<<"Error al recibir"<< std::endl;
    }
    std::string mensaje = this->mensaje_servidor.str();
    std::cout<<mensaje<< std::endl;
}

void Cliente::correr(){
	std::string petitorio;

	while (getline(std::cin, petitorio, '\n')) {
		petitorio.push_back('\n');
		this->socket.enviar(petitorio.c_str(), petitorio.size());
    }
    this->socket.apagar_escritura();
    this->procesar_respuesta_servidor();
}

Cliente::~Cliente(){}
