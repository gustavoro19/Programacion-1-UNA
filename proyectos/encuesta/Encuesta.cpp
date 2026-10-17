#include "Encuesta.h"
#include "Pregunta.h"

#include <iostream>

Encuesta::Encuesta(string idEncuesta, string titulo, string descripcion, string fechaInicio, string fechaFin){
    this->idEncuesta = idEncuesta;
    this->titulo = titulo;
    this->descripcion = descripcion;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->activa = false;
    this->cantidadRespuestas = 0;
}

Encuesta::~Encuesta(){
    for (int i = 0; i < (int)preguntas.size(); i++) {
        delete preguntas[i];
    }
}

void Encuesta::agregarPregunta(Pregunta* pregunta){
    if (pregunta == nullptr) {
        return;
    }
    if (activa) {
        cout << "No se pueden agregar preguntas a una encuesta activa." << endl;
        delete pregunta;
        return;
    }
    preguntas.push_back(pregunta);
}

void Encuesta::eliminarPregunta(Pregunta* pregunta){
    if (activa) {
        cout << "No se pueden eliminar preguntas de una encuesta activa." << endl;
        return;
    }
    for (int i = 0; i < (int)preguntas.size(); i++) {
        if (preguntas[i] == pregunta) {
            delete preguntas[i];
            preguntas.erase(preguntas.begin() + i);
            return;
        }
    }
}

void Encuesta::activar(){
    if (preguntas.size() == 0) {
        cout << "La encuesta necesita al menos una pregunta para activarse." << endl;
        return;
    }
    activa = true;
}

void Encuesta::cerrar(){
    activa = false;
}

vector<Pregunta*> Encuesta::obtenerPreguntas(){
    return preguntas;
}

int Encuesta::obtenerCantidadRespuestas(){
    return cantidadRespuestas;
}

void Encuesta::registrarParticipacion(){
    cantidadRespuestas++;
}

bool Encuesta::estaActiva(){
    return this->activa;
}

string Encuesta::obtenerTitulo(){
    return this->titulo;
}

string Encuesta::obtenerId(){
    return this->idEncuesta;
}

string Encuesta::obtenerDescripcion(){
    return this->descripcion;
}

string Encuesta::obtenerFechaInicio(){
    return this->fechaInicio;
}

string Encuesta::obtenerFechaFin(){
    return this->fechaFin;
}
