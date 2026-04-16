//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_SIMULADOR_H
#define PROYECTO1F_SIMULADOR_H
#include "ColeccionEquipos.h"
#include "MantStrategy.h"

class Simulador {
private:
    ColeccionEquipos* equipos;
public:
    Simulador(ColeccionEquipos *equipoos);
    void ejecutarSimulador();
};


#endif //PROYECTO1F_SIMULADOR_H