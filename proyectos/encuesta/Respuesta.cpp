#include "Respuesta.h"
#include "Pregunta.h"

Respuesta::Respuesta(string idRespuesta, string valor, Pregunta* pregunta){
    this->idRespuesta = idRespuesta;
    this->valor = valor;
    this->pregunta = pregunta;
}

string Respuesta::getValor(){
    return this->valor;
}

bool Respuesta::esValida(){
    if (pregunta == nullptr) {
        return false;
    }
    return pregunta->validarRespuesta(*this);
}

Pregunta* Respuesta::getPregunta(){
    return this->pregunta;
}
