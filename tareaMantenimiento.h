//
// Created by jr156 on 15/4/2026.
//

#ifndef PROYECTO1F_TAREAMANTENIMIENTO_H
#define PROYECTO1F_TAREAMANTENIMIENTO_H

#include <string>
using namespace std;

class Equipo;

class tareaMantenimiento {
private:
    string equipo_id;
    string tipo_mantenimiento;
    int dia_asignado;
    bool completada;

public:
    tareaMantenimiento(const string &equipo_id, const string &tipo_mantenimiento, int dia_asignado);

    string getEquipoId() const;

    string getTipoMantenimiento() const;

    int getDiaAsignado() const;

    bool isCompletada() const;

    void completar();

    string toTexto() const;
};


#endif //PROYECTO1F_TAREAMANTENIMIENTO_H
