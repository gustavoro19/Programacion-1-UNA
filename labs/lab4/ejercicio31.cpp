/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 3, Ejercicio 3.1
 *              Menú principal con tres opciones que se repite hasta
 *              que el usuario elige Salir.
 */

#include <iostream>

using namespace std;

int main() {
  int opcion;

  /*
     Se usa do-while y no while porque el menú SIEMPRE debe mostrarse al
     menos una vez, antes de que exista una opción que evaluar. Con while
     habría que inventar un valor inicial falso para 'opción' solo para que
     la primera vuelta ocurra; el do-while ejecuta primero y pregunta
     después, que es justo el orden que necesita un menú.
  */
  do {
    // Impresión del menú: va dentro del ciclo para que reaparezca
    // después de cada acción
    cout << "=============================" << endl;
    cout << "        MENÚ PRINCIPAL" << endl;
    cout << "=============================" << endl;
    cout << "  1. Saludar" << endl;
    cout << "  2. Mostrar fecha del sistema" << endl;
    cout << "  3. Salir" << endl;
    cout << "=============================" << endl;
    cout << "Seleccione una opción: ";
    cin >> opcion;

    // Selección: switch elige el caso que coincide con la opción digitada.
    // El default atrapa cualquier número que no esté en el menú.
    switch (opcion) {
    case 1:
      cout << "¡Hola! Bienvenido al sistema." << endl;
      break;
    case 2:
      cout << "Fecha actual: 2026" << endl;
      break;
    case 3:
      cout << "Hasta luego." << endl;
      break;
    default:
      cout << "Opción no válida, intente de nuevo." << endl;
      break;
    }

    cout << endl;

    // La condición se evalúa al final: si la opción fue 3 el ciclo termina
  } while (opcion != 3);

  return 0;
}
