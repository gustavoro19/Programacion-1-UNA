/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 11/08/2026
 * Descripción: Laboratorio 2 — Parte 2, Ejercicio 2.2
 *              Extiende el ejercicio 2.1 agregando la clasificación
 *              del promedio con if / else if / else.
 */

#include <iostream>
#include <string> // necesario para poder usar el tipo string

using namespace std;

int main() {
  // Declaración de variables: cada dato usa el tipo que le corresponde
  string nombre;   // string : cadena de texto
  int edad;        // int    : número entero
  double promedio; // double : número con decimales

  // Lectura: cout muestra la etiqueta y cin guarda lo que digita el usuario
  cout << "Ingrese su nombre: ";
  cin >> nombre;

  cout << "Ingrese su edad: ";
  cin >> edad;

  cout << "Ingrese su promedio: ";
  cin >> promedio;

  // Validación: se vuelve a pedir el promedio mientras esté fuera de 0 a 10
  while (promedio < 0 || promedio > 10) {
    cout << "Promedio inválido, ingrese de nuevo (0-10): ";
    cin >> promedio;
  }

  // Salida: se muestran los datos ingresados con el formato solicitado
  cout << endl;
  cout << "--- Datos ingresados ---" << endl;
  cout << "Nombre : " << nombre << endl;
  cout << "Edad   : " << edad << " años" << endl;
  cout << "Promedio: " << promedio << endl;

  /*
     Clasificación: la cadena if / else if / else ubica el promedio en uno
     de los cuatro rangos de la tabla del laboratorio:
       9.0 – 10.0  -> Excelente
       7.0 –  8.9  -> Bueno
       5.0 –  6.9  -> Suficiente
       menor a 5.0 -> Insuficiente
     Como las condiciones se evalúan en orden de mayor a menor, basta con
     comparar contra el límite inferior de cada rango: si el promedio no
     llegó al rango anterior, ya se sabe que está por debajo. Así ningún
     valor decimal queda sin clasificar y el else cubre todo lo menor a 5.0.
  */
  cout << "Clasificación: ";
  if (promedio >= 9.0) {
    cout << "Excelente" << endl;
  } else if (promedio >= 7.0) {
    cout << "Bueno" << endl;
  } else if (promedio >= 5.0) {
    cout << "Suficiente" << endl;
  } else {
    cout << "Insuficiente" << endl;
  }

  return 0;
}
