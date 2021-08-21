#ifndef CLIENTE_H
#define CLIENTE_H

#include "common_socket.h"
#include "client_lector.h"
#include "common_encriptador.h"

typedef struct {
	encriptador_t encriptador;
	lector_t* lector;
	socket_t socket;
} cliente_t;

/*
 *Inicializa al cliente con los parámetros recibidos.
 */
int cliente_inicializar(cliente_t* self,
						lector_t* un_lector, 
						char* metodo,
						char* key);
/*
 *El cliente se conectará y enviara mensajes por medio del socket.
 *Devolverá EXITO(0) si completó sus acciones o de lo contrario ERROR(-1)
 */
int cliente_correr(cliente_t* self, char* host, char* server_port);

/*
 *Devolverá EXITO(0) en caso de que se haya cerrado o de lo contrario ERROR(-1)
 */
int cliente_cerrar(cliente_t* self);

#endif /*CLIENTE_H*/
