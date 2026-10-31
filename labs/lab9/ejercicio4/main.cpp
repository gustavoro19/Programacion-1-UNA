/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 29/10/2026
 * Descripción: Laboratorio 9 — Ejercicio 4
 *              Calculadora con herencia y polimorfismo: todas las
 *              operaciones se ejecutan a través de un puntero a Operacion.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "Suma.h"
#include "Resta.h"
#include "Multiplicacion.h"
#include "Division.h"

using namespace std;

int leerEntero(string mensaje) {
  int numero;
  cout << mensaje;
  while (!(cin >> numero)) {
    if (cin.eof()) {
      exit(0);
    }
    cout << "Error: debe ingresar un número entero. Intente de nuevo: ";
    cin.clear();
    cin.ignore(10000, '\n');
  }
  return numero;
}

void mostrarMenu() {
  cout << "=============================" << endl;
  cout << "         CALCULADORA" << endl;
  cout << "=============================" << endl;
  cout << "  1. Suma" << endl;
  cout << "  2. Resta" << endl;
  cout << "  3. Multiplicación" << endl;
  cout << "  4. División" << endl;
  cout << "  0. Salir" << endl;
  cout << "=============================" << endl;
}

int main() {
  Suma suma;
  Resta resta;
  Multiplicacion multiplicacion;
  Division division;

  Operacion* operacion;
  int opcion;

  do {
    mostrarMenu();
    opcion = leerEntero("Seleccione una opción: ");

    // Solo aquí se conoce la clase concreta; después todo pasa por el puntero
    switch (opcion) {
      case 1:
        operacion = &suma;
        break;
      case 2:
        operacion = &resta;
        break;
      case 3:
        operacion = &multiplicacion;
        break;
      case 4:
        operacion = &division;
        break;
      default:
        operacion = nullptr;
        break;
    }

    if (opcion == 0) {
      cout << "Saliendo de la calculadora..." << endl;
    } else if (operacion == nullptr) {
      cout << "Opción inválida, intente de nuevo." << endl << endl;
    } else {
      cout << endl << "--- " << operacion->getNombre() << " ---" << endl;
      int a = leerEntero("Ingrese el primer número: ");
      int b = leerEntero("Ingrese el segundo número: ");

      if (operacion->puedeCalcular(a, b)) {
        double resultado = operacion->calcular(a, b);
        cout << fixed << setprecision(2);
        cout << a << " " << operacion->getSimbolo() << " " << b
             << " = " << resultado << endl << endl;
      } else {
        cout << "Error: no se puede dividir entre cero." << endl << endl;
      }
    }
  } while (opcion != 0);

  return 0;
}
