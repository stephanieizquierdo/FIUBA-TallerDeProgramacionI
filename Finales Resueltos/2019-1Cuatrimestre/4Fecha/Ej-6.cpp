/*
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe
aceptar una unica conexión e imprimir en stdout todo lo recibido. Al recibir el texto ‘FIN’ debe
finalizar el programa sin imprimir dicho texto.
*/
//Nos esta pidiendo un servidor;

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Cantidad incorrecta de argumentos\n");
    }
    char* puerto = argv[1];
    char* ip = argv[2];

    struct addrinfo hints;
    struct addrinfo *result, *ptr;

    memset(hints, 0, sizeof(struct addrinfo));
    hints->ai_family = AI_INET;
    hints->ai_flags = AI_PASSIVE;
    hints->ai_socktype = SOCK_STREAM;

    getaddrinfo(NULL, puerto, &hints, &result);
    int socket_fd = -1;
    for(ptr = result; ptr != NULL; ptr = ptr->ai_next){
        socket_fd = socket(ptr->ai_family, ptr->ai_addr, ptr->ai_addrlen);
        if(socket_fd != -1){
            break;
        }
    }
    if(!ptr){
        return -1;
    }
    bind(socket_fd, ptr->ai_addr, ptr->ai_addrlen);
    listen(socket_fd, 1);

    int peerskt = accept(socket_fd, NULL, NULL);
    bool termine = false;
    char buff[1024];
    while (!termine ) {
        ssize_t recibido = recv(peerskt, buff, sizeof(buff), 0)/* code */
        if(recibido<=0){
            termine = true;
        } else if( /*HACER LO DE FIN!!!*/ )
    }

}
