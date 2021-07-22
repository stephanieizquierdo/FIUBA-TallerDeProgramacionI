# Taller de programacion 1 [75.42] - RESUMEN

## Memoria en C/C++
    Los punteros son del mismo tamaño
### Exacta reserva de memoria:
    Depende de la arquitectura y del compilador cuanto ocupa cada tipo de dato.

### Alineación y Padding:
    Donde se ubica el comienzo de las variables. Los objetos se pueden almacenar en un numero de memoria que es multiplo de 4/8 para tener mayor velocidad de acceso.

    Ejemplo con estructura:

    ```C
    struct S{       //D= disponible, -= No disponible, es espacio que queda sin utilizar
        int a;  //         |D|D|D|D| -> |0|0|0|1| 4bytes
        char b; //         |D|-|-|-| -> |2|-|-|-| 4bytes
        int c; //          |D|D|D|D| -> |0|0|0|3| 4bytes
        char d; //         |D|-|-|-| -> |4|-|-|-| 4bytes
    };

    struct S s= {1,2,3,4};  
    ```

    Podemos ver como cada campo se alinea en la memoria para ser multiplo de cuatro. Ganamos velocidad apesar de desperdiciar espacio. El tamaño de la estructura es de 16 Bytes, que no es lo mismo que la suma del tamaño de cada tipo de dato independientemente, que es 10.

    Ejemplo para no desperdiciar espacio:

    ```C
    struct S{       //D: disponible, -: No disponible, es espacio que queda sin utilizar
        int a;  //         |D|D|D|D| -> |0|0|0|1| 4bytes
        char b; //         |D|D|D|D| -> |2|0|0|0| 4bytes
        int c; //          |D|D|-|-| -> |3|4|-|-| 4bytes  
        char d; //       
    }__attribute__((packed));;

    struct S s= {1,2,3,4};  
    ```    
    Al usar la directiva packed informamos que queremos todos los datos uno atras del otro, sin desperdicio de memoeria en el medio. Podemos observar que seguimos desperdiciando memoria al final pero es mucho menor. Ahora sizeof(S) es 12.

### Endianess:
    Existen dos tipos de almacenamiento

    - BigEndian: Las variables se almacenan como lo lo hacemos numericamente, comenzando por el bit mas significativo y terminamos por el menos significativo.

    - LittleEndian: Los bytes se invierten de orden segun bigEndian
    ```C
    int i = 1; // BE= |0|0|0|1|   LE = |1|0|0|0|
    int j = 1023; // BE= |0|0|3|ff|   LE = |ff|3|0|0|
    ```
