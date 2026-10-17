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

string Pregunta::getTipo(){
    return "Pregunta";
}

void Pregunta::mostrar(){
    cout << endl;
    cout << titulo << " (" << getTipo();
    if (obligatoria) {
        cout << ", obligatoria)" << endl;
    } else {
        cout << ", opcional)" << endl;
    }
    cout << enunciado << endl;
}

string Pregunta::getId(){
    return this->idPregunta;
}

string Pregunta::getTitulo(){
    return this->titulo;
}

string Pregunta::getEnunciado(){
    return this->enunciado;
}

bool Pregunta::esObligatoria(){
    return this->obligatoria;
}
