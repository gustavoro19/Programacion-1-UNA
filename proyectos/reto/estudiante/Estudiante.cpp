/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Clase Estudiante (implementación)
*/
#include "Estudiante.h"

// El constructor recibe los dos datos y los guarda en los atributos privados.
Estudiante::Estudiante(string nombre, string apellido) {
  this->nombre = nombre;
  this->apellido = apellido;
}

string Estudiante::getNombre() {
  return this->nombre;
}

void Estudiante::setNombre(string nombre) {
  this->nombre = nombre;
}

string Estudiante::getApellido() {
  return this->apellido;
}

void Estudiante::setApellido(string apellido) {
  this->apellido = apellido;
}
