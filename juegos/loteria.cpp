#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

// Dibuja el titulo del juego en arte ASCII.
// Ojo: dentro de un string de C++ hay que escribir "\\" para que salga UNA sola
// barra invertida, porque la barra sola arranca secuencias como \n.
void mostrarTitulo()
{
    cout << endl;
    cout << "  +=======================================================+" << endl;
    cout << "  |    _       ___   _____  _____  ____   ___     _       |" << endl;
    cout << "  |   | |     / _ \\ |_   _|| ____||  _ \\ |_ _|   / \\      |" << endl;
    cout << "  |   | |    | | | |  | |  |  _|  | |_) | | |   / _ \\     |" << endl;
    cout << "  |   | |___ | |_| |  | |  | |___ |  _ <  | |  / ___ \\    |" << endl;
    cout << "  |   |_____| \\___/   |_|  |_____||_| \\_\\|___|/_/   \\_\\   |" << endl;
    cout << "  |                  * * *   1 0   * * *                  |" << endl;
    cout << "  +=======================================================+" << endl;
}

// Imprime las opciones del menu principal.
void mostrarMenu()
{
    cout << endl;
    cout << "  [1] Jugar" << endl;
    cout << "  [2] Como se juega" << endl;
    cout << "  [3] Salir" << endl;
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

// Explica las reglas.
void mostrarInstrucciones()
{
    cout << endl;
    cout << "  COMO SE JUEGA" << endl;
    cout << "  -------------------------------------------------------" << endl;
    cout << "  1. Eliges un numero del 1 al 100." << endl;
    cout << "  2. Se sortean 10 numeros distintos, sin repetir ninguno." << endl;
    cout << "  3. Si tu numero sale en alguno de los 10, ganas 100$." << endl;
    cout << endl;
    cout << "  Como los 10 sorteos son distintos, tu chance es de" << endl;
    cout << "  10 en 100, o sea exactamente 10%." << endl;
    cout << endl;
}

// Juega una partida completa de 10 sorteos sin repetir.
// El generador llega por referencia (&) para reutilizar el mismo de todo el
// programa: si se creara uno nuevo aqui, dos partidas seguidas podrian
// sembrarse igual y repetir la misma secuencia de numeros.
void jugar(mt19937 &gen, uniform_int_distribution<int> &distrib)
{
    int numero = leerEntero("  Tu numero (1-100): ", 1, 100);

    // usados[n] == true significa que el numero n ya salio en ESTA partida.
    bool usados[101] = {false};
    bool gano = false;

    cout << endl;
    for (int i = 0; i < 10 && !gano; i++)
    {
        // Pausa de 600 ms antes de revelar cada sorteo, para que se vean
        // de a uno y no los diez de golpe. Funciona porque cada 'endl' anterior
        // ya vacio el buffer: lo escrito aparece en pantalla ANTES de dormir.
        this_thread::sleep_for(chrono::milliseconds(600));

        // Sortea hasta obtener un numero que todavia no haya salido.
        int result;
        do
        {
            result = distrib(gen);
        } while (usados[result]);
        usados[result] = true;

        if (numero == result)
        {
            cout << "  Intento " << i + 1 << ": salio " << result << endl;
            cout << endl;
            cout << "  *** FELICIDADES, GANASTE 100$ ***" << endl;
            gano = true;
        }
        else
        {
            cout << "  Intento " << i + 1 << ": salio " << result << " ... no es el tuyo" << endl;
        }
    }

    if (!gano)
    {
        cout << endl;
        cout << "  Se acabaron los 10 intentos. Tu numero era el " << numero << "." << endl;
    }
    cout << endl;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);

    mostrarTitulo();

    int opcion = 0;
    while (opcion != 3)
    {
        mostrarMenu();
        opcion = leerEntero("  Opcion: ", 1, 3);

        switch (opcion)
        {
        case 1:
            jugar(gen, distrib);
            break;
        case 2:
            mostrarInstrucciones();
            break;
        case 3:
            cout << endl << "  Gracias por jugar. Hasta luego!" << endl << endl;
            break;
        }
    }
    return 0;
}
