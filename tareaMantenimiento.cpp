//
// Created by jr156 on 15/4/2026.
//

#include "tareaMantenimiento.h"

tareaMantenimiento::tareaMantenimiento(const string& equipo_id, const string& tipo_mantenimiento, int dia_asignado)
    : equipo_id(equipo_id),
      tipo_mantenimiento(tipo_mantenimiento),
      dia_asignado(dia_asignado),
      completada(false) {
}

string tareaMantenimiento::getEquipoId() const {
    return equipo_id;
}

string tareaMantenimiento::getTipoMantenimiento() const {
    return tipo_mantenimiento;
}

int tareaMantenimiento::getDiaAsignado() const {
    return dia_asignado;
}

bool tareaMantenimiento::isCompletada() const {
    return completada;
}

void tareaMantenimiento::completar() {
    completada = true;
}

string tareaMantenimiento::toTexto() const {
    return "TASK;" + equipo_id + ";" + tipo_mantenimiento + ";dia=" + to_string(dia_asignado) + ";completada=" + (completada ? "SI" : "NO");
}