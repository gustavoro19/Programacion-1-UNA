#include <iostream>
#include "Rectangulo.h"

using namespace std;

int main()
{
    Rectangulo r1 {4, 6};
    Rectangulo r2 {5, 5};
    Rectangulo r3 {5,7};

    cout << "r1 -> area: " << r1.getArea()
         << ", perimetro: " << r1.getPerimetro()
         << ", es cuadrado: " << (r1.esCuadrado() ? "si" : "no") << endl;

    cout << "r2 -> area: " << r2.getArea()
         << ", perimetro: " << r2.getPerimetro()
         << ", es cuadrado: " << (r2.esCuadrado() ? "si" : "no") << endl;

    int n = 10;
    cout << "\nincrementar(" << n << endl;
    r3.incrementar(n);
    cout << "n es ahora: " << n << endl;

    cout << "\nArea de r3 antes de incrementar: " << r3.getArea() << endl;
    r3.incrementar(r1);
    cout << "Area de r3 despues de incrementar: " << r3.getArea() << endl;
    cout << "Area de r1 sigue siendo: " << r1.getArea() << endl;

    return 0;
}
