/*
 Escriba una función ISO C que permita procesar sobre sí mismo
 (sin generar archivos intermedios ni cargar el archivo completo a memoria)
 un archivo texto con palabras separadas por espacios. El procesamiento
 consiste en duplicar las palabras que tengan al menos de 2 vocales.
*/

//expasion  de archivo.
//en el peor de los casos voy a tener todos las palabras debe nser duplicadas.

int main(int argc, char* argv[]){
    FILE* lectura = fopen(argv[1], "r");
    FILE* escritura = fopen(argv[1], "r+");

    //veo el tamaño para duplicado
    int tamanio;
    feek(escritura, 0, SEEK_END);
    tamanio =  ftell(escritura);
    int i = 0;
    char aux;
    while(i < tamanio && !feof(lectura)){
        fread(aux, sizeof(char), 1, lectura);
        fwrite(aux, sizeof(char), 1 , escritura);
        i++;
    }
    rewind(escritura);
    fseek(lectura, -tamanio, SEEK_END);
    fread(aux, sizeof(aux), 1, lectura);
    while (!feof(lectura)) {
        if(aux != ' '){
            int vocales = 0, letras = 1;
            while(aux != ' ' || aux != '\n' || feof(archivo)){
                if(aux == 'a' || aux == 'e' || aux == 'i' || aux == 'o' || aux == 'u' || aux =='A' || aux == 'E' || aux == 'I' ||aux =='O' || aux == 'U'){
                    vocales++;
                }
                letras++;
                fwrite(aux, sizeof(aux), 1, escritura);
                fread(aux, sizeof(aux), 1, lectura);
            }
            if(contador >= 2){ //duplico. Vuevlvo el contador al comienzo de la palabra para releerla y volverla a escribir
                fseek(lectura, -(letras+1), SEEK_CUR);
                for(int i = 0; i < letras; i++){
                    fwrite(aux, sizeof(aux), 1, escritura);
                }
            }
        }
        fread(aux, sizeof(aux), 1, lectura);
    }
    long int pos = ftell(escritura);
    ftruncate(fileno(escritura), sizeof(char)*pos);
    fclose(escritura);
    fclose(lectura);
    return 0;
}
