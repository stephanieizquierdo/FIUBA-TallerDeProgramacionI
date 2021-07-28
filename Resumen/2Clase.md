# Taller de programacion 1 [75.42] - **RESUMEN**
###### Stephanie Izquierdo Osorio


## **Redes TCP/IP**

### Medio compartido
Los mensajes son recibidos por todos. Solo un participante puede hablar a la vez, entonces la performance se degrada a mayor cantidad de participantes.

### Protocolo Ip (simplificado)
El medio es segmentado. Los mensajes son ruteados a sus destinos(hosts).
Son redes _Best effort_: los paquetes se pueden perder o pueden llegar en desorden o duplicados (Esto ultimo es porque los mensajes pueden tomar distintos caminos para llegar al destinatario).

Un router puede no enviarmensajes porque o esta caido, o esta super saturado o no hay un link

### Protocolo TCP
Corre sobre IP, permite el direccionamiento a nivel de servicio (port/puerto).
Genera una especie de tunel virtual (stream) entre emisor y receptor. Entones se dice que esta orientado a bytes y no a mensajes. Los bytes no se pierden, desordenan ni se duplican.
Pero no garantiza que se mantenga la division entre los paquetes.

Tcp solo entiende entre servidor y cliente, siendo servidor el pasivo y cliente el activo.

### Protocolo DNS

El destino tiene nombre de dominio.
La registracion de dominios se hace a nivel gunernamental.
La resolucion de un dominio a una o varias direcciones IP las hace el servidor de DNS

## Protocolo de texto vs protocolo binario

### Binarios
Son simples y eficientes en terminos de memoria y velocidad de procesamiento. Son dificiles de debuggear. Es necesario tomar en consideracion el endianess, el padding, los tamaños y los signos.

### Texto

Son lentos, ineficientes y mas dificiles de parsear pero mas facil de debuggear. Son independientes del endianess, padding t otros pero dependen del encoding del texto (los simbolos especiales no ocupan si o si 1 byte) y que caracteres se usan como delimitadores.


## **Manejo de archivos**

- fseek(file, posicion, modo): Nos posiciona en el archivo donde le indiquemos.
- ftell(file): nos dice en la posicion que estamos
- rewind(file): Nos posicionan al comienzo del archivo
- ftruncate sirve para cortar el archivo. O sea digo ahora se termina aca.

Para escribir/leer en archivos binarios usar: fread y fwrite.

### Como saber el tamaño de un archivo
```C
fseek(file, 0, SEEK_END);
printf("Tamaño del archivo: %d bytes.\n", ftell(file));

rewind(file) //para volver al comienzo
```

### Formas de apertura de archivos

- "r" : Lectura. El archivo **debe** existir.
- "w" : Escritura (**crea** el archivo si no existe; Sobreescribe uno existente)
- "a" : Append, crea el archivo si no existe, si existe **continua al final**
- "r+": Lectura y escritura. Empieza al principio. El archivo **debe** existir. podemos ir sobreescribiendo el archivo
- "w+": Lectura y escritura (sobreescribe el archivo si existe) El archivo es reseteado de entrada.
- "a+": Lectura y escritura. Hace Apend si existe el archivo. (se abre al final)
- "b" : Para lectoescritura de archivos binarios. (se usa con alguno de los anteriores, ej: "r+b")
- "t" : Para lectoescritura de archivos en modo texto.

Estos ultimos dos modos, en linux no se usan. Es para windows.
