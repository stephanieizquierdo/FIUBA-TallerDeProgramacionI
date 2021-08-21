#ifndef ENCRIPTADOR_H
#define ENCRIPTADOR_H

#define TAM_STREAM 256

typedef struct {
	int tipo_encriptacion;
	void* key;
	unsigned char stream[TAM_STREAM];
	int pos_a;
	int pos_b;
} encriptador_t;

/*
 *inicializa la estructura con la clave y método pasados. Se contemplan los
 *métodos: "cesar" "vigenere" o "rc4". Devolverá EXITO(0) en caso de que se
 *haya inicializado o de lo contrario ERROR(-1)
 */
int encriptador_inicializar(encriptador_t* self,
							  const char* metodo,
							  void* key);
/*
 *Encripta el mensaje pasado por parámetro con el método que fue asignado
 *al inicializar la estructura.
 */
int encriptador_encriptar(encriptador_t* self,
							unsigned char* mensaje,
							int cant_leidos);

/*
 *Desencripta el mensaje pasado por parámetro con el método que fue asignado
 *al inicializar la estructura.
 */
int encriptador_desencriptar(encriptador_t* self,
							unsigned char* mensaje,
							int cant_leidos);

/*
 *Cierra el encriptador. Devolverá EXITO(0) en caso de que se haya cerrado
 * o de lo contrario ERROR(-1)
 */
int encriptador_cerrar(encriptador_t* self);

#endif /*ENCRIPTADOR_H*/
