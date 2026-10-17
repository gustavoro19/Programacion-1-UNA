/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 11/08/2026
 * Descripción: Laboratorio 2 — Parte 2, Ejercicio 2.1
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

  // Salida: se muestran los datos ingresados con el formato solicitado
  cout << endl;
  cout << "--- Datos ingresados ---" << endl;
  cout << "Nombre : " << nombre << endl;
  cout << "Edad   : " << edad << " años" << endl;
  cout << "Promedio: " << promedio << endl;

  return 0;
}
