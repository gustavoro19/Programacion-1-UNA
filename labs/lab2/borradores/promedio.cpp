/**
 * Estudiante  :  Gustavo Rojas Porras
 * Curso       : EIF 201 Programación I
 * Fecha       : 11/08/2026
 * Descripción : Laboratorio 2 — Parte 3, Ejercicio 3.2.
 */

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  if (argc != 4) {
    cout << "Uso: ./promedio <numero1> <numero2> <numero3>" << endl;
    return 1;
  }

  double num1 = stod(argv[1]);
  double num2 = stod(argv[2]);
  double num3 = stod(argv[3]);
  double promedio = (num1 + num2 + num3) / 3.0;
  /**
   * Notas ingresadas: 8.5, 7.0, 9.5
   * Promedio        : 8.33
   * Clasificación   : Bueno
   */
  cout << "Notas ingresadas: " << num1 << ", " << num2 << " y " << num3 << endl;
  cout << "Promedio        : " << promedio << endl;
  cout << "Clasificacion   : " << endl;

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