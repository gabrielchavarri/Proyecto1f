//
// Created by jr156 on 13/4/2026.
#include "MantCorrectivo.h"
void MantCorrectivo::aplicar(Equipo* equipo) {
    equipo->resolverIncidencia();
    equipo->setEstado(equipo->getEstado() + 20.0f);
    if (equipo->getEstado() > 100.0f)
        equipo->setEstado(100.0f);
}
