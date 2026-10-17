#ifndef COLUMNA_H
#define COLUMNA_H
#include <string>
#include <vector>
#include "Ficha.h"

using namespace std;

class Columna
{
private:
    string nombre;
    vector<Ficha> fichas;

public:
    Columna(string nombre);
    string getNombre();
    vector<Ficha> getFichas();
    bool agregarFicha(const Ficha& ficha);
    bool removerFicha(const Ficha& ficha);
    bool moverFicha(Columna& destino);
    void mostrarColumna();
};

#endif
