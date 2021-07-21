#ifndef SOCKET_ERROR_ACEPTAR_H
#define SOCKET_ERROR_ACEPTAR_H

#include <typeinfo>

class SocketErrorAceptar : public std::exception {
public:
    SocketErrorAceptar();
    virtual~SocketErrorAceptar() noexcept;   
};

#endif /*SOCKET_ERROR_ACEPTAR_H*/
