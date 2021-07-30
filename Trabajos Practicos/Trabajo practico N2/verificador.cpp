#include "verificador.h"

Verificador::Verificador(std::vector<std::string> &nombres_archivos,
						 const int& cant_hilos) :
	repo_archivos(nombres_archivos),
	repo_resultados(),
	cant_hilos(cant_hilos){}

void Verificador::correr(){
	for (int i = 0; i < this->cant_hilos; i++) {
		hilos.push_back(new Procesador_BPF(this->repo_archivos,
											this->repo_resultados));
		hilos.back()->start();
	}
	for (int i = 0; i < this->cant_hilos; i++) {
        hilos.at(i)->join();    
        delete(hilos.at(i));
    }
    repo_resultados.imprimir_elementos_ordenadamente();
}
