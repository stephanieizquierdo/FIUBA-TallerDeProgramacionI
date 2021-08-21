#include <stdio.h>
#include "client_lector.h"

#define BUFFER_TAM 50
#define MODO_LECTURA "rb"

void lector_inicializar(lector_t *self, const char *nombre_archivo) {
	if (nombre_archivo) {
		FILE* un_archivo = fopen(nombre_archivo, MODO_LECTURA);
		self->archivo = un_archivo;
	} else {
		self->archivo = stdin;
	}
}

void lector_cerrar(lector_t *self) {
	if (self->archivo != stdin) {
		fclose(self->archivo);
	}
}

void lector_iterar(lector_t *self,
	                    lector_mensajero_t enviar_mensaje,
	                    void *medio,
						lector_seguridad_t aplicar_seguridad,
						void* encriptador) {
	char buffer[BUFFER_TAM];

	while (!feof(self->archivo)) {
		size_t result = fread(buffer, 1, BUFFER_TAM, self->archivo);
		aplicar_seguridad(buffer, result, encriptador);
		enviar_mensaje(buffer, result, medio);
	}
}
