/*Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer
grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos
decimales (que representen el mismo número leído pero en decimal). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>


#define MAX_LINEA 5
#define NOMBRE_ARCHIVO "numeros.txt"
#define MODO_APERTURA "r+"

bool leer_linea(FILE* archivo, long int* pos_lectura, char* linea){
    fseek(archivo, *pos_lectura, SEEK_SET);
    char* retorno = fgets(linea, MAX_LINEA, archivo);
    *pos_lectura = ftell(archivo);
    return retorno;
}
/*
 * ESTO NO FUNCIONA! deberia leer todos los 4 numeros e ir posicionandolos en las bases, no es lo mismo
 * FFFF que 16+16+16+16 (mi codigo hace esto), es 65535 (esto es lo que debe hacer)
 */
int transformar_hexa_a_dec(char caracter){
    int valor = 0;
    printf("LEI: %c \n", caracter);
    if (caracter >= '0' && caracter <= '9') {
        valor = (int)caracter - 48;
        printf("TRANSFORME: %i\n", valor);
    } else if (caracter >= 'A' && caracter<='F') {
        valor = ((int)caracter) - 55;
        printf("TRANSFORME: %i\n", valor);
    } else if (caracter >= 'a' && caracter <= 'f') {
        valor = (int)caracter - 87;
        printf("TRANSFORME: %i\n", valor);
    }
    return valor;
}
void escribir(FILE* archivo, long int* pos_escritura, int valor){
    fseek(archivo, *pos_escritura, SEEK_SET);
    char str[1000];
    sprintf(str, "%d", valor);
    fwrite(str, sizeof(int), 1, archivo);
    *pos_escritura = ftell(archivo);
}

void procesar(FILE* archivo){
    long int pos_escritura = 0, pos_lectura = 0;
    char linea[MAX_LINEA];
    while(leer_linea(archivo, &pos_lectura, linea)){
        int valor = 0;
        for(int i = 0; i < MAX_LINEA-1; i++){
            valor += transformar_hexa_a_dec(linea[i]);
            printf("ESTOY POR ESCRIBIR: %i \n", valor);
        }
        escribir(archivo, &pos_escritura, valor);
    }
}

int main(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO, MODO_APERTURA);
    if(!archivo){
        printf("error: No existe el archivo \"numeros.txt");
        return 0;
    }
    procesar(archivo);
    fclose(archivo);
}
