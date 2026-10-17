/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 28/08/2026
 * Descripción: Laboratorio 4 — Parte 2, Ejercicio 2.2
 *              Acumula los números que digita el usuario hasta que
 *              ingrese un 0, que funciona como valor centinela.
 */

#include <iostream>

using namespace std;

int main() {
  // Inicialización: los acumuladores arrancan en 0 antes de entrar al ciclo.
  // Si no se inicializan, contienen basura y la suma sale mal.
  int cantidad = 0;
  int suma = 0;
  int numero;

  // La primera lectura va ANTES del while porque la condición necesita un
  // valor para evaluar. A este patrón se le llama "lectura adelantada".
  cout << "Ingrese un número (0 para terminar): ";
  cin >> numero;

  // Ciclo: se repite mientras el número no sea el centinela.
  // El 0 solo corta el ciclo, no se acumula ni se cuenta.
  while (numero != 0) {
    suma = suma + numero; // acumula el valor
    cantidad++;           // cuenta cuántos van

    // Última línea del cuerpo: leer el siguiente número para que la
    // condición de arriba tenga un dato nuevo que evaluar
    cout << "Ingrese un número (0 para terminar): ";
    cin >> numero;
  }

  // Salida: se muestran los resultados ya calculados
  cout << endl;
  cout << "Cantidad de números ingresados: " << cantidad << endl;
  cout << "Suma total                     : " << suma << endl;

  return 0;
}
