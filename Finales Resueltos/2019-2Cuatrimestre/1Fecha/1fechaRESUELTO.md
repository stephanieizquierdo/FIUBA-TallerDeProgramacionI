# Taller - 2019 2do cuatri, primera instancia :dart:
_Hecho por Stephanie Izquierdo Osorio_


## Ejercicio 1

_Que es f?  `int(*f)(short * int, char[3]);`_

<details>
<summary> Respuesta :bulb:</b></summary>

f es un un puntero a funcion que recibe como primer parametro un puntero short y como segundo y ultimo parametro un array de tamaño 3 tipo char. Devuelve int

</details>

## Ejercicio 2
_Explique qué es cada uno de los siguientes, haciendo referencia a su inicialización, su comportamiento y el area de memoria donde residen: a) Una variable global static. b) Una variable local static. c) Un atributo de clase static._

<details>
<summary> Respuesta :bulb:</b></summary>

1. Una variable global static: Se almacena en el data segment, y su visibilidad es global dentro del archivo donde fue definido ya que al ser static no es exportada por el enlazador.
Una variable global static puede inicializarse con una constante en tiempo de compilacion.
En caso de que no se inicilice se le asigna un cero, null o el valor correspondiente estipulado segun el lenguaje.

2. Una variable local static: Es almacenada en el stack de donde fue creada, es una variable local a esta funcion y ademas es destruida cuando se sale desde esta y al ser estatica solo puede ser llamada dentro de ese archivo. No son inicializadas al menos que el programador lo haga explicitamente

3. Un atributo de clase static: Un atributo de clase static se almacena en el data segment y puede inicializarse con una constante en tiempo de compilación. En caso de omitirse su inicializacion se inicializará con 0, null o el valor correspondiente al tipo según lo estipulado en el estándar dentro del lenguaje. Su visibilidad está restringida a la clase que la define. El valor del atributo se comparte entre todas las instancias de la clase y en caso de declararse público es accesible desde fuera de la clase, anteponiendo el nombre de la misma (en lugar una instancia es Clase::Attrib). En caso de ser privado su valor no podra ser accedido por otros entes. Es exportado al enlazador, con lo cual puede accederse desde otros  archivos si se declara público

</details>

## Ejercicio 3

_Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo, duplicando los enteros de 2 bytes múltiplos de 3._

Respuesta en Archivo aparte

## Ejercicio 4

_¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartidon sin que se generen problemas de consistencia? Ejemplifique._

<details>
<summary> Respuesta :bulb:</b></summary>

Para que esto suceda hay que usar un mutex que proteja las acciones haciedno que se acceda a la parte protegida un thread a la vez. Un ejemplo de esto es:
``` C++
  class Contador{
    Mutex m; //mutex RAI
    int contador;
  }
  public:
     void aumentarContador(){
        mutex.lock();
        contador++;
        mutex.unlock();
     }
```

</details>

## Ejercicio 5

_Escriba el .H de una biblioteca de funciones ISO C para cadenas de caracteres. Incluya, al menos, 4 funciones._

<details>
<summary> Respuesta :bulb:</b></summary>

``` C
#ifndef _CADENA_CARACTERES_H
#define _CADENA_CARACTERES_H

//Compara dos strings. Devuelve True si son iguales o False en caso contrario.
bool son_cadenas_iguales(const char* string1, const char* string2);

//Devuelve True si el segundo string se encuentra dentro del primero
bool esta_incluido(const char* string1, const char* string2);

//Copia el contenido de stringOrigen a stringDestino
void copiar_cadenas(const char* stringOrigen, char* stringDestino);

//Ordena alfabeticamente
void ordenar_alfabeticamente_ascendentemente(char* string);

//devuelve el largo del string
int largo(char* str)

#endif //_CADENA_CARACTERES_H
```

</details>

## Ejercicio 6
_¿Qué es una macro de C? Detalle las buenas prácticas para su definición. Ejemplifique_

<details>
<summary> Respuesta :bulb:</b></summary>

Una macro es un alias que se puede incluir en el código que será reemplazado por lo que se haya definido
cuando el compilador efectúe el paso de preprocesamiento. Las macros son capaces de realizar decisiones
lógicas o funciones matemáticas. Se recomienda encerrar los parámetros de una macro entre paréntesis
porque si se le pasa una expresión como parámetro, al expandir la macro se podría formar una expresión
que no cumpla el orden de las operaciones matemáticas de la forma deseada

Ejemplo:
``` C
define CUBE_WRONG(A) A*A*A      /*Macro incorrecta para el cubo*/
#define CUBE(A) (A)*(A)*(A)      /*Macro correcta para el cubo*/

CUBE_WRONG(5+1) = 5+1*5+1*5+1 = 16   //y debería dar 216
CUBE(5+1) = (5+1)*(5+1)*(5+1) = 216  //y da 216 :D
```

</details>

## Ejercicio 7
_Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas y las tareas desarrolladas en cada una de ellas._


<details>
<summary> Respuesta :bulb:</b></summary>

Primero antes del ensamblado, en el preensamblado/preprocesamiento se hacen las expansiones de las macros, si es que hay, copiando y pegando sus líneas en todos los lugares donde fue invocada reemplazando los parámetros correspondientes.
Luego en tiempo de ensamblado, el ensamblador se dedica a determinar las direcciones de todos los datos e instrucciones. Además también se encarga de realizar cualquier operación aritmética necesaria y hace la traduccion 1 a 1 de codigo fuente a codigo maquina y además genera otro archivo con la tabla e información adicional para uso del linker y loader, como por ejemplo: el nombre y tamaño del módulo, la dirección del símbolo de comienzo (si es que hay uno al comienzo), información acerca de símbolos globales y externos, información acerca de las rutinas de biblioteca a las que el módulo hace referencia, los valores de cualquier constante que deba cargarse en memoria e información de reubicación.

El programa de linkeo necesita saber la dirección de cualquier símbolo global definido en el módulo y exportado por el mismo, así como necesitará saber qué símbolo se encuentra indefinidos en el módulo porque se definen como globales en otro módulo.
Cuando se invoca al programa de enlace, la mayoría de módulos a incluir deben reubicarse a medida que se concatenan. El linker combina programas ensamblados por separado para generar un único módulo de carga. El linker resuelve todas las referencias globales y externas y reubica las direcciones de los diferentes módulos.
Finalmente el Loader ubica los modulos de carga para que puedan ser ejecutados

## Ejercicio 8
_Indique la salida del siguiente programa:_
``` C++
class A{ A(){cout << “A()” << endl;} ~A(){ cout << “~A()” << endl;} }`
class B : public A { B(){cout << “B()” << endl;} ~B(){ cout << “~B()” << endl;} }`
int main () { B b; return 0;}`
```
<details>
<summary> Respuesta :bulb:</b></summary>

A() (primero instancia un A dentro de B, pero no se destruye hasta que finalice B)

B() (B ya hizo lo tuyo entonces se va a destruir)

~B  (Y primero se destruye B)

~A  (Y finalmente se destruye A)

Esto se debe a que primero se llama al constructor de la clase base y luego al de la clase derivada y lo opuesto
pasa con el destructor (como si se tratara de una pila).

</details>

## Ejercicio 9

_Implemente una función C++ denominada **Sacar** que reciba dos listas de elementos y devuelva una nueva lista con los elementos de la primera que no están en la segunda:_
`std::list<T> Sacar(std::list<T> a, std::list<T> b);`

<details>
<summary> Respuesta :bulb:</b></summary>

```C++
template<class T>

std::list<T> Sacar(std::list<T> a, std::list<T> b) {
    std::list resultado;
    for (auto it = a.begin(); it != a.end(); it++) {   /*itero por los elementos de la lista a*/
        auto elemento = std::find(b.begin(), b.end(), *it); /*me fijo si el elemento actual se encuentra en b*/

        if(elemento == b.end()){   /*Si find no lo encuentra devuelve el ultimo*/
            resultado.pushback(*elemento);
        }
    }
    return resultado;
}
```

</details>

## Ejercicio 10
_Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa debe establecer una unica conexión, quedar en escucha e imprimir en stdout todo lo recibido. Al recibir el texto ‘FINAL’ debe finalizar el programa sin imprimir dicho texto._
