/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 3, Ejercicio 3.2
 *              El usuario adivina un número secreto fijo; el programa
 *              le indica si el secreto es mayor o menor a su intento.
 */

#include <iostream>

using namespace std;

int main() {
  // const indica que el valor no cambia durante todo el programa.
  // Si alguien intentara modificarlo, el compilador da error.
  const int SECRETO = 42;

  int intento;
  int contador = 0; // cuenta cuántas veces intentó el usuario

  // Encabezado del juego: se muestra una sola vez, fuera del ciclo
  cout << "=== Adivina el número (entre 1 y 100) ===" << endl;

  do {
    // Lectura del intento
    cout << "Ingrese su intento: ";
    cin >> intento;
    contador++; // cada vuelta del ciclo es un intento

    // Pistas: la cadena if / else if / else cubre los tres casos posibles
    // y solo uno de ellos puede ejecutarse
    if (intento < SECRETO) {
      cout << "  → El número secreto es MAYOR." << endl;
    } else if (intento > SECRETO) {
      cout << "  → El número secreto es MENOR." << endl;
    } else {
      cout << "  → ¡Correcto! Lo lograste en " << contador << " intento(s)."
           << endl;
    }

    // Condición de salida: se repite mientras NO haya adivinado
  } while (intento != SECRETO);

  return 0;
}
