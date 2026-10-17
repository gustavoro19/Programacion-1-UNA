/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 2, Ejercicio 2.3
 *              Pide una calificación de 0 a 10 y la vuelve a pedir
 *              mientras el valor esté fuera de ese rango.
 */

#include <iostream>

using namespace std;

int main() {
  int nota;

  // Lectura adelantada: hace falta un primer valor para poder evaluarlo
  cout << "Ingrese una calificación (0-10): ";
  cin >> nota;

  while (nota < 0 || nota > 10) {
    // El mensaje de error va dentro del ciclo: solo se muestra si hubo error
    cout << "Valor inválido. Ingrese una calificación (0-10): ";
    cin >> nota;
  }

  // Si el programa llegó aquí, la condición del while dio false,
  // o sea que la nota ya está dentro del rango permitido
  cout << endl;
  cout << "Calificación aceptada: " << nota << endl;

  return 0;
}
