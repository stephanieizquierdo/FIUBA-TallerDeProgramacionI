#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LINEA 1024

bool leer_linea(FILE* archivo, long int* pos_lectura, char* linea){
    fseek(archivo, *pos_lectura, SEEK_SET);
    char* retorno = fgets(linea, MAX_LINEA, archivo);
    *pos_lectura = ftell(archivo);
    return (retorno);
}

bool es_mas_de_una_palabra(char* linea){
    int i = 0;
    bool encontre = false;
    while(i < strlen(linea) && !encontre){
        char caracter = linea[i];
        if(caracter == ' '){
            encontre = true;  //Encontro un espacio, entonces hay mas de una palabra.
        }
        i++;
    }
    return encontre;
}

void escribir_linea(FILE* archivo, long int* pos_escritura, char* linea){
    fseek(archivo, *pos_escritura, SEEK_SET);
    fputs(linea, archivo);
    *pos_escritura = ftell(archivo);
}

void procesar(FILE *archivo){
    long int pos_lectura = 0, pos_escritura = 0;
    char linea[MAX_LINEA];
    long int tam_final = 0;
    while(leer_linea(archivo, &pos_lectura, linea)){
        if(es_mas_de_una_palabra(linea)){
            escribir_linea(archivo, &pos_escritura, linea);
            tam_final+=strlen(linea);
        }
    }
    ftruncate(fileno(archivo), sizeof(char)*(tam_final));
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("error: cantidad de argumentos invalida");
        return 0;
    }
    FILE* archivo = fopen(argv[1], "r+");
    if(!archivo){
        printf("error: el archivo no existe");
        return 0;
    }
    procesar(archivo);
    fclose(archivo);
    return 0;
}
