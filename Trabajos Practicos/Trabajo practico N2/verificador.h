#ifndef VERIFICADOR_H
#define VERIFICADOR_H

#include "repositorio.h"
#include <vector>
#include <string>
#include "procesador_bpf.h"

class Verificador{
	private:
		Repositorio repo_archivos;
		Repositorio repo_resultados;
		int cant_hilos;
		std::vector<Procesador_BPF*> hilos;

	public:
		/*
		 * Recibe un vector de nombre de archivos (validos) e inicializa con estos
		 * el repositorio de archivos. Tambien recibe una cantidad de hilos los 
		 * cuales, en la función "correr", se encargaran de procesar los archivos
		 * y guardar los resultados en el repositorio de resultados.
		 */
		Verificador(std::vector<std::string> &nombres_archivos,
					 const int& cant_hilos);
		~Verificador(){}
		/*
		 * Verificara los archivos que se solicitaron y se imprimirá por
		 * pantalla el estado de cada uno. 
		 */
		void correr();
};

#endif /*VERIFICADOR_H*/
