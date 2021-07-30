#include "DFS.h"
#include <iostream>
#include <string>
#include <vector>
#include "nodo.h"

#define MENSAJE_CICLOS " FAIL: cycle detected"
#define MENSAJE_LINEAS_SUELTAS " FAIL: unused instructions detected"
#define MENSAJE_TODO_OK " GOOD"

DFS::DFS(const Grafo & un_grafo) :
		graforef(un_grafo),
		hay_ciclo(false),
		hay_lineas_sueltas(false){}

void DFS::init() {
    this->visitados.assign(graforef.cant_vertices, false);
}

void DFS::detectar_ciclos_DFS(int una_pos) {
	if (hay_ciclo) {
		return;
	}
    this->visitados.at(una_pos) = true;

    Nodo un_nodo = graforef.vertices.at(una_pos);
	std::vector<int> vecinos = un_nodo.get_vecinos();

    for (int i = 0; i < un_nodo.cant_vecinos; i++) {
    	Nodo nodo_vecino = graforef.vertices.at(vecinos.at(i));

        if (!this->visitados.at(vecinos.at(i))) {
        	detectar_ciclos_DFS(vecinos.at(i));
        } else if (this->visitados.at(vecinos.at(i)) &&
        			!nodo_vecino.get_tiene_return()) {        
            hay_ciclo = true;
        }
    }
}

void DFS::detectar_instrucciones_sin_usar(){
	unsigned int i = 0;
	while (i < this->visitados.size() && !hay_lineas_sueltas) {
		if (!this->visitados.at(i)) {
			hay_lineas_sueltas = true;
		}
		i++;
	}
}

void DFS::completar_flags_con_dfs(){
	this->init();
	int comienzo = 0;
	this->detectar_ciclos_DFS(comienzo);
	this->detectar_instrucciones_sin_usar();
}

std::string DFS::analizar(){
	this->completar_flags_con_dfs();
	if (hay_ciclo) {
		return MENSAJE_CICLOS;
	} else if (hay_lineas_sueltas) {
		return MENSAJE_LINEAS_SUELTAS;
	} else {
		return MENSAJE_TODO_OK;
	}
}
