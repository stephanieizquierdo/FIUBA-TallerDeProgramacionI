#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <errno.h>

#include "common_socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define ERROR -1
#define EXITO 0

#define FINALIZADO 0
#define FD_INVALIDO -1

#define MAX_CONECCIONES_ESPERANDO 7

typedef struct addrinfo addrinfo;

/******************* DES/INICIALIZACIONES ********************/
void socket_inicializar(socket_t* socket){
    socket->fd = FD_INVALIDO;
}

void socket_cerrar(socket_t* self){
    shutdown(self->fd, SHUT_RDWR);
    close(self->fd);
}

/******************* ENLAZAR Y ESCUCHAR ***********************/

void socket_bind_and_listen(socket_t* self, const char* servicio){
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
       printf("Error getaddrinfo: %s\n", gai_strerror(errno));
    }

    item_lista = result;

    while (item_lista != NULL && pude_bindear == false) {
        int fd = FD_INVALIDO;
        fd = socket(item_lista->ai_family,
                                item_lista->ai_socktype,
                                item_lista->ai_protocol);
        if (fd == FD_INVALIDO) {
            printf("Error bind_listen funcion socket: %s\n", strerror(errno));
        } else {
            int val = 1;
            setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
            if (bind (fd, item_lista->ai_addr,
                      item_lista->ai_addrlen) == ERROR) {
                printf("Error funcion bind: %s\n", strerror(errno));
                close(fd);
            } else {
                pude_bindear=true;
                self->fd = fd;
            }
        }
       item_lista = item_lista->ai_next;
    }
    freeaddrinfo(result);
    listen(self->fd, MAX_CONECCIONES_ESPERANDO);
}

/********************* ACEPTAR Y CONECTAR **********************/

int socket_accept(socket_t* self, socket_t* peer){
    peer->fd = accept(self->fd, NULL, NULL);
    if (peer->fd == FD_INVALIDO) {
        printf("Error accept: %s\n", strerror(errno));
        return ERROR;
    }
    return EXITO;
}

int socket_connect(socket_t* self,
                     const char* host,
                     const char* servicio){
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
       printf("Error getaddrinfo: %s\n", gai_strerror(errno));
       return ERROR;
    }

    item_lista = result;

    while (item_lista != NULL && pude_conectar == false) {
        int fd = FD_INVALIDO;
        fd = socket(item_lista->ai_family,
                    item_lista->ai_socktype,
                    item_lista->ai_protocol);
        if (fd == FD_INVALIDO) {
            printf("Error en funcion connect_socket: %s\n", strerror(errno));
            close(fd);
        } else {
            estado = connect(fd, item_lista->ai_addr, item_lista->ai_addrlen);
            if (estado != 0) {
                printf("Error en funcion connect: %s\n", strerror(errno));
                close(fd);
            } else {
                pude_conectar = true;
                self->fd = fd;
            }
        }
       item_lista = item_lista->ai_next;
    }
    freeaddrinfo(result);
    if (!pude_conectar) {
        return ERROR;
    }
    return EXITO;
}


/************************ ENVIAR Y RECIBIR ************************/

int socket_enviar(socket_t* peer, const char* buffer, size_t tamanio){
    ssize_t acumulado_enviado = 0;
    ssize_t enviado = 0;
    bool finalizo_envio = false;
    bool hubo_error = false;

    while (acumulado_enviado < tamanio && !finalizo_envio && !hubo_error) {
        enviado = send(peer->fd,
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
        return ERROR;
    } else if (!finalizo_envio) {
        return acumulado_enviado;
    } else {
       return enviado;
    }
}

int socket_recibir(socket_t* self, char* buffer, size_t tamanio){
    if (self->fd == FD_INVALIDO) {
        return ERROR;
    }
    int bytes_recibidos = 0;
    int recibido = recv(self->fd,
                    (void*)&buffer[bytes_recibidos],
                    tamanio - bytes_recibidos,
                    0);
    return recibido;
}
