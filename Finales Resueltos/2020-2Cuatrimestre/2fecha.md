# Taller - 2020 2do cuatri, segunda instancia :dart:
_Resuelto por Stephanie Izquierdo Osorio_

## Ejercicio 1

Escriba un programa (desde la inicialización hasta la liberación de los recursos) que escuche el puerto 120 y reciba paquetes de la forma:
		[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM]
donde [CHAR_LIM] puede ser cualquier caracter ASCII
Al completar la recepción del paquete deberá imprimir el caracter con más apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.

## Ejercicio 2

¿Qué función se utiliza para lanzar hilos?¿Qué parámetros tiene y para qué sirven?
Ejemplifique.

std::thread(function,parameters)

## Ejercicio 3

¿Qué finalidad tiene la palabra virtual antepuesta a un método? Ejemplifique.


Dejar en claro que ese metodo lo implementaran las clases hijas. Esto es parte del principio de la programacion orientada a objetos, para ser mas especifica a la parte de herencia, donde una clase "madre" declara un conjunto de funciones/atributos que vas a tener todas las clases que hereden de ella pero que lo van a poder implementar a su forma por ejemplo:

se puede tener la clase madre Vehiculo con los atributos velocidad por hora, cantidad de ruedas, funcones como acelerar y se tenga como clases hijas un auto, una moto, una camioneta dodne van a tener que redefinir los atributos y funciones

## Ejercicio 4

Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que están en la segunda:
		std::list<T> Duplicar(std::list<T> a,std::list<T> b);

## Ejercicio 5

Declare una clase a elección considerando:
		- Atributos que son necesarios
		- Accesibilidad a la Clase
		- Incluir los operadores *, --(pre-decremento), ++(post-incremento), << (impresión), >>(carga desde consola), functor



## Ejercicio 6

Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:

```c
extern int *a[25];
int b()
{
static float c; char d=70;
return c+(float) d;
}
```

Respuesta

- a: arreglo de 25 punteros a int. Es externo por lo cual va a estar definida en un archivo externo a la declaracion. No forma parte de ningun segmento ya que no se guarda memoria para esta.

- b: definicion de la funcion b que no recibe parametros y devuelve int. Reside en el Data segment

- c: declaracion de un float estatico, es decir que solo pertenece a este archivo y ademas es local, ya que al salir de la funcion b no puede existir mas. Al ser una declaracion no se almacena memoria para esta, entonces no esta en ningun segmento de memoria.

- d: Definicion de un char, cuyo valor es el correspondiente en la tabla ascci del numero 70. Reside en el data segmentent.

## Ejercicio 7

Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.

**No idea jeje lol (proximamente lo subo)**

## Ejercicio 8

¿Qué diferencia existe entre un constructor por copia y uno por movimiento?
Ejemplifique.

El constructor por copia hace una copia naive bit a bit del objeto. En cambio el constructor por movimiento cambia el origen del objeto, es decir el ownership, por ende no hay una duplicacion de este, sino que se "mueve" del lugar de origen. Ademas de esto en un constructor por copia no se puede modificar el objeto que se recibe, en vambio en el de movimiento si

```c
class complejo{
public:
	Complejo(int real, int imaginario)
	Complejo( Complejo&& otro);
	Complejo(const Complejo& complejo)
}

```

## Ejercicio 9

Escriba una función ISO C que permita procesar sobre sí mismo (sin generar archivos intermedios ni cargar el archivo completo a memoria) un archivo texto con palabras separadas por espacios. El procesamiento consiste en duplicar las palabras que tengan al menos de 2 vocales.

## Ejercicio 10

¿Qué es la compliación condicional? Ejemplifique

Una compilacion condicional sucede cuando hay partes de codigos que se compilan o no dependiendo si esta definido un alias o incluido algun archivo en especifico. Esto es util para cortar los includes ciclicos.

```C
#ifndef __COMPLEJOS_H__
#define COMPLEJOS_H
...
#endif
```
