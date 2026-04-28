#include "Simulador.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"
#include "Incidencia.h"
#include <cstdlib>

Simulador::Simulador(ColeccionEquipos* equipoos) {
    equipos = equipoos;
}

void Simulador::ejecutarSimulador() {
    FILE* archivo = fopen("reporte.txt", "w");
    int total = equipos->getSize();
    int backlog = 0;

    for (int dia = 1; dia <= 30; dia++) {
        fprintf(archivo, "Dia %d\n", dia);

        for (int i = 0; i < total; i++)
            equipos->obtener(i)->degradar();

        for (int i = 0; i < total; i++) {
            if (rand() % 100 < 30)
                equipos->obtener(i)->agregarIncidencia(
                    new Incidencia(equipos->obtener(i)->getId(), "MEDIA", dia)
                );
        }

        equipos->ordenarPorPrioridad();

        int limite = (total < 3) ? total : 3;
        fprintf(archivo, "Top prioridad: ");

        for (int i = 0; i < limite; i++) {
            Equipo* eq = equipos->obtener(i);
            if (eq->getIncidenciasActivas() > 2) {
                MantCorrectivo correctivo;
                correctivo.aplicar(eq);
            } else {
                MantPreventivo preventivo;
                preventivo.aplicar(eq);
            }
            fprintf(archivo, "%s(%.1f) ", eq->getId().c_str(), eq->calcularPrioridad());
        }

        fprintf(archivo, "\n");
        backlog += (total - limite);
        fprintf(archivo, "Backlog: %d\n", backlog);

        float riesgo = 0;
        for (int i = 0; i < total; i++)
            riesgo += equipos->obtener(i)->calcularPrioridad();

        if (riesgo > total * 8) fprintf(archivo, "Riesgo: ALTO\n");
        else if (riesgo > total * 5) fprintf(archivo, "Riesgo: MEDIO\n");
        else fprintf(archivo, "Riesgo: BAJO\n");

        fprintf(archivo, "------------------------\n");
    }
    fclose(archivo);
}