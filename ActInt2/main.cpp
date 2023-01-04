// E2 - Actividad Integradora 2
//
// A00831991 - Eunice Santos Galindo
// A00829855 - Brenda Elena Saucedo Gonz�lez
// A00830568 - Edgar Alexandro Castillo Palacios
#include <fstream>
#include "problem1.h"
#include "problem2.h"
#include "problem3.h"

// =================================================================
// Funci�n que ayuda a verificar la posible uni�n entre v�rtices
// y actualiza par�metros para futuros c�lculos.
//
// Complejidad: O(c), en donde "c" depende de la cantidad de
//                    caracteres en cada l�nea.
// =================================================================
void removeSpace(string line, vector<int> &infoGraph) {

  // Mientras la l�nea no este vac�a, la seguimos procesando.
  while (line != "") {

    // Buscamos espacios en la l�nea.
    size_t found = line.find(" ");

    // Si encontramos espacios, procedemos a continuar.
    if (found != string::npos) {

      // Si en la primera posici�n no hay un espacio,
      // procesamos el dato substraido de la l�nea y
      // la agregamos al vector de tipo entero.
      if (line.substr(0,1) != " ") {
        infoGraph.push_back(stoi(line.substr(0, found + 1)));
      }

      // Eliminamos la parte que substraida y procesada,
      // as� como el espacio encontrado.
      line = line.substr(found + 1, line.length() - found);

    }
    // En caso de que no se haya encontrado un espacio en la l�nea.
    else {
      
      // Verificamos si hay un salto de l�nea, para quitarlo
      // de lo que resta de esta misma y agregarla al vector.
      if (line.substr(line.length() - 1, line.length()) == "\n") {
        infoGraph.push_back(stoi(line.substr(0, line.length() - 1)));
      }
      // Si no hay un salto de l�nea, solamente la procesamos
      // y agregamos al vector.
      else {
        infoGraph.push_back(stoi(line));
      }

      // Vaciamos la l�nea.
      line = "";
      
    }
    
  }
  
}

// =================================================================
// Funci�n principal.
// =================================================================
int main() {
  // cont = auxiliar que ayuda a contar las l�neas del archivo
  //        para las entradas necesarias.
  // row = fila actual de la matriz.
  int cont = 0, row = 0;
  // g = grafo sobre el que se esta trabajando.
  graph g;
  // line = almacena cada l�nea del archivo.
  string line;
  // Almacena la informaci�n de cada l�nea procesada y
  // convertida a entero.
  vector<int> infoGraph;
  // Matriz que almacena las distancias para el problema 2.
  vector<vector<int>> matrixDist;
  // Matriz que almacena las capacidades para el problema 3.
  vector<vector<int>> matrixCap;
  
  // Abrimos el archivo que contiene la informaci�n del grafo.
  ifstream file("input.txt");

  // Obtenemos cada l�nea del archivo.
  while (getline(file, line)) {

    // Mientras la l�nea no este vac�a la procesamos.
    if (line != "") {

      // Remueve los espacios de la l�nea
      // y substraemos la informaci�n de los grafos.
      removeSpace(line,infoGraph);

      // La 1ra iteraci�n es la cantidad de v�rtices.
      if (cont == 0) {
        g.vertex = infoGraph[0];
      } else {
        // Las sigiuentes "v" l�neas son las distancias
        // en km entre colonias.
        if (cont <= g.vertex) {
          for (int i = 0; i < infoGraph.size(); i++) {
            if (infoGraph[i] > 0) {
              g.dist.push_back({infoGraph[i], row, i});
            }
          }
          matrixDist.push_back(infoGraph);
        }
        // Las sigiuentes "v" l�neas son las capacidades
        // m�ximas de flujo de datos entre colonias.
        else {
          matrixCap.push_back(infoGraph);
        }

        // Actualizamos el valor de las filas.
        row++;
      }

      // Actualizamos el contador de l�neas.
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

  // Ejecutamos determinados m�todo y/o algoritmo para la soluci�n de cada sub-problema.
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

Entrada: Un numero entero N que representa el n�mero de colonias
          en la ciudad.
         Matriz cuadrada de N x N que representa el grafo con las
          distancias en kil�metros entre las colonias de la ciudad.
         Matriz cuadrada de N x N que representa las capacidades
          m�ximas de flujo de datos entre colonia i y colonia j.
         Lista de N pares ordenados de la forma (A,B) que representan
          la ubicaci�n en un plano coordenado de las centrales.

Salida: 1. Forma de cablear las colonias con fibra.
           - Lista de arcos de la forma (A,B).
        2. Ruta a seguir por el personal que reparte correspondencia,
           considerando inicio y fin en al misma colonia.
        3. Valor de flujo m�ximo de informaci�n del nodo
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
