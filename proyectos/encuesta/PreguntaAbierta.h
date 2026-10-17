#ifndef PREGUNTAABIERTA_H
#define PREGUNTAABIERTA_H
#include "Pregunta.h"

class PreguntaAbierta : public Pregunta {
    private:
        int longitudMaxima;
    public:
        PreguntaAbierta(string idPregunta, string titulo, string enunciado, bool obligatoria, int longitudMaxima);
        bool validarRespuesta(Respuesta respuesta);
        string obtenerTipo();
        void mostrar();
};
#endif
