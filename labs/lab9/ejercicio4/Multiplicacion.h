#ifndef MULTIPLICACION_H
#define MULTIPLICACION_H

#include "Operacion.h"

class Multiplicacion : public Operacion {
public:
  double calcular(int a, int b) override;
  string getSimbolo() override;
  string getNombre() override;
};

#endif
