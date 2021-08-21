#include <stdio.h>
#include <string.h>

#include "client_cliente.h"
#include "common_socket.h"
#include "client_lector.h"
#include "common_encriptador.h"

#define ARGUMENTOS_CORRECTOS 5

#define ARG_HOST 1
#define ARG_PORT 2
#define ARG_METODO 3
#define DESFASAJE_METODO 9
#define ARG_KEY 4
#define DESFASAJE_KEY 6
#define ARG_FILE 5

#define TAMANIO_MAX 100

#define CESAR "cesar"
#define VIGENERE "vigenere"
#define RC4 "rc4"

#define ERROR -1
#define EXITO 0


static void mensaje_de_error_argumentos(){
    printf("La cantidad de argumentos ingresados son incorrectos. ");
    printf("Vuelva a intentar.\n");
}

static void mensaje_error_metodos(){
    printf("El metodo introducido es incorrecto. ");
    printf("Pruebe con cesar, vigenere o rc4.\n");
}

static void mensaje_error_cliente(){
    printf("Ocurrio un error mientras se ejecutaba el cliente.\n");
}

static bool verifica_argumentos(int argc, char* argv[]){
    bool verifica = false;

    if (argc != ARGUMENTOS_CORRECTOS) {
        mensaje_de_error_argumentos();
    } else if (strcmp(argv[ARG_METODO] + DESFASAJE_METODO, CESAR) != 0
              && strcmp(argv[ARG_METODO] + DESFASAJE_METODO , VIGENERE)!=0
              && strcmp(argv[ARG_METODO] + DESFASAJE_METODO, RC4)!= 0){
        mensaje_error_metodos();
    } else {
        verifica = true;
    }
    return verifica;
}
/*
 * Inicializa el host, puerto del servicio, metodo y
 * clave con los argumentos correspondientes
 */
static void recepcionar_argumentos(char* argv[],
                                    char* host,
                                    char* server_port,
                                    char* metodo,
                                    char* key){
    strncpy(host, argv[ARG_HOST], TAMANIO_MAX);
    strncpy(server_port, argv[ARG_PORT], TAMANIO_MAX);
    strncpy(metodo, argv[ARG_METODO] + DESFASAJE_METODO, TAMANIO_MAX);
    strncpy(key, argv[ARG_KEY] + DESFASAJE_KEY, TAMANIO_MAX);
}

static void inicializar(cliente_t* cliente,
                        lector_t* lector,
                        char* archivo,
                        char* metodo,
                        char* key){
    lector_inicializar(lector, archivo);
    cliente_inicializar(cliente, lector, metodo, key);
}

static void cerrar(cliente_t* cliente, lector_t* lector){
    lector_cerrar(lector);
    cliente_cerrar(cliente);
}

int main(int argc, char *argv[]){
    if (!verifica_argumentos(argc, argv)) {
        return 0;
    }

    char host[TAMANIO_MAX];
    char server_port[TAMANIO_MAX];
    char metodo[TAMANIO_MAX];
    char key[TAMANIO_MAX];

    recepcionar_argumentos(argv, host, server_port, metodo, key);

    lector_t lector;
    cliente_t cliente;
    
    inicializar(&cliente, &lector, argv[ARG_FILE], metodo, key);
    
    if (cliente_correr(&cliente, host, server_port) == ERROR) {
        mensaje_error_cliente();
    }

    cerrar(&cliente, &lector);

    return 0;
}
