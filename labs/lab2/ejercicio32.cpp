/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 11/08/2026
 * Descripción: Laboratorio 2 — Parte 3, Ejercicio 3.2
 *              Recibe tres notas como argumentos, calcula el promedio
 *              y lo clasifica según la tabla del ejercicio 2.2.
 */

#include <iomanip> // para fixed y setprecision
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  // argc : cantidad de argumentos (incluye el nombre del programa)
  // argv : arreglo de cadenas con los argumentos
  //        argv[0] = nombre del ejecutable
  //        argv[1], argv[2], argv[3] = las tres notas

  // Validación: deben ser exactamente 3 notas más el nombre del programa,
  // por eso argc tiene que ser igual a 4
  if (argc != 4) {
    cout << "Uso: ./ejercicio32 <nota1> <nota2> <nota3>" << endl;
    return 1;
  }

  // Conversión: los argumentos llegan como texto, stod los pasa a double
  double nota1 = stod(argv[1]);
  double nota2 = stod(argv[2]);
  double nota3 = stod(argv[3]);

  // Cálculo: se divide entre 3.0 para que la división sea con decimales
  double promedio = (nota1 + nota2 + nota3) / 3.0;

  // Salida: las notas se muestran tal como se escribieron en la consola y
  // el promedio se redondea a dos decimales con fixed y setprecision
  cout << "Notas ingresadas: " << argv[1] << ", " << argv[2] << ", " << argv[3]
       << endl;
  cout << "Promedio        : " << fixed << setprecision(2) << promedio << endl;

  /*
     Clasificación: se aplica la misma tabla del ejercicio 2.2.
       9.0 – 10.0  -> Excelente
       7.0 –  8.9  -> Bueno
       5.0 –  6.9  -> Suficiente
       menor a 5.0 -> Insuficiente
     Las condiciones van de mayor a menor, así que comparar contra el
     límite inferior de cada rango es suficiente para cubrir todos los casos.
  */
  cout << "Clasificación   : ";
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
