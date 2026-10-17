#ifndef SEMAFORO_H
#define SEMAFORO_H
#include <string>

using namespace std;

class Semaforo {
    private:  
        std::string estado;
        float tiempoCambio;
    public:
        void cambiarEstado();
        void funcionar();
        Semaforo(string estado, float tiempoCambio);
};

#endif
