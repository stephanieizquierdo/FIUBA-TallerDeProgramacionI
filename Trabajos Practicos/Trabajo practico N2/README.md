# Verificador eBPF - Ejercicio N°2

###### Autora: Stephanie Izquierdo Osorio, Padrón: 104196

## Programa:

Este ejercicio consta de hacer un verificador de codigo eBPF y detectar si hay bucles o lineas sin usar.

Para ejecutar este programa se utiliza la siguiente linea
 ```
  ./tp <cant_hilos> <archivo1> <archivo2>...
 ```

## Modelo:

  Para llevar a cabo este ejercicio se modelaron las siguientes clases:
  
  Por un lado se tiene el Verificador que trabaja con dos instancias de la clase Repositorio y tambien lanza instancias de la clase Procesador_BPF, que a su vez hereda de thread. Verificador se encarga de instanciar los hilos necesarios y le delega la responsabilidad de procesar los archivos. Luego imprime por pantalla los resultados.

  <p align="center">
  <img src="https://github.com/stephanieizquierdo/Taller-TP2/blob/main/relaci%C3%B3n_externa.png">
  </p>
  
  Y la clase Procesador_BPF es la que se encarga de obtener archivos e instanciar las clases necesarias para delegarles la responsabilidad de modelar, analizar y obtener un resultado. Luego este resultado lo inserta en el repositorio de resultados.
  
  <p align="center">
  <img src="https://github.com/stephanieizquierdo/Taller-TP2/blob/main/Relaciones_mas_profundas.png">
  </p>
  

## Cambios respecto de la primera entrega:

 issue #1 :Se simplificaron las funciones y se modularizó más.
 
 issue #2: Se prestó más atención a los pasajes por copias y se declaro const en los lugares que correspondia.
 
 issue #3 : Se agregó documentación en el código.
  
 issue #4: Se agregó concurrencia
 
 Se modelaron más entidades.
 
