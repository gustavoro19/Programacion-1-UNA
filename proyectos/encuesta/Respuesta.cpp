#include "Respuesta.h"
#include "Pregunta.h"

Respuesta::Respuesta(string idRespuesta, string valor, string fechaHora, Pregunta* pregunta){
    this->idRespuesta = idRespuesta;
    this->valor = valor;
    this->fechaHora = fechaHora;
    this->pregunta = pregunta;
}

string Respuesta::obtenerValor(){
    return this->valor;
}

bool Respuesta::esValida(){
    if (pregunta == nullptr) {
        return false;
    }
    return pregunta->validarRespuesta(*this);
}

Pregunta* Respuesta::obtenerPregunta(){
    return this->pregunta;
}

string Respuesta::obtenerFechaHora(){
    return this->fechaHora;
}
