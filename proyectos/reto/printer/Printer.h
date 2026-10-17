/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Clase Printer (declaración)
*/
#ifndef PRINTER_H
#define PRINTER_H

class Printer {
  private:
    double tintaNegra;  
    double tintaColor;  
  public:
    Printer(double tintaNegra, double tintaColor);
    double getTintaNegra();
    double getTintaColor();
    void print(int paginas, bool esColor);
    double getTintaDisponible();
};
#endif
