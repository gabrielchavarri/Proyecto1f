//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_ORDENADOR_T_H
#define PROYECTO1F_ORDENADOR_T_H

#include "Equipo.h"

class Ordenador_T {
public:
    void ordenar(Equipo **arr, int n);

    int busquedaBinaria(Equipo **arr, int n, const string &id);

    void acomodar(Equipo **arr, int n, int i);
};


#endif //PROYECTO1F_ORDENADOR_T_H
