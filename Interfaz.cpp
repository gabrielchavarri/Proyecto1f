#include "Interfaz.h"
#include "ArchivoInvalidoExc.h"
#include "FormatoInvalidoExc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;


void animacionCarga(string mensaje) {
    cout << mensaje;
    cout.flush();

    for (int i = 0; i < 3; i++) {
        this_thread::sleep_for(chrono::milliseconds(400));
        cout << ".";
        cout.flush();
    }
    cout << endl;
}

Interfaz::Interfaz() {
    coleccion = new ColeccionEquipos();
    srand(time(0));
}

Interfaz::~Interfaz() {
    delete coleccion;
}

void Interfaz::mostrarBienvenida() {
    cout << "========================================\n";
    cout << "   SISTEMA DE MANTENIMIENTO\n";
    cout << "========================================\n\n";
}

void Interfaz::cargarDatos() {
    CargadorDatos cargador;

    try {
        animacionCarga("Equipos");
        cargador.cargarEquipos("equipos.txt", *coleccion);
        cout << "Equipos cargados: " << coleccion->getSize() << "\n\n";

        animacionCarga("Incidencias");
        cargador.cargarIncidencias("incidencias.txt", *coleccion);
        cout << "Incidencias listas\n\n";

    } catch (const ArchivoInvalidoExc &e) {
        cout << "Archivo: " << e.what() << "\n";
        exit(1);
    } catch (const FormatoInvalidoExc &e) {
        cout << "Formato: " << e.what() << "\n";
        exit(1);
    }
}

void Interfaz::ejecutarSimulacion() {
    animacionCarga("Simulacion 30 dias");

    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();

    cout << "\nSimulacion completada\n";
    cout << "Generado en reporte.txt\n";
}

void Interfaz::ejecutar() {
    mostrarBienvenida();

    cargarDatos();

    if (coleccion->getSize() == 0) {
        cout << "No hay equipos. Cancelando...\n";
        return;
    }

    ejecutarSimulacion();

    cout << "\nTodo salió bien \n";
}