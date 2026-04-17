#include "Simulador.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"
#include "EquipoCritico.h"
#include "EquiposLaboratorio.h"
#include <fstream>
#include <cstdlib>

Simulador::Simulador(ColeccionEquipos* equipoos) {
    equipos = equipoos;
}

void Simulador::ejecutarSimulador() {
    std::ofstream archivo("reporte.txt");
    int total = equipos->getSize();
    int backlog = 0;

    for (int dia = 1; dia <= 30; dia++) {
        archivo << "Dia " << dia << std::endl;

        for (int i = 0; i < total; i++) {
            equipos->obtener(i)->degradar();
        }

        for (int i = 0; i < total; i++) {
            if (rand() % 100 < 30) {
                equipos->obtener(i)->agregarIncidencia(
                    new Incidencia(equipos->obtener(i)->getId(), "MEDIA", dia)
                );
            }
        }

        equipos->ordenarPorPrioridad();

        int limite = (total < 3) ? total : 3;
        archivo << "Top prioridad: ";

        for (int i = 0; i < limite; i++) {
            Equipo* eq = equipos->obtener(i);
            if (eq->getIncidenciasActivas() > 2) {
                MantCorrectivo correctivo;
                correctivo.aplicar(eq);
            } else {
                MantPreventivo preventivo;
                preventivo.aplicar(eq);
            }
            archivo << eq->getId() << "(" << eq->calcularPrioridad() << ") ";
        }

        archivo << std::endl;
        backlog += (total - limite);
        archivo << "Backlog: " << backlog << std::endl;

        float riesgo = 0;
        for (int i = 0; i < total; i++)
            riesgo += equipos->obtener(i)->calcularPrioridad();

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