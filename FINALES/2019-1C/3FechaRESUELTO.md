# Taller - 2019 1er cuatrimestre, Tercera instancia :dart:

_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

Declare una clase a elección considerando:
- Atributos que son necesarios
- Accesibilidad a la Clase
- Incluir los operadores +, ++ (post-incremento), --(pre-incremento), >> (impresión), << (carga desde consola), long

<details>
<summary> Respuesta :bulb:</b></summary>

``` C
class Fraccion {
    int numerador;
    int denominador;

    public:
        Fraccion(int numerador, int denomidor);
        Fraccion(const Fraccion& otro); // constructor por copia
        Fraccion(Fraccion&& otro); //constructor por movimiento
        Fraccion& operador=(const Fraccion& otro);
        Fraccion&& operator=(const Fraccion&& otro);

        Fraccion operator+(const Fraccion& fraccion) const;
        Fraccion operator++();
        Fraccion operator--();

        std::istream operator>>(std::istream &input, Fraccion& f);
        std::ostream operator<<(std::ostream &output, const Fraccion &f);

        operator long() const;

        void simplificar();        
}

```
</details>

## Ejercicio 2

¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique.


<details>
<summary> Respuesta :bulb:</b></summary>
Un functor es un objeto que tiene sobrecargado el operador () y actua como si fuera una función.
El mismo permite desacoplar el momento en que se le pasa los parámetros a una función del momento en
que se inicia la ejecución de la misma.
ejemplo:
```C
class Cliente{
    private:
        Socket socket;
		void procesar_respuesta_servidor();
        void correr();
    public:
        Cliente(const char* host, const char* server_port);
        void operator()(){
            this->correr();
        }
}
```
</details>
## Ejercicio 3

Escriba un programa que imprima por salida estándar los números entre 1 y 100, en orden
ascendente. Se pide que los números sean contabilizados por una variable global única y que
los pares sean escritos por un hilo mientras que los impares sean escritos por otro.
Contemple la correcta sincronización entre hilos y la liberación de los recursos utilizados.

## Ejercicio 4

Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de
inicialización, su comportamiento y el area de memoria donde residen:
```C
static int a;
int b(){
    static int c; char d=65;
    return c+(int) d;
}
```
<details>
<summary> Respuesta :bulb:</b></summary>
---
- a : Es una declaracion de una variable int estatica, es decir que solo puede ser accedida desde donde fue declarada. Al ser una declaracion no posee un valor ya que no se reservó memoria para ella. Y no reside en ningun segmento de memoria ya que no ocupa un lugar.

- b : Es una funcion que no recibe parametros y devuelve int, esta definida y reside en el datasegment  

- c : Declaracion de un int estatico.

- d : definicion de un char. Su valor es el caracter correspondiente al que tiene el valor 65 en la tabla ascii. Es una variable local y se almaxena en el stack. Al salir de la funcion esta se destruye.
---
</details>

## Ejercicio 5

Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..

<details>
<summary> Respuesta :bulb:</b></summary>
</details>

## Ejercicio 6

¿Por qué las librerías que usan Templates se publican con todo el código fuente y no como
un .h y .o/.obj?.

<details>
<summary> Respuesta :bulb:</b></summary>
</details>

## Ejercicio 7

¿Qué características debe tener un compilador C para se considerado “portable”?

<details>
<summary> Respuesta :bulb:</b></summary>

Un compilador C portable es aquel que soporta la sintaxis de C dado un estandar y no debe agregar ninguna otra sintaxis extra, de esta forma el codigo puede ser compilado por otro compilador.
Ademas el compilador debe ofrecer una implementacion a las bilbiotecas estandar de C respetando el estandar. Y por ultimo debe seguir un proceso determinaod de transformacion de codigo fuente al ejecutable.
</details>

## Ejercicio 8

Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba
paquetes de la forma [nnn+nn+….+nnnn] (numeros separados por +, encerrados entre
corchetes) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un
paquete vacío (“[]”) debe cerrarse ordenadamente. No considere errores.

## Ejercicio 9

Escriba una función ISO C que permita procesar un archivo texto que contenga frases (1
por línea) sobre sí mismo, sin generar archivos intermedios ni cargar el archivo completo a
memoria. El procesamiento consiste en eliminar las palabras de más de 3 letras de cada línea.

## Ejercicio 10

¿Qué diferencia existe entre un constructor por copia y uno por movimiento?
Ejemplifique.

<details>
<summary> Respuesta :bulb:</b></summary>
En C++ por defecto todos los pasajes de los objetos son por copia, es decir que literalmente duplica la informacion/bits de lo pasado al constructor. En cambio un constructor por movimiento cambia el ownership o sea, que se cmabia el "dueño"/origen del objeto

</details>
