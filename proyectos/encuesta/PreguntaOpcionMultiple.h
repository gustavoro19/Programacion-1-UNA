#ifndef PREGUNTAOPCIONMULTIPLE_H
#define PREGUNTAOPCIONMULTIPLE_H
#include <vector>
#include "Pregunta.h"
#include "Opcion.h"

class PreguntaOpcionMultiple : public Pregunta {
    private:
        bool permiteVariasOpciones;
        vector<Opcion> opciones;
        vector<string> separarIds(string valor);
        bool existeOpcion(string id);
    public:
        PreguntaOpcionMultiple(string idPregunta, string titulo, string enunciado, bool obligatoria, bool permiteVariasOpciones);
        void agregarOpcion(Opcion opcion);
        vector<Opcion> getOpciones();
        bool validarRespuesta(Respuesta respuesta);
        string getTipo();
        void mostrar();
        void registrarVotos(string valor);
        int getTotalVotos();
};
#endif
