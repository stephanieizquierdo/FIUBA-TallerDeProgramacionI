#ifndef REPOSITORIO_H
#define REPOSITORIO_H

#include <vector>
#include <string>
#include <mutex>

class Repositorio{
	private:
		std::vector<std::string> elementos;
		std::mutex m;

	public:
		explicit Repositorio(const std::vector<std::string> &nombres);
		Repositorio();

		std::string obtener_elemento_si_tiene();
		void agregar_elemento(std::string un_resultado);
		
		void imprimir_elementos_ordenadamente();

		~Repositorio(){}
};

#endif /*REPOSITORIO_H*/
