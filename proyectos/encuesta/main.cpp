#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>
#include "Participante.h"
#include "Encuesta.h"
#include "Respuesta.h"
#include "PreguntaAbierta.h"
#include "PreguntaOpcionMultiple.h"
#include "PreguntaEscala.h"
#include "Opcion.h"

using namespace std;

void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarTitulo()
{
    cout << endl;
    cout << "  +=======================================================+" << endl;
    cout << "  |          S I S T E M A   D E   E N C U E S T A S      |" << endl;
    cout << "  +=======================================================+" << endl;
}

void mostrarMenu()
{
    cout << endl;
    cout << "  [1] Ver encuestas" << endl;
    cout << "  [2] Ver participantes y sus respuestas" << endl;
    cout << "  [3] Responder una encuesta" << endl;
    cout << "  [0] Salir" << endl;
    cout << endl;
}

int leerEntero(const string &mensaje, int minimo, int maximo)
{
    int valor;
    while (true)
    {
        cout << mensaje;
        if (cin >> valor)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (valor >= minimo && valor <= maximo)
            {
                return valor;
            }
            cout << "  >> Fuera de rango. Debe ser de " << minimo << " a " << maximo << "." << endl;
        }
        else if (cin.eof())
        {
            cout << endl << "  Entrada terminada. Hasta luego!" << endl;
            exit(0);
        }
        else
        {
            cout << "  >> Entrada invalida. Escribe un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void pausar()
{
    cout << endl << "  Presione Enter para continuar...";
    string linea;
    getline(cin, linea);
}

int elegirEncuesta(vector<Encuesta*> &encuestas)
{
    cout << endl;
    cout << "  ENCUESTAS" << endl;
    cout << "  -------------------------------------------------------" << endl;
    for (int i = 0; i < (int)encuestas.size(); i++)
    {
        cout << "  [" << i + 1 << "] " << encuestas[i]->getTitulo();
        if (encuestas[i]->estaActiva())
        {
            cout << "  (activa)" << endl;
        }
        else
        {
            cout << "  (cerrada)" << endl;
        }
    }
    cout << "  [0] Volver" << endl;
    cout << endl;

    int opcion = leerEntero("  Opcion: ", 0, encuestas.size());
    return opcion - 1;
}

int elegirParticipante(vector<Participante*> &participantes)
{
    cout << endl;
    cout << "  PARTICIPANTES" << endl;
    cout << "  -------------------------------------------------------" << endl;
    for (int i = 0; i < (int)participantes.size(); i++)
    {
        cout << "  [" << i + 1 << "] " << participantes[i]->getNombre()
             << "  (" << participantes[i]->getId() << ")" << endl;
    }
    cout << "  [0] Volver" << endl;
    cout << endl;

    int opcion = leerEntero("  Opcion: ", 0, participantes.size());
    return opcion - 1;
}

void mostrarDetalleEncuesta(Encuesta *encuesta)
{
    cout << endl;
    cout << "  " << encuesta->getTitulo() << endl;
    cout << "  -------------------------------------------------------" << endl;
    cout << "  Código          : " << encuesta->getId() << endl;
    cout << "  Descripción     : " << encuesta->getDescripcion() << endl;
    cout << "  Vigencia        : " << encuesta->getFechaInicio() << " al " << encuesta->getFechaFin() << endl;
    if (encuesta->estaActiva())
    {
        cout << "  Estado          : activa" << endl;
    }
    else
    {
        cout << "  Estado          : cerrada" << endl;
    }
    cout << "  Preguntas       : " << encuesta->getPreguntas().size() << endl;
    cout << "  Participaciones : " << encuesta->getCantidadRespuestas() << endl;
}

void mostrarResultados(Encuesta *encuesta, vector<Participante*> &participantes)
{
    cout << endl;
    cout << "  RESULTADOS: " << encuesta->getTitulo() << endl;
    cout << "  -------------------------------------------------------" << endl;
    cout << "  Participaciones: " << encuesta->getCantidadRespuestas() << endl;
    cout << fixed << setprecision(1);

    vector<Pregunta*> preguntas = encuesta->getPreguntas();
    for (int i = 0; i < (int)preguntas.size(); i++)
    {
        cout << endl << "  " << preguntas[i]->getTitulo() << ": " << preguntas[i]->getEnunciado() << endl;

        if (preguntas[i]->getTipo() == "Opción múltiple")
        {
            PreguntaOpcionMultiple *multiple = (PreguntaOpcionMultiple*) preguntas[i];
            int total = multiple->getTotalVotos();
            vector<Opcion> opciones = multiple->getOpciones();
            for (int j = 0; j < (int)opciones.size(); j++)
            {
                cout << "    " << opciones[j].getTexto() << ": " << opciones[j].getVotos()
                     << " votos (" << opciones[j].getPorcentaje(total) << " %)" << endl;
            }
        }
        else
        {
            bool hayRespuestas = false;
            for (int j = 0; j < (int)participantes.size(); j++)
            {
                vector<Respuesta*> respuestas = participantes[j]->getRespuestas();
                for (int k = 0; k < (int)respuestas.size(); k++)
                {
                    if (respuestas[k]->getPregunta() == preguntas[i])
                    {
                        cout << "    " << participantes[j]->getNombre() << ": ";
                        if (respuestas[k]->getValor() == "")
                        {
                            cout << "(sin respuesta)" << endl;
                        }
                        else
                        {
                            cout << respuestas[k]->getValor() << endl;
                        }
                        hayRespuestas = true;
                    }
                }
            }
            if (!hayRespuestas)
            {
                cout << "    Todavía no hay respuestas." << endl;
            }
        }
    }
}

void menuEncuesta(Encuesta *encuesta, vector<Participante*> &participantes)
{
    int opcion;
    do
    {
        limpiarPantalla();
        mostrarTitulo();
        mostrarDetalleEncuesta(encuesta);
        cout << endl;
        cout << "  [1] Ver preguntas" << endl;
        cout << "  [2] Ver resultados" << endl;
        if (encuesta->estaActiva())
        {
            cout << "  [3] Cerrar encuesta" << endl;
        }
        else
        {
            cout << "  [3] Activar encuesta" << endl;
        }
        cout << "  [0] Volver" << endl;
        cout << endl;
        opcion = leerEntero("  Opcion: ", 0, 3);

        switch (opcion)
        {
        case 1:
        {
            vector<Pregunta*> preguntas = encuesta->getPreguntas();
            for (int i = 0; i < (int)preguntas.size(); i++)
            {
                preguntas[i]->mostrar();
            }
            pausar();
            break;
        }
        case 2:
            mostrarResultados(encuesta, participantes);
            pausar();
            break;
        case 3:
            if (encuesta->estaActiva())
            {
                encuesta->cerrar();
            }
            else
            {
                encuesta->activar();
            }
            break;
        }
    } while (opcion != 0);
}

void mostrarRespuestasDe(Participante *participante, vector<Encuesta*> &encuestas)
{
    cout << endl;
    cout << "  " << participante->getNombre() << endl;
    cout << "  -------------------------------------------------------" << endl;
    cout << "  Carné  : " << participante->getId() << endl;
    cout << "  Correo : " << participante->getEmail() << endl;

    vector<Respuesta*> respuestas = participante->getRespuestas();
    if (respuestas.size() == 0)
    {
        cout << endl << "  Todavía no ha respondido ninguna encuesta." << endl;
        return;
    }

    for (int i = 0; i < (int)encuestas.size(); i++)
    {
        bool tituloImpreso = false;
        vector<Pregunta*> preguntas = encuestas[i]->getPreguntas();
        for (int j = 0; j < (int)preguntas.size(); j++)
        {
            for (int k = 0; k < (int)respuestas.size(); k++)
            {
                if (respuestas[k]->getPregunta() == preguntas[j])
                {
                    if (!tituloImpreso)
                    {
                        cout << endl << "  " << encuestas[i]->getTitulo() << endl;
                        tituloImpreso = true;
                    }
                    cout << "    " << preguntas[j]->getTitulo() << ": ";
                    if (respuestas[k]->getValor() == "")
                    {
                        cout << "(sin respuesta)" << endl;
                    }
                    else
                    {
                        cout << respuestas[k]->getValor() << endl;
                    }
                }
            }
        }
    }
}

int main()
{
    Encuesta evaluacion("E1", "Evaluación del curso Programación I",
                        "Opinión de los estudiantes sobre el curso EIF201", "2026-10-01", "2026-10-31");
    PreguntaOpcionMultiple *lenguaje = new PreguntaOpcionMultiple("P1", "Lenguaje favorito", "¿Qué lenguaje prefiere?", true, false);
    lenguaje->agregarOpcion(Opcion("1", "C++"));
    lenguaje->agregarOpcion(Opcion("2", "Python"));
    lenguaje->agregarOpcion(Opcion("3", "Java"));
    evaluacion.agregarPregunta(lenguaje);
    evaluacion.agregarPregunta(new PreguntaEscala("P2", "Dificultad", "Del 1 al 5, ¿qué tan difícil fue el curso?", true, 1, 5));
    evaluacion.agregarPregunta(new PreguntaAbierta("P3", "Comentario", "¿Qué mejoraría del curso?", false, 150));
    evaluacion.activar();

    vector<Encuesta*> encuestas = {&evaluacion};

    Participante ana("402350187", "Gustavo Rojas", "gustavo.rojas.porras@est.una.ac.cr");
    Participante luis("501920796", "Raychel Rodriguez", "raychel.rodriguez.marquez@est.una.ac.cr");
    vector<Participante*> participantes = {&ana, &luis};

    int opcion;
    do
    {
        limpiarPantalla();
        mostrarTitulo();
        mostrarMenu();
        opcion = leerEntero("  Opcion: ", 0, 3);

        switch (opcion)
        {
        case 1:
        {
            int pos;
            do
            {
                limpiarPantalla();
                mostrarTitulo();
                pos = elegirEncuesta(encuestas);
                if (pos != -1)
                {
                    menuEncuesta(encuestas[pos], participantes);
                }
            } while (pos != -1);
            break;
        }
        case 2:
        {
            int pos;
            do
            {
                limpiarPantalla();
                mostrarTitulo();
                pos = elegirParticipante(participantes);
                if (pos != -1)
                {
                    mostrarRespuestasDe(participantes[pos], encuestas);
                    pausar();
                }
            } while (pos != -1);
            break;
        }
        case 3:
        {
            limpiarPantalla();
            mostrarTitulo();
            cout << endl << "  ¿Quién va a responder?" << endl;
            int posParticipante = elegirParticipante(participantes);
            if (posParticipante == -1)
            {
                break;
            }
            cout << endl << "  ¿Qué encuesta va a responder " << participantes[posParticipante]->getNombre() << "?" << endl;
            int posEncuesta = elegirEncuesta(encuestas);
            if (posEncuesta == -1)
            {
                break;
            }
            participantes[posParticipante]->responderEncuesta(encuestas[posEncuesta]);
            pausar();
            break;
        }
        case 0:
            cout << endl << "  Gracias por participar. Hasta luego!" << endl << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
