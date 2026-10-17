#include "Ficha.h"

#include <iostream>

using namespace std;

Ficha::Ficha(int valor)
{
    this->valor = valor;
}

int Ficha::getValor() const
{
    return this->valor;
}
