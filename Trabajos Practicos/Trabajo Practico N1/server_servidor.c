#include "server_servidor.h"
#include "common_socket.h"
#include "common_encriptador.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>

#define ERROR -1
#define EXITO 0

#define SOCKET_CERRADO 0

#define BUF_TAM 40

int servidor_inicializar(servidor_t* self, char* metodo, char* clave){
	if (!self || !metodo  || !clave){
		return ERROR;
	}
	encriptador_inicializar(& self->encriptador, metodo, clave);
	socket_inicializar(& self->socket);
	return EXITO;
}

static void imprimir_por_pantalla(char* buffer, size_t tamanio){
    fwrite(buffer, 1, tamanio, stdout);
}

static int procesar_llamada(socket_t *self,
                       char *buffer,
                       ssize_t tamanio,
                       encriptador_t* encriptador){
    bool socket_cerrado = false;
    bool error_al_recibir = false;

    while (!socket_cerrado && !error_al_recibir){
        int cant_recibida = socket_recibir(self, buffer, tamanio);

        if (cant_recibida == ERROR){
            error_al_recibir = true;
        } else if (cant_recibida == SOCKET_CERRADO){
            socket_cerrado = true;
        } else {
             encriptador_desencriptar(encriptador,
                                      (unsigned char*) buffer,
                                      cant_recibida);
             imprimir_por_pantalla(buffer, cant_recibida);
        }
    }
    if (error_al_recibir){
        return ERROR;
    } else {
        return EXITO;
    }   
}

int servidor_correr(servidor_t* self, char* puerto_servicio){
    socket_bind_and_listen(&(self->socket), puerto_servicio);

    socket_t peer;
    socket_inicializar(&peer);

    int estado = socket_accept(&(self->socket), &peer);
    if (estado == ERROR){
        socket_cerrar(&peer);
        return ERROR;
    }
    char buffer[BUF_TAM];
    for (int i = 0; i < BUF_TAM; i++) {
        buffer[i] = 0;
    }
    estado = procesar_llamada(&peer, buffer, BUF_TAM-1, &(self->encriptador));

    socket_cerrar(&peer);
    return estado;
}

int servidor_cerrar(servidor_t* self){
	if (!self) {
		return ERROR;
	}
    encriptador_cerrar(& self->encriptador);
	socket_cerrar(& self->socket);
	return EXITO;
}
