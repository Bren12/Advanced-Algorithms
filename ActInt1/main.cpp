// E1 - Actividad Integradora 1
//
// A00831991 - Eunice Santos Galindo
// A00829855 - Brenda Elena Saucedo González
#include "kmp.h"
#include "lcs.h"
#include "manacher.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

// Complejidad: O(n), donde n depende del tamaño del vector a imprimir.
// Funcion que imprime el vector de posiciones de las coincidencias.
void printVecInt(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
}

int main() {
  // Variables auxiliares.
  palindrome aux, palindrome1, palindrome2;
  int line1 = 0, line2 = 0, k = 0;
  string lineT, lineM, textT = "";
  vector<string> vecT(2);

  // Variables para la lectura de archivos.
  vector<string> maliciousFile = {"mcode1.txt", "mcode2.txt", "mcode3.txt"};
  vector<string> transmissionFile = {"transmission1.txt", "transmission2.txt"};

  // Empieza a leer los archivos.
  for (int i = 0; i < transmissionFile.size(); i++) {

    // Abrimos el archivo de Transimición.
    ifstream fileT(transmissionFile[i].c_str());

    // Obtenemos cada línea del archivo.
    while (getline(fileT, lineT)) {

      // Concatena en un solo string todo el contenido
      // del archivo de transmisión.
      textT += lineT + "\n";

      // Almacena el palindromo encontrado.
      aux = manacher(lineT);

      // Si el palindromo encontrado es más grande
      // que el almacenado, se actualiza.
      if (transmissionFile[i] == "transmission1.txt" &&
          aux.pal.length() > palindrome1.pal.length()) {
        palindrome1 = aux;
        line1 = k;
      }
      if (transmissionFile[i] == "transmission2.txt" &&
          aux.pal.length() > palindrome2.pal.length()) {
        palindrome2 = aux;
        line2 = k;
      }

      // Actualizamos el contador.
      k++;
    }

    // Volvemos a inicializar el contador de lineas.
    k = 0;

    // Cerramos el archivo.
    fileT.close();
    
    // Removemos los saltos de linea del final del
	// contenido del archivo de Transmición.
	textT = textT.substr(0, textT.size() - 1);
      
    if (transmissionFile[i] == "transmission1.txt") {
      vecT[0] = textT;
    } else {
      vecT[1] = textT;
    }

    // Abre y lee los archivos mcodeX.tx (maliciosos).
    for (int j = 0; j < maliciousFile.size(); j++) {

      // Abrimos el archivo Malicioso.
      ifstream fileM(maliciousFile[j].c_str());

      /////////////////////////////////// Parte 1 //////////////////////////////////////

      // Obtenemos cada línea del archivo Malicioso.
      while (getline(fileM, lineM)) {

        // Empiza buscando las coincidencias.
        vector<int> pos = kmp(textT, lineM);

        // Si el vector retornado esta vacío, no se encontraron coincidencias.
        // Si no, imprime las posiciones en las que se encontro.
        if (pos.empty()) {
          cout << maliciousFile[j] << " --> Code: " << lineM << endl;
          cout << transmissionFile[i] << " = FALSE\n\n";
        } else {
          cout << maliciousFile[j] << " --> Code: " << lineM << endl;
          cout << transmissionFile[i] << " = TRUE ";
          printVecInt(pos);
          cout << endl;
        }
      }

      // Cerramos el archivo.
      fileM.close();
    }

    // Volvemos a inicializar las variables auxiliares.
    textT = "";
    aux.pal = "";
    aux.posF = -1;
    aux.posI = -1;
  }

  /////////////////////////////////// Parte 2 //////////////////////////////////////
  cout << "=============================================\n\n";
  // Si "palindrome" no esta vacío, imprime la información del
  // palindromo encontrado, si no, imprime que no se encontro.
  if (palindrome1.pal.length() != 0) {
    cout << "Palindromo mas grande en transmisicion1.txt\n";
    cout << "Palindromo --> " << palindrome1.pal << endl;
    cout << "Linea --> " << line1 << endl;
    cout << "Posicion --> " << palindrome1.posI << " " << palindrome1.posF << endl;
  } else {
    cout << "NO hay palindromos en transmisicion1.txt\n";
  }

  if (palindrome2.pal.length() != 0) {
    cout << "\nPalindromo mas grande en transmisicion2.txt\n";
    cout << "Palindromo --> " << palindrome2.pal << endl;
    cout << "Linea --> " << line2 << endl;
    cout << "Posicion --> " << palindrome2.posI << " " << palindrome2.posF << endl;
  } else {
    cout << "NO hay palindromos en transmisicion2.txt\n";
  }

  /////////////////////////////////// Parte 3 //////////////////////////////////////
  cout << "\n=============================================\n\n";
  LCS subString = LCSubStr(vecT[0], vecT[1]);
  if (subString.cadena.length() != 0) {
    cout << "\nSubstring comun mas largo entre archivos de transmision\n";
    cout << "Substring --> " << subString.cadena << endl;
    cout << "Posicion en archivo transmisicion1.txt --> " << subString.inicio << " " << subString.fin << endl;
  } else {
    cout << "NO hay substring comun entre archivos de transmision\n";
  }

  return 0;
}
