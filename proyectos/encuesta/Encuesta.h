#ifndef ENCUESTA_H
#define ENCUESTA_H
#include <string>
#include <vector>

using namespace std;

class Pregunta;

class Encuesta {
    private:
        string idEncuesta;
        string titulo;
        string descripcion;
        string fechaInicio;
        string fechaFin;
        bool activa;
        int cantidadRespuestas;
        vector<Pregunta*> preguntas;
    public:
        Encuesta(string idEncuesta, string titulo, string descripcion, string fechaInicio, string fechaFin);
        ~Encuesta();
        void agregarPregunta(Pregunta* pregunta);
        void eliminarPregunta(Pregunta* pregunta);
        void activar();
        void cerrar();
        vector<Pregunta*> getPreguntas();
        int getCantidadRespuestas();
        void registrarParticipacion();
        bool estaActiva();
        string getTitulo();
        string getId();
        string getDescripcion();
        string getFechaInicio();
        string getFechaFin();
};
#endif
