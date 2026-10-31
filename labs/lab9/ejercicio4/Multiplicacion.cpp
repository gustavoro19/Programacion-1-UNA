#include "Multiplicacion.h"

double Multiplicacion::calcular(int a, int b) {
  return (double)a * b;
}

string Multiplicacion::getSimbolo() {
  return "*";
}

string Multiplicacion::getNombre() {
  return "Multiplicación";
}
