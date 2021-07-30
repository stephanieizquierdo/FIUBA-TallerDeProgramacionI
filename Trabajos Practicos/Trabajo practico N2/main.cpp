#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "verificador.h"
#define CANT_ARG_MINIMO 2

#define ARG_HILOS 1
#define ARG_INICIAL_ARCHIVOS 2

static bool verifica_argumentos(int argc){
	bool verificacion = false;
	if (argc < CANT_ARG_MINIMO) {
		std::cout<<"La cantidad de argumentos ingresados son incorrectos."<<std::endl;
		std::cout<<"Use: ./<ejecutable> <cant hilos> <archivo1> ..."<<std::endl;
	} else {
		verificacion = true;
	}
	return verificacion;
}

static void inicializar_vector_con_archivos_validos
			(std::vector<std::string> &vector, int argc, char* argv[]){
	for (int i = ARG_INICIAL_ARCHIVOS; i < argc; i ++) {
		std::ifstream archivo(argv[i]);
		if (!archivo) {
			std::cout<<"No se pudo abrir el archivo: "<<argv[i]<<std::endl;
		} else {
			archivo.close();
			vector.push_back(argv[i]);
		}
	}
}

int main(int argc, char* argv[]){
	if (!verifica_argumentos(argc)) {
		return 0;
	}
	int cant_hilos = std::stoi(argv[ARG_HILOS]);

	std::vector<std::string> nombres_archivos;
	inicializar_vector_con_archivos_validos(nombres_archivos, argc, argv);

	Verificador un_verificador(nombres_archivos, cant_hilos);

	un_verificador.correr();

	return 0;
}
