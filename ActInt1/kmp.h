#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Complejidad: O(m), donde "m" depende del tamaño del patrón.
vector<int> lps(string pattern) {
  
  // Almacena el tamaño del patrón.
  int size = pattern.length();
  
  // Vector que almacena la posición en donde se
  // encuentran las coincidencias dentro del patrón,
  // es decir, en donde puede volver a empezar sin 
  // tener que regresarse al inicio, si es que es posible.
  vector<int> matchPattern(size, 0);
  
  // Contadores.
  int j = 0, i = 1;

  // Primero verifica si hay coincidencias dentro del patrón.
  // Verifica si el prefijo coincide con el sufijo.
  // aca --> 0,0,1 --> ya que se puede volver a empezar en la posicion 2.
  // acac --> 0,0,1,2 --> puede empezar en la posicion "ac" (pos 0 y 1 respectivamente),
  //                  --> puede empezar en la posicion "ac" (pos 2 y 3 respectivamente).

  // Mientras "i" sea menor que el tamaño del
  // patrón procede a continuar.
  while (i < size) {
    
    // Busca que los caracteres en dichas posiciones
    // se parezcan para proceder a continuar.
    if (pattern[i] == pattern[j]) {
      // Actualiza el vector en dicha posición
      // y actualiza los contadores.
      matchPattern[i++] = ++j;
    } else {
      // Si los caracteres en dichas posiciones no se parecen,
      // actualiza el vector en dicha posición a 0 y aumenta el
      // iterador "i", en caso contrario, actualiza el iterador "j".
      if (j == 0) {
        matchPattern[i] = 0;
        i++;
      } else {
        j = matchPattern[j - 1];
      }
    }
  }

  return matchPattern;
}

// Complejidad: O(n + m), donde "n" depende del tamaño del texto
//                        y "m" depende del tamaño del patrón.
vector<int> kmp(string text, string pattern) {
  
  // Vector que almacena las posiciones de todas las coincidencias.
  vector<int> posMatch;
  
  // Vector con las coincidencias encontradas en el patrón.
  vector<int> matchPattern = lps(pattern);

  // i --> text (iterador)
  // j --> pattern (iterador)
  int j = 0, i = 0;

  // Variables que almacenan el tamaño del texto y el patrón.
  int sizeT = text.length();
  int sizeP = pattern.length();

  // Mientras el contador "i" sea menor que el
  // tamaño del texto, seguira iterando.
  while (i < sizeT) {

    // Busca que los caracteres en dichas posiciones
    // se parezcan para proceder a continuar.
    if (text[i] == pattern[j]) {
      
      // Actualiza los contadores.
      i++; j++;
      
      // Para no sobrepasar el tamaño del patrón.
      if (j == sizeP) {
        
        // Si encontro una coincidencia en el texto,
        // lo agrega al vector de posiciones.
        posMatch.push_back(i - sizeP);

        // Actualiza la posición del iterador del patrón.
        j = matchPattern[j - 1];
        
      }
      
    } else {
      
      // Si los caracteres en dichas posiciones no se parecen,
      // primero verifica que el iterador del patrón no sea 0
      // para aumentar el iterador del texto, en caso
      // contrario, actualiza el iterador del patrón.
      if (j == 0) {
        i++;
      } else {
        j = matchPattern[j - 1];
      }
      
    }
    
  }
  
  return posMatch;
}
