#include "Simulador.h"
#include "ColeccionEquipos.h"
#include "EquipoCritico.h"
#include "EquiposLaboratorio.h"
#include <cstdlib>
#include <ctime>
#include <string>

int main() {
    srand(time(0));
    ColeccionEquipos* coleccion = new ColeccionEquipos();
    int cantidad = 30;
    for (int i = 0; i < cantidad; i++) {
        std::string id = "EQ" + std::to_string(i + 1);
        float criticidad = rand() % 10 + 1;
        float estado = rand() % 61 + 40;
        if (i % 2 == 0)
            coleccion->agregar(new EquipoCritico(id, criticidad, estado, "Protocolo-A"));
        else
            coleccion->agregar(new EquiposLaboratorio(id, criticidad, estado, "Microscopio"));
    }
    Simulador simulador(coleccion);
    simulador.ejecutarSimulador();
    delete coleccion;
    return 0;
}