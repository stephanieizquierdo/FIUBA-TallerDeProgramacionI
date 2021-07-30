#include "procesador_bpf.h"

#include <fstream>
#include <string>
#include "grafo.h"
#include "parser.h"


Procesador_BPF::Procesador_BPF(Repositorio & unos_archivos,
						Repositorio & unos_resultados) :
						archivos(unos_archivos), resultados(unos_resultados),
						puedo_procesar(true){}

void Procesador_BPF::run(){
	while (this->puedo_procesar) {
		try {
			std::string nombre_arch = this->archivos.obtener_elemento_si_tiene();
			Grafo grafo;
			Parser parseador;
			
			std::ifstream archivo(nombre_arch);
			std::string linea;
			while (std::getline(archivo, linea, '\n')) {
				if (linea != "\0") {
					parseador.agregar_instruccion(linea);
					grafo.agregar_vertice(linea);
				}
			}
			archivo.close();

			parseador.inicializar_tabla();
			grafo.establecer_conexiones(parseador);
			std::string un_resultado = grafo.analizar_lineas(nombre_arch);
			this->resultados.agregar_elemento(un_resultado);
		} catch(...) {
			this->puedo_procesar = false;
		}	
	}
}

Procesador_BPF::~Procesador_BPF(){
	this->join();
}
