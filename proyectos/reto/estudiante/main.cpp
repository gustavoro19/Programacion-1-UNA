/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Uso de la clase Estudiante (instanciación, getters y setters)
*/
#include <iostream>
#include "Estudiante.h"

using namespace std;

int main() {
  Estudiante est("Gustavo", "Rojas");

  cout << "Estudiante creado: " << est.getNombre() << " " << est.getApellido() << endl;

  // Uso de los setters para modificar el objeto
  est.setNombre("Gus");
  est.setApellido("Rojas Porras");

  cout << "Estudiante modificado: " << est.getNombre() << " " << est.getApellido() << endl;

  return 0;
}
