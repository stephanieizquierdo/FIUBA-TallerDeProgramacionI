#include <errno.h>
#include <iostream>
#include <string>

#include "socket_error.h"

SocketError::SocketError(const std::string &error) noexcept {
    this->mensaje_error = error;
}

const char* SocketError::what() const noexcept{
    return this->mensaje_error.c_str();
}

SocketError::~SocketError() {}
