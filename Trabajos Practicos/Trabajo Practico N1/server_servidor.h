#ifndef SERVIDOR_H
#define SERVIDOR_H

#include "common_socket.h"
#include "common_encriptador.h"

typedef struct {
	encriptador_t encriptador;
	socket_t socket;
} servidor_t;

/*
 *Inicializa al servidor con los parámetrps recibidos.
 *Devolverá EXITO(0) si se pudo inicializar o de lo contrario ERROR(-1)
 */
int servidor_inicializar(servidor_t* self, char* metodo, char* clave);

/*
 *El servidor se conectará al puerto del servicio y recibirá mensajes.
 *Devolverá EXITO(0) si completó sus acciones o de lo contrario ERROR(-1)
 */
int servidor_correr(servidor_t* self, char* puerto_servicio);

/*
 *Devolverá EXITO(0) en caso de que se haya cerrado o de lo contrario ERROR(-1)
 */
int servidor_cerrar(servidor_t* self);

#endif /*SERVIDOR_HS*/
