/*
  Estudiante : Gustavo Rojas Porras
  Curso      : EIF201 Programación I
  Fecha      : 18 de setiembre de 2026
  Descripción: Reto — Uso de la clase Printer (impresiones a color y B/N, verificación de tinta)
*/
#include <iostream>
#include "Printer.h"

using namespace std;

// Muestra el estado de los cartuchos y el total disponible
void mostrarNiveles(Printer &p) {
  cout << "  Tinta negra: " << p.getTintaNegra()
       << " | Tinta color: " << p.getTintaColor()
       << " | Total disponible: " << p.getTintaDisponible() << endl;
}

int main() {
  // Instanciación con niveles iniciales de tinta
  Printer impresora(20, 10);

  cout << "Niveles iniciales:" << endl;
  mostrarNiveles(impresora);

  // Impresión en blanco y negro
  cout << "\nImprimiendo 5 paginas en blanco y negro..." << endl;
  impresora.print(5, false);
  mostrarNiveles(impresora);

  // Impresión a color
  cout << "\nImprimiendo 4 paginas a color..." << endl;
  impresora.print(4, true);
  mostrarNiveles(impresora);

  // Intento que debe ser rechazado: solo quedan 6 de color
  cout << "\nImprimiendo 8 paginas a color (no hay suficiente tinta)..." << endl;
  impresora.print(8, true);
  mostrarNiveles(impresora);

  // Otra impresión en blanco y negro que sí cabe
  cout << "\nImprimiendo 15 paginas en blanco y negro..." << endl;
  impresora.print(15, false);
  mostrarNiveles(impresora);

  // Intento que debe ser rechazado: solo queda 0 de negra
  cout << "\nImprimiendo 1 pagina en blanco y negro (cartucho vacio)..." << endl;
  impresora.print(1, false);
  mostrarNiveles(impresora);

  return 0;
}
