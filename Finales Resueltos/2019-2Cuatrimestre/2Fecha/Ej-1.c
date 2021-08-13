/*Escriba un programa (desde la inicialización hasta la liberación de los
 recursos) que reciba paquetes de la forma nnn+nn+....+nnnn=
 (numeros separados por +, seguidos de =) e imprima el resultado de la suma de
 cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse
 ordenadamente. No considere errores.*/

//considero que se recibe un puerto y soy un cliente.

int mian(int argc, char* argv[]){
    if (argc != 2){
        printf("Error cantidad de argumentos\n");
        return -1;
    }

    char* puerto = argv[1];

    struct addrinfo hints;
    struct addrinfo *result, *ptr;

    memset(&hints, NULL, sizeof(struct addrinfo));

    hints->ai_family = AI_INET;
    hints->ai_socktype = AI_SOCKSTREAM;
    hints->ai_flags = 0;

    getaddrinfo(0, puerto, &hints, result);
    int socket_fd = -1;
    for(ptr = result; ptr; ptr = ptr->ai_next){
         socket_fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
         if(socket_fd != -1){
             connect(socket_fd, ptr->ai_addr, ptr->ai_addrlen);
             break;
         }
    }
    


}
