// E2 - Actividad Integradora 2
//
// A00831991 - Eunice Santos Galindo
// A00829855 - Brenda Elena Saucedo González
// A00830568 - Edgar Alexandro Castillo Palacios
#include <fstream>
#include "problem1.h"
#include "problem2.h"
#include "problem3.h"

// =================================================================
// Función que ayuda a verificar la posible unión entre vértices
// y actualiza parámetros para futuros cálculos.
//
// Complejidad: O(c), en donde "c" depende de la cantidad de
//                    caracteres en cada línea.
// =================================================================
void removeSpace(string line, vector<int> &infoGraph) {

  // Mientras la línea no este vacía, la seguimos procesando.
  while (line != "") {

    // Buscamos espacios en la línea.
    size_t found = line.find(" ");

    // Si encontramos espacios, procedemos a continuar.
    if (found != string::npos) {

      // Si en la primera posición no hay un espacio,
      // procesamos el dato substraido de la línea y
      // la agregamos al vector de tipo entero.
      if (line.substr(0,1) != " ") {
        infoGraph.push_back(stoi(line.substr(0, found + 1)));
      }

      // Eliminamos la parte que substraida y procesada,
      // así como el espacio encontrado.
      line = line.substr(found + 1, line.length() - found);

    }
    // En caso de que no se haya encontrado un espacio en la línea.
    else {
      
      // Verificamos si hay un salto de línea, para quitarlo
      // de lo que resta de esta misma y agregarla al vector.
      if (line.substr(line.length() - 1, line.length()) == "\n") {
        infoGraph.push_back(stoi(line.substr(0, line.length() - 1)));
      }
      // Si no hay un salto de línea, solamente la procesamos
      // y agregamos al vector.
      else {
        infoGraph.push_back(stoi(line));
      }

      // Vaciamos la línea.
      line = "";
      
    }
    
  }
  
}

// =================================================================
// Función principal.
// =================================================================
int main() {
  // cont = auxiliar que ayuda a contar las líneas del archivo
  //        para las entradas necesarias.
  // row = fila actual de la matriz.
  int cont = 0, row = 0;
  // g = grafo sobre el que se esta trabajando.
  graph g;
  // line = almacena cada línea del archivo.
  string line;
  // Almacena la información de cada línea procesada y
  // convertida a entero.
  vector<int> infoGraph;
  // Matriz que almacena las distancias para el problema 2.
  vector<vector<int>> matrixDist;
  // Matriz que almacena las capacidades para el problema 3.
  vector<vector<int>> matrixCap;
  
  // Abrimos el archivo que contiene la información del grafo.
  ifstream file("input.txt");

  // Obtenemos cada línea del archivo.
  while (getline(file, line)) {

    // Mientras la línea no este vacía la procesamos.
    if (line != "") {

      // Remueve los espacios de la línea
      // y substraemos la información de los grafos.
      removeSpace(line,infoGraph);

      // La 1ra iteración es la cantidad de vértices.
      if (cont == 0) {
        g.vertex = infoGraph[0];
      } else {
        // Las sigiuentes "v" líneas son las distancias
        // en km entre colonias.
        if (cont <= g.vertex) {
          for (int i = 0; i < infoGraph.size(); i++) {
            if (infoGraph[i] > 0) {
              g.dist.push_back({infoGraph[i], row, i});
            }
          }
          matrixDist.push_back(infoGraph);
        }
        // Las sigiuentes "v" líneas son las capacidades
        // máximas de flujo de datos entre colonias.
        else {
          matrixCap.push_back(infoGraph);
        }

        // Actualizamos el valor de las filas.
        row++;
      }

      // Actualizamos el contador de líneas.
      cont++;

      // Reseteamos el valor de las filas para la
      // siguiente matriz.
      if (row % g.vertex == 0) {
        row = 0;
      }

      // Vaciamos el vector para recibir nuevos datos.
      infoGraph.clear();
    }
  }

  // Cerramos el archivo.
  file.close();

  // Ejecutamos determinados método y/o algoritmo para la solución de cada sub-problema.
  cout << "-------------------------------------\nProblema 1\n";
  cout << "-------------------------------------\n";
  kruskal(g);
  
  cout << "\n-------------------------------------\nProblema 2\n";
  cout << "-------------------------------------\n";
  TSP(matrixDist);

  cout << "\n-------------------------------------\nProblema 3\n";
  cout << "-------------------------------------\n";
  fordFulkerson(matrixCap, 0, matrixCap.size()-1, matrixCap.size());

  cout << "-------------------------------------\n";

  return 0;
}

/*
EJEMPLO RUN

Entrada: Un numero entero N que representa el número de colonias
          en la ciudad.
         Matriz cuadrada de N x N que representa el grafo con las
          distancias en kilómetros entre las colonias de la ciudad.
         Matriz cuadrada de N x N que representa las capacidades
          máximas de flujo de datos entre colonia i y colonia j.
         Lista de N pares ordenados de la forma (A,B) que representan
          la ubicación en un plano coordenado de las centrales.

Salida: 1. Forma de cablear las colonias con fibra.
           - Lista de arcos de la forma (A,B).
        2. Ruta a seguir por el personal que reparte correspondencia,
           considerando inicio y fin en al misma colonia.
        3. Valor de flujo máximo de información del nodo
           inicial al nodo final.

-------------------------------------------------------------

Ejemplo de entrada:

4

0   16  45  32
16  0   18  21
45  18  0   7
32  21  7   0

0   48  12  18
52  0   42  32
18  46  0   56
24  36  52  0


Ejemplo de salida:

-------------------------------------
Problema 1
-------------------------------------
(2,3) -> 7
(0,1) -> 16
(1,2) -> 18
Distancia Minima: 41

-------------------------------------
Problema 2
-------------------------------------
Ruta a seguir: A B C D A 
Costo de la ruta: 73

-------------------------------------
Problema 3
-------------------------------------
Flujo maximo desde 0 a 3 es de 78
-------------------------------------
*/
