# Instrucciones

Escribe en C++ un programa que ayude a una empresa que quiere incursionar en los servicios de Internet respondiendo a la situación problema 2.



***



El programa debe:

1. Leer un archivo de entrada que contiene la información de un grafo representado en forma de una matriz de adyacencias con grafos ponderados
El peso de cada arista es la distancia en kilómetros entre colonia y colonia, por donde es factible meter cableado.

    * El programa debe desplegar cuál es la forma óptima de cablear con fibra óptica conectando colonias de tal forma que se pueda compartir información entre cuales quiera dos colonias.

2. Debido a que las ciudades apenas están entrando al mundo tecnológico, se requiere que alguien visite cada colonia para ir a dejar estados de cuenta físicos, publicidad, avisos y notificaciones impresos. por eso se quiere saber ¿cuál es la ruta más corta posible que visita cada colonia exactamente una vez y al finalizar regresa a la colonia origen?

    * El programa debe desplegar la ruta a considerar, tomando en cuenta que la primera ciudad se le llamará A, a la segunda B, y así sucesivamente

3. El programa también debe leer otra matriz cuadrada de N x N datos que representen la capacidad máxima de transmisión de datos entre la colonia i y la colonia j. Como estamos trabajando con ciudades con una gran cantidad de campos electromagnéticos, que pueden generar interferencia, ya se hicieron estimaciones que están reflejadas en esta matriz.

    * La empresa quiere conocer el flujo máximo de información del nodo inicial al nodo final. Esto debe desplegarse también en la salida estándar.



***



## Entrada
Un numero entero N que representa el número de colonias en la ciudad.
<br>
<br>
Matriz cuadrada de N x N que representa el grafo con las distancias en kilómetros entre las colonias de la ciudad.
<br>
<br>
Matriz cuadrada de N x N que representa las capacidades máximas de flujo de datos entre colonia i y colonia j.

## Salida:
1. Forma de cablear las colonias con fibra.
    * Lista de arcos de la forma (A,B).
2. Ruta a seguir por el personal que reparte correspondencia, considerando inicio y fin en al misma colonia.
3. Valor de flujo máximo de información del nodo inicial al nodo final.



***



# Ejemplo de entrada:
4

<br>

0 16 45 32

16  0 18 21

45 18  0  7

32 21  7  0

<br>


0 48  12  18

52  0 42 32

18 46  0 56

24 36 52  0


# Ejemplo de salida:

<br>
-------------------------------------

Problem 1

(2,3)

(0,1)

(1,2)

<br>
-------------------------------------

Problem 2

Minimum cost: 73

Path: 0 1 2 3

<br>
-------------------------------------

Problem 3

Maximum flow from 0 to 3 is 54



***



# Especificaciones

Entrega en este espacio en canvas  un archivo .ZIP llamado A0XXXXXXX_ActInt2, (donde las XXXXXXXs son la matrícula de alguno de los integrantes del equipo) que contenga dentro una carpeta llamada A0XXXXXXX_ActInt2, en donde se encontrará UN único archivo .cpp. Se pueden tener uno o más archivos .h. 
Incluye un archivo team.txt que incluya los nombres de todos los integrantes del equipo, con sus matrículas y las partes específicas del proyecto en las que trabajó cada quien 
Incluye también los  archivos ReflexActInt2_A0XXXXXXX.pdf

Ten en cuenta que tu programa se probará con casos de prueba grandes.

Se tendrá una sesión de revisión donde a cada integrante del equipo se le harán preguntas específicas y todos deben saber cómo funciona cada parte de la solución propuesta



***



# **Ponderación**

Para obtener el **100%** de los puntos de esta actividad, se divide en:

* **80%** - Cumple correcta y eficientemente con la funcionalidad requerida por parte de la actividad:
    * **20%** - Primera parte del output (forma de cableado óptimo).
    * **20%** - Segunda parte del output (ruta para repartir correspondencia).
    * **20%** - Tercera parte del output (substring más largo común).
    * **20%** - Cuarta parte del output (lista de polígonos).
* **15%** - El documento de reflexión incluye la explicación de diferentes algoritmos aplicados a esta situación problema, así como la complejidad computacional de cada uno de ellas.
* **5%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación.



***