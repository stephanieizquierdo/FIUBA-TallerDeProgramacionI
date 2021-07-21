#ifndef SOCKET_H
#define SOCKET_H

#include <stdio.h>
#include <stddef.h>


class Socket {
	private:
		int filedescriptor;
		explicit Socket(int fd);

	public:
		Socket();
		~Socket();
		/*
		 * Hace un shutdown y close del socket, si es que este es válido.
		 */
		void cerrar();
		
		Socket(const Socket &copia) = delete;
		Socket & operator=(const Socket &copia) = delete;

		Socket(Socket && otro) noexcept;
		Socket& operator= (Socket &&other); 

		/*
		 *Enlaza y deja en estado de "escuchar" las conexiones 
		 *(maximo 7 conexiones en espera)
		 */
		void bind_and_listen(const char *servicio);

		/*
		 *Acepta una conexión que estaba esperando. Devuelve un socket
		 *por movimiento. Si falla lanza una excepcion.
		 */
		Socket aceptar();

		/*
		 *Conecta. Devolverá EXITO(0) si completó sus acciones o de
		 *lo contrario ERROR(-1)
		 */
		void conectar(const char *host, const char *servicio);

		/*
		 *Envia length cantidad de bytes del buffer. Lanza excepcion si ocurre
		 *algún error. Retorna la cantidad de bytes enviados.
		 */
		unsigned int enviar(const char *buffer, size_t tamanio);

		/*
		 *Recibe length cantidad de bytes del buffer.  Lanza excepcion si ocurre
		 *algún error. Retorna la cantidad de bytes recibidos.
		 */
		unsigned int recibir(char* buffer, size_t tamanio);

		/*
		 *Hace un Shutdown en modo WR, escritura.
		 */
		void apagar_escritura();

		/*
		 *Hace un Shutdown en modo RD, lectura.
		 */
		void apagar_lectura();
};

#endif /*SOCKET_H*/
