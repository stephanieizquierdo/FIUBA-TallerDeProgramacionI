# Taller - 2019 1er cuatrimestre, primera instancia :dart:

## Ejercicio 1

Explique qué es y para qué sirve un constructor de copia en C++.
1. Indique cómo se comporta el sistema si éste no es definido por el desarrollador
2. Explique al menos una estrategia para evitar que una clase particular sea copiable;
3. Indique qué diferencia existe entre un constructor de copia y uno move.

**Respuesta**

En C++ por defecto todos los pasajes de los objetos son por copia, es decir que literalmente duplica la informacion/bits de lo pasado al constructor.

1. Si un objeto no tiene implementado por el desarrolador el constructor por copia, se le asigna uno por default. En caso de que se haya borrado explicitamente el constructor por copia, el objeto deja de ser copiable.

2. Para evitar que una clase en particular sea copiable:
    1. Se puede borrar explicitamente el constructor por copia y el de asignacion.
        ```C++
            Foo (const Foo &bar) = delete;
            Foo& operator= (const Foo &bar) = delete;
        ```
        Y así en caso de se intente copiar, al momento de compilar el programa dará error.
    2. Otra forma seria declarar pero no definir ni el constructor por copia ni el operador asignación y hacerlos privados. El intento fallido de copia se detecta en tiempo de compilación y linkeo.

3. En un constructor tipo move se cambia el origen del elemento es decir que se cambia el ownership de el. Lo que hace es mover los punteros/ referencias que se encuentran dentro de la instancia recibida por parametro y esta instancia deja de apuntar a esas referencias. Entonces de esta forma no hay una copia.

## Ejercicio 2

2) Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de S salvo los caracteres que se encuentran entre los índices I1 e I2 que serán duplicados Q veces.
Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.

**Respuesta**

```C
char* replicar (const char* S, size_t I1, size_t I2, size_t Q){
    recorrer el string
    mientras recorro me fijo si el contador es uno de los indices, si lo es lo voy metiendo en un coso aparte
    y asi hasta llegar al indice final, luego lo pongo Q veces y leugo sigo.
    if (I1 < strlen(S) || I2 < strlen(S) || /*Q == */)
        fprintf(stderr, "Error Replicar: Parametros incorrectos");

    size_t largo_a_repetir = I2-I1;
    char repetir[largo_a_repetir];
    for ( int i = 0; i < strlen(S); i ++ ) {
        if (i >= I1 || i <= I2) {
            strcopy()
        }
    }
}
```

## Ejercicio 3

Describa con exactitud las siguientes declaraciones/definiciones globales:
    1. void (*F)(int i);
    2. static void B(float a, float b){}
    3. int *(*C)[5];

## Ejercicio 4

Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo
procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido a
memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.

## Ejercicio 5

Declare una clase de elección libre. Incluya todos los campos de datos requeridos con su
correcta exposición/publicación, y los operadores ++, -, ==, >> (carga), << (impresión),
constructor move y operador float().

## Ejercicio 6

¿Qué es una macro de C? Describa las buenas prácticas para su definición y ejemplifique.

## Ejercicio 7
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe aceptar una única conexión e imprimir en stdout la sumatoria de los enteros recibidos
en cada paquete. Un paquete está definido como una sucesión de números recibidos como
texto, en decimal, separados por comas y terminado con un signo igual (ej: “27,12,32=”). Al
recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.

## Ejercicio 8

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas,
las tareas desarrolladas y los tipos de error generados en cada una de ellas.

## Ejercicio 9

¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock?

## Ejercicio 10

¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en términos
de mantener el programa ‘vivo’ ?
