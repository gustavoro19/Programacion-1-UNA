/**
 * Estudiante  :  Gustavo Rojas Porras
 * Curso       : EIF 201 Programación I
 * Fecha       : 11/08/2026
 * Descripción : Laboratorio 2 — Parte 3, Ejercicio 3.1.
 */
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  // argc : cantidad de argumentos (incluye el nombre del programa)
  // argv : arreglo de cadenas con los argumentos
  //        argv[0] = nombre del ejecutable
  //        argv[1] = primer argumento del usuario
  //        argv[2] = segundo argumento, etc.

  if (argc < 2) {
    cout << "Uso: ./saludo <nombre>" << endl;
    return 1;
  }

  cout << "Hola " << argv[1] << " Bienvenido al curso de Programacion I"
       << endl;
  return 0;
}