/*Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat”
 sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando los impares.*/

//INTERPRETO DEL ENUNCIADO QUE SE TRIPLICA EL NUMERO, NO QUE SE TIENE QUE ESCRIBIR TRES VECES EL NUMERO
 int main(){
     FILE* lectura = fopen("bigEndian.dat");
     FILE* escritura = fopen("bigEndian.dat");

    unit32_t aux;

    fread(aux, sizeof(aux), 1, lectura);
    while(!feof(lectura)){
        if(aux%2 == 1){ //es impar
            aux = aux*3; //triplico
        }
        fwrite(aux, sizeof(aux), 1, escritura); //escribo
        fread(aux, sizeof(aux) 1,lectura);
    }
    fclose(lectura);
    fclose(escritura);
    return 0;
 }
