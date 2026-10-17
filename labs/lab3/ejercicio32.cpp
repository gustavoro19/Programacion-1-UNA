/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 17/08/2026
 * Descripción: Laboratorio 3 — Parte 3, Ejercicio 3.2
 *              Extiende el ejercicio 3.1 calculando la suma total y el
 *              promedio de las cinco calificaciones ingresadas.
 */

#include <iomanip> // para fixed y setprecision
#include <iostream>

using namespace std;

int main() {
  // Declaración: el acumulador arranca en 0.0 para poder ir sumándole
  const int TAM = 5;
  double notas[TAM];
  double suma = 0.0;

  // Lectura y acumulación: el mismo for que llena el array va sumando cada
  // nota, así no hace falta un ciclo aparte solo para el total
  for (int i = 0; i < TAM; i++) {
    cout << "Ingrese la nota " << (i + 1) << ": ";
    cin >> notas[i];
    suma += notas[i];
  }

  // Cálculo: el promedio se obtiene una vez terminado el ciclo, cuando la
  // suma ya tiene las cinco notas
  double promedio = suma / TAM;

  // Salida: dos decimales para todos los números
  cout << fixed << setprecision(2);
  cout << endl;
  cout << "Notas ingresadas:" << endl;
  for (int i = 0; i < TAM; i++) {
    cout << "  Nota [" << (i + 1) << "] = " << notas[i] << endl;
  }

  cout << endl;
  cout << "Suma total : " << suma << endl;
  cout << "Promedio   : " << promedio << endl;

  return 0;
}
