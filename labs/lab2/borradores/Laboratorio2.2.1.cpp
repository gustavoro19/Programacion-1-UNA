/**
 * Estudiante  :  Gustavo Rojas Porras
 * Curso       : EIF 201 Programación I
 * Fecha       : 11/08/2026
 * Descripción : Laboratorio 2 — Parte 2, Ejercicio 2.1 y 2.2.
 */

#include <iostream>

using namespace std;

int main() {
  // Declaracion de variables
  string nombre;
  int edad;
  double promedio;

  // Solicitud de datos al usuario
  cout << "Ingrese su nombre: " << endl;
  cin >> nombre;
  cout << endl;

  cout << "Ingrese su edad: " << endl;
  cin >> edad;
  cout << endl;

  cout << "Ingrese su promedio: " << endl;
  cin >> promedio;
  cout << endl;

  // Validacion de promedio mientras este fuera del rango 0-10
  while (promedio < 0 || promedio > 10) {
    cout << "Promedio Invalido, ingrese de nuevo(0-10)" << endl;
    cin >> promedio;
    cout << endl;
  }

  // Impresion de datos ingresados y validaciones
  cout << "--- Datos Ingresados ---" << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Edad: " << edad << endl;
  cout << "Promedio: " << promedio << endl;
  cout << endl;

  /*
    Clasificacion de la nota obtenida en base a las siguientes reglas:
    - 9.0–10.0: Excelente
    - 7.0–8.9: Bueno
    - 5.0–6.9: Suficiente
    - 0–4.9: Insuficiente
  */
  cout << "--- Clasificacion de Nota ---" << endl;
  if (promedio >= 9.0 && promedio <= 10.0) {
    cout << "Excelente" << endl;
  } else if (promedio >= 7.0 && promedio <= 8.9) {
    cout << "Bueno" << endl;
  } else if (promedio >= 5.0 && promedio <= 6.9) {
    cout << "Suficiente" << endl;
  } else if (promedio >= 0 && promedio <= 4.9) {
    cout << "Insuficiente" << endl;
  } else {
    cout << "Promedio Invalido" << endl;
  }

  return 0;
}