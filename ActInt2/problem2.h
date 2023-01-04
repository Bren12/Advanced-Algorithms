#include <iostream>
#include <vector>

using namespace std;

void TSP(vector<vector<int>> matrizAd) {

  // Se define el índice del nodo por el que se empieza el camino
  int nodoInicial = 0;

  // Se crea un vector con los nodos que faltan por visitar
  vector<int> nodosFaltantes;
  for (int i = 1; i < matrizAd.size(); i++) {
    nodosFaltantes.push_back(i);
  }

  // Se almacena un costo INF para comparar en la primera iteración con el
  // mínimo
  int costoMinimo = 999;
  // Se crea un vector donde se almacenara los indices de las colonias que
  // forman la ruta de menor costo
  vector<int> ruta;

  // Se calculan los costos para todas las rutas
  do {
    // Variable para almacenar el costo temporal
    int nuevoCosto = 0;
    // Vector para almacenar la ruta temporal
    vector<int> nuevaRuta;
    // Se empieza la ruta
    nuevaRuta.push_back(nodoInicial);
    // Se define el nodo en el que nos encontramos
    int nodoActual = nodoInicial;
    // Se van recorriendo los demás nodos y calculando costos
    for (int i = 0; i < nodosFaltantes.size(); i++) {
      nuevoCosto += matrizAd[nodoActual][nodosFaltantes[i]];
      nuevaRuta.push_back(nodosFaltantes[i]);
      nodoActual = nodosFaltantes[i];
    }
    // Costo de regreso al inicio
    nuevoCosto += matrizAd[nodoActual][nodoInicial];
    // Se regresa al inicio
    nuevaRuta.push_back(nodoInicial);

    // Si el costo de la nueva ruta es menor al que se tenia se almacena y se
    // actualiza junto con la ruta
    if (nuevoCosto < costoMinimo) {
      costoMinimo = nuevoCosto;
      ruta = nuevaRuta;
    }

  }
  // Se prueban todas las posibles rutas
  while (next_permutation(nodosFaltantes.begin(), nodosFaltantes.end()));

  // Se imprime la ruta final (menor costo)
  cout << "Ruta a seguir: ";
  for (int i = 0; i < ruta.size(); i++) {
    cout << static_cast<char>(65 + ruta[i]) << " ";
  }
  cout << endl;

  // Se imprime el costo de la ruta
  cout << "Costo de la ruta: " << costoMinimo << endl;
}
