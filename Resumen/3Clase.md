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

- Constructor por copia: Son por default

- fubcion() const; significa que la funcion es de solo lectura, no va a modificar nada.
