/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 29/10/2026
 * Descripción: Laboratorio 9 — Ejercicio 1
 *              Operaciones aritméticas básicas con dos enteros, mostrando
 *              el nombre de cada elemento de la operación.
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int ANCHO = 13;

// Devuelve el texto centrado en un espacio de 'ancho' caracteres
string centrar(string texto, int ancho) {
  int espacios = ancho - (int)texto.size();
  if (espacios <= 0) {
    return texto;
  }
  int izquierda = espacios / 2;
  int derecha = espacios - izquierda;
  return string(izquierda, ' ') + texto + string(derecha, ' ');
}

void mostrarOperacion(string a, string operador, string b, string resultado,
                      string nombreA, string nombreB, string nombreResultado) {
  cout << centrar(a, ANCHO) << "  " << operador << "  " << centrar(b, ANCHO)
       << "  =  " << centrar(resultado, ANCHO) << endl;
  cout << "|___________|     |___________|     |___________|" << endl;
  cout << centrar(nombreA, ANCHO) << "     " << centrar(nombreB, ANCHO)
       << "     " << centrar(nombreResultado, ANCHO) << endl;
  cout << endl;
}

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

int main() {
  int a = leerEntero("Ingrese el primer número: ");
  int b = leerEntero("Ingrese el segundo número: ");
  cout << endl;

  string textoA = to_string(a);
  string textoB = to_string(b);

  mostrarOperacion(textoA, "+", textoB, to_string(a + b),
                   "sumando", "sumando", "total");
  mostrarOperacion(textoA, "-", textoB, to_string(a - b),
                   "minuendo", "sustraendo", "diferencia");
  mostrarOperacion(textoA, "*", textoB, to_string(a * b),
                   "factor", "factor", "producto");

  if (b == 0) {
    cout << "Error: no se puede dividir entre cero." << endl;
  } else {
    // Se convierte a double para que la división no sea entera
    double cociente = (double)a / b;
    ostringstream texto;
    texto << fixed << setprecision(2) << cociente;
    mostrarOperacion(textoA, "/", textoB, texto.str(),
                     "dividendo", "divisor", "cociente");
  }

  return 0;
}
