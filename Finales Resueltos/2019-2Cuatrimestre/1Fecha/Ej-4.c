/*Escribir un programa ISO C que procese el archivo “nros2bytes.dat”
 sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.*/

 #include <stdio.h>
 #include <stdbool.h>
 #include <string.h>

#define NOMBRE_ARCHIVO "nros2bytes.dat"
#define MODO_APERTURA "r+"




void procesar_archivo(FILE* archivo) {
    leer_archivo(archivo);
    while (!eof(archivo)) {
        if(es_multiplo_3()){
            duplicar()
        }
        escribir()
        leer_archivo(archivo);
    }
}

int main(){
    FILE* archivo = fopen(NOMBRE_ARCHIVO, MODO_APERTURA);
    if (!archivo) {
        printf("Error: No existe el archivo %s\n", NOMBRE_ARCHIVO);
        return 0;
    }
    procesar_archivo(archivo);
    return 0;
}
