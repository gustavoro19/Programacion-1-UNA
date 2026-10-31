/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 29/10/2026
 * Descripción: Laboratorio 9 — Ejercicio 3
 *              Suma de dos números binarios usando aritmética binaria
 *              (sin convertirlos a decimal).
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool esBinario(string numero) {
  if (numero.empty()) {
    return false;
  }
  for (int i = 0; i < (int)numero.size(); i++) {
    if (numero[i] != '0' && numero[i] != '1') {
      return false;
    }
  }
  return true;
}

// Suma de derecha a izquierda, como se hace a mano, llevando el acarreo
string sumarBinarios(string a, string b) {
  string resultado = "";
  int i = (int)a.size() - 1;
  int j = (int)b.size() - 1;
  int acarreo = 0;

  while (i >= 0 || j >= 0 || acarreo == 1) {
    int bitA = 0;
    int bitB = 0;
    if (i >= 0) {
      bitA = a[i] - '0';
    }
    if (j >= 0) {
      bitB = b[j] - '0';
    }

    int suma = bitA + bitB + acarreo;
    // suma puede ser 0, 1, 2 o 3: el bit que queda es suma % 2
    resultado = char('0' + suma % 2) + resultado;
    acarreo = suma / 2;

    i--;
    j--;
  }

  return resultado;
}

string leerBinario(string mensaje) {
  string numero;
  cout << mensaje;
  getline(cin, numero);
  while (!esBinario(numero)) {
    if (cin.eof()) {
      exit(0);
    }
    cout << "Error: \"" << numero << "\" no es un número binario válido." << endl;
    cout << mensaje;
    getline(cin, numero);
  }
  return numero;
}

int main() {
  string a = leerBinario("Ingrese el primer número binario: ");
  string b = leerBinario("Ingrese el segundo número binario: ");
  string resultado = sumarBinarios(a, b);

  int largo = (int)a.size();
  if ((int)b.size() > largo) {
    largo = (int)b.size();
  }
  // Ancho total de cada línea: 4 de margen + "+ " + el número más largo
  int ancho = largo + 6;

  cout << endl;
  cout << setw(ancho) << a << endl;
  cout << "    + " << setw(largo) << b << endl;
  cout << "    " << string(largo + 2, '-') << endl;
  cout << setw(ancho) << resultado << endl;

  return 0;
}
