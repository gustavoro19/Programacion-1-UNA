#include "Pregunta.h"
#include "Respuesta.h"

#include <iostream>

Pregunta::Pregunta(string idPregunta, string titulo, string enunciado, bool obligatoria){
    this->idPregunta = idPregunta;
    this->titulo = titulo;
    this->enunciado = enunciado;
    this->obligatoria = obligatoria;
}

Pregunta::~Pregunta(){
}

string Pregunta::obtenerTipo(){
    return "Pregunta";
}

void Pregunta::mostrar(){
    cout << endl;
    cout << titulo << " (" << obtenerTipo();
    if (obligatoria) {
        cout << ", obligatoria)" << endl;
    } else {
        cout << ", opcional)" << endl;
    }
    cout << enunciado << endl;
}

string Pregunta::obtenerId(){
    return this->idPregunta;
}

string Pregunta::obtenerTitulo(){
    return this->titulo;
}

string Pregunta::obtenerEnunciado(){
    return this->enunciado;
}

bool Pregunta::esObligatoria(){
    return this->obligatoria;
}
