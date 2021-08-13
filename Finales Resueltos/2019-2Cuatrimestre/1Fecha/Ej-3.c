/*
 Escribir un programa ISO C que procese el archivo “nros2bytes.dat”
 sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3
*/
 #include <stdio.h>
 #include <stdbool.h>
 #include <string.h>

#define NOMBRE_ARCHIVO "nros2bytes.dat"
#define MODO_APERTURA "r+"

int main(){
    FILE* lectura = fopen(NOMBRE_ARCHIVO, MODO_APERTURA);
    if(!lectura){
        printf("Error en apertura de archivo\n");
        return -1;
    }
    FILE* escritura = fopen("nros_2bytes_bigendian");
    if(!escritura){
        printf("Error en apertura de archivo\n");
        fclose(lectura);
        return -1;
    }
    unit16_t num;
    fread(&num, sizeof(num), 1, lectura);
    while(!feof(lectura)){
        if(num % 3 == 0){
            num = num*2;
        }
        fwrite(&num, sizeof(num), 1, escritura);
        fread(&num, sizeof(num), 1, lectura);
    }
    fclose(escritura);
    fclose(lectura);
    return 0;
}
