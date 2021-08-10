/*
Escriba un programa (desde la inicialización hasta la liberación de los recursos)
que escuche el puerto 120 y reciba paquetes de la forma:
		[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM]
donde [CHAR_LIM] puede ser cualquier caracter ASCII
Al completar la recepción del paquete deberá imprimir el caracter con más apariciones
del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente.
No considere errores.
*/

#define MAX 5

//Escuchar ->servidor
int main(){
    char* puerto = 120;

    struct addrinfo hints;
    struct addrinfo *ptr, *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints->ai_family = AI_NET;
    hints->ai_flags = AI_PASSIVE;
    hints->ai_socktype = SOCK_STREAM;

    getaddrinfo(NULL, puerto, &hints, &result);

    int sock_fd = -1;

    for(ptr = result; ptr; ptr = ptr->ai_next){
        sock_fd = socket(ptr->ai_family, ptr->ai_addr, ptr ->ai_addrlen);
        if(sock_fd != -1){
            break;
        }
    }
    freeaddrinfo(ptr);
    if(!ptr){
        return -1;
    }
    bind(sock_fd, ptr->ai_addr, ptr ->ai_addrlen);
    listen(ptr, MAX);
    int peerskt = accept(socket_fd, NULL, NULL);

    bool termino = false;
    char buf;

    ssize_t recibido = recv(peerskt, buf, sizeof(char), 0);
    if(recibido <= 0){
        termino = true;
    } char char_lim = buf;

    std::string paquete;
    while(!termino){
        recibido = recv(peerskt, buf, sizeof(char), 0);
        if(recibido<=0){
            termino = true;
        } else if(buf != char_lim) {
            paquete.pushbak(buf);
        } else {
            char mayor_apariciones;
            int contador_mejor = 0;
            int contador_actual = 0;

            for(int i = 0; i < paquetes.leght(); i++){
                char actual = paquete[i];
                contador_actual = std::count(paquete.begin(), paquete.end(), actual);
                if(contador_actual > contador_mejor){
                    contador_mejor = contador_actual;
                    mayor_apariciones = actual;
                }
                contador_actual = 0;
            }
            std::cout << mayor_apariciones << std::endl;
            paquete.clean();
        }
    }
    showdown(peerskt, SHUT_RDWR);
    showdown(socket_fd, SHUT_RDWR);
    fclose(peerskt);
    fclose(socker_fd);
    return 0;
}
