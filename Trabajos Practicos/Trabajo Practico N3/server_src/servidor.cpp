#include "servidor.h"

#include "aceptador.h"

#define TERMINAR 'q'

Servidor::Servidor(const char* un_puerto, const char* una_ruta) : 
    puerto(un_puerto), items(una_ruta){}

void Servidor::correr(){
    this->socket.bind_and_listen((this->puerto).c_str());
    Aceptador aceptador(this->socket, this->items);
    aceptador.start();

    char caracter;
    do {
        std::cin >> caracter;
    } while (caracter != TERMINAR); 

    this->socket.cerrar();
    aceptador.join();
}

Servidor::~Servidor(){}
