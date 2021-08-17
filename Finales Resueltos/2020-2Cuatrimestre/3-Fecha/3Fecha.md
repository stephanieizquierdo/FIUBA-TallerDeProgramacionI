# Taller - 2020 2do cuatri, tercera instancia :dart:
_Resuelto por Stephanie Izquierdo Osorio_

## Ejercicio 1
¿Qué diferencia existe entre un constructor por copia y uno por movimiento? Ejemplifique.

<details>
<summary> Respuesta :bulb:</b></summary>

Un constructor por copia, copia literalmente el objeto pasado es decir que duplica los bytes de este. Estos constructores son generados por default a menos que se los eliminen explicitamente.
Los constructores por movimiento lo que hacen es un cambio en el ownership, es decir que el objeto deja de pertenecer de su origen y pasa a ser de un nuevo "dueño". En estos casos si el objeto posee punteros hay que ser cuidadosos y redireccionarlos en la definicion. Este constructor no es por deafult, debemos declararlo e implementarlo

```cpp
		Complejo(const Complejo& otro); //constructor por copia
		Complejo(Complejo && otro); //constrcutor por movimiento
		Complejo(const Complejo& otro) =delete; //Eliminamos el constructor por copia
};
```

</details>

## Ejercicio 2

Escriba una rutina que dibuje un rombo azul del tamaño de la pantalla.

[Respuesta](ej-2.cpp)

## Ejercicio 3

Escribir un programa ISO C MULTIPLATAFORMA que procese el archivo “bigEndian.dat” sobre sí mismo, leyendo nros. de 4 bytes Big-Endian y triplicando los impares.

[Respuesta](ej-3.c)

## Ejercicio 4

¿Qué es un Deadlock? Ejemplifique.

<details>
<summary> Respuesta :bulb:</b></summary>

Un deadlock sucede cuando uno o más hilos se bloquean permanentemente.
Un ejemplo de esto es cuadno un hilo toma un recurso A y espera a que se libere el recurso B para liberar a a A y tomar B. Mientras tanto hay otro hilo que tomo el recurso B y espera a que se libere A para liberar B y tomar A.
Entonces ambos hilos se quedan bloqueados esperando hasta que se desocupe el otro -> deadlock

</details>

## Ejercicio 5

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe conectarse y quedar en escucha de paquetes con la forma “d..d+d..d+...=”. El programa debe imprimir en stdout cada suma hasta que la misma sea 0 (cero). En ese caso debe finalizar ordenadamente.

## Ejercicio 6

Describa con exactitud las siguientes declaraciones/definiciones globales:
- char *(*A)();
- static int *(*C)[5];
- short *B(){return NULL;}


<details>
<summary> Respuesta :bulb:</b></summary>

1. A un puntero a funcion que no recibe parametros y devuelve un puntero a char.
2. C un puntero a un array de 5 punteros a int y c es estatico
3. B es una funcion que no recibe parametros, el tipo de retorno estipulado es un puntero a short y el comportamient ode esta funcion es retornar un puntero NULL.

</details>

## Ejercicio 7

Declare una clase a elección considerando:
		- Atributos que son necesarios
		- Accesibilidad a la Clase
		- Incluir los operadores -, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), float

[Respuesta](ej-7.cpp)

## Ejercicio 8

Implemente una función C++ denominada SoloMuliplos que reciba una lista de elementos numéricos y un elemnto numérico x. La función debe devolver una nueva lista con los elementos de la primera que sean múltiplos de x:
		std::list<T> SoloMultiplos(std::list<T> a,T x);

[Respuesta](ej-8.cpp)

## Ejercicio 9

¿Se puede evitar que un objeto de una clase sea copiado?¿y clonado?. En caso afirmativo explique cómo puede hacerse. En caso negativo explique por qué no se puede.

<details>
<summary> Respuesta :bulb:</b></summary>

Sí se puede evitar. Esto se hace eliminando explicitamente el constructor y la asignacion por copia/clonado de la siguiente forma:

```cpp

UnaClase(const UnaClase& otra) = delete;
UnaClase& operator=(const UnaClase& otra) = delete;

```

</details>

## Ejercicio 10

¿Qué es un thread?¿Qué recursos comparte con otros threads del mismo proceso?¿Cuales son exclusivos (no compartidos)?

<details>
<summary> Respuesta :bulb:</b></summary>

Un thread es la ejecucion de una funcion/bloque de codigo. Cuando tenemos multiples hilos estos bloques de codigo se ejecutan concurrentemente. Cuando un proceso es multithreading se comparte el data segment, code segment, heap y los filesdescriptors. Los exclusivos son el stack y los registros.

</details>
