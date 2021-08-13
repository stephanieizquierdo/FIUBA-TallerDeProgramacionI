# Taller - 2019 1er cuatrimestre, Segunda instancia :dart:
_Hecho por Stephanie Izquierdo Osorio_


## Ejercicio 1

Declare la clase Número para encapsular una cadena numérica larga. Incluya al menos:
Constructor(unsigned long), Constructor default y Constructor move; Operador <<, (), =, long y
++(int). Implemente el operador >>.

<details>
<summary> Respuesta :bulb:</b></summary>

``` c
class Numero{
        Numero(unsigned long numero);
        Numero(const Numero & otro); //constructor por copia(default)
        Numero(Numero && otro); //constructor por movimiento
        std::istream operator>>(std::istream & input, Numero & numero){
            in>>numero;
            return in;
        }
        std::ostream operator<<(std::ostram &output, const Numero& numero);

        Numero& operator=(const Numero& otro); //asignacion por copia
        Numero& operator=(const Numero&& otro); //asignacion por movimiento
        Numero operator++(int);
        operator long() const;
};
```
</details>


## Ejercicio 2

¿Qué significa que una función es bloqueante? ¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?

<details>
<summary> Respuesta :bulb:</b></summary>

Que una funcion sea bloqueante significa que no puede hacer nada, o sea se bloquea, hasta que cumpla su cometido. Entonces para subsanar esto, se utilizan los threads que son varios hilos, entonces cada uno hace lo suyo independienteme.

</details>

## Ejercicio 3

Explique qué son los métodos virtuales y para qué sirven. De un breve ejemplo donde su
uso sea imprescindible.

<details>
<summary> Respuesta :bulb:</b></summary>

La palabra virtual antepuesta a un método de una clase habilita lo que se conoce como dynamic binding. Esto
quiere decir que el método  se resuelve en tiempo de ejecución.
Esto permite utilizar polimorfismo basado en herencia, es decir, los métodos de las clases derivadas reemplazan a los de la clase base independientemente de cómo se lo acceda (desde un puntero a la base o al tipo derivado). En el código objeto esto genera una diferencia debido a que el dynamic binding requiere tener una tabla de métodos virtuales para cada objeto (la VTable) de modo de permitir determinar en tiempo de ejecución qué método debe ser llamado (resolución dinámica).

Su uso es imprensendible cuando se tienen clases abstractas, como por ejmplo una clase figura, donde van a teeenr que implementarse clsses hijas como Triangulo, cuadrado, circulo para redefinir el comportamiento.
</details>

## Ejercicio 4

Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer
grupos de 4 caracteres hexadecimales y reemplazarlos por los correspondientes dígitos
decimales (que representen el mismo número leído pero en decimal).

[Respuesta](Ej-4.cpp)

## Ejercicio 5

Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

<details>
<summary> Respuesta :bulb:</b></summary>

La compilación condicional permite incluir o excluir distintos fragmentos de código según el valor de distintas
constantes conocidas al momento de la compilación. La misma se resuelve en la etapa de preprocesado.  Un ode sus usos es para evitar las inclusiones ciclicas, como por ejemplo el siguiente caso: A necesita de la bilbioteca B, que necesita a C y C necesita a A;
Por ejemplo:

```c
#ifndef __UTIL__
#define UTIL.H

#endif

```
</details>

## Ejercicio 6

Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B..
ej.: reemp.exe “Este es el final” final -----> Este es el final final

[Respuesta](Ej-6.c)

## Ejercicio 7

Escriba las siguientes definiciones/declaraciones:
1. Definición de una la función SUMA, que tome dos enteros largos con signo y devuelva
su suma. Esta función sólo debe ser visible en el módulo donde se la define.
2. Declaración de un puntero a puntero a entero sin signo.
3. Definición de un caracter solamente visible en el módulo donde se define.

<details>
<summary> Respuesta :bulb:</b></summary>

1.
```C
static long int suma(const long int numero1, const long int numero2){
    return numero1+numero2
}
```

2. `unsigned int **a`

3. `static char b = 'b';`

</details>

## Ejercicio 8
¿Qué valor arroja sizeof(int)? Justifique .

<details>
<summary> Respuesta :bulb:</b></summary>

Depende de la arquitectura y el compilador en la que se solicita dicha acción.

</details>

## Ejercicio 9
Describa el concepto de loop de eventos (events loop) utilizado en programación orientada
a eventos y, en particular, en entornos de interfaz gráfica (GUIs).

<details>
<summary> Respuesta :bulb:</b></summary>

En la programación orientada a eventos el programa está constantemente esperando que se generen eventos, y luego los
despacha a sus respectivos manejadores. El loop de eventos es el ciclo principal del programa y se compone
de dos tareas:
1. Decodificar el siguiente evento, donde se determina quién debe ser notificado
2. Despachar el evento, donde se envían las notificaciones

Los manejadores son secciones de código que saben cómo responder a la aparición de un evento. Como los
va a disparar el event loop, se van a ejecutar de manera secuencial así que no van a tener problemas de
concurrencia entre ellos y si uno tarda mucho va a retrasar a todos los que vengan después. En aplicaciones
con GUI se deben programar handlers cortos y que den feedback al usuario. En muchos frameworks gráficos,
el event loop corre en el hilo principal

</details>

## Ejercicio 10
¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock?

<details>
<summary> Respuesta :bulb:</b></summary>

La principal ventaja reside en que el mutex se libera automáticamente cuando la variable de tipo std::mutex
sale de scope.
Las ventajas de utilizar RAII residen en que al instanciarse objetos RAII en el stack, sus constructores
adquieren los recursos automáticamente. Al irse de scope cada objeto se les invoca su destructor automáticamente y liberan sus recursos sin necesidad de hacerlo explícitamente. De esta manera el código C++ se
simplifica y se hace más robusto a errores de programación

</details>
