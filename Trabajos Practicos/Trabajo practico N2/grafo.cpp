#include "grafo.h"
#include "nodo.h"
#include "parser.h"
#include "DFS.h"

#include <vector>
#include <iostream>

#define COMA ','

Grafo::Grafo() : cant_aristas(0), cant_vertices(0){}
Grafo::~Grafo(){}

void Grafo::agregar_vertice(std::string& unstring){
	Nodo nuevo_nodo = Nodo(unstring);
	(this->vertices).push_back(nuevo_nodo);
	this->cant_vertices += 1;
}

std::string Grafo::analizar_lineas(const std::string & nombre_archivo){
	DFS un_dfs = DFS(*this);
	return nombre_archivo + un_dfs.analizar();
}

void Grafo::establecer_conexiones(Parser& parseador){
	for (int i = 0; i < this->cant_vertices; i++) {
		std::string linea = (this->vertices.at(i)).get_instruccion();
		int ultimapos = 0;
		if (parseador.es_comun(linea)) {
			conectar_comun(parseador,i);
		} else if (parseador.tiene_salto(linea, ultimapos)) {
			int cant_comas = parseador.cant_comas(linea);
			if (cant_comas == 0) {		
				conectar_branch_1_argumentos(parseador, linea, ultimapos, i);
			} else if (cant_comas == 1) {
				conectar_branch_con_2_argumento(parseador, linea, i);
			} else {
				conectar_branch_con_3_argumentos(parseador, linea, i);
			}
		} else {
			this->vertices.at(i).set_tiene_return();
		}
	}
}

void Grafo::conectar_comun(Parser& parseador, const int &actual){
	if (actual + 1 < this->cant_vertices) {
		(this->vertices.at(actual)).agregar_vecino(actual + 1);
		this->cant_aristas += 1;
	}		
}

void Grafo::conectar_branch_1_argumentos(Parser& parseador,
									std::string& linea,
									const int &ultimapos,
									const int &actual){
	std::string tag_en_linea = linea.substr(ultimapos);
	tag_en_linea = parseador.limpiar_string(tag_en_linea);			
	int pos_tag = parseador.obtener_posicion_tag(tag_en_linea);

	(this->vertices.at(actual)).agregar_vecino(pos_tag);
	this->cant_aristas += 1;
}

void Grafo::conectar_branch_con_2_argumento(Parser& parseador,
											std::string& linea,
											const int& actual){
	int pos_coma = linea.find(COMA);
	std::string tag_en_linea = linea.substr(pos_coma + 1);
	tag_en_linea = parseador.limpiar_string(tag_en_linea);
	int pos_tag = parseador.obtener_posicion_tag(tag_en_linea);

	(this->vertices.at(actual)).agregar_vecino(pos_tag);
	(this->vertices.at(actual)).agregar_vecino(actual + 1);

	this->cant_aristas += 2;
}

void Grafo::conectar_branch_con_3_argumentos(Parser& parseador,
									 std::string& linea,
									 const int &actual){
	int pos_coma1 = linea.find(COMA);
	int pos_coma2 = linea.rfind(COMA);

	std::string primer_tag = linea.substr(pos_coma1 + 1, pos_coma2 - 1);
	primer_tag = parseador.limpiar_string(primer_tag);
	int pos_primer_tag = parseador.obtener_posicion_tag(primer_tag);

	(this->vertices.at(actual)).agregar_vecino(pos_primer_tag);

	std::string segundo_tag = linea.substr(pos_coma2 + 1);
	segundo_tag = parseador.limpiar_string(segundo_tag);
	int pos_segundo_tag = parseador.obtener_posicion_tag(segundo_tag);

	(this->vertices.at(actual)).agregar_vecino(pos_segundo_tag);

	this->cant_aristas += 2;
}
