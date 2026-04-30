//
// Created by jr156 on 13/4/2026.
#include "MantCorrectivo.h"
void MantCorrectivo::aplicar(Equipo* equipo) {
    if (!equipo) return;
    while (equipo->getIncidenciasActivas() > 0) {
        equipo->resolverIncidencia();
    }
    equipo->setEstado(equipo->getEstado() + 25);
    if (equipo->getEstado() > 100)
        equipo->setEstado(100);
    equipo->resetTiempoInactivo();
}
