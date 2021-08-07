/*Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe aceptar una única conexión e imprimir en stdout la sumatoria de los enteros recibidos
en cada paquete. Un paquete está definido como una sucesión de números recibidos como
texto, en decimal, separados por comas y terminado con un signo igual (ej: “27,12,32=”). Al
recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.*/

    //PIDE UN SERVIDOR!!
#include <stdio.h>

#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netdb.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define CONEXIONES_EN_COLA 1
#define CANT_COMANDOS_CORRECTOS 3
#define ERROR -1


int main(int argc, char* argv[]){
    if(argc != CANT_COMANDOS_CORRECTOS){
        return ERROR;
    }
    char* puerto = argv[1];
    char* host = argv[2];

    struct addrinfo hints;
    struct addrinfo *result, *ptr;

    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hits.ai_flags = AI_PASSIVE;
    if(getaddrinfo(host, puerto, &hints, &result) < 0){
        printf("Error");
        return ERROR;
    }

    for(ptr = result, ptr != NULL, ptr = ptr->ai_next) {
        int socket_fd = socket(result->ai.family, result->ai_socktype, result -> ai_protocol);
        if(socket_fd != -1){
            break;
        }
    }
    if(!ptr){
        return ERROR;
    }
    bind(socket_fd, ptr->ai_addr, ptr->ai_addrlen)
    listen(socket_fd, CONEXIONES_EN_COLA);

    int peerskt = accept(socket_fd, NULL, NULL);

    /*Un paquete está definido como una sucesión de números recibidos como
    texto, en decimal, separados por comas y terminado con un signo igual (ej: “27,12,32=”). Al
    recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos*/
    bool salir = false, termine = false;
    int resultado = 0;
    char buf;
    while (!salir && !termine){
        lei = recv(peerskt, buffer, sizeof(buf), 0);
        if (lei <= 0){
            salir = true;
        }
        if(buf == '=' || buf == 'F'){
            termine = true;
        } else if (buf != '+'){
            resultado += buf;
        }
    }
    printf("El resultado es: %i\n", resultado);
    //liberaciones
    shutdown(peerskt, SHUT_RDWR);
    shutdown(socket_fd, SUT_RDWR);
    close(socket_fd);
    close(peerskt);
    freeadrrinfo(ptr);

    return 0;
}
