#include "cliente.h"
#include <iostream>
#include <string>

#define ARGUMENTOS_CORRECTOS 3

#define ARG_HOST 1
#define ARG_PORT 2

static void mensaje_de_error_argumentos(){
    printf("La cantidad de argumentos ingresados son incorrectos. ");
    printf("recuerde que el uso es: ./<ejecutable> <host> <puerto>\n");
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
        return 0;
    }
     try {
        Cliente cliente(argv[ARG_HOST], argv[ARG_PORT]);
        cliente();
    } catch (std::exception &exc) {
        std::cout << exc.what() << std::endl;
        return 0;
    }
	return 0;
}
