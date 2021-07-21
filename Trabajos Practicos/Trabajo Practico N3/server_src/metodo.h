#ifndef METODO_H
#define METODO_H
#include <map>
#include <string>

class Metodo{
	public:
		/*
		 * Devolverá un mensaje en base a las circunstancias
		 */
		virtual std::string correr(std::map <std::string, std::string> &mapa)=0;
		
		virtual ~Metodo() {} 
};

/********************************** P O S T ***********************************/

class Post_sinRecurso : public Metodo {
	private:
		std::string responder();

	public:
		Post_sinRecurso();
		
		std::string correr(std::map <std::string, std::string> &mapa)override;
	   
	    ~Post_sinRecurso(){}
};

class Post_ConRecurso : public Metodo {
	private:
		std::string responder();

	public:
		std::string recurso;
		std::string body;

	 Post_ConRecurso(const std::string &un_recurso, const std::string& un_body);
		
		std::string correr(std::map <std::string, std::string> &mapa)override;
	    
	    ~Post_ConRecurso(){}
};

/********************************** G E T *************************************/

class Get_SinRecurso : public Metodo {
	private:
		std::string responder();

	public:
		std::string nombre_archivo;

		explicit Get_SinRecurso(const std::string &un_nombre);
		
		std::string correr(std::map <std::string, std::string> &mapa)override;
	   
	    ~Get_SinRecurso(){}
};

class Get_ConRecurso : public Metodo {
	private:
		std::string responder();

	public:
		std::string recurso;
		std::string body;

		explicit Get_ConRecurso(const std::string &un_recurso);
		
		std::string correr(std::map <std::string, std::string> &mapa)override;
	    
	    ~Get_ConRecurso(){}
};

/**************************** I N V A L I D ***********************************/

class Invalido : public Metodo {
	private:
		std::string responder();
		
	public:
		std::string requess;

		explicit Invalido(const std::string &un_requess);
		
		std::string correr(std::map <std::string, std::string> &mapa)override;
};

#endif /*METODO_H*/
