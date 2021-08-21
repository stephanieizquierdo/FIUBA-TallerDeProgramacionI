#include "common_encriptador.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 256

#define ENCRIPTAR 'E'
#define DESENCRIPTAR 'D'

#define CESAR 1
#define VIGENERE 2
#define RC4 3

#define ERROR -1
#define EXITO 0

/*
 * Encripta o desencripta (segun el modo) el mensaje recibido por parametro
 * usando el método cesar
 */
static void cesar(unsigned char* mensaje,
					  int key,
					  int cant_leido,
					  char modo){
	int i = 0;
	if (modo == ENCRIPTAR) {
		while (i < cant_leido) {
			mensaje[i] += key;
        	i ++;
    	}
    } else {
    	while (i < cant_leido) {
	        mensaje[i] -= key;
	        i ++;
    	}
    }
}

/*
 * Encripta o desencripta (segun el modo) el mensaje recibido por parametro
 * usando el método vigenere
 */
static void vigenere(encriptador_t* self,
                          unsigned char* mensaje,
						  int cant_leido,
						  char modo){
	int i= 0;
	if (modo == ENCRIPTAR) {
		while (i < cant_leido) {
			if (self->pos_b == strlen(((const char*)(self->key)))) {
				self->pos_b = 0;
			}
	        mensaje[i] += ((unsigned char*)(self->key))[self->pos_b];
	        i++;
	        self->pos_b ++;
    	}
	} else {
		while (i < cant_leido){
			if (self->pos_b == strlen(((const char*)(self->key)))){
				self->pos_b = 0;
			}
		    mensaje[i] -= ((unsigned char*)(self->key))[self->pos_b];
		    i ++;
		    self->pos_b ++;
    	}
	}
}
/********************************** R C 4 ***********************************/
static void swap(unsigned char* stream, int i, int j) {
    unsigned char tmp = stream[i];
    stream[i] = stream[j];
    stream[j] = tmp;
}
//inicializa la tabla a usar por el metodo rc4
static void rc4_ksa(unsigned char *key, unsigned char* stream) {
    unsigned int j = 0;
    for (unsigned int i = 0; i < TAM_MAX; i++){
        stream[i] = (unsigned char)i;
    }
    for (int f = 0; f < TAM_MAX; f++) {
        j = (j + key[f % strlen((const char*)key)] + stream[f]) % TAM_MAX;
        swap(stream, f, j);
    }
}
//Pseudo-Random Generation Algorithm 
static unsigned char rc4_prga(unsigned char* stream, int* i , int* j) {
    *i = (*i + 1) % TAM_MAX;
    *j = (*j + stream[*i]) % TAM_MAX;

    swap(stream, *i, *j);

    return stream[(stream[*i] + stream[*j]) % TAM_MAX];
}

/*
 * Encripta o desencripta (es el mismo procedimiento en ambos casos)
 * el mensaje recibido por parametro usando el método RC4
 */
static void rc4(encriptador_t* self, unsigned char* mensaje, int cant_leido){
	int i = 0;

	while (i < cant_leido){
		mensaje[i] ^= rc4_prga(self->stream, &self->pos_a, &self->pos_b);
		i++;
	}
}
/******************************************************************************/
int encriptador_inicializar(encriptador_t* self,
							  const char* metodo,
							  void* key){
	self->key = key;
    self->pos_a = 0;
    self->pos_b = 0;

	if (strcmp(metodo, "cesar") == 0) {
		self->tipo_encriptacion = CESAR;

	} else if (strcmp(metodo, "vigenere") == 0) {
		self->tipo_encriptacion = VIGENERE;

	} else if (strcmp(metodo, "rc4") == 0) {
		self->tipo_encriptacion = RC4;
		rc4_ksa(self->key, self->stream);
	} else {
		return ERROR;
	}
	return EXITO;
}

int encriptador_encriptar(encriptador_t* self,
							unsigned char* mensaje,
							int cant_leido){
	if (!self || !mensaje || cant_leido == ERROR){
		return ERROR;
	}
	if (self->tipo_encriptacion == CESAR){
		int key_cesar = atoi(self->key);
		cesar(mensaje, key_cesar, cant_leido, ENCRIPTAR);
	
	} else if (self->tipo_encriptacion == VIGENERE) {
		vigenere(self, mensaje, cant_leido, ENCRIPTAR);
	} else {
		rc4(self, mensaje, cant_leido);
	}
	return EXITO;
}

int encriptador_desencriptar(encriptador_t* self,
							unsigned char* mensaje,
							int cant_leido){
	if (!self || !mensaje || cant_leido < 0){
		return ERROR;
	}
	if (self->tipo_encriptacion == CESAR){
		int key_cesar = atoi(self->key);
		cesar(mensaje, key_cesar, cant_leido, DESENCRIPTAR);
	
	} else if (self->tipo_encriptacion == VIGENERE) {
		vigenere(self, mensaje, cant_leido, DESENCRIPTAR);
	} else {
		rc4(self, mensaje, cant_leido);
	}
	return EXITO;
}

int encriptador_cerrar(encriptador_t* self){
	if(!self){
		return ERROR;
	}
	self->key = NULL;
    self->pos_a = 0;
    self->pos_b = 0;
    self->tipo_encriptacion = 0;
    
    return EXITO;
}
