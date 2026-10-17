#ifndef PREGUNTA_H
#define PREGUNTA_H
#include <string>

using namespace std;

class Respuesta;

class Pregunta {
    private:
        string idPregunta;
        string titulo;
        string enunciado;
        bool obligatoria;
    public:
        Pregunta(string idPregunta, string titulo, string enunciado, bool obligatoria);
        virtual ~Pregunta();
        virtual bool validarRespuesta(Respuesta respuesta) = 0;
        virtual string obtenerTipo();
        virtual void mostrar();
        string obtenerId();
        string obtenerTitulo();
        string obtenerEnunciado();
        bool esObligatoria();
};
#endif
