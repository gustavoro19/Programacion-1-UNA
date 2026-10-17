/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 2, Ejercicio 2.2
 *              Muestra un array, duplica cada uno de sus elementos
 *              y vuelve a mostrarlo para comparar ambos estados.
 */

#include <iostream>

using namespace std;

int main() {
  // Declaración: mismo array del ejercicio 2.1
  const int TAM = 6;
  int numeros[TAM] = {5, 12, 8, 27, 3, 19};

  // Salida 1: el array tal como quedó inicializado
  cout << "Array original:" << endl;
  for (int i = 0; i < TAM; i++) {
    cout << numeros[i] << "  ";
  }
  cout << endl << endl;

  // Modificación: cada posición se reemplaza por su propio valor por 2.
  // Como se asigna sobre numeros[i], el cambio queda guardado en el array
  for (int i = 0; i < TAM; i++) {
    numeros[i] = numeros[i] * 2;
  }

  // Salida 2: el mismo array después de la modificación
  cout << "Array después de duplicar:" << endl;
  for (int i = 0; i < TAM; i++) {
    cout << numeros[i] << "  ";
  }
  cout << endl;

  return 0;
}
