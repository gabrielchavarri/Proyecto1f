//
// Created by jr156 on 29/4/2026.
//

#include "Interfaz.h"
#include "ArchivoInvalidoExc.h"
#include "FormatoInvalidoExc.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Interfaz::Interfaz() {
    coleccion = new ColeccionEquipos();
    srand(time(0));
}

Interfaz::~Interfaz() {
    delete coleccion;
}

void Interfaz::mostrarBienvenida() {
    cout << "========================================" << endl;
    cout << "  Sistema de Planificacion de Mantenimiento" << endl;
    cout << "  Universidad Nacional de Costa Rica" << endl;
    cout << "========================================" << endl;
}

void Interfaz::cargarDatos() {
    CargadorDatos cargador;
    try {
        cout << "Cargando equipos..." << endl;
        cargador.cargarEquipos("equipos.txt", *coleccion);
        cout << "Equipos cargados: " << coleccion->getSize() << endl;

        cout << "Cargando incidencias..." << endl;
        cargador.cargarIncidencias("incidencias.txt", *coleccion);
        cout << "Incidencias cargadas correctamente." << endl;

    } catch (ArchivoInvalidoExc& e) {
        cout << "Error: " << e.what() << endl;
        exit(1);
    } catch (FormatoInvalidoExc& e) {
        cout << "Error: " << e.what() << endl;
        exit(1);
    }
}

void Interfaz::ejecutarSimulacion() {
    cout << "Iniciando simulacion de 30 dias..." << endl;
    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();
    cout << "Simulacion completada." << endl;
    cout << "Reporte generado en: reporte.txt" << endl;
}

void Interfaz::ejecutar() {
    mostrarBienvenida();
    cargarDatos();
    ejecutarSimulacion();
}