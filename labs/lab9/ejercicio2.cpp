/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 29/10/2026
 * Descripción: Laboratorio 9 — Ejercicio 2
 *              Valida si dos cadenas representan números binarios.
 */

#include <iostream>
#include <string>

using namespace std;

// Un binario válido no está vacío y solo tiene caracteres '0' y '1'
bool esBinario(string numero) {
  if (numero.empty()) {
    return false;
  }
  for (int i = 0; i < (int)numero.size(); i++) {
    if (numero[i] != '0' && numero[i] != '1') {
      return false;
    }
  }
  return true;
}

int main() {
  string primero;
  string segundo;

  // getline permite que el usuario ingrese una cadena vacía
  cout << "Ingrese el primer número: ";
  getline(cin, primero);
  cout << "Ingrese el segundo número: ";
  getline(cin, segundo);
  cout << endl;

  if (esBinario(primero)) {
    cout << "El primer número es binario válido." << endl;
  } else {
    cout << "El primer número no es binario válido." << endl;
  }

  if (esBinario(segundo)) {
    cout << "El segundo número es binario válido." << endl;
  } else {
    cout << "El segundo número no es binario válido." << endl;
  }

  return 0;
}
