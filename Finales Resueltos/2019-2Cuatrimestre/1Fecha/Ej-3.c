/*
 Escribir un programa ISO C que procese el archivo “nros2bytes.dat”
 sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3
*/
 #include <stdio.h>
 #include <stdbool.h>
 #include <string.h>

#define NOMBRE_ARCHIVO "nros2bytes.dat"
#define MODO_APERTURA "r+"

typedef struct nro2bytes{
    char numero[2];
} nro2bytes_t;

int leer_archivo(FILE* archivo, nro2bytes_t* numero, long int* pos_lectura){
    fseek(archivo, *pos_lectura, )
    int bytes_leidos = fread(numero, sizeof(nro2bytes_t), 1, archivo);
    *pos_lectura = ftell(archivo);

    return bytes_leidos;
}

bool es_multiplo_3(char* linea){
    int numero = atoi(linea);
    return (numero%3 == 0)
}

void duplicar(char* linea){
    int numero = atoi(linea);
    numero *= 2;
    linea = itoa(numero);
}

void escribir(FILE* archivo, nro2bytes_t* dato,  long int* pos_escritura){
    fseek(archivo, *pos_lectura, SEEK_SET);
    fwrite(dato, sizeof(nro2bytes_t), 1, archivo);
    *pos_escritura = ftell(archivo);
}

void procesar_archivo(FILE* archivo) {
    long int pos_lectura = 0, pos_escritura = 0;
    nro2bytes_t dato;
    int cant_leido = leer_archivo(archivo, &dato, &pos_lectura);
    while (!eof(archivo)) {
        if(es_multiplo_3(dato.numero)){
            duplicar(dato.numero);
        }
        escribir(archivo, &dato, &pos_escritura);
        cant_leido += leer_archivo(archivo);
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
