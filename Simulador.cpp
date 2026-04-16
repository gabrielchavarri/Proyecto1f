#include "Simulador.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"
#include <fstream>
#include <cstdlib>

Simulador::Simulador(ColeccionEquipos *equipoos) {
    equipos = equipoos;
}

void Simulador::ejecutarSimulador() {
    std::ofstream archivo("reporte.txt");
    int total = equipos->getSize();
    for (int dia = 1; dia <= 30; dia++) {
        archivo << "Dia " << dia << std::endl;
        for (int i = 0; i < total; i++) {
            Equipo* eq = equipos->obtener(i);
            eq->degradar();
            eq->incrementarTiempoInactivo();
            if (rand() % 100 < 30) {
                eq->generarIncidencia();
            }
        }
        equipos->ordenarPorPrioridad();
        int limite = (total < 3) ? total : 3;
        archivo << "Top prioridad: ";
        for (int i = 0; i < limite; i++) {
            Equipo* eq = equipos->obtener(i);
            if (eq->getIncidenciasActivas() > 2)
                eq->setStrategy(new MantCorrectivo());
            else
                eq->setStrategy(new MantPreventivo());
            eq->aplicarMantenimiento();
            archivo << eq->getId()
                    << "(" << eq->calcularPrioridad() << ") ";
        }
        archivo << std::endl;
        static int backlog = 0;
        backlog += (total - limite);
        archivo << "Backlog: " << backlog << std::endl;
        float riesgo = 0;
        for (int i = 0; i < total; i++) {
            riesgo += equipos->obtener(i)->calcularPrioridad();
        }
        if (riesgo > total * 8)
            archivo << "Riesgo: ALTO";
        else if (riesgo > total * 5)
            archivo << "Riesgo: MEDIO";
        else
            archivo << "Riesgo: BAJO";
        archivo << std::endl;
        archivo << "------------------------" << std::endl;
    }
    archivo.close();
}