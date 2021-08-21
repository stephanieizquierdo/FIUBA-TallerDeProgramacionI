#include <stdio.h>
#include <string.h>

#include "server_servidor.h"
#include "common_socket.h"
#include "common_encriptador.h"

#define ERROR -1

#define ARGUMENTOS_CORRETOS 4

#define ARG_PUERTO 1
#define ARG_METODO 2
#define DESFASAJE_METODO 9
#define ARG_CLAVE 3
#define DESFASAJE_CLAVE 6

#define TAMANIO_MAX 100

#define CESAR "cesar"
#define VIGENERE "vigenere"
#define RC4 "rc4"

static void mensaje_error_argumentos(){
    printf("La cantidad de argumentos ingresados son incorrectos. ");
    printf("Vuelva a intentar.\n");
}

static void mensaje_error_metodos(){
    printf("El metodo introducido es incorrecto. ");
    printf("Pruebe con cesar, vigenere o rc4.\n");
}

static void mensaje_error_servidor(){
    printf("Ocurrio un error mientras se ejecutaba el servidor.\n");
}

static bool verifica_argumentos(int argc, char* argv[]){
    bool verifica = false;

    if (argc != ARGUMENTOS_CORRETOS) {
        mensaje_error_argumentos();
    } else if (strcmp(argv[ARG_METODO] + DESFASAJE_METODO, CESAR) != 0
              && strcmp(argv[ARG_METODO] + DESFASAJE_METODO , VIGENERE)!=0
              && strcmp(argv[ARG_METODO] + DESFASAJE_METODO, RC4)!= 0) {
        mensaje_error_metodos();
    } else {
        verifica = true;
    }
    return verifica;
}
/*
 * Inicializa el puerto del servicio, metodo y
 * clave con los argumentos correspondientes
 */
static void recepcionar_argumentos(char* argv[],
                                    char* puerto_servicio,
                                    char* metodo,
                                    char* clave){
    strncpy(puerto_servicio, argv[ARG_PUERTO], TAMANIO_MAX);
    strncpy(metodo, argv[ARG_METODO] + DESFASAJE_METODO, TAMANIO_MAX);
    strncpy(clave, argv[ARG_CLAVE] + DESFASAJE_CLAVE, TAMANIO_MAX);
}


int main(int argc, char *argv[]){
    if (!verifica_argumentos(argc, argv)) {
        return 0;
    }

    char puerto_servicio[TAMANIO_MAX];
    char metodo[TAMANIO_MAX];
    char clave[TAMANIO_MAX];

    recepcionar_argumentos(argv, puerto_servicio, metodo, clave);

    servidor_t servidor;

    servidor_inicializar(&servidor, metodo, clave);

    if (servidor_correr(&servidor, puerto_servicio) == ERROR) {
        mensaje_error_servidor();
    }
    
    servidor_cerrar(&servidor);

    return 0;
}
