#ifndef DFS_H
#define DFS_H

#include "grafo.h"
#include <string>
#include <vector>

class DFS{
	private:
		std::vector<bool> visitados;
		const Grafo & graforef;
		bool hay_ciclo;
		bool hay_lineas_sueltas;
			
	public:
		explicit DFS(const Grafo & un_grafo);

		/*
		 * Analiza si el grafo posee ciclos o hay instrucciones sin usar
		 * y devuelve un string con el resultado.
		 */
		std::string analizar();
		~DFS(){}

	private:
		void init();

		void detectar_ciclos_DFS(int una_pos);
		
		void detectar_instrucciones_sin_usar();
		
		void completar_flags_con_dfs();
};

#endif /*DFS_H*/
