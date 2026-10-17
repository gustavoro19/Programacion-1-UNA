/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 4, Ejercicio 4.1
 *              Busca y muestra la nota más alta del array de
 *              calificaciones ingresado por el usuario.
 */

#include <iomanip> // para fixed y setprecision
#include <iostream>

using namespace std;

int main() {
  // Declaración
  const int TAM = 5;
  double notas[TAM];

  // Lectura: se llena el array igual que en el ejercicio 3.1
  for (int i = 0; i < TAM; i++) {
    cout << "Ingrese la nota " << (i + 1) << ": ";
    cin >> notas[i];
  }

  /*
     Búsqueda del máximo: se parte de que la primera nota es la mayor.
     Iniciar en 0 sería un error, porque si todas las notas fueran
     negativas el resultado quedaría en 0, que no está en el array.

     El for arranca en el índice 1 porque la posición 0 ya está guardada
     en maximo. En cada vuelta se compara la nota actual contra el mayor
     encontrado hasta el momento y, si es más grande, la reemplaza.
  */
  double maximo = notas[0];

  for (int i = 1; i < TAM; i++) {
    if (notas[i] > maximo) {
      maximo = notas[i];
    }
  }

  // Salida
  cout << fixed << setprecision(2);
  cout << endl;
  cout << "La nota más alta es: " << maximo << endl;

  return 0;
}
