//
// Created by jr156 on 13/4/2026.
//

#include "Equipo.h"

#include "MantCorrectivo.h"

Equipo::Equipo(const string &id, float criticidad, float estado) {
    this->id = id;
    this->criticidad = criticidad;
    this->estado = estado;
    this->tiempo_inactivo = 0;
    this->incidencias_activas = 0;
    this->estrategia = nullptr;
}

float Equipo::calcularPrioridad() const {
    return (criticidad * 0.5) + (incidencias_activas * 0.3) + (tiempo_inactivo * 0.2);
}

void Equipo::degradar() {
    estado -= (rand() % 4 + 1);
    if (rand() % 100 < 40) { // 40% probabilidad
        incidencias_activas++;
    }
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

void Equipo::setEstado(float estado) {
    this->estado = estado;
}

void Equipo::setStrategy(MantStrategy *strategy) {
    if (estrategia == nullptr)
        delete estrategia;
    estrategia = strategy;
}
void Equipo::aplicarMantenimiento() {
    if (estrategia != nullptr) {
        estrategia->aplicar(this);
    }
        tiempo_inactivo = 0;

}
Equipo::~Equipo(){
    if (estrategia != nullptr) {
        delete estrategia;
    }
}
MantStrategy* Equipo::getStrategy() const {
    return estrategia;
}
void Equipo :: incrementarTiempoInactivo() {
    tiempo_inactivo++;
}
std::string Equipo::getTipo() const {
    return "Equipo";
}
void Equipo::generarIncidencia() {
    if (incidencias_activas < 10) {
        incidencias_activas++;
    }
}
