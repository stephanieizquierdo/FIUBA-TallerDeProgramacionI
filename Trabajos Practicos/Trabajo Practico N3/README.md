# Taller-Pages - Ejercicio N°3

###### Autora: Stephanie Izquierdo Osorio, Padrón: 104196

## Programa:

Este ejercicio consta de establecer una o más conexión entre un/muchos cliente/s y un servidor. Este es quien que atenderá petitorios HTTP, mediante los cuales podrá acceder y dar alta a recursos del mismo.

El cliente se ejecutará usando el siguiente formato:
```
 ./client <server-host> <server-port> 
```

Y el servidor con el siguiente:
 ```
  ./server <server-port> <root_file>
 ```
###### Nota: primero debe ejecutarse el servidor.

## Modelo:

Para este ejercicio se modelaron las siguientes clases:

Del lado del servidor podemos identificar las siguientes clases: Servidor, Items_servidor, Aceptador (hereda de la clase Thread), y ThClient(tambien hereda de la clase Thread), y la relación estre ellas es la siguiente:

<p align="center">
  <img src="https://github.com/stephanieizquierdo/TP3--Taller/blob/main/diagrama_clases_parte_servidor.png">
</p>


A su vez, en los items del servidor se encuentra un parseador, instancia de la clase Parser, y es este quien interpreta los pedidos del cliente y crea un método que puede ser Post, Get (ambas con sus variantes) o Invalido, y son estos tipos de métodos quienes se encargan de responderle correctamente al cliente.

<p align="center">
  <img src="https://github.com/stephanieizquierdo/TP3--Taller/blob/main/Diagrama_clases_items_parser_metodos.png">
</p>

Luego de la parte orientada al cliente tenemos la clase Cliente. Esta, junto con Servidor, se comunican mediante la clase Socket.
<p align="center">
  <img src="https://github.com/stephanieizquierdo/TP3--Taller/blob/main/diagrama_clases_cliente_socket_servidor.png">
</p>
