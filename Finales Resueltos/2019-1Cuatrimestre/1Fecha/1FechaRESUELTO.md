# Taller - 2019 1er cuatrimestre, primera instancia :dart:
_Hecho por Stephanie Izquierdo Osorio_

## Ejercicio 1

Explique qué es y para qué sirve un constructor de copia en C++.
1. Indique cómo se comporta el sistema si éste no es definido por el desarrollador
2. Explique al menos una estrategia para evitar que una clase particular sea copiable;
3. Indique qué diferencia existe entre un constructor de copia y uno move.

<details>
<summary> Respuesta :bulb:</b></summary>

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

</details>

## Ejercicio 2

2) Escriba una función ISO C llamada Replicar que reciba 1 cadena (S), dos índices (I1 e I2) y una cantidad (Q). La función debe retornar una copia de S salvo los caracteres que se encuentran entre los índices I1 e I2 que serán duplicados Q veces.
Ej. replicar(“Hola”, 1, 2, 3) retorna “Hololola”.

<details>
<summary> Respuesta :bulb:</b></summary>

```C
char* replicar (const char* S, size_t I1, size_t I2, size_t Q){
    if (I1 < strlen(S) || I2 < strlen(S) || Q <= 0)
        fprintf(stderr, "Error Replicar: Parametros incorrectos");

    size_t largo_nuevo = (strlen(S)-(I2-I1+1))+((I2-I1+1)*Q);

    char* nuevo_string = malloc(sizeof(char)*largo_nuevo);
    if (!nuevo_string)
        fprintf(stderr, "Error Replicar: No se pudo crear nuevo string");
    int pos = 0;
    for (int i = 0; i < strlen(S); i++){
        if (i < I1 || i > I2){
            nuevo_string[pos] = S[i];
            pos++;
        } else{
            while (Q > 0) {
                for (int j = i; j <=I2; j++) {
                        nuevo_string[pos] = S[j];
                        pos ++;               
                }
                Q--;
            }
        }
    }
    return nuevo_string;
}

```
**ESTO ESTA MAL:**
```C
char* replicar (const char* S, size_t I1, size_t I2, size_t Q){
    if (I1 < strlen(S) || I2 < strlen(S) || Q <= 0)
        fprintf(stderr, "Error Replicar: Parametros incorrectos");

    size_t largo_nuevo = (strlen(S)-(I2-I1+1))+((I2-I1+1)*Q);

    char* nuevo_string = malloc(sizeof(char)*largo_nuevo);
    if (!nuevo_string)
        fprintf(stderr, "Error Replicar: No se pudo crear nuevo string");
    /* char aux[I2-I1+1]; ESTO NO FUNCIONA YA QUE NO SE PUEDE MODIFICAR AUX!!!!
    int aux_contador = 0;
    int pos_copiar = I1;
    for (int i = 0; i < strlen(S); i ++) {
        if (i < I1){
            nuevo_string[i] = S[i];    
        } elseif (i >= I1 && i <= I2) {
            aux[aux_contador] = S[i]; //PODRIA HACER UN STRCPY O UN STRCAT
            aux_contador++;
            if (i == I2) {
                while (Q > 0) {
                    nuevo_string[pos_copiar]= aux;
                    pos_copiar =+ (I2-I1+1);
                    Q--;
                }
            }
        } else {
            nuevo_string[pos_copiar] = S[i];
            pos_copiar++
        }
    }
    */
}
```
_Reflexion_: si bien la primera tiene alta complejidad por los for/while, la prefiero antes que la segunda ya que para arreglar la segunda deberia hacer otro malloc para hacerlo mas simple.

</details>

## Ejercicio 3

Describa con exactitud las siguientes declaraciones/definiciones globales:
    1. void (*F)(int i);
    2. static void B(float a, float b){}
    3. int *(*C)[5];

<details>
<summary> Respuesta :bulb:</b></summary>

1. Puntero a funcion que recibe un int y no retorna nada, es void.

2. Una funcion B que recibe dos parametros tipo float. Es una funcion que no reotrna nada y es estatica osea que es de alcance local.

3. `int *(*C)[5];`
    1. (*C) C es un puntero, si hago el nombramiento (*C)==X tengo que

    2. `int* X [5]`: X apunta a int, y veo que son 5 de esos, entonces X es un array de 5 punteros a int

    3. Entonces volviendo al original obtengo que C es un puntero a un arreglo de 5 punteros a int

</details>

## Ejercicio 4

Escribir un programa ISO C que reciba por argumento el nombre de un archivo de texto y lo
procese sobre sí mismo (sin crear archivos intermedios ni subiendo todo su contenido a
memoria). El procesamiento consiste en eliminar las líneas de 1 sola palabra.

**Respuesta en archivo aparte** [respuesta](https://github.com/stephanieizquierdo/FIUBA-TallerDeProgramacionI/blob/master/FINALES/2019-1C/1Fecha_ej4.cpp)

## Ejercicio 5

Declare una clase de elección libre. Incluya todos los campos de datos requeridos con su
correcta exposición/publicación, y los operadores ++, -, ==, >> (carga), << (impresión),
constructor move y operador float().

<details>
<summary> Respuesta :bulb:</b></summary>

```C
class Fraccion{
    private:
        int numerador;
        int denominador;
    public:
        Fraccion(int numerador, int denominador);
        Fraccion(const Fraccion & otro); //Constructor por copia
        Fraccion(Fraccion && otro); //Constructor por Movimiento
        Fraccion& operator=(const Fraccion& otro); //asignacion por copia
        Fraccion& operator=(const Fraccion&& otro); //asignacion por movimiento

        Fraccion& operator++();
        Fraccion operator+(const Fraccion& otro) const;
        Fraccion operator-(const Fraccion& otro) const;
        std::istream& operator>>(std::istream & in, Fraccion& fraccion);
        std::ostream& operator<<(std::ostream & out, const Fraccion& fraccion);
        operator float() const;
        void simplificacion();
}
```
</details>

## Ejercicio 6

¿Qué es una macro de C? Describa las buenas prácticas para su definición y ejemplifique.

<details>
<summary> Respuesta :bulb:</b></summary>

Una macro es un 'alias' de una porcion de codigo. Al momento del preprocesamiento en compilación, en donde se haya invocado la macro, se sustituira con el codigo de ella. Las macros son capaces de realizar decisiones logicas o expresiones matemáticas. Se recomienda encerrar los parametros de una macro entre parentesis porque si se le pasa una expresion como parametro, al expandir la macro se podria formar una expresion erronea, como por ejemplo:

```C
#define CUBE_WRONG(a) a*a*a         //ESTA MACRO NO CUMPLE CON LAS BUENAS PRACTICAS
#define CUBE_RIGHT(a) (a)*(a)*(a)

CUBE_WRONG(5+1) = 5+1*5+1*5+1
CUBE_RIGHT(5+1) = (5+1)*(5+1)*(5+1)
```

</details>

## Ejercicio 7

Escriba un programa que reciba por línea de comandos un Puerto y una IP. El programa
debe aceptar una única conexión e imprimir en stdout la sumatoria de los enteros recibidos
en cada paquete. Un paquete está definido como una sucesión de números recibidos como
texto, en decimal, separados por comas y terminado con un signo igual (ej: “27,12,32=”). Al
recibir el texto ‘FIN’ debe finalizar el programa ordenadamente liberando los recursos.

**Respuesta A REALIZAR**

## Ejercicio 8

Describa el proceso de transformación de código fuente a un ejecutable. Precise las etapas,
las tareas desarrolladas y los tipos de error generados en cada una de ellas.

<details>
<summary> Respuesta :bulb:</b></summary>

</details>

## Ejercicio 9

¿Qué ventaja ofrece un lock raii frente al tradicional lock/unlock?

<details>
<summary> Respuesta :bulb:</b></summary>

La ventaja más apreciable es que al ser raii, el mutex se libera por si solo cuando este sale de scope.

</details>

## Ejercicio 10

¿Qué significa que una función es bloqueante?¿Cómo subsanaría esa limitación en términos
de mantener el programa ‘vivo’ ?

<details>
<summary> Respuesta :bulb:</b></summary>

Cuando una funcion es bloqueante significa que se queda "esperando" a obtener un resultado y no puede hacer nada mientras no lo obtenga. Para subsanar esto se pueden utilizar hilos, de forma tal que un hilo este esperando y otro siga haciendo cosas.

</details>
