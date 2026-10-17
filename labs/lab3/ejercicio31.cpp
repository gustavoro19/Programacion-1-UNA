/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 3, Ejercicio 3.1
 *              Lee cinco calificaciones del usuario dentro de un ciclo
 *              for y las muestra numeradas con dos decimales.
 */

#include <iomanip> // para fixed y setprecision
#include <iostream>

using namespace std;

int main() {
  // Declaración: array de 5 doubles, todavía sin valores
  const int TAM = 5;
  double notas[TAM];

  // Lectura: el for llena una posición del array en cada vuelta.
  // Se muestra i + 1 para que el usuario vea "nota 1" y no "nota 0"
  for (int i = 0; i < TAM; i++) {
    cout << "Ingrese la nota " << (i + 1) << ": ";
    cin >> notas[i];
  }

  // Salida: fixed y setprecision(2) fijan dos decimales en todo lo que
  // se imprima de aquí en adelante
  cout << fixed << setprecision(2);
  cout << endl;
  cout << "Notas ingresadas:" << endl;
  for (int i = 0; i < TAM; i++) {
    cout << "  Nota [" << (i + 1) << "] = " << notas[i] << endl;
  }

  return 0;
}
