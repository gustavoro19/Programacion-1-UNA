/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Clase Estudiante (declaración)
*/
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

using namespace std;

class Estudiante {
  private:
    string nombre;
    string apellido;
  public:
    Estudiante(string nombre, string apellido);
    string getNombre();
    void setNombre(string nombre);
    string getApellido();
    void setApellido(string apellido);
};
#endif
