//
// Created by jr156 on 13/4/2026.
//

#ifndef PROYECTO1F_COLECCIONEQUIPOS_H
#define PROYECTO1F_COLECCIONEQUIPOS_H


#include "Equipo.h"
#include "Ordenador_T.h"

class ColeccionEquipos {
private:
    Equipo **equipos;
    int size;
    int capacidad;
    Ordenador_T ordenador;

public:
    ColeccionEquipos();

    ~ColeccionEquipos();

    void agregar(Equipo *e);

    void ordenarPorPrioridad();

    Equipo *buscar(const string &id);

    Equipo *obtener(int indice);

    void degradarTodos();

    int getSize() const;
    void actualizarPrioridades();
};

#endif //PROYECTO1F_COLECCIONEQUIPOS_H