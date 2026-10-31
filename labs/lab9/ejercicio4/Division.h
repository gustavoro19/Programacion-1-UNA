#ifndef DIVISION_H
#define DIVISION_H

#include "Operacion.h"

class Division : public Operacion {
public:
  double calcular(int a, int b) override;
  string getSimbolo() override;
  string getNombre() override;
  bool puedeCalcular(int a, int b) override;
};

#endif
