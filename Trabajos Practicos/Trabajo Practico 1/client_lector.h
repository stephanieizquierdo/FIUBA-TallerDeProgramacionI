#ifndef LECTOR_H
#define LECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
	FILE* archivo;
} lector_t;

typedef void (*lector_mensajero_t)(const char *mensaje,
									size_t tamanio,
									void *medio);

typedef void (*lector_seguridad_t)(const char *mensaje,
									int tamanio,
									void *encriptador);
/*
 * Inicializa la estructura
 */
void lector_inicializar(lector_t *self, const char *nombre_archivo);

/*
 * Libera sus recursos si es necesario
 */
void lector_cerrar(lector_t *self);

/*
 * Lee iterando por el archivo que tiene como atributo e invoca a 
 * aplicar_seguridad usando un encriptador y luego llama a enviar_mensaje por 
 * el medio de envio correspondiente
 */
void lector_iterar(lector_t *self,
				lector_mensajero_t enviar_mensaje,
				void *medio,
				lector_seguridad_t aplicar_seguridad,
				void* encriptador);

#endif /*LECTOR_H*/
