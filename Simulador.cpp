#include "Simulador.h"
#include "MaintenancePlanner.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"
#include "Incidencia.h"
#include "EquipoCritico.h"
#include <cstdlib>
#include <string>


Simulador::Simulador(ColeccionEquipos *equipoos) {
    equipos = equipoos;
}

void Simulador::ejecutarSimulador() {
    FILE *archivo = fopen("reporte.txt", "w");
    if (!archivo) {
        printf("Error al crear archivo de reporte\n");
        return;
    }
    int total = equipos->getSize();
    int backlog = 0;

    for (int dia = 1; dia <= 30; dia++) {
        fprintf(archivo, "========== Dia %d ==========\n", dia);

        // 1. Degradar todos
        for (int i = 0; i < total; i++)
            equipos->obtener(i)->degradar();

        // 2. Agregar incidencias
        for (int i = 0; i < total; i++) {
            if (rand() % 100 < 15) {
                Equipo *eq = equipos->obtener(i);

                string severidad;
                int r = rand() % 100;

                if (r < 20) severidad = "ALTA";
                else if (r < 60) severidad = "MEDIA";
                else severidad = "BAJA";

                Incidencia* inc = new Incidencia(eq, eq->getId(), severidad, dia);
                eq->agregarIncidencia(inc);


                if (inc->getEquipo()->getCriticidad() > 9) {
                    inc->resolver();
                }
            }
        }

        // 3. Calcular prioridad UNA vez por día
        MaintenancePlanner planner(equipos);
        planner.planificarDia();

        Equipo* seleccionados[3];
        int cantidad = 0;
        planner.seleccionarTop3(seleccionados, cantidad);

        // 4. Ordenar por prioridad
        fprintf(archivo, "Top prioridad: ");
        for (int i = 0; i < cantidad; i++) {
            fprintf(archivo, "%s(%.1f)", seleccionados[i]->getId().c_str(), seleccionados[i]->getPrioridad());
            if (i < cantidad - 1) fprintf(archivo, ", ");
        }
        fprintf(archivo, "\n");


        // 5. Aplicar mantenimiento
        fprintf(archivo, "Asignados: ");
        for (int i = 0; i < cantidad; i++) {
            Equipo *eq = seleccionados[i];

            EquipoCritico *ec = dynamic_cast<EquipoCritico *>(eq);
            if (ec) {
                ec->activarProtocolo();
                fprintf(archivo, "%s[CRITICO] ", eq->getId().c_str());
            } else {
                fprintf(archivo, "%s[LAB] ", eq->getId().c_str());
            }
        }

        planner.ejecutarMantenimiento(seleccionados, cantidad);
        fprintf(archivo, "\n");

        // 6. Pendientes
        fprintf(archivo, "Pendientes: ");
        for (int i = cantidad; i < total; i++) {
            Equipo *eq = equipos->obtener(i);
            fprintf(archivo, "%s(%.1f) ", eq->getId().c_str(), eq->getPrioridad());
        }
        fprintf(archivo, "\n");

        // 7. Backlog
        backlog = 0;
        for (int i = 0; i < total; i++) {
            if (equipos->obtener(i)->getIncidenciasActivas() >= 2) {
                backlog++;
            }
        }
        fprintf(archivo, "Backlog pendiente: %d\n", backlog);

        // 8. Riesgo global
        float riesgo = 0;
        for (int i = 0; i < total; i++)
            riesgo += equipos->obtener(i)->getPrioridad();

        riesgo /= total;

        if (riesgo > 8) fprintf(archivo, "Riesgo global: ALTO\n");
        else if (riesgo > 5) fprintf(archivo, "Riesgo global: MEDIO\n");
        else fprintf(archivo, "Riesgo global: BAJO\n");

        // 9. Extra
        fprintf(archivo, "Tecnicos disponibles: 3\n");

        fprintf(archivo, "Estado simulacion: dia %d de 30 completado\n", dia);
        fprintf(archivo, "------------------------\n");
    }

    fclose(archivo);
}