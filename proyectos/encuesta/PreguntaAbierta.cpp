#include "PreguntaAbierta.h"
#include "Respuesta.h"

#include <iostream>

PreguntaAbierta::PreguntaAbierta(string idPregunta, string titulo, string enunciado, bool obligatoria, int longitudMaxima)
    : Pregunta(idPregunta, titulo, enunciado, obligatoria){
    this->longitudMaxima = longitudMaxima;
}

bool PreguntaAbierta::validarRespuesta(Respuesta respuesta){
    string valor = respuesta.obtenerValor();
    if (valor == "") {
        return !esObligatoria();
    }
    if ((int)valor.length() > longitudMaxima) {
        return false;
    }
    return true;
}

string PreguntaAbierta::obtenerTipo(){
    return "Abierta";
}

void PreguntaAbierta::mostrar(){
    Pregunta::mostrar();
    cout << "(máximo " << longitudMaxima << " caracteres)" << endl;
}
