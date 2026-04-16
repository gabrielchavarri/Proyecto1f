//
// Created by Gabri on 4/15/26.
//

#include "MaintenancePlanner.h"
#define maxtecnico 3

MaintenancePlanner::MaintenancePlanner(ColeccionEquipos *e) {
   equipos = e;
   cantidadTecnicos = 3;
}

void MaintenancePlanner::planificarDia() {
   equipos->actualizarPrioridades();
   equipos-> ordenarPorPrioridad();

}

void MaintenancePlanner::seleccionarTop3(Equipo *seleccionados[], int &cantidad) {
   cantidad = 0;
   for (int i =0;i<equipos->getSize() && cantidad < maxtecnico;i++) {
      seleccionados[cantidad++] = equipos->obtener(i);
   }
}

void MaintenancePlanner::ejecutarMantenimiento(Equipo* seleccionados[],int& cantidad) {
   for (int i = 0; i < cantidad; i++) {
      MantStrategy* estrategia = seleccionados[i]->getStrategy();
   }
}