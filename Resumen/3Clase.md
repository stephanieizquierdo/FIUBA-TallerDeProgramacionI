# Taller de programacion 1 [75.42] - **RESUMEN**
###### Stephanie Izquierdo Osorio

## C++

### Clases
Son estructuras que pueden albergar funciones y permite restringir la visibilidad. Las estructuras tiene
todo publico por defecto y las clases tiene las cosas privadas por defecto.

### RAII

Cuando se instancia un objeto de la clase, se llama automaticamente al constructor y luego al momento de liberarse del stack/heap se llama automaticamente al destructor.

- **Los objetos se destruyen en orden inverso al que fueron instaciados** (funciona como un stack)

- operador New: ademas de reservar memoria, llama al constructor

- operador delete: es como el free del malloc (ahora new)

- Constructor por copia: Son por default. Hay que tener mucho cuidado porque si la clase original tenia un atributo con memoria en el heap, cuando se lo copie la nueva instancia va a tener un puntero pero que apunta a la memoria del anterior, entonces al momento de destuir ocurriria un error porque dice: ah tengo que borrar el buffer de B, okey quien es? es un puntero al buffer de A, listo lo libero. Ahora tenogo que liberar a A entonces libero su buffer... CHAN! doble free!!! x.x Como lo solucionaria? definiendo el constructor por copia y diciendo que haga un memcpy del buffer.


- Constructor por movimiento:

- funcion() const; significa que la funcion es de solo lectura, no va a modificar nada.

- con & podemos tener una programacion mas legible, entonces es mas facil de programar introducioendo menos erroes, facilitando el debugging(esto dijo veiga)

### Operadores

En C++ podemos sobrecargar los operadores, es buena practicar usar const para decirle al usuario que el objeto no va a ser modificado.

## Herencia y Polimorfismo

### Herencia
Es uno de los pilares de la POO y cumple con la relacion "es un", donde la clase derivada extiende de la clase base, la cual generaliza a las clases derivadas.

- Una instancia de la clase derivada es tambien una instancia de la clase base 'çlass Derivada: public Base {}'

- No se heredan los constructores, los operadores, ni los friend. Se peude heredar en forma protected o privated.

- usar member initializer list para delegar el constructor, esta tiene que estar ordenada

- El constructor de Base se llama antes que el constructor de derivada. Y se destruyen al revés.

### Polimorfismo

Posibilita a un objeto a tener distintas formas. La misma llamada a funcion tiene distintos comportamientos dependiendo del tipo del objeto.

## Metodos virtules vs final

## Metodos de clase

se marcan con static y cuando esta adelante de un metodo significa que es un metodo de clase
