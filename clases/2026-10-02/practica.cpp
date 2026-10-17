#include <iostream>
#include <vector>

using namespace std;

class Animal
{
public:
    void comer()
    {
        cout << "Comer" << endl;
    }
    virtual void hacerSonido()
    {
        cout << "hacer sonido" << endl;
    }
};

class Gato : public Animal
{
private:
    int nombre;

public:
    void hacerSonido() override
    {
        cout << "maullar" << endl;
    }
};

class Perro : public Animal
{
public:
    void hacerSonido() override
    {
        cout << "ladrar" << endl;
    }
};

class Granja
{
private:
    vector<Animal> animales;

public:
    void agregarAnimal(Animal a)
    {
        animales.push_back(a);
    }

    void mostrar()
    {
        for (auto &an : animales)
        {
            Animal *aa;
            aa = &an;
            aa->hacerSonido();
        }
    }
};

int main()
{
    Granja gr;
    Gato g;
    Perro p;
    gr.agregarAnimal(g);
    gr.agregarAnimal(p);
    gr.mostrar();
}