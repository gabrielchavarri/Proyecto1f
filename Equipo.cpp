//
// Created by jr156 on 13/4/2026.
//

#include "Equipo.h"

Equipo::Equipo(const string &id, float criticidad, float estado) {
    this->id = id;
    this->criticidad = criticidad;
    this->estado = estado;
    this->tiempo_inactivo = 0;
    this->incidencias_activas = 0;
}

float Equipo::calcularPrioridad() const {
    return (criticidad * 0.5) + (incidencias_activas * 0.3) + (tiempo_inactivo * 0.2);
}

void Equipo::degradar() {
    estado -= 5;
    tiempo_inactivo++;
    if (estado < 0)
        estado = 0;
}

string Equipo::getId() const {
    return id;
}

float Equipo::getCriticidad() const {
    return criticidad;
}

float Equipo::getEstado() const {
    return estado;
}

int Equipo::getTiempoInactivo() const {
    return tiempo_inactivo;
}

int Equipo::getIncidenciasActivas() const {
    return incidencias_activas;
}

void Equipo::agregarIncidencia() {
    incidencias_activas++;
}

void Equipo::resolverIncidencia() {
    if (incidencias_activas > 0)
        incidencias_activas--;
}
