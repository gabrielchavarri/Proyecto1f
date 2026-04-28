#include "Simulador.h"
#include "ColeccionEquipos.h"
#include "Equipo.h"
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    srand(time(0));
    ColeccionEquipos* coleccion = new ColeccionEquipos();
    int cantidad = 30;
    for (int i = 0; i < cantidad; i++) {
        std::string id = "EQ" + std::to_string(i + 1);
        int criticidad = rand() % 10 + 1;
        int estado = rand() % 61 + 40;
        coleccion->agregar(new Equipo(id, criticidad, estado));
    }
    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();
    delete coleccion;

    return 0;
}