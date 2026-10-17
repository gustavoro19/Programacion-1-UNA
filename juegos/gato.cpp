#include <iostream>

using namespace std;

// Cantidad de casillas del tablero. Se declara como constante porque dentro
// de una funcion no se puede calcular el tamano de un arreglo recibido.
const int TAM = 9;

// Dibuja el tablero. Las casillas vacias muestran su numero para que el
// jugador sepa cual digitar.
void mostrarTablero(char tablero[])
{
    cout << endl;

    for (int i = 0; i < TAM; i += 3)
    {
        for (int j = i; j < i + 3; j++)
        {
            if (tablero[j] == ' ')
            {
                cout << " " << j << " ";
            }
            else
            {
                cout << " " << tablero[j] << " ";
            }

            if (j < i + 2)
            {
                cout << "|";
            }
        }

        cout << endl;

        if (i < 6)
        {
            cout << "---+---+---" << endl;
        }
    }

    cout << endl;
}

bool siGanoSimbolo(char simbolo, char tablero[])
{
    if (tablero[0] == simbolo && tablero[1] == simbolo && tablero[2] == simbolo)
    {
        return true;
    }

    if (tablero[3] == simbolo && tablero[4] == simbolo && tablero[5] == simbolo)
    {
        return true;
    }

    if (tablero[6] == simbolo && tablero[7] == simbolo && tablero[8] == simbolo)
    {
        return true;
    }

    if (tablero[0] == simbolo && tablero[3] == simbolo && tablero[6] == simbolo)
    {
        return true;
    }

    if (tablero[1] == simbolo && tablero[4] == simbolo && tablero[7] == simbolo)
    {
        return true;
    }

    if (tablero[2] == simbolo && tablero[5] == simbolo && tablero[8] == simbolo)
    {
        return true;
    }

    if (tablero[0] == simbolo && tablero[4] == simbolo && tablero[8] == simbolo)
    {
        return true;
    }

    if (tablero[2] == simbolo && tablero[4] == simbolo && tablero[6] == simbolo)
    {
        return true;
    }

    return false;
}

bool siHayEmpate(char tablero[])
{
    // Se recorre con TAM. Aqui sizeof(tablero) daria 8, que es el tamano de
    // un puntero y no el del arreglo, y la ultima casilla nunca se revisaria.
    for (int i = 0; i < TAM; i++)
    {
        if (tablero[i] == ' ')
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char arreglo[TAM] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char turnoActual = 'X';
    int posicionSeleccionada = -1;

    do
    {
        mostrarTablero(arreglo);

        cout << "Es el turno de " << turnoActual << endl;
        cout << "Elija una casilla (0-8): ";
        cin >> posicionSeleccionada;

        // Se vuelve a pedir mientras la jugada no sirva. El orden de las
        // condiciones importa: primero se revisa el rango y de ultimo la
        // casilla, porque leer arreglo[posicion] con un indice fuera del
        // arreglo escribe en memoria que no le pertenece al programa.
        while (!cin || posicionSeleccionada < 0 || posicionSeleccionada >= TAM ||
               arreglo[posicionSeleccionada] != ' ')
        {
            if (!cin)
            {
                // Si se digito algo que no es numero hay que limpiar el error
                // y descartar la linea, o cin queda fallando para siempre
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Eso no es un numero. Elija una casilla (0-8): ";
            }
            else if (posicionSeleccionada < 0 || posicionSeleccionada >= TAM)
            {
                cout << "Esa casilla no existe. Elija una casilla (0-8): ";
            }
            else
            {
                cout << "Esa casilla ya esta ocupada. Elija otra (0-8): ";
            }

            cin >> posicionSeleccionada;
        }

        arreglo[posicionSeleccionada] = turnoActual;

        if (turnoActual == 'X')
        {
            turnoActual = 'O';
        }
        else
        {
            turnoActual = 'X';
        }

    } while (!siGanoSimbolo('X', arreglo) && !siGanoSimbolo('O', arreglo) && !siHayEmpate(arreglo));

    mostrarTablero(arreglo);

    // Van encadenados con else if y no como tres if sueltos: cuando la jugada
    // ganadora es la que llena el tablero, siHayEmpate tambien da true y se
    // imprimirian dos resultados a la vez.
    if (siGanoSimbolo('X', arreglo))
    {
        cout << "ha ganado la X" << endl;
    }
    else if (siGanoSimbolo('O', arreglo))
    {
        cout << "ha ganado la O" << endl;
    }
    else
    {
        cout << "Empate" << endl;
    }

    return 0;
}
