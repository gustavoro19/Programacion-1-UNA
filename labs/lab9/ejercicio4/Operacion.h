/*
 * Estudiante : Gustavo Rojas Porras
 * Curso      : EIF201 Programación I
 * Fecha      : 29/10/2026
 * Descripción: Laboratorio 9 — Ejercicio 4
 *              Clase base de todas las operaciones de la calculadora.
 */

#ifndef OPERACION_H
#define OPERACION_H

#include <string>

using namespace std;

class Operacion {
public:
  virtual ~Operacion() {}

  virtual double calcular(int a, int b) = 0;
  virtual string getSimbolo() = 0;
  virtual string getNombre() = 0;

  virtual bool puedeCalcular(int a, int b);
};

#endif
