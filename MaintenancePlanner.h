#ifndef PROYECTO1F_MAINTENANCEPLANNER_H
#define PROYECTO1F_MAINTENANCEPLANNER_H

#include "ColeccionEquipos.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"

class MaintenancePlanner {
private:
    ColeccionEquipos* equipos;
    int cantidadTecnicos;
public:
    MaintenancePlanner(ColeccionEquipos* e);
    void planificarDia();
    void seleccionarTop3(Equipo* seleccionados[], int& cantidad);
    void ejecutarMantenimiento(Equipo* seleccionados[], int& cantidad);
};

#endif