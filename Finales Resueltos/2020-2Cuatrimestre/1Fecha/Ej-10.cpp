/*
Escriba un programa que reciba por línea de comandos un Puerto y una IP.
El programa debe establecer una unica conexión, quedar en escucha e imprimir
en stdout todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el
programa sin imprimir dicho texto.
*/

//establecer -> cliente

int main( int argc, char* argv[]){
    if(argc != 3){
        printf("Error: cantidad de argumentos invalido\n");
        return -1;
    }
    char* puerto = argv[1];
    char* ip = argv[2];

    struct addrinfo hints;
    struct addrinfo *result, *ptr;

    memset(&hints, 0, sizeof(hints));

    hints->ai_family = AI_INET;
    hints->ai_socktype = AI_SOCKSTREAM;
    hints->ai_flags = 0;

    getaddrinfo(ip, puerto, &hints, result);
    int sock_fd =-1;
    for(ptr = result; ptr; ptr = ptr->ai_next){
        socket_fd = socket(ptr->ai_family, ptr->socketype, ptr->ai_protocol);
        if(socket!= -1) break;
    }
    if(!ptr){
        printf("ERROR\n");
        return -1;
    }
    connect(socket_fd, ptr->ai_addr, ptr->ai_addrlen);
    freeadrrinfo(ptr);

    char final[] = "FINAL";
    char buf;
    salir = false;
    while(!salir){
        ssize_t rec = recv(sock_fd, &buf, sizeof(buf), 0);
        if(rec <= 0){
            salir = true;
        }
        else if(buf == final[i]){
            i++;
            if(i == 3){
                salir = true;
            }
        } else {
            i = 0;
            fwrite(&buf, sizeof(buf), 1, stdout);
        }
    }
    shutdown(sock_fd, SHUT_RDWR);
    close(sock_fd);
    return 0;
}
