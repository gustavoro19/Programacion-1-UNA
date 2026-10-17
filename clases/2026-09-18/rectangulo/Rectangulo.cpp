#include "Rectangulo.h"

#include <iostream>

using namespace std;

Rectangulo::Rectangulo(float altura, float base)
{
    this->altura = altura;
    this->base = base;
}

float Rectangulo::getArea()
{
    return altura * base;
}

float Rectangulo::getPerimetro()
{
    return 2 * (altura + base);
}

bool Rectangulo::esCuadrado()
{
    return altura == base;
}

void Rectangulo::incrementar(int &valor)
{
    valor += 1;
}


void Rectangulo::incrementar(const Rectangulo &rectangulo)
{
    this->altura += rectangulo.altura;
    this->base += rectangulo.base;
}
