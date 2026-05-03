//
// Created by jr156 on 13/4/2026.
//

#include "GeneradorReportes.h"

void GeneradorReportes::generarReporteDiario(int dia, Equipo** atendidos, int cantidad, int backlog, float riesgo) {
    FILE* archivo = fopen("reporte.txt", "a");
    if (!archivo) return;
    fprintf(archivo, "Dia: %d\n", dia);
    fprintf(archivo, "Top prioridad: ");
    for (int i = 0; i < cantidad; i++)
        fprintf(archivo, "%s(%.1f) ", atendidos[i]->getId().c_str(), atendidos[i]->calcularPrioridad());
    fprintf(archivo, "\nAsignados: ");
    for (int i = 0; i < cantidad; i++) {
        fprintf(archivo, "%s", atendidos[i]->getId().c_str());
        if (i < cantidad - 1) fprintf(archivo, ", ");
    }
    if (riesgo > 100) fprintf(archivo, "\nRiesgo: ALTO\n");
    else if (riesgo > 50) fprintf(archivo, "\nRiesgo: MEDIO\n");
    else fprintf(archivo, "\nRiesgo: BAJO\n");
    fprintf(archivo, "Backlog: %d\n", backlog);
    fprintf(archivo, "------------------------\n");
    fclose(archivo);
}