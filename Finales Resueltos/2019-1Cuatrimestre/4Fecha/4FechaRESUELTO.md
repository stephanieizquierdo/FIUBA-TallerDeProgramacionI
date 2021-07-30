# Taller - 2019 1er cuatrimestre, Cuarta instancia :dart:

_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

¿Qué es una macro de C? Enumere buenas prácticas para su definición.

## Ejercicio 2

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y
las tareas desarrolladas en cada una de ellas.

## Ejercicio 3
Explique breve y concretamente qué es f:
`char (*f) (int *, char[3]);`

## Ejercicio 4

Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí
mismo, eliminando los número múltiplos de 7.

## Ejercicio 5

Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera si están en la segunda:
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);

## Ejercicio 6

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe
aceptar una unica conexión e imprimir en stdout todo lo recibido. Al recibir el texto ‘FIN’ debe
finalizar el programa sin imprimir dicho texto.

## Ejercicio 7

Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al
menos, 4 funciones.

## Ejercicio 8

Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su
comportamiento y el area de memoria donde residen:
1. Una variable global static
2. Una variable local static
3. Un atributo de clase static.

## Ejercicio 9

¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin
que se generen problemas de consistencia? Ejemplifique.

## Ejercicio 10

Indique la salida del siguiente programa:
```
class A { A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}
```
