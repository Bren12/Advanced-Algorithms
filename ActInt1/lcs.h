#include <iostream>
#include <string>
using namespace std;

// Estructura que almacena
struct LCS {
  int inicio;
  int fin;
  string cadena;
};

// Función que encuentra el substring en común más largo
// Complejidad de O(m*n), en donde “n” depende del tamaño del primer string
//                        y “m” depende de la tamaño del segundo string.
LCS LCSubStr(string X, string Y) {
  // Tamaño de ambos strings a comparar
  int m = X.length();
  int n = Y.length();

  // tamaño del substring resultado
  int result = 0;
  // indice de fin del substring
  int end;

  // Matriz que almacena el resultado de las dos filas
  // consecutivas al mismo tiempo
  int len[2][n + 1];

  //  fila  actual de la matriz
  int currRow = 0;

  // Para cada valor i y j, len[currRow][j] almacena la
  // la longitud de la subcadena en compun más larga.
  // En el string 1 desde pos 0 hasta pos i
  // En el string 2 desde pos 0 hasta pos j
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        len[currRow][j] = 0;
      } else if (X[i - 1] == Y[j - 1]) {
        len[currRow][j] = len[1 - currRow][j - 1] + 1;
        if (len[currRow][j] > result) {
          result = len[currRow][j];
          end = i - 1;
        }
      } else {
        len[currRow][j] = 0;
      }
    }

    // Convierte la fila actual en la fila anterior
	// y la fila anterior en la nueva fila actual.
    currRow = 1 - currRow;
  }

  LCS sub;

  // No hay substrings en comun
  if (result > 0) {
    sub.inicio = end - result + 1;
    sub.fin = end;
    sub.cadena = X.substr(end - result + 1, result);
  }
  // Existen substrings en comun
  else {
    sub.inicio = -1;
    sub.fin = -1;
    sub.cadena = "";
  }

  return sub;
}
