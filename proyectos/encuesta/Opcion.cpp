#include "Opcion.h"

Opcion::Opcion(string idOpcion, string texto){
    this->idOpcion = idOpcion;
    this->texto = texto;
    this->votos = 0;
}

void Opcion::registrarVoto(){
    votos++;
}

double Opcion::obtenerPorcentaje(int totalVotos){
    if (totalVotos == 0) {
        return 0;
    }
    return (votos * 100.0) / totalVotos;
}

string Opcion::obtenerId(){
    return this->idOpcion;
}

string Opcion::obtenerTexto(){
    return this->texto;
}

int Opcion::obtenerVotos(){
    return this->votos;
}
