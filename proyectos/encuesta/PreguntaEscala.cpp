#include "PreguntaEscala.h"
#include "Respuesta.h"

#include <iostream>

PreguntaEscala::PreguntaEscala(string idPregunta, string titulo, string enunciado, bool obligatoria, int valorMinimo, int valorMaximo)
    : Pregunta(idPregunta, titulo, enunciado, obligatoria){
    this->valorMinimo = valorMinimo;
    this->valorMaximo = valorMaximo;
}

bool PreguntaEscala::validarRespuesta(Respuesta respuesta){
    string valor = respuesta.getValor();
    if (valor == "") {
        return !esObligatoria();
    }
    if (valor.length() > 5) {
        return false;
    }
    for (int i = 0; i < (int)valor.length(); i++) {
        if (valor[i] < '0' || valor[i] > '9') {
            return false;
        }
    }
    int numero = stoi(valor);
    if (numero < valorMinimo || numero > valorMaximo) {
        return false;
    }
    return true;
}

string PreguntaEscala::getTipo(){
    return "Escala";
}

void PreguntaEscala::mostrar(){
    Pregunta::mostrar();
    cout << "(número del " << valorMinimo << " al " << valorMaximo << ")" << endl;
}
