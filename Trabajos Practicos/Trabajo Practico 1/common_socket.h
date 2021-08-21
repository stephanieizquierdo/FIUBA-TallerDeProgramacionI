#ifndef SOCKET_H
#define SOCKET_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
	int fd;
} socket_t;


/*
 *Inicializa el socket con un file descriptor inválido
 */
void socket_inicializar(socket_t *self);

/*
 *Hace un shutdown y cierra el socket
 */
void socket_cerrar(socket_t *self);

/*
 *Enlaza y deja en estado de "escuchar" las conexiones 
 *(máximo 7 conexiones en espera)
 */
void socket_bind_and_listen(socket_t *self,
	                        const char *servicio);

/*
 *Acepta una conexión que estaba esperando
 */
int socket_accept(socket_t *self, socket_t *peer);

/*
 *Conecta. Devolverá EXITO(0) si completó sus acciones o de
 *lo contrario ERROR(-1)
 */
int socket_connect(socket_t *self,
					const char *host,
					const char *servicio);

/*
 *Envia una cierta cantidad de bytes. Devolverá EXITO(0) si completó sus
 *acciones o de lo contrario ERROR(-1) 
 */
int socket_enviar(socket_t *self, const char *buffer, size_t length);

/*
 *Recibe cierta cantidad de bytes. Devolverá EXITO(0) si completó sus acciones
 * o de lo contrario ERROR(-1)
 */
int socket_recibir(socket_t *self, char* buffer, size_t tamanio);

#endif /*SOCKET_H*/
