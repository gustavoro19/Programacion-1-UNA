/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 2, Ejercicio 2.1
 *              Declara un array de enteros y muestra cada elemento
 *              junto con su índice usando un ciclo for.
 */

#include <iostream>

using namespace std;

int main() {
  // Declaración: TAM es const para que el tamaño no se pueda cambiar por
  // error y sirva de límite en el ciclo
  const int TAM = 6;

  // El array se declara con sus valores ya inicializados
  int numeros[TAM] = {5, 12, 8, 27, 3, 19};

  // Recorrido: i va de 0 hasta TAM - 1, que son los índices válidos.
  // Con i < TAM nunca se accede fuera del array
  for (int i = 0; i < TAM; i++) {
    cout << "Elemento [" << i << "] = " << numeros[i] << endl;
  }

  return 0;
}
