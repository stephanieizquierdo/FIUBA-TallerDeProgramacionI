#ifndef NODO_H
#define NODO_H

#include <vector>
#include <fstream>
#include <string>

class Nodo {
	bool tiene_return;
	std::string instruccion;
	std::vector<int> vecinos;

	public:
		int cant_vecinos;
		explicit Nodo(std::string &una_instruccion);
		~Nodo();

		/*
		 * Agrega al nodo un "vecino", es decir un numero que representa la
		 * posición de otro nodo que posee una conexión con este.
		 */
		void agregar_vecino(int un_numero);

		/*
		 * Devuelve un vector de int que representan el indice de los nodos
		 * vecinos
		 */
		std::vector<int> get_vecinos();

		std::string get_instruccion();
		/*
		 * Settea en true el flag tiene_return.
		 */
		void set_tiene_return();

		bool get_tiene_return();
};

#endif /*NODO_H*/
