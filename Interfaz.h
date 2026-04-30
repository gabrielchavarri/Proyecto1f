//
// Created by jr156 on 29/4/2026.
//

#ifndef PROYECTO1F_INTERFAZ_H
#define PROYECTO1F_INTERFAZ_H



#include "ColeccionEquipos.h"
#include "Simulador.h"
#include "CargadorDatos.h"

class Interfaz {
private:
    ColeccionEquipos* coleccion;
    void mostrarBienvenida();
    void cargarDatos();
    void ejecutarSimulacion();

public:
    Interfaz();
    ~Interfaz();
    void ejecutar();
};

#endif //PROYECTO1F_INTERFAZ_H