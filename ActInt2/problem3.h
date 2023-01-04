#include <climits>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

// Funcion booleanda que indica si existe un camino desde el nodo inicial al
// final en el grafo residual. Ademàs agrega el recorrido realizado al vector
// que guarda el camino. Al usar un recorrido en amplitud con implementacion en
// matriz de adyacencia,
// Complejidad: O(V^2), donde V = numero de vertices del grafo.
bool camino(vector<vector<int>> residual, int nodoInicial, int nodoFinal, int nV, int recorrido[]) {
  // Vector que marca si los vertices ya fueron visitados
  vector<bool> visitado(nV, false);

  // El camino se recorre usando una tecnica similar a la busqueda en amplitud,
  // por lo que se crea una fila queue
  queue<int> q;
  q.push(nodoInicial);          // se agrega el nodo inicial al q
  visitado[nodoInicial] = true; // se marca ese nodo como visitado
  recorrido[nodoInicial] = -1; 	// y como no hay un camino antes del inicial se marca en el arreglo
          						// que lleva registro del nodo anterior en el recorrido con con -1.

  // Recorriendo el grafo en amplitud
  while (!q.empty()) { // mientras no este vacio
    int u = q.front(); // nodo procesado
    q.pop();

    // por cada vertice
    for (int v = 0; v < nV; v++) {
      if (!visitado[v] && residual[u][v] > 0) {
        // Si existe una conexion al nodo final
        // almacenamos el nodo anterior como parte del camino
        // recorrido y regresamos TRUE, existe un camino
        if (v == nodoFinal) {
          recorrido[v] = u;
          return true;
        }

        q.push(v);          // se encola el nodo
        recorrido[v] = u;   // se agrega su recorrido anterior
        visitado[v] = true; // se marca como visitado
      }
    }
  }

  // Si el proceso no se detuvo y la queue esta vacia
  // significa que no existe un camino del nodo inicial
  // hasta el final y se devuelve falso
  return false;
}

// Funcion que encuentra el flujo maximo de un grafo
// sus argumentos son el grafo, el nodo inicial, final y el numero de vertices
// del grafo.
// Complejidad: O(EV^3), donde E = aristas, V = vertices
void fordFulkerson(vector<vector<int>> grafo, int nodoInicial, int nodoFinal, int nV) {

  // Se crea un grafo residual, que almacena el flujo que
  // aun se puede utilizar en las aristas del grafo
  // se inicializa con las mismos valores del grafo original
  // porque representan las capacidades maximas de flujo
  // de cada arista que conecta dos vertices

  vector<vector<int>> residual = grafo;
  // Se asume que si el valor de una arista ponderada es 0
  // significa que tampoco existe un camino entre esos
  // vertices

  int recorrido[nV]; // Guarda el nodo que precede a cada uno:
                     // recorrido[nodo] = nodoAnterior

  int flujoMax = 0; // Inicializamos el flujo maximo en 0

  // Se aumenta el valor del flujoMax mientras aun se encuentre un camino
  // posible desde el nodo inicial al final usando las capacidades almacenadas
  // en el grafo residual
  while (camino(residual, nodoInicial, nodoFinal, nV, recorrido)) {

    // Encontrar el flujo maximo posible (residual) en el camino, mientras aun
    // haya uno. Para eso se necesita saber la minima capacidad residual en el
    // camino actual, porque la capacidad de un camino limita a los anteriores
    int flujoRes = INT_MAX;
    for (int v = nodoFinal; v != nodoInicial; v = recorrido[v]) {
      int u = recorrido[v];
      flujoRes = min(flujoRes, residual[u][v]);
    }

    // Se actualiza el valor de cada arista con la nueva capacidad residual
    for (int v = nodoFinal; v != nodoInicial; v = recorrido[v]) {
      int u = recorrido[v];
      residual[u][v] -= flujoRes;
      residual[v][u] += flujoRes;
    }

    // se agrega el flujo encontrado al total de flujo maximo
    flujoMax += flujoRes;
  }

  // Se muestra cual es el valor del flujo maximo en el recorrido
  cout << "Flujo maximo desde ";
  cout << nodoInicial << " a " << nodoFinal;
  cout << " es de " << flujoMax << endl;
}
