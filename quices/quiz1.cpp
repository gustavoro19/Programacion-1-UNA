#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{

    if (argc > 1)
    {
        string semana[7] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};
        int dia = atoi(argv[1]);
        int diaSiguiente = dia + 1;
        int diaAnterior = dia - 1;
        if(dia < 0 || dia > 6){
            cout<<"Pon un numero del 0 al 6" << endl;
            return 0;
        }
        if (dia == 0)
        {
            diaAnterior = 6;
        }
        else if (dia == 6)
        {
            diaSiguiente = 0;
        }
        cout << "Seleccionaste: " << semana[dia] << endl;
        cout << "Dia Anterior: " << semana[diaAnterior] << endl;
        cout << "Dia Siguiente: " << semana[diaSiguiente] << endl;
    }

    return 0;
}