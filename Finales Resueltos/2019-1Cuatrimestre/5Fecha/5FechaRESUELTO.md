# Taller - 2019 1er cuatrimestre, Cuarta instancia :dart:

_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

Escriba una rutina (para ambiente gráfico Windows o Linux) que dibuje un triángulo
amarillo del tamaño de la ventana.

[Respuesta](Ej-1.cpp)

## Ejercicio 2

Escriba las siguientes definiciones/declaraciones:

1. Declaración de un puntero a puntero a entero largo con signo.
2. Definición de una la función RESTA, que tome dos enteros largos con signo y devuelva
su resta. Esta función debe ser visible en todos los módulos del programa.
3. Definición de un caracter solamente visible en el módulo donde se define.

<details>
<summary> Respuesta :bulb:</b></summary>

---
1. ` long int* *d`
2. ` long int resta(long int numero1, long int numero2);`
3. `static char c = 'a'`
---

</details>


## Ejercicio 3

Declare la clase TELEFONO para encapsular una cadena numérica correspondiente a un
teléfono. Incluya al menos: Constructor(area, numero), Constructor move y Constructor de
Copia; Operador <<, ==, =, long y >>. Implemente el operador >>.

<details>
<summary> Respuesta :bulb:</b></summary>

---
```C
class Telefono{
    private:
        str numero;
    public:
        Telefono(size_t area, size_t numero);

        Telefono(const Telefono& otro); //constructor copia
        Telefono(const Telefono&& otro); //constructor move

        Telefono& operator=(const Telefono& tel);

        bool operator==(const Telefono& tel);

        operator long()const;

        std::ostream operator<<(std::ostream output, const Telefono& tel);
        std::istream operator>>(std::istream input, Telefono& tel){
            input>>tel.numero;
            return input;
        }
}
```
---

</details>


## Ejercicio 4

Explique qué se entiende por “compilación condicional”. Ejemplifique mediante código.

<details>
<summary> Respuesta :bulb:</b></summary>

---
Una compilacion condicional es cuano si hay un alias definido entonces se compila cierto codigo, sino otro. Es como un if pero a nivel de codigo. Sirve mucho para cortar las inclusiones de bibliotecas.

ejemplo simple:

```c
##ifndef PI
#define  PI 3.14
#endif
```
Entonces si no esta definido PI, lo define, si ya esta definido no hace nada.
---

</details>


## Ejercicio 5

¿Qué significa que una función es blocante?¿Cómo subsanaría esa limitación en término de
mantener el programa ‘vivo’ ?

<details>
<summary> Respuesta :bulb:</b></summary>

---
Cuando una funcion es bloqueante, significa que no se puede hacer otra cosa hasta obtener lo que retorne la funcion. Entonces para subsanar esto se usan hilos de forma tal que un hilo se quede esperando el retorno de la funcion y otro hilo continue haciendo otras cosas.
---

</details>


## Ejercicio 6

Explique qué son los métodos virtuales puros y para qué sirven. De un breve ejemplo
donde su uso sea imprescindible.

<details>
<summary> Respuesta :bulb:</b></summary>

---
Los metodos virtuales puros son un tipo de metodo virtual y son los que se declaran como virtual .... = 0 . Estos son metodos abstractos que deben ser implementados por las clases derivadas de la clase que declara dicho metodo virtual puro. Sirven para poder aplicar polimorfismo, para que las distintas clases derivadas tengan un comportamiento distinto al invocarse este metodo. Un ejemplo imprescindible es el caso en el que queremos definir una clase que actue de interfaz. Para esto, debemos declarar sus metodos como virtuales puros.
---

</details>


## Ejercicio 7

Escribir un programa C que procese el archivo “numeros.txt” sobre sí mismo (sin crear
archivos intermedios y sin subir el archivo a memoria). El procesamiento consiste en leer nros
hexadecimales de 4 símbolos y reemplazarlos por su valor decimal (en texto).

[Respuesta](Ej-7.c)


## Ejercicio 8

¿Qué es el polimorfismo? Ejemplifique mediante código.

<details>
<summary> Respuesta :bulb:</b></summary>

---
El polimorfismo es uno de los pilares de la programacion orientada a objetos. El polimorfismo es el hecho de poder adaptarse/cambiar segun la problematica. Por ejemplo podemos tener la clase cocinero y la funcion cocinar, pero que segun la especialidad cocine cosas distintas. Si es pastelero que cocinar devuelva "cake", si es panadero devuelva "Bread", etc. Entonces segun las distintas especialidades cocinar se comporta distinto.
---

</details>


## Ejercicio 9

¿Qué función utiliza para esperar la terminación de un thread? Ejemplifique mediante
código.

<details>
<summary> Respuesta :bulb:</b></summary>

---
La funcion que se utiliza es join(). Esta funcion bloquea la ejecucion del hilo que llama a esta funcion hasta que la funcion que se ejecuta en el hilo retorna. Luego de llamar a esta funcion, el hilo se vuelve non-joinable y puede ser destruido de manera segura. Por ejemplo:
---

</details>


## Ejercicio 10

Escriba un programa C que tome 2 cadenas por línea de comandos: A y B; e imprima la
cadena A después de haber duplicado todas las ocurrencias de B.
ej.: reemp.exe “El final está aprobado” aprobado -----> El final está aprobado aprobado

[Respuesta](Ej-10.c)
