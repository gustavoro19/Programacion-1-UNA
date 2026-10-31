#ifndef RESTA_H
#define RESTA_H

#include "Operacion.h"

class Resta : public Operacion {
public:
  double calcular(int a, int b) override;
  string getSimbolo() override;
  string getNombre() override;
};

#endif
