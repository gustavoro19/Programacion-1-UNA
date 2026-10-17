/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 4, Ejercicio 4.1
 *              Lee tres lados, verifica si forman un triángulo válido
 *              y clasifica el tipo usando expresiones lógicas.
 */

#include <iostream>

using namespace std;

int main() {
  // Se usan enteros para que las comparaciones de igualdad (a == b) sean exactas. 
  // Con decimales, dos lados "iguales" pueden diferir en un milésimo invisible y el == daría false.
  int a, b, c;

  // Lectura de los tres lados
  cout << "Ingrese el lado a: ";
  cin >> a;
  cout << "Ingrese el lado b: ";
  cin >> b;
  cout << "Ingrese el lado c: ";
  cin >> c;

  /*
       (a + b > c) : los lados a y b alcanzan para rodear a c
       (a + c > b) : lo mismo tomando b como el lado opuesto
       (b + c > a) : lo mismo tomando a como el lado opuesto
  */
  bool esValido = (a + b > c) && (a + c > b) && (b + c > a);

  cout << endl;
  cout << "¿Es triángulo válido? " << (esValido ? "Sí" : "No") << endl;

  if (esValido) {
    cout << "Tipo: ";

    if (a == b && b == c) {
      cout << "Equilátero" << endl;
    } else if (a == b || b == c || a == c) {
      // Isósceles: con || basta que UN par de lados coincida.
      // Este else if solo se evalúa si no fue equilátero, así que
      // aquí "al menos dos iguales" ya significa "exactamente dos".
      cout << "Isósceles" << endl;
    } else {
      // Escaleno: no entró en ninguna de las anteriores, o sea que
      // ningún par de lados es igual
      cout << "Escaleno" << endl;
    }
  }

  return 0;
}
