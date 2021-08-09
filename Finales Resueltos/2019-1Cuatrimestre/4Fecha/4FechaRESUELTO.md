# Taller - 2019 1er cuatrimestre, Cuarta instancia :dart:

_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

¿Qué es una macro de C? Enumere buenas prácticas para su definición.

<details>
<summary> Respuesta :bulb:</b></summary>

---

Una macro en C es un alias a un segmento de código. Al momento de la compilacion en el preprocesamiento, se hace un find y replace del alias y el codigo de la macro. Es por esto que es muy importante encerrar entre parentesis los parametros de la macro. Ejemplo:

```C
#define GOOD_SQR(x) (x)*(x)  //Cumple las buenas practicas
#define BAD_SQR(x) x*x //NO CUMPLE las buenas practicas

int main(){
    int cuadrado = GOOD_SQR(3); // 3*3 = 9
    int mal_cuadrado = BAD_SQR(2+1); // 2+1*2+1 = 5
}
```

---

</details>

## Ejercicio 2

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y
las tareas desarrolladas en cada una de ellas.

<details>
<summary> Respuesta :bulb:</b></summary>

---
Primero, el codigo fuente pasa a la compilacion, en la cual primero pasa por un preprocesamiento en donde se resuelven las expresiones logicas, se reemplazan las alias de las macros por su codigo y (blabla). Luego se hace la conversion 1 a 1 de codigo fuente a codigo maquina y en caso de que hayan referencias sin arreglar se resuelven en el paso de Linkeo. El linkeo se encarga de vincular los .o necesarios para armar el ejecutable.


---

</details>

## Ejercicio 3
Explique breve y concretamente qué es f:
`char (*f) (int *, char[3]);`

<details>
<summary> Respuesta :bulb:</b></summary>

---

f es un puntero a funcion que devuelve char y recibe como parametros un puntero a int, y un array de char.

---

</details>

## Ejercicio 4

Escribir un programa ISO C que procese el archivo “nros_2bytes_bigendian.dat” sobre sí
mismo, eliminando los número múltiplos de 7.

 [Respuesta](Ej-4.c)

</details>

## Ejercicio 5

Implemente una función C++ denominada DobleSegunda que reciba dos listas de elementos
y devuelva una nueva lista duplicando los elementos de la primera si están en la segunda:
std::list<T> DobleSegunda(std::list<T> a,std::list<T> b);

 [Respuesta](Ej-5.cpp)

## Ejercicio 6

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe
aceptar una unica conexión e imprimir en stdout todo lo recibido. Al recibir el texto ‘FIN’ debe
finalizar el programa sin imprimir dicho texto.

 [Respuesta](Ej-6.cpp)

## Ejercicio 7

Escriba el .H de una biblioteca de funciones ISO C para números complejos. Incluya, al
menos, 4 funciones.

<details>
<summary> Respuesta :bulb:</b></summary>

---

```c
#ifndef COMPLEJOS_H
#define COMPLEJOS_H

typedef struct complejo complejo_t;

int obtener_parte_real(const complejo_t complejo);

int obtener_parte_imaginaria(const complejo_t completo);

int obtener_angulo_principal(complejo_t complejo);

int modulo(complejo_t complejo);

void incrementar_parte_real();

void incrementar_parte_imaginaria();

void decrementar_parte_real();

void decrementar_parte_imaginaria();

#endif /*COMPLEJOS_H*/
```

---

</details>

## Ejercicio 8

Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su
comportamiento y el area de memoria donde residen:

1. Una variable global static

2. Una variable local static

3. Un atributo de clase static.

<details>
<summary> Respuesta :bulb:</b></summary>

---

1. Una variable global static es una variable que puede se puede hacer referencia dentro del archivo donde se la declaró ya que al ser static no puede ser exportada por el linker. Reside en el datasegment y si no se la definio explicitamente se le dara un valor NULL. Su lifetime es la misma que el archivo

2. Una variable local static es una variable que al ser local solo se le va a poder hacer referencia en la funcion que se la haya declarado y morira al salir de esta.

3. Un atributo de una clase static se almacena en el data segment. En caso de no inicializarla explicitamente, se le dara al momento de compilacion un valor nulo. Su visibilidad es restringida a la clase que lo define si es que es un atributo privado. En caso de ser publico va a poder ser accedida al anteponer el nombre de la clase.

---

</details>

## Ejercicio 9

¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin
que se generen problemas de consistencia? Ejemplifique.

<details>
<summary> Respuesta :bulb:</b></summary>

---

Esto se puede lograr usando un Mutex. Este funciona como si a la seccion de codigo que se quiere cuidar se le pone un candado y la llave solo se le puede dar a un hilo a la vez.

```

escribir_en_Archivo(){
    mutex.lock();
    escribir();
    mutex.unlock;
}

```

---

</details>

## Ejercicio 10

Indique la salida del siguiente programa:
```
class A { A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }
int main () { B b; return 0;}
```

<details>
<summary> Respuesta :bulb:</b></summary>

---

salida: A()B()~A~B()

---

</details>
