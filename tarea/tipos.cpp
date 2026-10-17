/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 04/09/2026
 * Descripción: Pregunta 2 — Ejemplo de cuatro tipos de datos de C++.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int edad = 20;              // entero: sin parte decimal
  double promedio = 8.75;     // real de doble precisión
  char inicial = 'G';         // un solo carácter, entre comillas simples
  bool aprobado = true;       // valor lógico: solo true o false
  string nombre = "Gustavo";  // cadena de texto, entre comillas dobles

  cout << "int    edad     = " << edad << "   (" << sizeof(edad) << " bytes)" << endl;
  cout << "double promedio = " << promedio << " (" << sizeof(promedio) << " bytes)" << endl;
  cout << "char   inicial  = " << inicial << "   (" << sizeof(inicial) << " byte)" << endl;
  cout << "bool   aprobado = " << aprobado << "   (" << sizeof(aprobado) << " byte, imprime 1 = true)" << endl;
  cout << "string nombre   = " << nombre << endl;

  return 0;
}
