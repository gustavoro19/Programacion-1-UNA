#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <string>
#include <vector>

using namespace std;

class Encuesta;
class Respuesta;

class Participante {
    private:
        string idParticipante;
        string nombre;
        string email;
        vector<Respuesta*> respuestas;
        vector<Encuesta*> encuestas;
    public:
        Participante(string idParticipante, string nombre, string email);
        ~Participante();
        void responderEncuesta(Encuesta* encuesta);
        vector<Respuesta*> getRespuestas();
        string getNombre();
        string getId();
        string getEmail();
};
#endif
