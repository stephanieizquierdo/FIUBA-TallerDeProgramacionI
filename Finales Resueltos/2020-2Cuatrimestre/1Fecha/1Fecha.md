# Taller - 2019 1er cuatrimestre, primera instancia :dart:
_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

Explique breve y concretamente qué es f:
`int *(**f) (short int *, char *[2]);`

f es un puntero a un puntero de funcion que recibe un puntero a short int y un array de 2 punteros a char, y devuelve un puntero a int.

## Ejercicio 2

Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen: a) Una variable global static b) Una variable local static c) Un atributo de clase static.

- a: Una variable global static es una variable que tiene el lifetime del programa, y es visibole solo en él ya que al ser static no puede ser compartida entre otros archivos. Reside en el Data Segment y  si no se la definio explicitamente se le dara un valor Null

- b Una variable local static reside en el data segment, Al ser static, su visibilidad se restringe al scope de donde fue definida pero su lifetime es desde el momento de definicion hasta el final de la ejecucion del programa. No son inicializadas hasta que el programador lo haga explicitamente definiendo la variable.

- c atributo de clase static: Recide en el data segment, su visibilidad es global. Los atributos pueden ser publicos o privados modificando asi tambien el acceso


## Ejercicio 3

Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3.

## Ejercicio 4

¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique.

Para lograr que no hayan problemas de consistencia o race condition cuando se quiera acceder a mismo recurso compartido tenemos que utilizar un mutex. Esto nos garantizaran que el codigo al cual acceden los threads solo se pueda acceder a el por uno solo. Entonces
un hilo toma el mutex y hasta que no lo libere no puede otro acceder a este. Ejemplo:

```cpp
int counter = 0;
std::mutex m;

void incrementar(){
    m.lock();
    counter++;
    m.unlock();
}

```
## Ejercicio 5

Escriba el .H de una biblioteca de funciones ISO C para cadenas de caracteres. Incluya, al menos, 4 funciones.

## Ejercicio 6

¿Qué es una macro de C? Detalle las buenas prácticas para su definición. Ejemplifique

Una macro en C es como un alias de una porcion de codigo, en el cual en el preprocesamiento del compilado se hace un find y replace de este con lo cual es muy importante respetar la siguien buena practica: Entrecerrar entre parentesis los argumentos de la funcion. Ejemplo:

```c
#define GOOD_SQR(x) (x)*(x) //RESPETA LAS BUENAS PRACTICAS
#define BAD_SQR(x) x*x //NO RESPETA LAS BUENAS PRACTICAS

int cuatro = GOOD_SQR(1+1); //(1+1)*(1+1);

int no_da_cuatro = BAD_SQR(1+1); //1+1*1+1 = 3

```

## Ejercicio 7

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas.



## Ejercicio 8
Indique la salida del siguiente programa:
```
class A {
    A(){cout << “A()” << endl;}
    ~A(){ cout << “~A()” << endl;}
}
class B : public A {
    B(){cout << “B()” << endl;}
    ~B(){ cout << “~B()” << endl;}
}
```

Respuesta:
A()

B()

~B()

~A()

## Ejercicio 9

Implemente una función C++ denominada Sacar que reciba dos listas de elementos y devuelva una nueva lista con los elementos de la primera que no están en la segunda:



## Ejercicio 10
Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, quedar en escucha e imprimir en stdout todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto.
