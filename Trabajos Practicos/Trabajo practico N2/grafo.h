#ifndef GRAFO_H
#define GRAFO_H

#include "parser.h"
#include "nodo.h"
#include <vector>
#include <string>

class Grafo {
	public:
		std::vector<Nodo> vertices;
		int cant_aristas;
		int cant_vertices;

		Grafo();
		~Grafo();
		/*
		 * Agrega un vertice (Nodo) con un determinado string.
		 */
		void agregar_vertice(std::string& unstring);

		/*
		 * Itera por los nodos del grafo, los analiza con el parseador y establece las
		 * conexiones entre cada nodo, mediante el criterio de llamadas de código BPF
		 * El orden de la lista del parser coincide con el de los vertices/nodos.
		 */
		void establecer_conexiones(Parser &un_Parseador);
		
		/* 
		 * Devuelve un string con el nombre de archivo más el veredicto que se
		 * obtuvo al buscar ciclos o instrucciones sin usar en dicho archivo
		 */
		std::string analizar_lineas(const std::string & nombre_archivo);

	private:
		/*
		 * La linea es comun, es decir no posee saltos ni retorna, entonces, si
		 * no es la ultima, se conecta con la linea siguiente.
		 * Si es la ultima linea del archivo entonces no se conecta con nada.
		 */
		void conectar_comun(Parser& parseador, const int &actual);
		/*
		 * Al ser una linea con un salto con 1 arg, debe conectarse solo con la
		 * linea donde se definio el tag que se invoca en el primer argumento
		 */
		void conectar_branch_1_argumentos(Parser& parseador,
											std::string& linea,
											const int& ultimapos,
											const int& actual);
		/*
		 * Al tener 2 argumentos entonces debe conectarse con la linea donde 
		 * se declaró el tag o con la siguiente instrucción
		 */
		void conectar_branch_con_2_argumento(Parser& parseador,
											std::string& linea,
											const int &actual);
		/*
		 * Al tener 3 argumentos debe conectarse con la linea donde se declaró el
		 * primer tag (cuyo nombre esta en el segundo argumento) y con la linea
		 * donde se declaró el segundo tag (su nombre está en el tercer argumento)
		 */
		void conectar_branch_con_3_argumentos(Parser& parseador,
											std::string& linea,
											const int &actual);
};

#endif /*GRAFO_H*/
