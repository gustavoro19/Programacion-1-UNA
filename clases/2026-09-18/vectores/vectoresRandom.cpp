#include <iostream>
#include <vector>
#include <random>

using namespace std;

void imprimir(const vector<int> &v)
{
    cout << "El tamaño del vector es: " << v.size() << endl;
    for (int n : v)
    {
        cout << n << ", ";
    }
    cout << endl;
}

vector<int> generarOrdenado(int cantidad)
{
    vector<int> v;
    for (int i = 1; i <= cantidad; i++)
    {
        v.push_back(i);
    }
    return v;
}

vector<int> desordenar(const vector<int> &original)
{
    random_device rd;
    mt19937 gen(rd());

    vector<int> baraja = original;
    vector<int> resultado;
    while (!baraja.empty())
    {
        uniform_int_distribution<int> distrib(0, baraja.size() - 1);
        int posicion = distrib(gen);

        resultado.push_back(baraja[posicion]);
        baraja[posicion] = baraja.back();
        baraja.pop_back();
    }

    return resultado;
}

int main()
{
    vector<int> ordenado = generarOrdenado(52);
    cout << "Lista ordenada:" << endl;
    imprimir(ordenado);

    vector<int> desordenado = desordenar(ordenado);
    cout << "\nLista desordenada:" << endl;
    imprimir(desordenado);

    return 0;
}
