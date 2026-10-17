/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 04/09/2026
 * Descripción: Pregunta 3 — Recibe por argumento de línea de comandos un
 *              número entero que representa un día de la semana
 *              (0 => lunes, 1 => martes, ... 6 => domingo) e indica el día
 *              seleccionado, el día anterior y el día siguiente.
 *              Sin argumentos, el programa termina sin mostrar nada.
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  /*
     argc cuenta los argumentos incluyendo el nombre del programa, así que
     argc == 1 significa que el usuario no pasó ninguno. En ese caso el
     enunciado pide terminar SIN MOSTRAR NADA: se retorna de una vez, sin
     imprimir ni siquiera un mensaje de error.
  */
  if (argc < 2) {
    return 0;
  }

  string argumento = argv[1];

  /*
     Validación: se revisa carácter por carácter que todos sean dígitos,
     comparando contra '0' y '9'. Hace falta porque stoi lanza un error y
     aborta el programa si recibe texto que no representa un número.

     También se limita el largo a dos caracteres. Los valores válidos van del
     0 al 6, así que nadie necesita más, y así stoi nunca recibe un número
     tan grande que no quepa en un int.
  */
  bool esNumero = !argumento.empty() && argumento.length() <= 2;
  for (int i = 0; i < (int)argumento.length(); i++) {
    if (argumento[i] < '0' || argumento[i] > '9') {
      esNumero = false;
    }
  }

  if (!esNumero) {
    cout << "Error: el argumento debe ser un numero entero del 0 al 6." << endl;
    return 1;
  }

  // stoi convierte la cadena a entero
  int dia = stoi(argumento);

  // Solo hay siete días, así que cualquier otro valor se rechaza
  if (dia < 0 || dia > 6) {
    cout << "Error: el numero debe estar entre 0 (lunes) y 6 (domingo)." << endl;
    return 1;
  }

  // El arreglo traduce el número a nombre. El índice coincide con el valor
  // que envía el usuario: dias[0] es lunes, dias[3] es jueves.
  string dias[7] = {"Lunes",   "Martes", "Miércoles", "Jueves",
                    "Viernes", "Sábado", "Domingo"};

  /*
     La semana es circular: el anterior del lunes es domingo y el siguiente
     del domingo es lunes. El operador % hace que el índice "dé la vuelta".

     Para el siguiente basta (dia + 1) % 7.

     Para el anterior se suma 6 en vez de restar 1. Con (dia - 1) % 7, si el
     usuario elige lunes (0), la operación sería -1 % 7, que en C++ vale -1
     y NO 6: el módulo conserva el signo del dividendo. Ese -1 usado como
     índice leería fuera del arreglo. Sumar 6 equivale a restar 1 en módulo 7
     y nunca produce un número negativo.
  */
  int anterior = (dia + 6) % 7;
  int siguiente = (dia + 1) % 7;

  // Salida con el formato solicitado en el enunciado
  cout << "1)Seleccionaste: " << dias[dia] << endl;
  cout << "2)Día anterior: " << dias[anterior] << endl;
  cout << "3)Día siguiente: " << dias[siguiente] << endl;

  return 0;
}
