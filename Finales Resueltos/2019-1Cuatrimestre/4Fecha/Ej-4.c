/*Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat”
 sobre sí mismo, eliminando los número múltiplos de 7.
*/

int main(){
    FILE* lectura = fopen("nros_2bytes_bigendian");
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
    short num;
    fread(num, sizeof(num), 1, lectura);
    while(!feof(lectura)){
        if(num%7 != 0){
            fwrite(num, sizeof(num), 1, escritura);
        }
        fread(num, sizeof(num), 1, lectura);
    }
    fclose(lectura);
    long int pos_final = ftell(escritura);

    ftruncate(escritura, pos_final);
    fclose(escritura);

    return 0;
}
