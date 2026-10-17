#ifndef PREGUNTAESCALA_H
#define PREGUNTAESCALA_H
#include "Pregunta.h"

class PreguntaEscala : public Pregunta {
    private:
        int valorMinimo;
        int valorMaximo;
    public:
        PreguntaEscala(string idPregunta, string titulo, string enunciado, bool obligatoria, int valorMinimo, int valorMaximo);
        bool validarRespuesta(Respuesta respuesta);
        string obtenerTipo();
        void mostrar();
};
#endif
