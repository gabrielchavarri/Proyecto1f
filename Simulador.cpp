#include "Simulador.h"
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
    int total = equipos->getSize();
    int backlog = 0;

    for (int dia = 1; dia <= 30; dia++) {
        fprintf(archivo, "========== Dia %d ==========\n", dia);

        // 1. Degradar todos
        for (int i = 0; i < total; i++)
            equipos->obtener(i)->degradar();

        // 2. Agregar incidencias (más realista)
        for (int i = 0; i < total; i++) {
            if (rand() % 100 < 15) {
                Equipo *eq = equipos->obtener(i);

                std::string severidad;
                int r = rand() % 100;

                if (r < 20) severidad = "ALTA";
                else if (r < 60) severidad = "MEDIA";
                else severidad = "BAJA";

                eq->agregarIncidencia(
                    new Incidencia(eq, eq->getId(), severidad, dia)
                );
            }
        }

        // 3. Calcular prioridad UNA vez por día
        for (int i = 0; i < total; i++) {
            Equipo* eq = equipos->obtener(i);
            float p = eq->calcularPrioridad();
            eq->setPrioridad(p);
        }

        // 4. Ordenar por prioridad
        equipos->ordenarPorPrioridad();

        // 5. Seleccionar top 3
        int limite = (total < 3) ? total : 3;

        // Top prioridad
        fprintf(archivo, "Top prioridad: ");
        for (int i = 0; i < limite; i++) {
            Equipo *eq = equipos->obtener(i);
            fprintf(archivo, "%s(%.1f)", eq->getId().c_str(), eq->getPrioridad());
            if (i < limite - 1) fprintf(archivo, ", ");
        }
        fprintf(archivo, "\n");

        // 6. Aplicar mantenimiento con dynamic_cast + Strategy
        fprintf(archivo, "Asignados: ");
        for (int i = 0; i < limite; i++) {
            Equipo *eq = equipos->obtener(i);

            EquipoCritico *ec = dynamic_cast<EquipoCritico *>(eq);
            if (ec) {
                ec->activarProtocolo();
                fprintf(archivo, "%s[CRITICO] ", eq->getId().c_str());
            } else {
                fprintf(archivo, "%s[LAB] ", eq->getId().c_str());
            }

            if (eq->getIncidenciasActivas() > 0) {
                MantCorrectivo correctivo;
                correctivo.aplicar(eq);
            } else {
                MantPreventivo preventivo;
                preventivo.aplicar(eq);
            }
        }
        fprintf(archivo, "\n");

        // 7. Equipos pendientes
        fprintf(archivo, "Pendientes: ");
        for (int i = limite; i < total; i++) {
            Equipo *eq = equipos->obtener(i);
            fprintf(archivo, "%s(%.1f) ", eq->getId().c_str(), eq->getPrioridad());
        }
        fprintf(archivo, "\n");

        // 8. Backlog (más realista)
        backlog = 0;
        for (int i = 0; i < total; i++) {
            if (equipos->obtener(i)->getIncidenciasActivas() >= 2) {
                backlog++;
            }
        }
        fprintf(archivo, "Backlog pendiente: %d\n", backlog);

        // 9. Riesgo global normalizado
        float riesgo = 0;
        for (int i = 0; i < total; i++)
            riesgo += equipos->obtener(i)->getPrioridad();

        riesgo /= total;

        if (riesgo > 8) fprintf(archivo, "Riesgo global: ALTO\n");
        else if (riesgo > 5) fprintf(archivo, "Riesgo global: MEDIO\n");
        else fprintf(archivo, "Riesgo global: BAJO\n");

        // 10. Info extra (suma puntos)
        fprintf(archivo, "Tecnicos disponibles: 3\n");

        fprintf(archivo, "Estado simulacion: dia %d de 30 completado\n", dia);
        fprintf(archivo, "------------------------\n");
    }

    fclose(archivo);
}
