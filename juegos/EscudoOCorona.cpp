#include <iostream>
#include <iomanip>  // setw y setprecision, para alinear la tabla
#include <string>
#include <limits>
#include <cstdlib>  // rand, srand, exit
#include <ctime>    // time

using namespace std;


// Borra la pantalla. El comando cambia segun el sistema operativo, asi que
// el #ifdef elige el correcto al compilar: cls en Windows, clear en Mac y
// Linux. De esa forma el mismo archivo sirve en los dos lados.
void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Dibuja el titulo del juego en arte ASCII.
void mostrarTitulo()
{
    cout << endl;
    cout << "  +=======================================================+" << endl;
    cout << "  |             E S C U D O   o   C O R O N A             |" << endl;
    cout << "  +=======================================================+" << endl;
}

// Imprime las opciones del menu principal.
void mostrarMenu()
{
    cout << endl;
    cout << "  [1] Jugar" << endl;
    cout << "  [2] Salir" << endl;
    cout << endl;
}

// Pide un entero entre minimo y maximo, y no devuelve hasta recibir uno valido.
// Maneja los dos casos malos por separado:
//   - Numero fuera de rango: se avisa y se vuelve a pedir.
//   - Texto en vez de numero: cin queda en estado de error y hay que repararlo,
//     si no cualquier lectura posterior falla al instante y el menu se imprime
//     infinitas veces.
int leerEntero(const string &mensaje, int minimo, int maximo)
{
    int valor;
    while (true)
    {
        cout << mensaje;
        if (cin >> valor)
        {
            if (valor >= minimo && valor <= maximo)
            {
                return valor;
            }
            cout << "  >> Fuera de rango. Debe ser de " << minimo << " a " << maximo << "." << endl;
        }
        else if (cin.eof())
        {
            // Ya no hay mas entrada (Ctrl+D o un archivo que se acabo).
            // Salimos en vez de girar para siempre pidiendo un dato que no llegara.
            cout << endl << "  Entrada terminada. Hasta luego!" << endl;
            exit(0);
        }
        else
        {
            cout << "  >> Entrada invalida. Escribe un numero." << endl;
            cin.clear();                                         // apaga el flag de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta lo que quedo escrito
        }
    }
}


void jugar()
{
    const int TIROS = 100000;

    int escudos = 0;
    int coronas = 0;

    cout << endl;
    cout << "  Lanzando la moneda " << TIROS << " veces..." << endl;

    for (int i = 0; i < TIROS; i++)
    {
        int tiro = rand() % 2; 

        if (tiro == 0)
        {
            escudos++;
        }
        else
        {
            coronas++;
        }
    }

    /*
       Porcentajes. El 100.0 con decimal es indispensable: si se escribiera
       (escudos * 100) / TIROS, ambos operandos serian enteros y C++ haria
       division entera, descartando los decimales. Al multiplicar por 100.0
       la operacion pasa a hacerse con numeros reales.
    */
    double pctEscudo = (escudos * 100.0) / TIROS;
    double pctCorona = (coronas * 100.0) / TIROS;

    cout << endl;
    cout << "  RESULTADOS DE " << TIROS << " TIROS" << endl;
    cout << "  -------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "  Escudo : " << setw(6) << escudos << " veces  " << setw(6) << pctEscudo << " %" << endl;
    cout << "  Corona : " << setw(6) << coronas << " veces  " << setw(6) << pctCorona << " %" << endl;
    cout << endl;
}

int main()
{
    // srand siembra el generador una sola vez, con la hora actual, para que
    // cada ejecucion del programa produzca una secuencia distinta. Si se
    // llamara dentro del ciclo de tiros, todos los tiros del mismo segundo
    // saldrian iguales.
    srand(time(0));

    mostrarTitulo();

    int opcion = 0;
    while (opcion != 2)
    {
        mostrarMenu();
        opcion = leerEntero("  Opcion: ", 1, 2);

        // Se limpia apenas el usuario escoge, y se vuelve a pintar el titulo
        // para que la pantalla no quede pelada. Los resultados de jugar()
        // se imprimen despues, y siguen a la vista hasta la proxima opcion.
        limpiarPantalla();
        mostrarTitulo();

        switch (opcion)
        {
        case 1:
            jugar();
            break;
        case 2:
            cout << endl << "  Gracias por jugar. Hasta luego!" << endl << endl;
            break;
        }
    }
    return 0;
}
