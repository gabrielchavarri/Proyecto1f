#include "Interfaz.h"
#include "ArchivoInvalidoExc.h"
#include "FormatoInvalidoExc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Interfaz::Interfaz() {
    coleccion = new ColeccionEquipos();
    srand(time(0));
}

Interfaz::~Interfaz() {
    delete coleccion;
}

void Interfaz::mostrarBienvenida() {
    cout << "========================================\n";
    cout << "  Sistema de Planificacion de Mantenimiento\n";
    cout << "  Universidad Nacional de Costa Rica\n";
    cout << "========================================\n\n";
}

void Interfaz::cargarDatos() {
    CargadorDatos cargador;

    try {
        cout << "[INFO] Cargando equipos...\n";
        cargador.cargarEquipos("equipos.txt", *coleccion);
        cout << "[OK] Equipos cargados: " << coleccion->getSize() << "\n\n";

        cout << "[INFO] Cargando incidencias...\n";
        cargador.cargarIncidencias("incidencias.txt", *coleccion);
        cout << "[OK] Incidencias cargadas desde archivo.\n\n";
    } catch (const ArchivoInvalidoExc &e) {
        cout << "[ERROR] Archivo invalido: " << e.what() << "\n";
        cout << "[ABORTANDO] No se puede continuar.\n";
        return;
    } catch (const FormatoInvalidoExc &e) {
        cout << "[ERROR] Formato invalido: " << e.what() << "\n";
        cout << "[ABORTANDO] Verifique los datos de entrada.\n";
        return;
    }
}

void Interfaz::ejecutarSimulacion() {
    cout << "[INFO] Iniciando simulacion de 30 dias...\n";

    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();

    cout << "[OK] Simulacion completada.\n";
    cout << "[INFO] Reporte generado en: reporte.txt\n";
}

void Interfaz::ejecutar() {
    mostrarBienvenida();

    cargarDatos();


    if (coleccion->getSize() == 0) {
        cout << "[WARN] No hay equipos cargados. Simulacion cancelada.\n";
        return;
    }

    ejecutarSimulacion();

    cout << "\n[FIN] Programa finalizado correctamente.\n";
}
