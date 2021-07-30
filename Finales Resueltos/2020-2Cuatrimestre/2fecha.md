#### Fecha: 18/03/2021 - Cuatrimestre: 2/2020 - Tema: 22

1) Escriba un programa (desde la inicialización hasta la liberación de los recursos) que escuche el puerto 120 y reciba paquetes de la forma:
		[CHAR_LIM]xxxxx.xxxxxxx[CHAR_LIM]
donde [CHAR_LIM] puede ser cualquier caracter ASCII
Al completar la recepción del paquete deberá imprimir el caracter con más apariciones del mismo (sin considerar [CHAR_LIM]). Al recibir un paquete vacío ([CHAR_LIM][CHAR_LIM]) debe cerrarse ordenadamente. No considere errores.

2) ¿Qué función se utiliza para lanzar hilos?¿Qué parámetros tiene y para qué sirven?
Ejemplifique.

3) ¿Qué finalidad tiene la palabra virtual antepuesta a un método? Ejemplifique.

4) Implemente una función C++ denominada DUPLICAR que reciba dos listas de elementos y devuelva una nueva lista duplicando los elementos de la primera que están en la segunda:
		std::list<T> Duplicar(std::list<T> a,std::list<T> b);

5) Declare una clase a elección considerando:
		- Atributos que son necesarios
		- Accesibilidad a la Clase
		- Incluir los operadores *, --(pre-decremento), ++(post-incremento), << (impresión), >>(carga desde consola), functor

6) Explique qué es (a), (b), (c) y (d), haciendo referencia a su valor y momento de inicialización, su comportamiento y el area de memoria donde residen:

```c
extern int *a[25];
int b()
{
static float c; char d=70;
return c+(float) d;
}
```

7) Escriba una rutina que dibuje un rombo verde que ocupe toda la ventana.

8) ¿Qué diferencia existe entre un constructor por copia y uno por movimiento?
Ejemplifique.

9) Escriba una función ISO C que permita procesar sobre sí mismo (sin generar archivos intermedios ni cargar el archivo completo a memoria) un archivo texto con palabras separadas por espacios. El procesamiento consiste en duplicar las palabras que tengan al menos de 2 vocales.

10) ¿Qué es la compliación condicional? Ejemplifique
