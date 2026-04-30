#include "Simulador.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"
#include "Incidencia.h"
#include "EquipoCritico.h"
#include <cstdlib>

Simulador::Simulador(ColeccionEquipos *equipoos) {
    equipos = equipoos;
}

void Simulador::ejecutarSimulador() {
    FILE *archivo = fopen("reporte.txt", "w");
    int total = equipos->getSize();
    int backlog = 0;

    for (int dia = 1; dia <= 30; dia++) {
        fprintf(archivo, "========== Dia %d ==========\n", dia);

        // 1. Degradar todos
        for (int i = 0; i < total; i++)
            equipos->obtener(i)->degradar();

        // 2. Agregar incidencias
        for (int i = 0; i < total; i++) {
            if (rand() % 100 < 10) {
                Equipo *eq = equipos->obtener(i);

                eq->agregarIncidencia(
                    new Incidencia(eq, eq->getId(), "MEDIA", dia)

                );
            }
        }

        // 3. Ordenar por prioridad
        equipos->ordenarPorPrioridad();

        // 4. Seleccionar top 3
        int limite = (total < 3) ? total : 3;

        // Top prioridad
        fprintf(archivo, "Top prioridad: ");
        for (int i = 0; i < limite; i++) {
            Equipo *eq = equipos->obtener(i);
            fprintf(archivo, "%s(%.1f)", eq->getId().c_str(), eq->calcularPrioridad());
            if (i < limite - 1) fprintf(archivo, ", ");
        }
        fprintf(archivo, "\n");

        // 5. Aplicar mantenimiento con dynamic_cast
        fprintf(archivo, "Asignados: ");
        for (int i = 0; i < limite; i++) {
            Equipo *eq = equipos->obtener(i);

            // downcasting seguro — accede a comportamiento exclusivo de EquipoCritico
            EquipoCritico *ec = dynamic_cast<EquipoCritico *>(eq);
            if (ec) {
                ec->activarProtocolo();
                fprintf(archivo, "%s[CRITICO] ", eq->getId().c_str());
            } else {
                fprintf(archivo, "%s[LAB] ", eq->getId().c_str());
            }

            // aplicar strategy
            if (eq->getIncidenciasActivas() > 2) {
                MantCorrectivo correctivo;
                correctivo.aplicar(eq);
            } else {
                MantPreventivo preventivo;
                preventivo.aplicar(eq);
            }
        }
        fprintf(archivo, "\n");

        // 6. Equipos pendientes
        fprintf(archivo, "Pendientes: ");
        for (int i = limite; i < total; i++) {
            Equipo *eq = equipos->obtener(i);
            fprintf(archivo, "%s(%.1f) ", eq->getId().c_str(), eq->calcularPrioridad());
        }
        fprintf(archivo, "\n");

        // 7. Backlog y riesgo global
        backlog = 0;

        for (int i = 0; i < total; i++) {
            if (equipos->obtener(i)->getIncidenciasActivas() > 0) {
                backlog++;
            }
        }
        fprintf(archivo, "Backlog pendiente: %d\n", backlog);

        float riesgo = 0;
        for (int i = 0; i < total; i++)
            riesgo += equipos->obtener(i)->calcularPrioridad();

        if (riesgo > total * 8) fprintf(archivo, "Riesgo global: ALTO\n");
        else if (riesgo > total * 5) fprintf(archivo, "Riesgo global: MEDIO\n");
        else fprintf(archivo, "Riesgo global: BAJO\n");

        fprintf(archivo, "Estado simulacion: dia %d de 30 completado\n", dia);
        fprintf(archivo, "------------------------\n");
    }
    fclose(archivo);
}
