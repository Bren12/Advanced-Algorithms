# Instrucciones

Escribe un programa en C++ que lea 5 archivos de texto (de nombre fijo, no se piden al usuario) que contienen exclusivamente caracteres del 0 al 9,
caracteres entre A y F y saltos de línea:
- transmission1.txt
- transmission2.txt
- mcode1.txt
- mcode2.txt
- mcode3.txt

Los archivos de transmision contienen caracteres de texto que representan el envío de datos de un dispositivo a otro.
<br>
Los archivos mcodex.txt representan código malicioso que se puede encontrar dentro de una transmisión.



***



El programa debe:

1. Analizar si el contenido de los archivos mcode1.txt, mcode2.txt y mcode3.txt están contenidos en los archivos transmission1.txt y transmission2.txt
y desplegar un true o false si es que las secuencias de chars están contenidas o no. En caso de ser true, muestra true, seguido de exactamente un espacio,
seguido de la posición en el archivo de transmissiónX.txt donde inicia el código de mcodeY.txt.

2. Suponiendo que el código malicioso tiene siempre código "espejeado" (palíndromos de chars), sería buena idea buscar este tipo de código en una transmisión.
El programa después debe buscar si hay código "espejeado" dentro de los archivos de transmisión. (palíndromo a nivel chars, no meterse a nivel bits).
El programa muestra en una sola linea dos enteros separados por un espacio correspondientes a la posición (iniciando en 1) en donde inicia y termina el código
"espejeado" más largo (palíndromo) para cada archivo de transmisión. Puede asumirse que siempre se encontrará este tipo de código.

3. Finalmente el programa analiza que tan similares son los archivos de transmisión, y debe mostrar la posición inicial y la posición final (iniciando en 1)
del primer archivo en donde se encuentra el substring más largo común entre ambos archivos de transmisión.



***



## Entrada
Nada, solamente deben existir los 5 archivos en la misma ruta donde se ejecuta el programa.

## Salida similar:
Parte 1
<br>
(true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode1.txt
<br>
(true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode2.txt
<br>
(true | false) si es que el archivo transmission1.txt contiene el código (secuencia de chars) contenido en el archivo mcode3.txt
<br>
(true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode1.txt
<br>
(true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode2.txt
<br>
(true | false) si es que el archivo transmission2.txt contiene el código (secuencia de chars) contenido en el archivo mcode3.txt
<br>
<br>

Parte 2
<br>
posiciónInicial posiciónFinal (para archivo de transmisión1)
<br>
posiciónInicial posiciónFinal (para archivo de transmisión2)
<br>
<br>

Parte 3
<br>
posiciónInicial posiciónFinal (de substring común más largo entre archivos de transmisión)



***



# Especificaciones

Entrega en este espacio en canvas  un archivo .ZIP llamado A0XXXXXXX_ActInt1, (donde las XXXXXXXs son la matrícula de alguno de los integrantes del equipo)
que contenga dentro una carpeta llamada A0XXXXXXX_ActInt1, en donde se encontrará UN único archivo .cpp. Se pueden tener uno o más archivos .h.
Incluye un archivo team.txt que incluya los nombres de todos los integrantes del equipo, con sus matrículas y las partes específicas del proyecto en las que
trabajó cada quien.
Incluye también los  archivos **ReflexActInt1_A0XXXXXXX.pdf**.

Por favor respeta el nombre exacto (minúsculas, sin acento) de los archivos de entrada, NO se piden al usuario, van directo en el código fuente.
Ten en cuenta que tu programa se probará con archivos grandes.



***



# **Ponderación**

Para obtener el **100%** de los puntos de esta actividad, se divide en:

* **75%** - Cumple correcta y eficientemente con la funcionalidad requerida por parte de la actividad:
    * **25%** - Primera parte del output (búsqueda de subsecuencias).
    * **25%** - Segunda parte del output (palíndromos en las secuencias de transmisión).
    * **25%** - Tercera parte del output (substring más largo común).
* **20%** - El documento de reflexión incluye la explicación de diferentes algoritmos aplicados a esta situación problema,
            así como la complejidad computacional de cada uno de ellas.
* **5%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación.



***
