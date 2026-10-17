#ifndef RESPUESTA_H
#define RESPUESTA_H
#include <string>

using namespace std;

class Pregunta;

class Respuesta {
    private:
        string idRespuesta;
        string valor;
        string fechaHora;
        Pregunta* pregunta;
    public:
        Respuesta(string idRespuesta, string valor, string fechaHora, Pregunta* pregunta);
        string obtenerValor();
        bool esValida();
        Pregunta* obtenerPregunta();
        string obtenerFechaHora();
};
#endif
