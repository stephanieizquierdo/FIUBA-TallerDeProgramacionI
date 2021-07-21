#ifndef SOCKET_ERROR_H
#define SOCKET_ERROR_H

#include <typeinfo>
#include <string>

class SocketError : public std::exception {
	private:
 	   std::string mensaje_error;
	public:
	    explicit SocketError(const std::string &error) noexcept;
	    virtual const char *what() const noexcept;
	    virtual ~SocketError() noexcept;   
};

#endif /*SOCKET_ERROR_H*/
