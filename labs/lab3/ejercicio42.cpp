/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 4, Ejercicio 4.2
 *              Cuenta cuántas notas del array están aprobadas (>= 7.0)
 *              y cuántas reprobadas (< 7.0).
 */

#include <iostream>

using namespace std;

int main() {
  // Declaración: los dos contadores arrancan en 0 porque todavía no se
  // ha revisado ninguna nota
  const int TAM = 5;
  double notas[TAM];
  int aprobadas = 0;
  int reprobadas = 0;

  // Lectura: se llena el array igual que en el ejercicio 3.1
  for (int i = 0; i < TAM; i++) {
    cout << "Ingrese la nota " << (i + 1) << ": ";
    cin >> notas[i];
  }

  // Conteo: cada nota cae en una sola de las dos categorías, por eso el
  // if / else. Con 7.0 exacto la nota cuenta como aprobada (>=)
  for (int i = 0; i < TAM; i++) {
    if (notas[i] >= 7.0) {
      aprobadas++;
    } else {
      reprobadas++;
    }
  }

  // Salida
  cout << endl;
  cout << "Notas aprobadas : " << aprobadas << endl;
  cout << "Notas reprobadas: " << reprobadas << endl;

  return 0;
}
