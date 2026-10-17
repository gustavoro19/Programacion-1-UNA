#include "Opcion.h"

Opcion::Opcion(string idOpcion, string texto){
    this->idOpcion = idOpcion;
    this->texto = texto;
    this->votos = 0;
}

void Opcion::registrarVoto(){
    votos++;
}

double Opcion::getPorcentaje(int totalVotos){
    if (totalVotos == 0) {
        return 0;
    }
    return (votos * 100.0) / totalVotos;
}

string Opcion::getId(){
    return this->idOpcion;
}

string Opcion::getTexto(){
    return this->texto;
}

int Opcion::getVotos(){
    return this->votos;
}
