#ifndef RESPUESTA_H
#define RESPUESTA_H
#include <string>

using namespace std;

class Pregunta;

class Respuesta {
    private:
        string idRespuesta;
        string valor;
        Pregunta* pregunta;
    public:
        Respuesta(string idRespuesta, string valor, Pregunta* pregunta);
        string getValor();
        bool esValida();
        Pregunta* getPregunta();
};
#endif
