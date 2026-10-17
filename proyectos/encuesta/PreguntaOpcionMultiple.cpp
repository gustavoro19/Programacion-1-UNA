#include "PreguntaOpcionMultiple.h"
#include "Respuesta.h"

#include <iostream>

PreguntaOpcionMultiple::PreguntaOpcionMultiple(string idPregunta, string titulo, string enunciado, bool obligatoria, bool permiteVariasOpciones)
    : Pregunta(idPregunta, titulo, enunciado, obligatoria){
    this->permiteVariasOpciones = permiteVariasOpciones;
}

vector<string> PreguntaOpcionMultiple::separarIds(string valor){
    vector<string> ids;
    string actual = "";
    for (int i = 0; i < (int)valor.length(); i++) {
        if (valor[i] == ',') {
            if (actual != "") {
                ids.push_back(actual);
            }
            actual = "";
        } else if (valor[i] != ' ') {
            actual = actual + valor[i];
        }
    }
    if (actual != "") {
        ids.push_back(actual);
    }
    return ids;
}

bool PreguntaOpcionMultiple::existeOpcion(string id){
    for (int i = 0; i < (int)opciones.size(); i++) {
        if (opciones[i].obtenerId() == id) {
            return true;
        }
    }
    return false;
}

void PreguntaOpcionMultiple::agregarOpcion(Opcion opcion){
    if (existeOpcion(opcion.obtenerId())) {
        return;
    }
    opciones.push_back(opcion);
}

vector<Opcion> PreguntaOpcionMultiple::obtenerOpciones(){
    return opciones;
}

bool PreguntaOpcionMultiple::validarRespuesta(Respuesta respuesta){
    vector<string> ids = separarIds(respuesta.obtenerValor());
    if (ids.size() == 0) {
        return !esObligatoria();
    }
    if (!permiteVariasOpciones && ids.size() > 1) {
        return false;
    }
    for (int i = 0; i < (int)ids.size(); i++) {
        if (!existeOpcion(ids[i])) {
            return false;
        }
        for (int j = 0; j < i; j++) {
            if (ids[j] == ids[i]) {
                return false;
            }
        }
    }
    return true;
}

string PreguntaOpcionMultiple::obtenerTipo(){
    return "Opción múltiple";
}

void PreguntaOpcionMultiple::mostrar(){
    Pregunta::mostrar();
    for (int i = 0; i < (int)opciones.size(); i++) {
        cout << "  " << opciones[i].obtenerId() << ") " << opciones[i].obtenerTexto() << endl;
    }
    if (permiteVariasOpciones) {
        cout << "(puede elegir varias, separadas por coma: 1,3)" << endl;
    } else {
        cout << "(elija una opción)" << endl;
    }
}

void PreguntaOpcionMultiple::registrarVotos(string valor){
    vector<string> ids = separarIds(valor);
    for (int i = 0; i < (int)ids.size(); i++) {
        for (int j = 0; j < (int)opciones.size(); j++) {
            if (opciones[j].obtenerId() == ids[i]) {
                opciones[j].registrarVoto();
            }
        }
    }
}

int PreguntaOpcionMultiple::obtenerTotalVotos(){
    int total = 0;
    for (int i = 0; i < (int)opciones.size(); i++) {
        total = total + opciones[i].obtenerVotos();
    }
    return total;
}
