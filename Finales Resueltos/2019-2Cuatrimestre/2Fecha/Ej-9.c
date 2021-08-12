/*Escribir un programa ISO C que procese el archivo de enteros de 2 bytes
 bigendian cuyo nombre es recibido como parámetro. El procesamiento
 consiste en eliminar los número múltiplos de 3, trabajando sobre el
 mismo archivo (sin archivos intermedios ni en memoria).*/

//eliminar -> voy a tener menos que el original

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Error: parametros incorrectos\n");
        return 0;
    }
    FILE* archivo_lectura = fopen(argv[1], "r");
    FILE* archivo_escritura = fopen(argv[1], "r+");
    if(!archivo_lectura){
        printf("Error: no existe archivo \n");
        return 0;
    }
    short num;
    short auxiliar;
    fread(&num, sizeof(short), 1, archivo_lectura);
    int tam = 0;
    while(!feof(archivo_lectura)){
        num = hton(num);
        if(!(num%3==0){ //si no es multiplo de 3 lo escribo
            fwrite(&num, sizeof(short), 1, archivo_escritura);
            tam++;
        }
        fread(&num, sizeof(short), 1, archivo_lectura);
    }
    rewind(archivo_escritura);
    ftruncate(fileno(archivo_escritura), tam*sizeof(short));

    fclose(archivo_escritura);
    fclose(archivo_lectura);

    return 0;
}
