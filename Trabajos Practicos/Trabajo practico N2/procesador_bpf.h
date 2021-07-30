#ifndef PROCESADOR_BPF_H
#define PROCESADOR_BPF_H

#include "thread.h"
#include "repositorio.h"
#include <atomic>

class Procesador_BPF : public Thread{
	private:
		Repositorio & archivos;
		Repositorio & resultados;
		std::atomic<bool> puedo_procesar;
		
	public:
		Procesador_BPF(Repositorio& unos_archivos, Repositorio& unos_resultados);
		/*
		 * Mientas tenga archivos para procesar, los obtendrá, analizará y
		 * se insertará en el repositorio de resultados el estado del archivo.
		 */
		void run() override;
		~Procesador_BPF();
};

#endif /*PROCESADOR_BPF_H*/
