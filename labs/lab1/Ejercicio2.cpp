#include <iostream>

using namespace std;

int main () {
    int iva = 13;
    double precio;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    cout << "El precio del producto con IVA es: " << precio + (precio * iva / 100) << endl;

}