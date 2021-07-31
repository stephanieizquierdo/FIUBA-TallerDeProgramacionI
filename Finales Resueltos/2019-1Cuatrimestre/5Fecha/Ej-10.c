/*Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CANT_CORRECTA_COMANDOS 3
#define ERROR -1

void procesar(char* primer_string, char* segundo_string){
    if(strcmp(primer_string, segundo_string)==0){ //caso en el que el primer string es identico al segundo
        printf("%s %s", segundo_string, segundo_string);
        return;
    }
    int largo_2do_string = strlen(segundo_string);
    char* ret = strstr(primer_string, segundo_string);
    if(!ret){ //caso en el que no hay apariciones del segundo en el primero
        printf("%s", primer_string);
        return;
    }
    for(int i = 0; i < strlen(primer_string); i++){
        bool es_distinto = true;
        int j = i, pos_2_actual = 0;
        if(primer_string[j] == segundo_string[pos_2_actual]){
            es_distinto = false;
            j++;
            pos_2_actual++;
            while(!es_distinto && pos_2_actual<strlen(segundo_string)){
                if(primer_string[j] != segundo_string[pos_2_actual]){
                    es_distinto = true;
                }
                j++;
                pos_2_actual++;
            }
            if(!es_distinto && (j-i) == strlen(segundo_string)){
                printf("%s %s", segundo_string, segundo_string);
                i += strlen(segundo_string);
            }
        }
        printf("%c", primer_string[i]);
    }
}


int main(int argc, char* argv[]){
    if (argc != CANT_CORRECTA_COMANDOS){
        printf("\nError: cantidad incorrecta de comandos\n");
        return ERROR;
    }
    char* primer_string = argv[1];
    char* segundo_string = argv[2];
    procesar(primer_string, segundo_string);
    return 0;
}
