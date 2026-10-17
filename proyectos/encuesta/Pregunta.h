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
        virtual string getTipo();
        virtual void mostrar();
        string getId();
        string getTitulo();
        string getEnunciado();
        bool esObligatoria();
};
#endif
