//
// Created by jr156 on 13/4/2026.
//

#include "GeneradorReportes.h"

void GeneradorReportes::generarReporteDiario(int dia, Equipo **atendidos, int cantidad, int backlog, float riesgo, std::ofstream &archivo) {
    archivo << "Dia: " << dia << std::endl;
    archivo<<"Top prioridad:";
    for (int i = 0; i < cantidad; i++) {
        archivo << atendidos[i]->getId()<<"("<<atendidos[i]->calcularPrioridad()<<")";
    }
    archivo << "Asignados: ";
    for (int i = 0; i < cantidad; i++) {
        archivo << atendidos[i]->getId();
        if (i < cantidad - 1) archivo << ", ";
    }
    archivo << std::endl;
    if (riesgo > 100) archivo << "Riesgo: ALTO";
    else if (riesgo > 50) archivo << "Riesgo: MEDIO";
    else archivo << "Riesgo: BAJO";
    archivo << std::endl;
    archivo << "Backlog: " << backlog << std::endl;
}
