/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 2, Ejercicio 2.1
 *              Cuenta regresiva de 10 hasta 1 usando un ciclo while.
 */

#include <iostream>

using namespace std;

int main() {
  // Inicialización: el contador arranca en 10 y va a ir bajando
  int contador = 10;

  // Ciclo: while evalúa la condición ANTES de cada vuelta, así que en cuanto
  // el contador llega a 0 el cuerpo ya no se ejecuta y el 0 nunca se imprime
  while (contador >= 1) {
    cout << contador << " "; // los números van en la misma línea
    contador--;              // sin esta línea la condición nunca cambia
                             // y el ciclo sería infinito
  }

  // Salida final: el salto de línea va después del ciclo, no adentro
  cout << endl;
  cout << "¡Despegue!" << endl;

  return 0;
}
