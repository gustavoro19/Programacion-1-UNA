#include <iostream>
using namespace std;

double calcNotaExamenes(double examen1, double examen2);
double calcNotaQuiz(int cantidadQuices);
double calcNotaTareas(int cantidadTareas);

void calcNota(){
    double notaFinal, proyecto, examen1, examen2, quices, tareas;
    int cantQuices = 2;
    int cantTareas = 4;
    double porcentProyecto = 0.4;
    double porcentExamenes = 0.3;
    double porcentQuices = 0.15;
    double porcentTareas = 0.15;
    cout << "Ingrese su nota del Proyecto" << endl;
    cin >> proyecto;
    if(proyecto < 0 || proyecto > 100){
        cout << "Nota invalida. Ingrese un numero entre 0 y 100" << endl;
        cin >> proyecto;
    }
    cout << "Ingrese su nota del examen numero 1" << endl;
    cin >> examen1;
    if(examen1 < 0 || examen1 > 100){
        cout << "Nota invalida. Ingrese un numero entre 0 y 100" << endl;
        cin >> examen1;
    }
    cout << "Ingrese su nota del examen numero 2" << endl;
    cin >> examen2;
    if(examen2 < 0 || examen2 > 100){
        cout << "Nota invalida. Ingrese un numero entre 0 y 100" << endl;
        cin >> examen2;
    }
    quices = calcNotaQuiz(cantQuices);
    tareas = calcNotaTareas(cantTareas);
    notaFinal = (proyecto * porcentProyecto) + (calcNotaExamenes(examen1, examen2) * porcentExamenes) + (quices * porcentQuices) + (tareas * porcentTareas);
    cout << "Su nota final es: " << notaFinal << endl;

};

double calcNotaExamenes(double examen1, double examen2){
    return (examen1 + examen2) / 2;
}

double calcNotaQuiz(int cantidadQuices){
    double suma = 0;
    double nota;
    for(int i = 0; i < cantidadQuices; i++){

        cout << "Ingrese su nota del quiz numero " << i + 1 << endl;
        cin >> nota;
        if(nota < 0 || nota > 100){
            cout << "Nota invalida. Ingrese un numero entre 0 y 100" << endl;
            cin >> nota;
        }
        suma = suma + nota;

    };
    return suma / cantidadQuices;
}

double calcNotaTareas(int cantidadTareas){
    double suma = 0;
    double nota;
    for(int i = 0; i < cantidadTareas; i++){

        cout << "Ingrese su nota de la tarea numero " << i + 1 << endl;
        cin >> nota;
        if(nota < 0 || nota > 100){
            cout << "Nota invalida. Ingrese un numero entre 0 y 100" << endl;
            cin >> nota;
        }
        suma = suma + nota;

    };
    return suma / cantidadTareas;
}

int main(){


    calcNota();

    return 0;
};
