//
// Created by Gabri on 4/15/26.
//

#ifndef PROYECTO1F_MAINTENANCEPLANNER_H
#define PROYECTO1F_MAINTENANCEPLANNER_H
#include "ColeccionEquipos.h"
#include "Tecnico.h"
#include "MantStrategy.h"

class MaintenancePlanner {
    private:
    ColeccionEquipos * equipos;
    Tecnico * tecnicos;
    int cantidadTecnicos;
public:
    MaintenancePlanner(ColeccionEquipos * e);
    void planificarDia();
  void seleccionarTop3(Equipo * seleccionados[],int& cantidad);
    void ejecutarMantenimiento(Equipo * seleccionados[],int& cantidad);
};


#endif //PROYECTO1F_MAINTENANCEPLANNER_H