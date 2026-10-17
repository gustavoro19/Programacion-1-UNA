/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 4, Ejercicio 4.2
 *              Consulta si un año es bisiesto; permite consultar varios
 *              años y termina cuando el usuario ingresa 0.
 */

#include <iostream>

using namespace std;

int main() {
  // Se escribe 'anio' y no 'año': la ñ no es un carácter válido para
  // nombres de variables en C++ estándar.
  int anio;

  // do-while: la primera consulta siempre debe pedirse antes de poder
  // revisar si el usuario quiere salir
  do {
    cout << "Ingrese un año: ";
    cin >> anio;

    // El 0 es el centinela: corta el ciclo sin evaluarse como año
    if (anio != 0) {
      /*
         Regla del calendario gregoriano, en una sola expresión:

           (anio % 4 == 0)      -> divisible por 4, requisito de base.
                                   Va con && porque es obligatorio: si
                                   falla, no hay nada más que revisar.

           (anio % 100 != 0)    -> NO es fin de siglo. Los fines de siglo
                                   son la excepción: 1900 pasa el filtro
                                   del 4 pero no es bisiesto.

           (anio % 400 == 0)    -> excepción de la excepción. Los fines de
                                   siglo divisibles por 400 sí son
                                   bisiestos, como el 2000.

         Los dos últimos van con || porque basta con que se cumpla uno.
         El paréntesis que los agrupa es indispensable: sin él, C++ evalúa
         primero el && y la expresión pasaría a significar
         ((anio%4==0 && anio%100!=0) || anio%400==0), que es otra regla.
      */
      if ((anio % 4 == 0) && ((anio % 100 != 0) || (anio % 400 == 0))) {
        cout << anio << " es bisiesto." << endl;
      } else {
        cout << anio << " NO es bisiesto." << endl;
      }
      cout << endl;
    }

  } while (anio != 0);

  return 0;
}
