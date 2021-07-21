# Final 2da instancia 2019 2C :dart:

## Ejercicio 1

_Escriba un programa (desde la inicialización hasta la liberación de los recursos) que reciba paquetes de la forma nnn+nn+....+nnnn= (numeros separados por +, seguidos de =) e imprima el resultado de la suma de cada paquete por pantalla. Al recibir un paquete vacío (“=”) debe cerrarse ordenadamente. No considere errores._

## Ejercicio 2
_Explique breve y concretamente qué es f:_

    `int (*f) (short *, char[4]);`

F es un puntero a funcion que recibe como primer parametro un puntero a short y un vector de tamanio 4 de char. Devuelve int.

## Ejercicio 3
_Analice el siguiente código y determine lo que se imprime (valor de Pi)_
``` C
    main(){
      int *Pi=1000;
      Pi++;
      printf(“Pi apunta a la dirección: %l”, (long)Pi);
    }
```

`int*pi` es un puntero y de solo lectura, al hacer Pi++ se mueve a la siguiente direccion donde esta Pi, y por ultimo se imprime esta en formato de long.

## Ejercicio 4

_¿Qué es un functor? ¿Qué ventaja ofrece frente a una función convencional? Ejemplifique._

Un functor es un objeto que tiene sobrecargado el operador () ('llamado') y actua como una "funcion". Permite desacoplar el momento en en el que se le pasa parametros a una funcion mientras esta es ejecutada
```C
class Sumar {
    public:
        Sumar(int a, int b): sumando_1(a), sumando_2(b) {}
        void operator()() {
            resultado = sumando_1 + sumando_2;
        }
        int obtener_resultado() const {
            return resultado;
        }
    private:
        int sumando_1, sumando_2, resultado;
};
int main() {
    Sumar suma(3, 4); //pasaje de parámetros
    std::thread t1(suma); //ejecución
    t1.join();
    std::cout << suma.obtener_resultado() << std::endl //obtención del resultado
    return 0;
}
```


## Ejercicio 5
_¿Cómo se logra que 2 threads accedan (lectura/escritura) a un mismo recurso compartido sin que se generen problemas de consistencia? Ejemplifique._

Con un mutex que bloquea una porcion de codigo para que peuda ser accedido por un solo hilo a la vez
```C
Class contador{
    private:
        Mutex m //mutex raii
    public:
        int contador++
        void contar(){
            m.lock()
            contador++  //esta protegido. Solo se puede acceder un hilo a la vez
            m.unlock()
        }    
}
```

## Ejercicio 6
_Describa el concepto de loop de eventos (events loop) utilizado en programación orientada a eventos y, en particular, en entornos de interfaz gráfica (GUIs)._

En la programación orientada a eventos el programa está constantemente esperando que se generen eventos, tales como pueden ser un clic, una pulsación del teclado, un paquete de red, un temporizador, etc y luego los despacha a sus respectivos manejadores. El loop de eventos es el ciclo principal del programa y se compone de dos tareas:
    1. Decodificar el siguiente evento, donde se determina quién debe ser notificado
    2. Despachar el evento, donde se envían las notificaciones
Pseudocódigo del event loop:
```
while se debe continuar:
evento := obtener el siguiente evento de la cola de eventos
if evento == salir:
se debe continuar := false
else if existe manejador para evento:
ejecutar manejador
```
Los manejadores son secciones de código que saben cómo responder a la aparición de un evento. Como los
va a disparar el event loop, se van a ejecutar de manera secuencial así que no van a tener problemas de concurrencia entre ellos y si uno tarda mucho va a retrasar a todos los que vengan después. En aplicaciones con GUI se deben programar handlers cortos y que den feedback al usuario. En muchos frameworks gráficos, el event loop corre en el hilo principal (GTK te abstrae de programarlo mientras que SDL te obliga a hacerlo).

## Ejercicio 7

_Considere la estructura struct ejemplo { int a; char b;}. ¿Es verdad que sizeof (ejemplo)=sizeof(a) +sizeof(b)? Justifique._


Falso. La memoria se almacena de a multiplos de 4 para ser mas veloz al acceder, entonces sizeof(ejemplo) puede ser 8, dado que int a tiene 4bytes pero charb podria tambien tener 4 bytes para "completar el multimplo de 4 del int" entonces, por separado sizeof(b) es 1, pero en conjunto es 4.

## Ejercicio 8
_¿En qué consiste el patrón de diseño RAII? Ejemplifique._

Es un patron que busca encapsular la parte de creacion/destruccion. Al instanciarse objetos RAII en el stack, sus constructores
adquieren los recursos automáticamente. Al irse de scope cada objeto se les invoca su destructor automáticamente y liberan sus recursos sin necesidad de hacerlo explícitamente. De esta manera el código C++ se simplifica y se hace más robusto a errores de programación.

Ejemplo:
```C
class Buffer{
    Buffer(size){
        this->data = new char[size];
    }
    ~Buffer(){
        delete[] this->data
    }
}
```

## Ejercicio 9
_Escribir un programa ISO C que procese el archivo de enteros de 2 bytes bigendian cuyo nombre es recibido como parámetro. El procesamiento consiste en eliminar los número múltiplos de 3, trabajando sobre el mismo archivo (sin archivos intermedios ni en memoria)._

## Ejercicio 10
_Implemente una función C++ denominada DobleSiNo que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que no están en la segunda:_

```C++
template<class T>

std::list<T> DobleSiNo(std::list<T> a, std::list<T> b) {
    std::list resultado;
    for (auto it = a.begin(); it != a.end(); it++) {   /*itero por los elementos de la lista a*/
        auto elemento = std::find(b.begin(), b.end(), *it); /*me fijo si el elemento actual se encuentra en b*/

        if(elemento == b.end()){   /*Si find no lo encuentra devuelve el ultimo*/
            resultado.pushback(*elemento);
            resultado.pushback(*elemento);
        }
    }
    return resultado;
}
```
