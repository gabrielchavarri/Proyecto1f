#include "Simulador.h"
#include "ColeccionEquipos.h"
#include "CargadorDatos.h"
#include "ArchivoInvalidoExc.h"
#include "FormatoInvalidoExc.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(time(0));
    ColeccionEquipos* coleccion = new ColeccionEquipos();
    CargadorDatos cargador;

    try {
        cargador.cargarEquipos("equipos.txt", *coleccion);
        cargador.cargarIncidencias("incidencias.txt", *coleccion);
    } catch (ArchivoInvalidoExc& e) {
        std::cout << "Error: " << e.what() << std::endl;
        delete coleccion;
        return 1;
    } catch (FormatoInvalidoExc& e) {
        std::cout << "Error: " << e.what() << std::endl;
        delete coleccion;
        return 1;
    }

    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();
    delete coleccion;
    return 0;
}