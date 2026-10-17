#include "Participante.h"
#include "Encuesta.h"
#include "Respuesta.h"
#include "Pregunta.h"
#include "PreguntaOpcionMultiple.h"

#include <iostream>

Participante::Participante(string idParticipante, string nombre, string email){
    this->idParticipante = idParticipante;
    this->nombre = nombre;
    this->email = email;
}

Participante::~Participante(){
    for (int i = 0; i < (int)respuestas.size(); i++) {
        delete respuestas[i];
    }
}

void Participante::responderEncuesta(Encuesta* encuesta){
    if (!encuesta->estaActiva()) {
        cout << "La encuesta no está activa." << endl;
        return;
    }
    for (int i = 0; i < (int)encuestas.size(); i++) {
        if (encuestas[i] == encuesta) {
            cout << nombre << " ya respondió esta encuesta." << endl;
            return;
        }
    }

    cout << endl << "=== " << encuesta->getTitulo() << " ===" << endl;
    vector<Pregunta*> preguntas = encuesta->getPreguntas();
    for (int i = 0; i < (int)preguntas.size(); i++) {
        Pregunta* pregunta = preguntas[i];
        pregunta->mostrar();

        string id = idParticipante + "-" + pregunta->getId();
        string valor;
        bool valida = false;
        do {
            cout << "> ";
            getline(cin, valor);
            if (cin.fail()) {
                cout << endl << "No hay más entrada, se cancela la encuesta." << endl;
                return;
            }
            Respuesta prueba(id, valor, pregunta);
            valida = prueba.esValida();
            if (!valida) {
                cout << "Respuesta no válida, intente de nuevo." << endl;
            }
        } while (!valida);

        respuestas.push_back(new Respuesta(id, valor, pregunta));

        if (pregunta->getTipo() == "Opción múltiple") {
            PreguntaOpcionMultiple* multiple = (PreguntaOpcionMultiple*) pregunta;
            multiple->registrarVotos(valor);
        }
    }

    encuestas.push_back(encuesta);
    encuesta->registrarParticipacion();
    cout << "Gracias, " << nombre << "." << endl;
}

vector<Respuesta*> Participante::getRespuestas(){
    return respuestas;
}

string Participante::getNombre(){
    return this->nombre;
}

string Participante::getId(){
    return this->idParticipante;
}

string Participante::getEmail(){
    return this->email;
}
