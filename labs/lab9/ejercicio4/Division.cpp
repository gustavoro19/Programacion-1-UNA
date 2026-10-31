#include "Division.h"

double Division::calcular(int a, int b) {
  return (double)a / b;
}

string Division::getSimbolo() {
  return "/";
}

string Division::getNombre() {
  return "División";
}

// No se puede dividir entre cero
bool Division::puedeCalcular(int, int b) {
  return b != 0;
}
