#ifndef OPCION_H
#define OPCION_H
#include <string>

using namespace std;

class Opcion {
    private:
        string idOpcion;
        string texto;
        int votos;
    public:
        Opcion(string idOpcion, string texto);
        void registrarVoto();
        double obtenerPorcentaje(int totalVotos);
        string obtenerId();
        string obtenerTexto();
        int obtenerVotos();
};
#endif
