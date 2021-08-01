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

int hex2int(char *hex) {
    int val = 0;
    while (*hex) {
        // get current character then increment
        char byte = *hex++;
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (byte >= '0' && byte <= '9') byte = byte - '0';
        else if (byte >= 'a' && byte <='f') byte = byte - 'a' + 10;
        else if (byte >= 'A' && byte <='F') byte = byte - 'A' + 10;
        // shift 4 to make space for new digit, and add the 4 bits of the new digit
        val = (val << 4) | (byte & 0xF);
    }
    printf("converti: %i",val);
    return val;
}

bool leer_linea(FILE* archivo, long int *pos_lectura, char* numero_hex){
    fseek(archivo, *pos_lectura, SEEK_SET);
    char* ret = fgets(numero_hex, CANT_HEX, archivo);
    *pos_lectura = ftell(archivo);
    return (ret!=NULL);
}

void escribir(FILE* archivo, long int* pos_escritura, int numero){
    char numeroTexto[CANT_HEX];
    sprintf(numeroTexto,"%d",numero);
    printf("OBTUVE: %s", numeroTexto);

    fseek(archivo, *pos_escritura, SEEK_SET);
    fputs(numeroTexto, archivo);
    //fwrite(numeroTexto,sizeof(int),1,archivo);
    *pos_escritura = ftell(archivo);
}

void procesar(FILE* archivo){
    char numero_hex[CANT_HEX];
    long int pos_lectura = 0, pos_escritura = 0, tam_final = 0;
    fseek(archivo, 0, SEEK_END);
    int cantidad_de_caracteres = ftell(archivo);
    printf("CANT BYTES TOTAL: %i \n", cantidad_de_caracteres);
    fseek(archivo, 0, SEEK_SET);
    int leidos = 0;
    while(leidos < cantidad_de_caracteres){
        leer_linea(archivo, &pos_lectura, numero_hex);
        printf("Lei: %s", numero_hex);
        int numero = hex2int(numero_hex);

        escribir(archivo, &pos_escritura, numero);
        leidos+=CANT_HEX;
    }
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
