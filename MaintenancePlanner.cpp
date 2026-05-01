#include "MaintenancePlanner.h"
#include "MantCorrectivo.h"
#include "MantPreventivo.h"

MaintenancePlanner::MaintenancePlanner(ColeccionEquipos* e) {
   equipos = e;
   cantidadTecnicos = 3;
}

void MaintenancePlanner::planificarDia() {
   equipos->ordenarPorPrioridad();
}

void MaintenancePlanner::seleccionarTop3(Equipo* seleccionados[], int& cantidad) {
   cantidad = 0;

   for (int i = 0; i < equipos->getSize() && cantidad < cantidadTecnicos; i++) {
      seleccionados[cantidad++] = equipos->obtener(i);
   }
}

void MaintenancePlanner::ejecutarMantenimiento(Equipo* seleccionados[], int& cantidad) {
   for (int i = 0; i < cantidad; i++) {

      if (seleccionados[i]->getIncidenciasActivas() > 0) {
         MantCorrectivo correctivo;
         correctivo.aplicar(seleccionados[i]);
      } else {
         MantPreventivo preventivo;
         preventivo.aplicar(seleccionados[i]);
      }
   }
}