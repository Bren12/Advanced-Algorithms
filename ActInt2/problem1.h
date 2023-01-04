#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Estructura del grafo, que tiene un "vertex",
// que representa la cantidad de colonias,
// una matriz "dist" que representan las distancias
// en km entre colonias y otra matriz "cap" que 
// representan las capacidades máximas de flujo de
// datos entre colonia.
struct graph {
  int vertex;               // Cantidad de vértices.
  vector<vector<int>> dist; // Lista de distancias.
};

// Estructura para comprender la ruta que se va a
// tomar y poder elegir la más óptima, de acuerdo
// a nodos padres y la clasificación por unión.
struct path {
  int *parent;
  int *rank;
};

// =================================================================
// Función que ayuda a buscar el nodo padre de un determinado nodo.
//
// Complejidad: O(1), en el mejor de los casos, ya que puede
//                    ejecutar las intrucciones una sola vez.
// Complejidad: O(E), en el peor de los casos, donde "E" depende
//                    de la cantidad de conexiones que se han hecho
//                    por el momento.
// =================================================================
int find(int i, path p) {
  // Significa que todavía no se ha asignado
  // un padre al nodo "i", por lo cuál podemos
  // acceder a él y agregarlo a la ruta.
  if (p.parent[i] == -1) {
    return i;
  }
  // En caso contrario, a dicho nodo le asigna como 
  // padre el padre raíz/origen de la ruta completa.
  return p.parent[i] = find(p.parent[i],p);
}

// =================================================================
// Función que ayuda a verificar la posible unión entre vértices
// y actualiza parámetros para futuros cálculos.
//
// Complejidad: O(1), en el mejor de los casos, ya que puede
//                    ejecutar las intrucciones una sola vez.
// Complejidad: O(E), en el peor de los casos, donde "E" depende
//                    de la cantidad de conexiones que se han hecho
//                    por el momento.
// =================================================================
void join(int start, int end, path p) {

  // Obtiene la raíz de cada nodo.
  int n1 = find(start,p);
  int n2 = find(end,p);

  // Verifica que los nodos no tengan la 
  // misma raíz y se forme un ciclo.
  // Aquí es donde se van a ir enlazando los vértices.
  if (n1 != n2) {
    // Si la clasificación del nodo de origen del 1
    // es menor que la del origen del nodo 2,
    // actualizamos el nodo padre/raíz del 1 con el origen
    // del nodo 2, así como actualizamos la clasificación
    // del nodo 2.
    if (p.rank[n1] < p.rank[n2]) {
      p.parent[n1] = n2;
      p.rank[n2] += p.rank[n1];
    }
    // Si la clasificación del nodo de origen del 1
    // es mayor o igual que la del origen del nodo 2,
    // actualizamos el nodo padre/raíz del 2 con el origen
    // del nodo 1, así como actualizamos la clasificación
    // del nodo 1.
    else {
      p.parent[n2] = n1;
      p.rank[n1] += p.rank[n2];
    }
  }
  
}

// =================================================================
// Función que ayuda a verificar la posible unión entre vértices
// y actualiza parámetros para futuros cálculos.
//
// Complejidad: O(E log(E)) o O(E log(V)), en donde "E" depende de
//              la cantidad de arcos y "V" depende de la cantidad
//              de vértices.
// =================================================================
void kruskal(graph g) {

  // Ordena en forma ascendente la matriz de distancias.
  // Primeramente ordena cada vector dependiendo de la
  // distancia, luego por el vértice de origen, y
  // finalmente por el vértice destino.
  sort(g.dist.begin(), g.dist.end());

  // Se inicializan los párametros del path, 
  // para encontrar la ruta más óptima para
  // cablear las colonias.
  path check;

  check.parent = new int[g.vertex];
  check.rank = new int[g.vertex];

  for (int i = 0; i < g.vertex; i++) {
    check.parent[i] = -1;
    check.rank[i] = 1;
  }

  // Se inicializa la distancia mínima a 0.
  int minDist = 0;

  // Recorremos cada arco existente.
  for (auto edge : g.dist) {
    
    // Extraemos los datos de cada arco.
    int dist = edge[0];
    int start = edge[1];
    int end = edge[2];

    // Verifica que los nodos no tengan la 
    // misma raíz y se forme un ciclo.
    if (find(start,check) != find(end,check)) {
      // Agrega el nodo a la ruta.
      join(start,end,check);
      // Actualiza el acumulador de la distancia.
      minDist += dist;
      // Despliega la lista de arcos.
      cout << "(" << start << "," << end << ") -> " << dist << endl;
    }
  }

  cout << "\nDistancia Minima: " << minDist << endl;
}
