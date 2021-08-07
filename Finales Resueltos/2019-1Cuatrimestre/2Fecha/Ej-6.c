/*Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “Este es el final” final -----> Este es el final final*/

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("ERROR: cantidad de argumentos invalidos \n");
        return -1;
    }
    char* str = argv[1];
    char* word = argv[2];

    for(int i = 0; i< strlen(str); i++){
        if(str[i] == word[0]) {
            int j = 1;
            bool es_distinto = false;
            int pos_palabra_str = i+1;
            while(j < strlen(word) && !es_distinto){
                if(str[pos_palabra_str] == word[j]){
                    j++;
                    pos_palabra_str++;
                } else {
                    es_distinto = true;
                }
            }
            if(!es_distinto && str[i+j+1] == ' ') { //OCURRENCIAS DE PALABRAS
                printf("%s ", word);
                printf("%s ", word);
                i += j + 1;
            }
        }
        printf("%c", str[i]);
    }
}
