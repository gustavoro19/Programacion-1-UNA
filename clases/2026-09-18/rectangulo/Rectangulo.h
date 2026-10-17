#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <string>

using namespace std;

class Rectangulo {
    private:  
        float altura;
        float base;
    public:
        Rectangulo(float altura, float base);
        float getArea();
        float getPerimetro();
        bool esCuadrado();
        void incrementar(int &valor);
        void incrementar(const Rectangulo &rectangulo);
};

#endif
