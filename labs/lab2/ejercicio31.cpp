/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 11/08/2026
 * Descripción: Laboratorio 2 — Parte 3, Ejercicio 3.1
 *              Saluda al usuario usando el nombre que recibe como
 *              argumento de la línea de comandos.
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  // argc : cantidad de argumentos (incluye el nombre del programa)
  // argv : arreglo de cadenas con los argumentos
  //        argv[0] = nombre del ejecutable
  //        argv[1] = primer argumento del usuario, en este caso el nombre

  // Validación: si no se recibió el nombre se muestra el modo de uso
  // y se termina el programa con código 1 (salida con error)
  if (argc < 2) {
    cout << "Uso: ./ejercicio31 <nombre>" << endl;
    return 1;
  }

  // Salida: se saluda usando el argumento recibido. No se usa cin
  cout << "Hola, " << argv[1] << "! Bienvenido al curso de Programación I."
       << endl;

  return 0;
}
