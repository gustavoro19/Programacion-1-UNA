#include "Semaforo.h"

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

Semaforo::Semaforo(string estado, float tiempoCambio)
{
    this->estado = estado;
    this->tiempoCambio = tiempoCambio;
}

void Semaforo::cambiarEstado()
{
    if (estado == "\033[31mROJO\033[0m")
    {
        estado = "\033[32mVERDE\033[0m";
    }
    else if (estado == "\033[32mVERDE\033[0m")
    {
        estado = "\033[93mAMARILLO\033[0m";
    }
    else
    {
        estado = "\033[31mROJO\033[0m";
    }
}

void Semaforo::funcionar()
{
    cout << "El semaforo empieza en: " << estado << endl;
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(tiempoCambio)));
        cambiarEstado();
        cout << "Estado actual:" << estado << endl;
    }
}
