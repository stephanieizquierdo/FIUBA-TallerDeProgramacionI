/*Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1
por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a
memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.
*/
#include <stdio.h>
#include <unistd.h>

void procesar(FILE* lectura, FILE* escritura){
    char buf = fgetc(lectura);
    int contador = 0;
    while(!feof(lectura)){
        while(buf != ' ' && buf != '\n' && !feof(lectura)){
            contador++;
            fputc(buf, escritura);
            buf = fgetc(lectura);
        }
        if(contador > 3){
            fseek(escritura, -contador, SEEK_CUR);
        } else {
            fputc(buf, escritura);
        }
        contador = 0;
        buf = fgetc(lectura);
    }
    int cant_total_bytes = ftell(escritura);

    rewind(escritura);
    ftruncate(fileno(escritura), cant_total_bytes-1);
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf(" ERROR: cantidad de argumentos erronea\n");
        return -1;
    }
    FILE* lectura = fopen(argv[1], "r");
    FILE* escritura = fopen(argv[1], "r+");
    if (!lectura || !escritura) {
        printf("ERROR al abrir el archivo\n");
        return -1;
    }
    procesar(lectura, escritura);
    fclose(lectura);
    fclose(escritura);

    return 0;
}
