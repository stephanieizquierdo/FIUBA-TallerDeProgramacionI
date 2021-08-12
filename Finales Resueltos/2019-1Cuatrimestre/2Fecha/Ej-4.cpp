/*
Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer nros
hexadecimales de 4 símbolos y reemplazarlos por su valor decimal (en texto).
*/

//HAY QUE HACER FIXES

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define NOMBRE_ARCHIVO "numeros.txt"
#define MODO "r+"
#define CANT_HEX 5

bool leer_linea(FILE* archivo, long int *pos_lectura, char* numero_hex){
    fseek(archivo, *pos_lectura, SEEK_SET);
    char* ret = fread(numero_hex,sizeof(char),4,archivo);
    *pos_lectura = ftell(archivo);
    return (ret!=NULL);
}

void escribir(FILE* archivo, long int* pos_escritura, int numero){
    char numeroTexto[CANT_HEX];
    sprintf(numeroTexto,"%d",numero);
    fseek(archivo, *pos_escritura, SEEK_SET);
    fwrite(numeroTexto,sizeof(int),1,archivo);
    fwrite("\n", sizeof(char),1,archivo);
    *pos_escritura = ftell(archivo);
}

void procesar(FILE* archivo){
    char numero_hex[CANT_HEX];
    long int pos_lectura = 0, pos_escritura = 0, tam_final = 0;
    int leidos = 0;
    leer_linea(archivo, &pos_lectura, numero_hex);
    while(!feof(archivo)){
        printf("Lei: %s", numero_hex);
        int numero = strtol(numero_hex, NULL, 16);
        char numero_texto[5];
        sprintf(numeroTexto,"%d",numero);
        leer_linea(archivo, &pos_lectura, numero_hex);
    }
    escribir(archivo, &pos_escritura, numero);
    ftruncate(fileno(archivo), sizeof(char)*(leidos));
}

int main(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO, MODO);
    if(!archivo){
        printf("ERROR: No existe el archivo %s", NOMBRE_ARCHIVO);
        return 0;
    }
    procesar(archivo);
    fclose(archivo);
    return 0;
}
