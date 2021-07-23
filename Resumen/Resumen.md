# Taller de programacion 1 [75.42] - **RESUMEN**

## **Memoria en C/C++ [Clase N1]**
- Los punteros son del mismo tamaño

- **Declaracion** de variables: Cuando declaro una variable, digo que la variable va a existir en algun otro momento. NO LE ESTOY ASIGNANDO MEMORIA. Le estoy diciendo al compilador "che, aca va a haber esto"

- **Definicion** de variables: Ademas de declarar le pido al compilador que reserve espacio para almacenar valores. Es una declaracion+asignacion de memoria.

### Exacta reserva de memoria:
Depende de la arquitectura y del compilador cuanto ocupa cada tipo de dato.

### Alineación y Padding:
Donde se ubica el comienzo de las variables. Los objetos se pueden almacenar en un numero de memoria que es multiplo de 4/8 para tener mayor velocidad de acceso.

Ejemplo con estructura:

```C
    struct S{       //  D: disponible, -: No disponible->es espacio que queda sin utilizar
        int a;      //         |D|D|D|D| -> |0|0|0|1| 4bytes
        char b;     //         |D|-|-|-| -> |2|-|-|-| 4bytes
        int c;      //         |D|D|D|D| -> |0|0|0|3| 4bytes
        char d;     //         |D|-|-|-| -> |4|-|-|-| 4bytes
    };

    struct S s= {1,2,3,4};  
```

Podemos ver como cada campo se alinea en la memoria para ser multiplo de cuatro. Ganamos velocidad apesar de desperdiciar espacio. El tamaño de la estructura es de 16 Bytes, que no es lo mismo que la suma del tamaño de cada tipo de dato independientemente, que es 10.

Ejemplo para no desperdiciar espacio:

```C
    struct S{       //D: disponible, -: No disponible-> es espacio que queda sin utilizar
        int a;      //         |D|D|D|D| -> |0|0|0|1| 4bytes
        char b;     //         |D|D|D|D| -> |2|0|0|0| 4bytes
        int c;      //         |D|D|-|-| -> |3|4|-|-| 4bytes  
        char d;     //       
    }__attribute__((packed));;

    struct S s= {1,2,3,4};  
```    
Al usar la directiva packed informamos que queremos todos los datos uno atras del otro, sin desperdicio de memoeria en el medio. Podemos observar que seguimos desperdiciando memoria al final pero es mucho menor. Ahora sizeof(S) es 12.

### Endianess:
Existen dos tipos de almacenamiento de los bytes de los objetos.

- **BigEndian**: Las variables se almacenan como lo lo hacemos numericamente, comenzando por el bit mas significativo y terminamos por el menos significativo.

- **LittleEndian**: Los bytes se invierten de orden segun bigEndian
```C
    int i = 1; // BE= |0|0|0|1|   LE = |1|0|0|0|
    int j = 1023; // BE= |0|0|3|ff|   LE = |ff|3|0|0|
```
_Esto tiene sentido si se quiere hacer un cambio entre char e int y similares_
Se puede intercambiar el endianess de una variable short int e int:
- Host to Network:
    1. `htons(short int)`: compu->red, Me aseguro que el short int se envie a la red a BigEndian
    2. `htonl(int)` compu->Red, me aseguro que el int se envie como BigEndian

- Network to Host:
    1. `ntohs(short int)` : Red->Compu me asegura que el short int que viene se va a transformar en el endianess que mi compu entiende.
    2. `ntohl(int)` : Red->Compu me asegura que el entero que viene se va a transformar en el endianess que mi compu entiende.


### Segmentos de memoria

- **Code Segment**: Ahi se encuentra el codigo de nuestro programa y las **Constantes**. Es un area de Solo lectura.

- **Data Segment**: Area de memoria en el cual las variables globales son creadas. Ocupan espacio en el ejecutable y son inicializadas con valor NULO (0 para int, NULL para punteros, false para booleanos etc etc). Las variables permanecen ahi hasta que termine el programa. No es de solo lectura, se puede modificar. Puede haber variables globales y locales (que enrealidad son globales pero de visibilidad reducida).

- **Stack**: Variables creadas al inicio de una llamada a funcion y destruidas automaticamente cuando esta llamada termina (o sean son locales a esa funcion). **SI NO SE INICIALIZAN LAS VARIABLES EXPLICITAMENTE, TIENEN BASURA!**.  Parte de memoria que se almacena como una pila. Se debe tener cuidado con el overflow para no pisar otra memoria.

- **Heap**: El programador tiene responsabilidad sobre este segmento. La duracion de las variables dependen del programador.

### Duracion (lifetime):
Tiempo desde que a la variable se le reserva memoria(empieza a existir) hasta que esta es liberada. Determinado por el segmento de memoria que se usa.

### Visibilidad (Scope):
Cuando una variable se la puede acceder y cuando està oculta. Por ejemplo, una variable static existe en todo el archivo donde fue creada pero solo puede ser accedida en la funcion donde se creo.



Ejemplos:

```C
int g = 2; //Data Segment, Scope Global: puede ser accedida por todos los codigos fuentes
static int I = 1; //Data Segment, Scope Local! (el static le dice que solo va a ser visible en este archivo)
extern char e; //No asigno memoria, Variable declarada con scope global que va a tener que ser definida en otro file(por el extern)

void Fa(){} // Code Segment; scope glocal
static func(){} //Code Segment; scope local
void Fun(); // Declaracion, No asigna memoria. Va a existir en otro lugar.

//ARGUMENTOS Y RETORNOS SON DEL STACK!
void foo (int arg) {
    int a = 1 //stack segment, scope local
    static int b = 1; //varibale que al tener static se aloca en el Data segment, es como si fuera global pero con scope local!. Y ademas el static hace que sea inicializada por unica vez en valor 1 y va a preservar su valor entre llamado y llamado.
    void *p = malloc(4)// p en el stack, apunta al heap
    free(p) //Libero el bloque de 4 bytes del heap! pero el puntero P sigue estando en el stack.

    char* c = 'ABC' // ABC ES UNA CONSTANTE! C es un puntero y va a tener la direccion de memoria de la constante, y entonces c apunta al code segment. C esta en el stack. NO SE PUEDE MODIFICAR

    char arreglo[] = "ABC" // el array se inicializa con ABC y se aloca en el Stack! se aloco ABC\0
} //fin del scope, todas las variables locales que estaban en el stack de foo son liberadas
```

### **Diferencia entre char* y char[]**

`char *a = "ABC"` En este caso 'a' es un puntero que ocupa 4bytes en el stack. Y tiene la direccion de memoria que tiene la constante("ABC") en el code segment.

`char b[] = "ABC"` En este caso, b es un arreglo de 4 bytes (ABC\0).

`b[0] = 'X'` Sin problema, b[0] es el primer elemento del arreglo que se apilo en el stack y se puede modificar :D
`a[0] = 'X'` Da Segmentation Fault porque a[0] es el primer BYTE de la cadena "ABC" del code segmente y EN EL CODE SEGMENT NO SE PUEDE ESCRIBIR!!! D:

### Punteros

Un puntero es una variable que guarda una direccion de memoria.

operador &: me da la direccion de memoria
operador *: Dereferencia o accede a la memoria cura direccion esta guardada en

Punteros a funciones: punteros al code segment

```C
int g(char){} //funcion g, que recibe un char y devuelve intercambiar
int(*p)(char); //puntero a una funcion que reciba char y devuelva int

p = &g;  // asigno a p la direccion de g, o sea el puntero a punta a la funcion g
```
Lectura rara pero que **SUPER TOMAN EN FINALES!**: Tenemos que tratar de leerlo del centro a la punta

- `char *a[10]`: *a a "a apunta a " char y luego leo que son 10 de esos, entonces "a" es un arreglo de 10 punteros a char

- `char (*c) [10]`: primero veo que tengo (*c), o sea que C apunta a algo... si digo `X==*c` voy a tener `char X[10]` entonces X es un array de 10 chars, entonces finalmente tenemos a:  C que apunta a un array de 10 chars

- `char (*f)(int)[10]`:
    1. Nos fijamos el centro: F
    2. Tenemos (*f), hacemos el truco de `X==*f`
    3. ahora tenemos `char X(int)[10]`
    4. vemos `char X(int)`: es una firmade una funcion que recibe int y devuelve char, decodificando X, tenemos `char (*f)(int)` un puntero a funcion que recibe int y devuelve char
    5. `char (*f)(int)[10]` f es un array de 10 punteros a funcion que reciben int y retornan chars

Simplificacion de la notacion:
`typedef char*X[10]` el tipo X es un array de 10 punteros a char
`X my_array == char *my_array[10]`

### Buffer overflow

Funciones inseguras que no ponen un limite en el tamaño de buffer que usan:
- gets(buf);
- strcpy(dst, src);
no usarlas!, mejor usar otras que si permiten definir un limite, pero es responsabilidad del programador poner algo coherente!
- getline(buf, max_buf_size, stream);
- strncpy(dst, src, max_dst_size)

## Proceso de Compilación

###Compilación
- **Pre compilacion**:  Su misión es buscar, en el texto del programa fuente entregado al compilador, ciertas directivas que le indican realizar alguna tarea a nivel de texto. Por ejemplo, inclusión de otros archivos, o sustitución de ciertas cadenas de caracteres (símbolos o macros) por otras. El preprocesador cumple estas directivas en forma similar a como podrían ser hechas manualmente por el usuario, utilizando los comandos de un editor de texto ("incluir archivo" y "reemplazar texto"), pero en forma automática. Una vez cumplidas todas estas directivas, el preprocesador entrega el texto resultante al resto de las etapas de compilación, que terminarán dando por resultado un módulo objeto.

- **Compilacion posta**:  El compilador acepta un archivo fuente, posiblemente relacionado con otros (una unidad de traducción), y genera con él un módulo objeto. Este módulo objeto contiene porciones de código
ejecutable mezclado con referencias, aún no resueltas, a variables o funciones cuya definición no
figura en los fuentes de entrada. Estas referencias quedan en forma simbólica en el módulo objeto
hasta que se resuelvan en un paso posterior.
- **Link editor**: [TEFI PONE ACA COSAS]

### Linkeo:

El linkeditor recibe como entrada un conjunto de módulos objeto y busca resolver, o enlazar, las
referencias simbólicas en ellos, buscando la definición de las variables o funciones faltantes en los
mismos objetos o en bibliotecas. Estas pueden ser la biblioteca standard u otras provistas por el
usuario. Cuando encuentra la definición de un objeto buscado (es decir, de una variable o función), el
linker la copia en el archivo resultante de salida (la resuelve). El objetivo del linker es resolver todas
las referencias pendientes para producir un programa ejecutable.

### Loader:
El loader es un administrador de módulos objeto. Su función es reunir módulos objeto en
archivos llamados bibliotecas, y luego permitir la extracción, borrado, reemplazo y agregado de
módulos. El conjunto de módulos en una biblioteca se completa con una tabla de información sobre
sus contenidos para que el linker pueda encontrar rápidamente aquellos módulos donde se ha definido
una variable o función, y así extraerlos durante el proceso de linkedición. El loader es utilizado
por el usuario cuando desea mantener sus propias bibliotecas. La creación de bibliotecas propias del
usuario ahorra tiempo de compilación y permite la distribución de software sin revelar la forma en que
se han escrito los fuentes y protegiéndolo de modificaciones. **[[chequeaaaaaaaaaar]]**
