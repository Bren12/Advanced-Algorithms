#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Para almacenar diferentes tipos de datos.
struct palindrome {
  int posI, posF;
  string pal;
};

// Complejidad: O(n), donde "n" depende del tama�o del texto.
palindrome manacher(string text) {

  // Struct que almacenar� la informaci�n del palindromo.
  palindrome pali;

  // No existe un palindromo de tama�o 0, por lo que retorna.
  if (text.length() == 0) {
  	pali.pal = "";
    pali.posF = -1;
    pali.posI = -1;
  	return pali;
  }
  // Se puede considerar palindromo de tama�o 1, por lo que retorna.
  else if (text.length() == 1) {
  	pali.pal = text;
    pali.posF = 0;
    pali.posI = 0;
  	return pali;
  }

  // Almacena el tama�o del texto.
  int size = 2 * text.length() + 1;

  // Arreglo del Longest-Pattern-Substring
  int lps[size];
  // Inicializa las primeras posiciones.
  lps[0] = 0;
  lps[1] = 1;

  // Inicializamos las pocisiones a recorrer.
  int center = 1, rightC = 2, posMirror;

  // Para habilitar la expansi�n.
  bool expand;

  // Variable auxiliar para calcular la diferncia entre rightC y actualPos.
  int diff = -1;

  // Variables que almacenan el tama�o y posici�n central del palindromo.
  int lpsSize = 0, lpsCenterPosition = 0;

  // Mientras el texto sea mayor que 2, puede existir un palindromo,
  // por lo que continua con el proceso.
  for (int actualPos = 2; actualPos < size; actualPos++) {

    // Calcula la posici�n espejeada de la posici�n actual.
    posMirror = 2 * center - actualPos;

    // Actualiza la expansi�n a falso
    // (no se requiere expandir).
    expand = false;

    // Auxiliar que calcula la diferencia entre
    // la posici�n derecha y la posici�n actual.
    diff = rightC - actualPos;

    // Si la diferencia es mayor o igual a 0, continua
    // con el proceso, ya que la posici�n actual todav�a
    // esta dentro de los limites de la posici�n de la derecha.
    if (diff >= 0) {

      // Caso 1
      if (lps[posMirror] < diff)
        lps[actualPos] = lps[posMirror];

      // Caso 2
      else if (lps[posMirror] == diff && rightC == size - 1)
        lps[actualPos] = lps[posMirror];

      // Caso 3
      else if (lps[posMirror] == diff && rightC < size - 1) {
        lps[actualPos] = lps[posMirror];
        // Habilita la expansi�n.
        expand = true;
      }

      // Caso 4
      else if (lps[posMirror] > diff) {
        lps[actualPos] = diff;
        // Habilita la expansi�n.
        expand = true;
      }
    } else {
      // Si la diferencia es menor que 0, en donde la posici�n actual
      // NO esta dentro de los l�mites de la posici�n de la derecha,
      // actualiza la variable lps con 0 en la posici�n actual.
      lps[actualPos] = 0;
      // Habilita la expansi�n.
      expand = true;
    }

    // Si la expansi�n esta habilitada, continuamos.
    if (expand) {

      // Intentamos expandir el pal�ndromo encontrado en la
      // posici�n actual "actualPos".
      // Para posiciones impares, comparamos caracteres, y
      // si coinciden, incrementamos la longitud de "lps" en 1.
      // Si es una posici�n par, solo incrementamos lps en 1
      // sin ninguna comparaci�n de caracteres.

      while (((actualPos + lps[actualPos]) < size &&
              (actualPos - lps[actualPos]) > 0) &&
             (((actualPos + lps[actualPos] + 1) % 2 == 0) ||
              (text[(actualPos + lps[actualPos] + 1) / 2] ==
               text[(actualPos - lps[actualPos] - 1) / 2]))) {
        lps[actualPos]++;
      }
    }

    // Actualiza el tama�o y la posici�n del LPS si el valor de la
    // posici�n actual del arreglo es mayor que el tama�o actual.
    if (lps[actualPos] > lpsSize) {
      lpsSize = lps[actualPos];
      lpsCenterPosition = actualPos;
    }

    // Si el pal�ndromo est� centrado en la posici�n actual
    // "actualPos", podemos expandir m�s all� de la posici�n
    // de la derecha "rightC", por lo que ajustamos la posici�n
    // central "center" seg�n la expansi�ns del pal�ndromo.
    if (actualPos + lps[actualPos] > rightC) {
      center = actualPos;
      rightC = actualPos + lps[actualPos];
    }
  }

  // Variables que almacenar�n la posici�n del palindromo.
  int start = -1, end = -1;

  // Calcula las posiciones del palindromo en el texto.
  start = (lpsCenterPosition - lpsSize) / 2;
  end = start + lpsSize - 1;

  // Almacena la informaci�n del palindromo en el struct.
  if (text.substr(start, lpsSize).length() > 0) {
    pali.posI = start;
    pali.posF = end;
    pali.pal = text.substr(start, lpsSize);
  } else {
    pali.pal = "";
    pali.posF = -1;
    pali.posI = -1;
  }

  return pali;
}
