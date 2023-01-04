#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Complejidad: O(m), donde "m" depende del tama�o del patr�n.
vector<int> lps(string pattern) {
  
  // Almacena el tama�o del patr�n.
  int size = pattern.length();
  
  // Vector que almacena la posici�n en donde se
  // encuentran las coincidencias dentro del patr�n,
  // es decir, en donde puede volver a empezar sin 
  // tener que regresarse al inicio, si es que es posible.
  vector<int> matchPattern(size, 0);
  
  // Contadores.
  int j = 0, i = 1;

  // Primero verifica si hay coincidencias dentro del patr�n.
  // Verifica si el prefijo coincide con el sufijo.
  // aca --> 0,0,1 --> ya que se puede volver a empezar en la posicion 2.
  // acac --> 0,0,1,2 --> puede empezar en la posicion "ac" (pos 0 y 1 respectivamente),
  //                  --> puede empezar en la posicion "ac" (pos 2 y 3 respectivamente).

  // Mientras "i" sea menor que el tama�o del
  // patr�n procede a continuar.
  while (i < size) {
    
    // Busca que los caracteres en dichas posiciones
    // se parezcan para proceder a continuar.
    if (pattern[i] == pattern[j]) {
      // Actualiza el vector en dicha posici�n
      // y actualiza los contadores.
      matchPattern[i++] = ++j;
    } else {
      // Si los caracteres en dichas posiciones no se parecen,
      // actualiza el vector en dicha posici�n a 0 y aumenta el
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

// Complejidad: O(n + m), donde "n" depende del tama�o del texto
//                        y "m" depende del tama�o del patr�n.
vector<int> kmp(string text, string pattern) {
  
  // Vector que almacena las posiciones de todas las coincidencias.
  vector<int> posMatch;
  
  // Vector con las coincidencias encontradas en el patr�n.
  vector<int> matchPattern = lps(pattern);

  // i --> text (iterador)
  // j --> pattern (iterador)
  int j = 0, i = 0;

  // Variables que almacenan el tama�o del texto y el patr�n.
  int sizeT = text.length();
  int sizeP = pattern.length();

  // Mientras el contador "i" sea menor que el
  // tama�o del texto, seguira iterando.
  while (i < sizeT) {

    // Busca que los caracteres en dichas posiciones
    // se parezcan para proceder a continuar.
    if (text[i] == pattern[j]) {
      
      // Actualiza los contadores.
      i++; j++;
      
      // Para no sobrepasar el tama�o del patr�n.
      if (j == sizeP) {
        
        // Si encontro una coincidencia en el texto,
        // lo agrega al vector de posiciones.
        posMatch.push_back(i - sizeP);

        // Actualiza la posici�n del iterador del patr�n.
        j = matchPattern[j - 1];
        
      }
      
    } else {
      
      // Si los caracteres en dichas posiciones no se parecen,
      // primero verifica que el iterador del patr�n no sea 0
      // para aumentar el iterador del texto, en caso
      // contrario, actualiza el iterador del patr�n.
      if (j == 0) {
        i++;
      } else {
        j = matchPattern[j - 1];
      }
      
    }
    
  }
  
  return posMatch;
}
