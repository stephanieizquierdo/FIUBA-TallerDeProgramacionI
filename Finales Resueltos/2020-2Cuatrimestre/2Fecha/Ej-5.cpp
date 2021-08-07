/*Declare una clase a elección considerando:
		- Atributos que son necesarios
		- Accesibilidad a la Clase
		- Incluir los operadores *, --(pre-decremento), ++(post-incremento),
           << (impresión), >>(carga desde consola), functor*/


class Contador(){
    int acumulador;
public:
    Contador(int cant_inicial);

    void agregar(int cantidad);
    
    void contar_unidad();

    Contador operator()();
    Contador operator--();
    Contador operator++();
    std::istream operator>>(std::istream input, Contador un_contador);
    std::ostream operator>>(std::ostream output, Contador un_contador);
}
