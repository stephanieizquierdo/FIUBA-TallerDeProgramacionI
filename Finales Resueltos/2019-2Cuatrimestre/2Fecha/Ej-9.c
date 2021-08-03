/*Escribir un programa ISO C que procese el archivo de enteros de 2 bytes
 bigendian cuyo nombre es recibido como parámetro. El procesamiento
 consiste en eliminar los número múltiplos de 3, trabajando sobre el
 mismo archivo (sin archivos intermedios ni en memoria).*/


procesar_archivo(FILE* archivo){
    leer();
    while(!eof(archivo)){

    }
}

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Error: parametros incorrectos\n");
        return 0;
    }
    FILE* archivo = fopen(argv[1], "r+");
    if(!archivo){
        printf("Error: no existe archivo \n");
        return 0;
    }
    procesar_archivo(archivo);
    return 0;
}
