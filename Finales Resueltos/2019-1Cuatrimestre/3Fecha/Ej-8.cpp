/*Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de la forma [nnn+nn+….+nnnn] (numeros separados por +, encerrados entre
corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un
paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.*/

//NOS ESTA PIDIENDO UN CLIENTE!

#include <cstring>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(){
    char* puerto = "8080";
    char* host = "localhost";

    struct addrinfo hints;
    struct addrinfo *result, *ptr;

    memset(&hints, 0, sizeof(struct addrinfo)); //setteo a cero el hints
    //configuro el hints
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    getaddrinfo(host, puerto, &hints, &result); //reciben char*, no std::string
    int socket_fd = -1;
    for(ptr = result; ptr!=NULL; ptr= ptr->ai_next){
        socket_fd = socket(ptr->ai_family, ptr->ai_addr, ptr->ai_addrlen);
        if(socket_fd != -1){
            conect(socket_fd, ptr->ai_addr, ptr->ai_addrlen);
            break;
        }
    }
    freeadrrinfo(result);
    if(!ptr) return -1;

    bool termine = false;
    char c;
    std::string numero_recibido;
    int acumulado;

    ssize_t recibido = recv(socket_fd, &c, sizeof(c), 0);
    if(recibido<=0) termine = true;

    while(!termine){
        if(c=='['){
            while(c!= ']' && !termine){
                if (c != '+') {
                    numero_recibido.push_back(c);
                } else if (c == '+') {
                    int numero = stoi(numero_recibido);
                    acumulado += numero;
                    numero_recibido.clear();
                }
                recibido = recv(socket_fd, &c, sizeof(c), 0);
                if (recibido <= 0) termine = true;
            }
            if(!acumulado){
                termine = true;
            } else {
                std::cout << acumulado << std::endl;
                acumulado = 0;
            }
        }
        ssize_t recibido = recv(socket_fd, &c, sizeof(c), 0);
        if(recibido<=0) termine = true;
    }
    close(socket_fd);
    return 0;
}
