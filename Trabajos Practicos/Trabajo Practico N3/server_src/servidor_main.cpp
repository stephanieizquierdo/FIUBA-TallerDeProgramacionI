#include "servidor.h"
#include <iostream>
#include <string>

#define ARGUMENTOS_CORRECTOS 3
#define ERROR_ARGUMENTOS 1
#define ARG_PORT 1
#define ARG_ROOT 2

static void mensaje_de_error_argumentos(){
    printf("La cantidad de argumentos ingresados son incorrectos. ");
    printf("recuerde que es: ./<ejecutable> <puerto> <ruta de archivo>\n");
}

static bool verifica_argumentos(int argc, const char* argv[]){
    bool verifica = true;

    if (argc != ARGUMENTOS_CORRECTOS){
        mensaje_de_error_argumentos();
        verifica = false;
    }
    return verifica;
}

int main(int argc, const char * argv[]){
    if (!verifica_argumentos(argc, argv)){
        return ERROR_ARGUMENTOS;
    }
    try {
        Servidor servidor(argv[ARG_PORT], argv[ARG_ROOT]);
        servidor.correr();
    } catch (std::exception &exc) {
        std::cout << exc.what() << std::endl;
        return 0;
    }

    return 0;
}
