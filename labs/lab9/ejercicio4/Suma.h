#ifndef SUMA_H
#define SUMA_H

#include "Operacion.h"

class Suma : public Operacion {
public:
  double calcular(int a, int b) override;
  string getSimbolo() override;
  string getNombre() override;
};

#endif
