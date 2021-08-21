#include "client_cliente.h"
#include "common_socket.h"
#include "client_lector.h"
#include "common_encriptador.h"

#define ERROR -1
#define EXITO 0

int cliente_inicializar(cliente_t* self,
                    	lector_t* un_lector,
                   		char* metodo,
                        char* key){
	if(!self || !un_lector || !metodo ||! key){
		return ERROR;
	}
	encriptador_inicializar(&self->encriptador, metodo, key);
	self->lector = un_lector;
	socket_inicializar(&self->socket);
	return EXITO;
}
/************************ CALLBACKS *******************************/
static void _enviar_mensaje(const char *mensaje,
                        size_t tamanio,
                        void *medio) {
    socket_t *socket = medio;
    socket_enviar(socket, mensaje, tamanio);
}

static void _encriptar_mensaje(const char* mensaje,
                            int cant_leidos,
                            void * encriptador){
    encriptador_encriptar((encriptador_t*)encriptador,
                          (unsigned char*) mensaje,
                          cant_leidos);
}
/*******************************************************************/
int cliente_correr(cliente_t* self, char* host, char* server_port){
    if (socket_connect(&self->socket, host, server_port) == ERROR) {
    	return ERROR;
    }

    lector_iterar(self->lector,
                    _enviar_mensaje,
                    &self->socket,
                    _encriptar_mensaje,
                    &self->encriptador);

    return EXITO;
}

int cliente_cerrar(cliente_t* self){
	if (!self) {
		return ERROR;
	}
	encriptador_cerrar(&self->encriptador);
	self->lector = NULL;
    socket_cerrar(&self->socket);
	return EXITO;
}
