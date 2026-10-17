/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Clase Printer (implementación)
*/
#include "Printer.h"

#include <iostream>
using namespace std;

Printer::Printer(double tintaNegra, double tintaColor)
{
  this->tintaNegra = tintaNegra;
  this->tintaColor = tintaColor;
}

double Printer::getTintaNegra()
{
  return this->tintaNegra;
}

double Printer::getTintaColor()
{
  return this->tintaColor;
}

void Printer::print(int paginas, bool esColor)
{
  if (esColor)
  {
    if (this->tintaColor != 0)
    {
      tintaColor -= paginas; 
    }
    else
    {
      cout << "No hay suficiente tinta!" << endl;
    }
  }
}

double Printer::getTintaDisponible()
{
  return this->tintaNegra + this->tintaColor;
}
