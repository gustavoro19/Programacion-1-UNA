#include <iostream>
#include <vector>
#include "Ficha.h"
#include "Columna.h"

using namespace std;

int main()
{
    vector<Columna> columnas;
    columnas.push_back(Columna{"1"});
    columnas.push_back(Columna{"2"});
    columnas.push_back(Columna{"3"});

    for (int i = 3; i >= 1; i--)
    {
        Ficha f{i};
        columnas[0].agregarFicha(f);
    }

    int origen, destino;
    int movimientos = 0;
    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            columnas[i].mostrarColumna();
        }

        cout << "Movimiento origen,destino(ej: 1,2) (0 para salir): " << endl;
        cin >> origen;
        if (origen == 0)
        {
            break;
        }

        char coma;
        cin >> coma >> destino;

        if (!columnas[origen - 1].moverFicha(columnas[destino - 1]))
        {
            continue;
        }

        movimientos++;

        if (columnas[2].getFichas().size() == 3)
        {
            columnas[2].mostrarColumna();
            cout << "Ganaste en " << movimientos << " movimientos!" << endl;
            break;
        }
    }

    return 0;
}
