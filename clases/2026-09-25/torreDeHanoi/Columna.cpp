#include "Columna.h"

#include <iostream>

using namespace std;

Columna::Columna(string nombre)
{
    this->nombre = nombre;
}

string Columna::getNombre()
{
    return this->nombre;
}

vector<Ficha> Columna::getFichas()
{
    return this->fichas;
}

bool Columna::agregarFicha(const Ficha& ficha)
{
    if (!fichas.empty() && fichas.back().getValor() < ficha.getValor())
    {
        cout << "No cabe sobre una ficha mas pequena." << endl;
        return false;
    }

    fichas.push_back(ficha);
    return true;
}

bool Columna::removerFicha(const Ficha& ficha)
{
    if (fichas.empty())
    {
        cout << "Esa columna esta vacia." << endl;
        return false;
    }

    if (fichas.back().getValor() != ficha.getValor())
    {
        return false;
    }

    fichas.pop_back();
    return true;
}


bool Columna::moverFicha(Columna& destino)
{
    if (fichas.empty())
    {
        cout << "Esa columna esta vacia." << endl;
        return false;
    }

    Ficha arriba = fichas.back();
    if (!destino.agregarFicha(arriba))
    {
        return false;
    }

    removerFicha(arriba);
    return true;
}

void Columna::mostrarColumna()
{
    cout << nombre << ": ";
    for (const Ficha& f : fichas)
    {
        cout << f.getValor() << " ";
    }
    cout << endl;
}
