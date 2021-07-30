#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <vector>
#include <map>

/*
 * Se encarga de parsear e interpretar instrucciones.
 */
class Parser {
	private: 
		std::vector<std::string> saltos = {"jmp","ja","jeq","jneq","jne",
											"jlt","jle","jgt","jge","jset"};

		std::vector<std::string> lista_instrucciones;

		std::map<std::string, std::size_t> tabla_de_tags;
		/*
		 * Si encuenta un ':' en la instrucción significa que se declaró un tag.
		 * Devuelve la posicion en donde lo encontró o std::string::npos si 
		 * no encontró
		 */
		std::size_t tiene_tag(std::string &instruccion);
		
	public:
		Parser(){}
		~Parser(){}

		/*
		 * Agrega una instruccion(string) en lista_instrucciones
		 */
		void agregar_instruccion(std::string &instruccion);
		/*
		 * Guarda en tabla_de_tags los tags declarados en el archivo y 
		 * los guarda junto con el numero de linea en el cual fue declarado.
 		 */
		void inicializar_tabla();
		/*
		 * Devuelve la posición, respecto de todas las lineas de
		 * "lista_instrucciones", del tag que recibe por parametro.
		 */
		int obtener_posicion_tag(std::string tag);
		/*
		 * Determina si la instrucción es "comun", es decir,
		 * que no posee saltos ni retornos
		 */
		bool es_comun(std::string &instruccion);
		/*
		 * Determina si la instrucción posee un salto. Si lo tiene, se modifica
		 * "ultimapos" con con la posición del ultimo caracter del salto
		 * respecto de la instrucción 
		 */
		bool tiene_salto(std::string &instruccion, int& ultimapos);
		/*
		 * Devuelve la cantidad de comas que posee la instrucción
		 */
		int cant_comas(std::string &instruccion);
		/*
		 * Determina si la instrucción pusee algun return 'ret'
		 */
		bool tiene_return(std::string &instruccion);
		/*
 		 *Recibe un string y lo devuelve sin whitespaces ni comas.
		 */
		std::string limpiar_string(const std::string &linea);
};

#endif /*PARSER_H*/
