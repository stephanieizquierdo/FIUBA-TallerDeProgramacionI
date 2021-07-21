#define _POSIX_C_SOURCE 200112L

#include "socket.h"
#include "socket_error_aceptar.h"
#include "socket_error.h"
#include <string>

#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <cstring>
#include <exception>
#include <utility>
#include <iostream>

#define ERROR -1

#define FINALIZADO 0
#define FD_INVALIDO -1

#define MAX_CONECCIONES_ESPERANDO 10

#define ERROR_ARGUMENTO_INVALIDO 22

Socket::Socket() : filedescriptor(FD_INVALIDO){}

Socket::~Socket(){
	if (this->filedescriptor != FD_INVALIDO) {
		::close(this->filedescriptor);
	}
	this->filedescriptor = FD_INVALIDO;
}

void Socket::cerrar(){
    if (this->filedescriptor != FD_INVALIDO)
        ::shutdown(this->filedescriptor,SHUT_RDWR);
    if (this->filedescriptor != FD_INVALIDO) {
        ::close(this->filedescriptor);
    }
    this->filedescriptor = FD_INVALIDO;
}

void Socket::apagar_escritura(){
    ::shutdown(this->filedescriptor, SHUT_WR);
}

void Socket::apagar_lectura(){
    ::shutdown(this->filedescriptor, SHUT_RD);
}

Socket::Socket(Socket && otro) noexcept : filedescriptor(otro.filedescriptor){
	otro.filedescriptor = FD_INVALIDO;
}

void Socket::bind_and_listen(const char *servicio){
	int estado = ERROR;
    bool pude_bindear = false;

    struct addrinfo hints;
    struct addrinfo *result, * item_lista;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;       
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    estado = getaddrinfo(NULL, servicio, &hints, &result);
    if (estado != 0) {
        std::string texto = "al intentar obtener lista de direcciones: ";
        std::string error_especifico = gai_strerror(errno);
        throw SocketError("Error Socket bind_and_listen, " +
                            texto + error_especifico);
    }
    item_lista = result;

    while (item_lista != NULL && pude_bindear == false) {
        int fd = FD_INVALIDO;
        fd = ::socket(item_lista->ai_family,
                        item_lista->ai_socktype,
                        item_lista->ai_protocol);
        if (fd == FD_INVALIDO) {
            std::string texto = "Error Socket bind_and_listen funcion socket: ";
            std::string error_especifico = strerror(errno);
            throw SocketError(texto + error_especifico);
        } else {
            int val = 1;
            setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
            if (bind (fd, item_lista->ai_addr,
                      item_lista->ai_addrlen) == ERROR) {
                std::string texto = "Error Socket bind_and_listen en bind: ";
                std::string error_especifico = strerror(errno);
                throw SocketError(texto + error_especifico);
            } else {
                pude_bindear = true;
                this->filedescriptor = fd;
            }
        }
       item_lista = item_lista->ai_next;
    }
    if (!pude_bindear) {
        throw SocketError("Error Socket bind_and_listen: no se pudo bindear");
    }
    freeaddrinfo(result);
    estado = listen(this->filedescriptor, MAX_CONECCIONES_ESPERANDO);
    if (estado == ERROR) {
        throw SocketError("Error Socket bind_listen funcion LISTEN");
    }
}

Socket::Socket(int fd) : filedescriptor(fd){} //constructor privado

Socket Socket::aceptar(){
	int fd = ::accept(this->filedescriptor, nullptr, nullptr);
	if (fd == FD_INVALIDO) {
        if (errno == ERROR_ARGUMENTO_INVALIDO) {
            throw SocketErrorAceptar();
        }
        throw SocketError("Error Socket: funcion aceptar.");
    }
	return std::move(Socket(fd));
}

void Socket::conectar(const char *host, const char *servicio){
	int estado = ERROR;
    bool pude_conectar = false;
    
    struct addrinfo hints;
    struct addrinfo *result, *item_lista;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;       
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    estado = getaddrinfo(host, servicio, &hints, &result);
    if (estado != 0) {
        freeaddrinfo(result);
        std::string texto = "Error Socket conectar funcion getaddrinfo: ";
        std::string error_especifico = gai_strerror(errno);
        throw SocketError(texto + error_especifico);
    }

    item_lista = result;

    while (item_lista != NULL && !pude_conectar) {
        int fd = FD_INVALIDO;
        fd = socket(item_lista->ai_family,
                    item_lista->ai_socktype,
                    item_lista->ai_protocol);
        if (fd == FD_INVALIDO) {
            freeaddrinfo(result);
            std::string texto = "Error Socket conectar funcion socket: ";
            std::string error_especifico = strerror(errno);
            throw SocketError(texto + error_especifico);
        } else {
            estado = connect(fd, item_lista->ai_addr, item_lista->ai_addrlen);
            if (estado != 0) {
                freeaddrinfo(result);
                std::string texto = "Error Socket conectar funcion connect: ";
                std::string error_especifico = strerror(errno);
                this->cerrar();
                throw SocketError(texto + error_especifico);
            } else {
                pude_conectar = true;
                this->filedescriptor = fd;
            }
        }
       item_lista = item_lista->ai_next;
    }
    freeaddrinfo(result);

    if (!pude_conectar) {
        throw SocketError("Error Socket conectar.");
    }
}

unsigned int Socket::enviar(const char* buffer, size_t tamanio){
	size_t acumulado_enviado = 0;
    int enviado = 0;
    bool finalizo_envio = false;
    bool hubo_error = false;

    while (acumulado_enviado < tamanio && !finalizo_envio && !hubo_error) {
        enviado = ::send(this->filedescriptor,
                        (void*) &buffer[acumulado_enviado],
                        tamanio - acumulado_enviado,
                        MSG_NOSIGNAL);
        if (enviado == FINALIZADO) {
            finalizo_envio = true;
        } else if (enviado == ERROR) {
            hubo_error = true;
        } else {
            acumulado_enviado += enviado;
        }
    }
    if (hubo_error) {
        throw SocketError("Error Socket enviar");
    } else if (!finalizo_envio) {
        return acumulado_enviado;
    } else {
       return enviado;
    }
}

unsigned int Socket::recibir(char* buffer, size_t tamanio){
	size_t acumulado_recibido = 0;
    bool finalizo = false;
    bool hubo_error = false;

    while (acumulado_recibido < tamanio && !finalizo && !hubo_error) {
	    int recibido = recv(this->filedescriptor,
	                    (void*)&buffer[acumulado_recibido],
	                    tamanio - acumulado_recibido,
	                    0);
    	if (recibido == 0) {
    		finalizo = true;
    	} else if (recibido == ERROR){
    		hubo_error = true;
    	} else {
    		acumulado_recibido += recibido;
    	}
	}
	if (hubo_error) {
		throw SocketError("Error Socket recibir");
	}
	return acumulado_recibido;
}
